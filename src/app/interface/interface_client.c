#include "interface_client.h"
#define MAX_ARTICLES 100
#define MAX_CLIENTS 100

void affiche_client(void) {
    printf("\n");
    printf("+-------------+\n");
    printf("|| Bonjour ! ||\n");
    printf("+-------------+\n");
    printf("\n");
    printf("+----------------------------------------------------------------+\n");
    printf("|| Que voulez-vous faire ?\t\t\t\t\t||\n");
    printf("||\t1 : Afficher le récapitulatif du panier.\t \t||\n");
    printf("||\t2 : Afficher les articles disponibles.\t\t\t||\n");
    printf("||\t3 : Ajouter un article au panier.   \t\t\t||\n");
    printf("||\t4 : Supprimer un article du panier. \t\t\t||\n");
    printf("||\t5 : Modifier la quantité d'un article du panier. \t||\n");
    printf("||\t6 : Réinitialiser le panier.\t\t\t\t||\n");
    printf("||\t9 : Quitter.\t\t\t\t\t\t||\n");
    printf("+----------------------------------------------------------------+\n");
}


void ajouter_article_au_panier(int numClient, int tRef[], float tPoids[], float tVol[], float tPrixUnitaire[],
                               int tNumClient[], float tCagnotte[], int tSus[], int tLogArticle, int tLogClient,
                               float volumeCoffre, float chargeMaximale, int tPanier[], int tQuantite[], int *tLogPanier, float budget) {

    int reference, quantite, articleIndex, clientIndex;
    float poidsTotal, montantTotal, volumeTotal, depassementCharge = 0, depassementVolume, depassementBudget = 0;


    printf("Entrez la référence de l'article : ");
    while (scanf("%d", &reference) != 1) {
        while (getchar() != '\n');
        printf("ERREUR : Veuillez entrer une référence valide (nombre) : ");
    }
    while (getchar() != '\n');

    articleIndex = trouver_index_article(reference, tRef, tLogArticle);

    while (articleIndex == -1) {
        printf("ERREUR : Article non trouvé. Veuillez entrer une référence valide : ");
        while(scanf("%d", &reference) != 1) {
            while (getchar() != '\n');
            printf("ERREUR : Veuillez entrer une référence valide (nombre) : ");
        }
        articleIndex = trouver_index_article(reference, tRef, tLogArticle);
    }

    printf("Entrez la quantité : ");
    while (scanf("%d", &quantite) != 1) {
        while (getchar() != '\n');
        printf("ERREUR : Veuillez entrer une quantité valide (nombre) : ");
    }
    while (getchar() != '\n');

    poidsTotal = tPoids[articleIndex] * quantite;
    volumeTotal = tVol[articleIndex] * quantite;
    montantTotal = tPrixUnitaire[articleIndex] * quantite;

    if (poidsTotal > chargeMaximale) {
        depassementCharge = poidsTotal - chargeMaximale;
    }

    if (volumeTotal > volumeCoffre) {
        depassementVolume = volumeTotal - volumeCoffre;
    }

    if (budget > 0 && montantTotal > budget) {
        depassementBudget = montantTotal - budget;
    }

    if (depassementCharge || depassementVolume || depassementBudget) {
        printf("Attention : \n");
        if (depassementCharge) {
            printf("\tDépassement de la charge autorisée de %.2f kg \n", depassementCharge);
        }
        if (depassementVolume) {
            printf("\tDépassement du volume autorisé de %.2f litres \n", depassementVolume);
        }
        if (depassementBudget) {
            printf("\tDépassement du budget autorisé de %.2f euros \n", depassementBudget);
        }
        printf("\n");
    }

    montantTotal = tPrixUnitaire[articleIndex] * quantite;

    clientIndex = trouver_index_client(numClient, tNumClient, tLogClient);

    if (clientIndex != -1) {
        tCagnotte[clientIndex] += 0.1 * montantTotal;
    }

    tPanier[*tLogPanier] = reference;
    tQuantite[*tLogPanier] = quantite;
    (*tLogPanier)++;

    printf("Contenu du panier : ");
    for (int i = 0; i < *tLogPanier; i++) {
        printf("%d ", tPanier[i]);
    }
    printf("\n");

    printf("Référence : %d\nQuantité : %d\n", reference, quantite);
    printf("Récap :\n");
    printf("Réf   Qté   Poids   Vol     PrixU   PoidsTot   VolTot   PrixTot   Cagnotte\n");
    printf("%d   %d     %.2f        %.2f      %.2f     %.2f           %.2f      %.2f      %.2f\n",
           reference, quantite, tPoids[articleIndex], tVol[articleIndex],
           tPrixUnitaire[articleIndex], poidsTotal, volumeTotal, montantTotal,
           tCagnotte[clientIndex]);
    printf("Prix total à payer: %.2f euros\n", montantTotal);
    printf("Cagnotte totale : %.2f euros\n", tCagnotte[clientIndex]);
    printf("Volume utilise : %.2f litres\n", volumeTotal);
    printf("Volume restant : %.2f litres\n", volumeCoffre - volumeTotal);
    printf("Charge Actuelle: %.2f kg\n", poidsTotal);
    printf("Charge restante: %.2f kg\n", chargeMaximale - poidsTotal);

}


void supprimer_article_du_panier(int tPanier[], int tQuantite[], int *tLogPanier, float tCagnotte[], int numClient, int tNumClient[], int tLogClient, int tRef[], float tPrixUnitaire[]) {
    int reference, articleIndex;
    printf("Entrez la référence de l'article à supprimer : ");
    while (scanf("%d", &reference) != 1) {
        while (getchar() != '\n');
        printf("ERREUR : Veuillez entrer une référence valide (nombre) : ");
    }
    while (getchar() != '\n');

    articleIndex = trouver_index_article(reference, tRef, MAX_ARTICLES);

    while (articleIndex == -1) {
        printf("Article non trouvé dans le panier. Veuillez entrer une référence valide : ");
        while(scanf("%d", &reference) != 1) {
            while (getchar() != '\n');
            printf("ERREUR : Veuillez entrer une référence valide (nombre) : ");
        }
        articleIndex = trouver_index_article(reference, tRef, MAX_ARTICLES);
    }

    supprimer_article(tPanier, tQuantite, tLogPanier, reference, numClient, tNumClient, tLogClient, tRef, tPrixUnitaire, tCagnotte);

    printf("Article supprimé du panier avec succès.\n");
}


void affiche_recap_panier(int tPanier[], int tLogPanier, int tRef[], float tPoid[], float tVol[],
                          float tPrixUnitaire[], int tQuantite[], float tCagnotte[], int numClient,
                          int tNumClient[], int tLogClient, float volumeCoffre, float chargeMaximale, float budget) {

    int reference, articleIndex, quantite, clientIndex;
    float poidsTotal = 0, volumeTotal = 0, montantTotal = 0, prixArticle = 0, poidsArticle = 0, volumeArticle = 0;
    char attentionDepassement[200] = "";

    printf("Contenu du panier : ");
    for (int i = 0; i < tLogPanier; i++) {
        printf("%d ", tPanier[i]);
    }
    printf("\n");

    printf("Récap :\n");
    printf("Réf   Qté   Poids   Vol     PrixU   PoidsTot   VolTot   PrixTot\n");

    for (int i = 0; i < tLogPanier; i++) {
        reference = tPanier[i];
        articleIndex = trouver_index_article(reference, tRef, MAX_ARTICLES);

        poidsArticle = tPoid[articleIndex];
        volumeArticle = tVol[articleIndex];
        prixArticle = tPrixUnitaire[articleIndex];
        quantite = tQuantite[i];

        printf("%d\t %d\t %.2f\t %.2f\t %.2f\t %.2f\t %.2f\t %.2f\n",
               reference, quantite, poidsArticle, volumeArticle,
               prixArticle, poidsArticle * quantite, volumeArticle * quantite, prixArticle * quantite);

        poidsTotal += poidsArticle * quantite;
        volumeTotal += volumeArticle * quantite;
        montantTotal += prixArticle * quantite;

        if (poidsTotal > chargeMaximale) {
            float depassement = poidsTotal - chargeMaximale;
            char message[100];
            sprintf(message, "Dépassement de la charge autorisée de %.2f kg.\n", depassement);
            strcat(attentionDepassement, message);
        }
        if (volumeTotal > volumeCoffre) {
            float depassement = volumeTotal - volumeCoffre;
            char message[100];
            sprintf(message, "Dépassement du volume autorisé de %.2f litres.\n", depassement);
            strcat(attentionDepassement, message);
        }
        if (budget > 0 && montantTotal > budget) {
            float depassement = montantTotal - budget;
            char message[100];
            sprintf(message, "Dépassement du budget autorisé de %.2f euros.\n", depassement);
            strcat(attentionDepassement, message);
        }
    }

    clientIndex = trouver_index_client(numClient, tNumClient, tLogClient);

    printf("Prix total à payer: %.2f euros\n", montantTotal);
    printf("Cagnotte totale : %.2f euros\n", tCagnotte[clientIndex]);
    printf("Volume utilise : %.2f litres\n", volumeTotal);
    printf("Charge Actuelle: %.2f kg\n", poidsTotal);

    if (strlen(attentionDepassement) > 0) {
        printf("Attention : %s", attentionDepassement);
    }
}

void configurer_session_client(int tNumClient[], int tLogClient, double *budget, float *volumeCoffre, float *chargeMaximale, int *numClient) {
    int indexClient, choixBudget = 0;

    printf("Veuillez saisir votre numéro de client : ");
    while (scanf("%d", numClient) != 1) {
        while (getchar() != '\n');
        printf("ERREUR : Veuillez entrer un numéro de client valide : ");
    }

    indexClient = trouver_index_client(*numClient, tNumClient, tLogClient);

    while (indexClient == -1) {
        printf("ERREUR : Veuillez entrer un numéro de client valide : ");
        while (scanf("%d", numClient) != 1) {
            while (getchar() != '\n');
            printf("ERREUR : Veuillez entrer un numéro de client valide : ");
        }
        indexClient = trouver_index_client(*numClient, tNumClient, tLogClient);
    }


    printf("Voulez-vous définir un budget à ne pas dépasser ? (1 pour Oui, 0 pour Non) : ");
    while (scanf("%d", &choixBudget) != 1 || (choixBudget != 0 && choixBudget != 1)) {
        while (getchar() != '\n');
        printf("ERREUR : Veuillez entrer 1 pour Oui ou 0 pour Non : ");
    }

    if (choixBudget == 1) {
        printf("Entrez le budget à ne pas dépasser : ");
        while (scanf("%lf", budget) != 1 || *budget <= 0) {
            while (getchar() != '\n');
            printf("ERREUR : Veuillez entrer un budget valide (nombre positif) : ");
        }
    }

    printf("Veuillez saisir la taille disponible du véhicule (en litres) : ");
    while (scanf("%f", volumeCoffre) != 1 || *volumeCoffre <= 0) {
        while (getchar() != '\n');
        printf("ERREUR : Veuillez entrer une taille de coffre valide (en litres) : ");
    }

    printf("Veuillez saisir la charge maximale autorisée (en kg) : ");
    while (scanf("%f", chargeMaximale) != 1 || *chargeMaximale <= 0) {
        while (getchar() != '\n');
        printf("ERREUR : Veuillez entrer une charge maximale valide (en kg) : ");
    }
}

void modifier_quantite_article_panier(int tPanier[], int tQuantite[], int *tLogPanier, float tCagnotte[], int numClient, float tPrixUnitaire[], int tRef[], int tLogClient, int tNumClient[]) {

    int reference, quantite, articleIndex, clientIndex;
    float prixArticle = 0, ancienneQuantite = 0;

    printf("Entrez la référence de l'article : ");
    while (scanf("%d", &reference) != 1) {
        while (getchar() != '\n');
        printf("ERREUR : Veuillez entrer une référence valide (nombre) : ");
    }
    while (getchar() != '\n');

    articleIndex = trouver_index_article(reference, tPanier, *tLogPanier);

    while (articleIndex == -1) {
        printf("Article non trouvé dans le panier. Veuillez entrer une référence valide : ");
        while (scanf("%d", &reference) != 1) {
            while (getchar() != '\n');
            printf("ERREUR : Veuillez entrer une référence valide (nombre) : ");
        }

        articleIndex = trouver_index_article(reference, tPanier, *tLogPanier);
    }

    printf("Entrez la quantité : ");
    while (scanf("%d", &quantite) != 1 || quantite <= 0) {
        while (getchar() != '\n');
        printf("ERREUR : Veuillez entrer une quantité valide (nombre) : ");
    }
    while (getchar() != '\n');

    // Mettre à jour la cagnotte en fonction du changement de quantité
    prixArticle = tPrixUnitaire[trouver_index_article(reference, tRef, MAX_ARTICLES)];
    clientIndex = trouver_index_client(numClient, tNumClient, tLogClient);
    ancienneQuantite = tQuantite[articleIndex];
    tCagnotte[clientIndex] -= (ancienneQuantite - quantite) * prixArticle * 0.1;

    tQuantite[articleIndex] = quantite;

    printf("Quantité modifiée avec succès.\n");
}

void reinitialiser_panier(int tPanier[], int tQuantite[], int *tLogPanier, float tCagnotte[], int numClient, int tNumClient[], int tLogClient, int tRef[], float tPrixUnitaire[]) {
    for (int i = 0; i < *tLogPanier; i++) {
        supprimer_article(tPanier, tQuantite, tLogPanier, tPanier[i], numClient, tNumClient, tLogClient, tRef, tPrixUnitaire, tCagnotte);
    }
    *tLogPanier = 0;
}

void deduire_cagnotte(int numClient, float montant, int tNumClient[], float tCagnotte[], int tLogClient, int tSus[]) {
    int clientIndex = -1;
    for (int i = 0; i < tLogClient; i++) {
        if (tNumClient[i] == numClient) {
            clientIndex = i;
            break;
        }
    }

    if (clientIndex == -1) {
        printf("Client non trouvé. Impossible de déduire la cagnotte.\n");
        return;
    }

    if (tCagnotte[clientIndex] < montant) {
        printf("Cagnotte insuffisante. Impossible de déduire la cagnotte.\n");
        return;
    }

    tCagnotte[clientIndex] -= montant;

    printf("Montant déduit de la cagnotte avec succès.\n");
}

void quitter_application(int tPanier[], int tLogPanier, int tRef[], float tPoid[], float tVol[],
                        float tPrixUnitaire[], int tQuantite[], float tCagnotte[], int numClient,
                        int tNumClient[], int tLogClient, float budget, int tSus[]) {

    int reference, articleIndex, quantite, clientIndex, choixCagnotte = 0;
    float montantTotal = 0, prixArticle = 0, montantDeduction = 0;
    char attentionDepassement[200] = "";

    for (int i = 0; i < tLogPanier; i++) {
        reference = tPanier[i];
        articleIndex = trouver_index_article(reference, tRef, MAX_ARTICLES);

        prixArticle = tPrixUnitaire[articleIndex];
        quantite = tQuantite[i];

        montantTotal += prixArticle * quantite;

        if (budget > 0 && montantTotal > budget) {
            float depassement = montantTotal - budget;
            char message[100];
            sprintf(message, "Dépassement du budget autorisé de %.2f euros.\n", depassement);
            strcat(attentionDepassement, message);
        }
    }

    clientIndex = trouver_index_client(numClient, tNumClient, tLogClient);

    if (tSus[clientIndex] == 1) {
        printf("Vous ne pourrez pas utiliser votre cagnotte car votre carte est suspendu.\n");
    }


    printf("Prix total à payer: %.2f euros\n", montantTotal);
    if (budget > 0) {
        printf("Budget : %.2f euros\n", budget);
    }

    if (budget > 0 && montantTotal > budget && tCagnotte[clientIndex] < (montantTotal - budget)) {
        printf("Attention : %s", attentionDepassement);
        printf("Vous ne pourrez pas payer. De plus vous n'avez pas assez dans votre cagnotte pour la déduire et payer\n");
        printf("Montant de votre cagnotte %.2f\n", tCagnotte[clientIndex]);
    }

    if (budget > 0 && montantTotal > budget && montantTotal < budget + tCagnotte[clientIndex]) {
        printf("Attention : %s", attentionDepassement);
        printf("Vous ne pourrez pas payer, mais vous avez suffisamment dans votre cagnotte pour payer.\n");
        printf("Montant de votre cagnotte %.2f\n", tCagnotte[clientIndex]);
        printf("Voulez-vous déduire de votre cagnotte avant de quitter ? (1 pour Oui, 0 pour Non) : ");
        while (scanf("%d", &choixCagnotte) != 1 || (choixCagnotte != 0 && choixCagnotte != 1)) {
            while (getchar() != '\n');
            printf("ERREUR : Veuillez entrer 1 pour Oui ou 0 pour Non : ");
        }

        if (choixCagnotte == 1) {
            printf("Entrez le montant à déduire de votre cagnotte : ");
            while (scanf("%f", &montantDeduction) != 1) {
                while (getchar() != '\n');
                printf("ERREUR : Veuillez entrer un montant valide (nombre) : ");
            }
            while (getchar() != '\n');

            while (montantDeduction < (montantTotal - budget)) {
                printf("ERREUR : Vous devez déduire suffisamment pour payer l'intégralité du montant dû.\n");
                printf("Montant minimum à déduire pour payer : %.2f\n", montantTotal - budget);
                printf("Entrez le montant à déduire de votre cagnotte : ");
                while (scanf("%f", &montantDeduction) != 1) {
                    while (getchar() != '\n');
                    printf("ERREUR : Veuillez entrer un montant valide (nombre) : ");
                }
                while (getchar() != '\n');
            }

            deduire_cagnotte(numClient, montantDeduction, tNumClient, tCagnotte, tLogClient, tSus);
            printf("Le montant a été déduit de votre cagnotte.\n");
            printf("Il vous reste %.2f euros dans votre cagnotte.\n", tCagnotte[clientIndex]);
        }
    }
}

void menu_client(int *choix) {
    affiche_client();
    printf("Vous choisissez: ");
    while (scanf("%d", choix) != 1 || *choix < 0 || *choix > 9 || (*choix > 6 && *choix < 9)) {
        while (getchar() != '\n');
        printf("ERREUR : Veuillez entrer un choix valide : ");
    }
}

void global_client(void) {
    int choix, tRef[MAX_ARTICLES], tNumClient[MAX_CLIENTS], tSus[MAX_CLIENTS], tLogArticle, tLogClient,
        numClient, tQuantite[MAX_ARTICLES], tPanier[MAX_ARTICLES], tLogPanier = 0;

    float tPoids[MAX_ARTICLES], tVol[MAX_ARTICLES], tPrixUnitaire[MAX_ARTICLES], tCagnotte[MAX_CLIENTS],
          volumeCoffre, chargeMaximale;

    double budget = -1.0;

    tLogArticle = chargementArticles(tRef, tPoids, tVol, tPrixUnitaire, MAX_ARTICLES);
    tLogClient = charger_clients(tNumClient, tCagnotte, tSus, MAX_CLIENTS);
    configurer_session_client(tNumClient, tLogClient, &budget, &volumeCoffre, &chargeMaximale, &numClient);

    do {
        menu_client(&choix);

        switch (choix) {
            case 1:
                affiche_recap_panier(tPanier, tLogPanier, tRef, tPoids, tVol, tPrixUnitaire, tQuantite, tCagnotte,
                                     numClient, tNumClient, tLogClient, volumeCoffre, chargeMaximale, budget);
                break;
            case 2:
                affichArticles(tRef, tPoids, tVol, tPrixUnitaire, tLogArticle);
                break;
            case 3:
                ajouter_article_au_panier(numClient, tRef, tPoids, tVol, tPrixUnitaire, tNumClient, tCagnotte,
                                          tSus, tLogArticle, tLogClient, volumeCoffre, chargeMaximale, tPanier, tQuantite, &tLogPanier, budget);
                break;
            case 4:
                supprimer_article_du_panier(tPanier, tQuantite, &tLogPanier, tCagnotte, numClient, tNumClient, tLogClient, tRef, tPrixUnitaire);
                affiche_recap_panier(tPanier, tLogPanier, tRef, tPoids, tVol, tPrixUnitaire, tQuantite, tCagnotte,
                                     numClient, tNumClient, tLogClient, volumeCoffre, chargeMaximale, budget);
                break;
            case 5:
                modifier_quantite_article_panier(tPanier, tQuantite, &tLogPanier, tCagnotte, numClient, tPrixUnitaire, tRef, tLogClient, tNumClient);
                break;
            case 6:
                reinitialiser_panier(tPanier, tQuantite, &tLogPanier, tCagnotte, numClient, tNumClient, tLogClient, tRef, tPrixUnitaire);
                printf("Le panier a été réinitialisé.\n");
                break;
            case 9:
                quitter_application(tPanier, tLogPanier, tRef, tPoids, tVol, tPrixUnitaire, tQuantite, tCagnotte, numClient, tNumClient, tLogClient, budget, tSus);
                sauvegarde_clients(tNumClient, tCagnotte, tSus, tLogClient);
                printf("Au revoir !\n");
                return;
        }
    } while (choix != 9);
}
