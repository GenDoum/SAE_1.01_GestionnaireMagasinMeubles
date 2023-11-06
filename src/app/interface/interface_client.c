#include "interface_client.h"
#define MAX_ARTICLES 100
#define MAX_CLIENTS 100

void affiche_client() {
    printf("\n");
    printf("+-------------+\n");
    printf("|| Bonjour ! ||\n");
    printf("+-------------+\n");
    printf("\n");
    printf("+----------------------------------------------------------------+\n");
    printf("|| Que voulez-vous faire ?\t\t\t\t\t||\n");
    printf("||\t1 : Afficher le récapitulatif du panier.\t \t||\n");
    printf("||\t2 : Ajouter un article au panier.   \t\t\t||\n");
    printf("||\t3 : Supprimer un article du panier. \t\t\t||\n");
    printf("||\t4 : Modifier la quantité d'un article du panier. \t||\n");
    printf("||\t5 : Réinitialiser le panier.\t\t\t\t||\n");
    printf("||\t9 : Quitter.\t\t\t\t\t\t||\n");
    printf("+----------------------------------------------------------------+\n");
}


void ajouter_article_au_panier(int numeroClient, int references[], float poids[], float volume[], float prixUnitaire[],
                               int numeros[], float cagnottes[], int suspendues[], int nombreArticles, int nombreClients,
                               float volumeCoffre, float chargeMaximale, int panier[], int quantites[], int *taillePanier, float budget) {

    int reference, quantite, articleIndex, clientIndex;
    float poidsTotal, montantTotal, volumeTotal, depassementCharge = 0, depassementVolume, depassementBudget = 0;


    printf("Entrez la référence de l'article : ");
    while (scanf("%d", &reference) != 1) {
        while (getchar() != '\n');
        printf("ERREUR : Veuillez entrer une référence valide (nombre) : ");
    }
    while (getchar() != '\n');

    articleIndex = trouver_index_article(reference, references, nombreArticles);

    while (articleIndex == -1) {
        printf("ERREUR : Article non trouvé. Veuillez entrer une référence valide : ");
        while(scanf("%d", &reference) != 1) {
            while (getchar() != '\n');
            printf("ERREUR : Veuillez entrer une référence valide (nombre) : ");
        }
        articleIndex = trouver_index_article(reference, references, nombreArticles);
    }

    printf("Entrez la quantité : ");
    while (scanf("%d", &quantite) != 1) {
        while (getchar() != '\n');
        printf("ERREUR : Veuillez entrer une quantité valide (nombre) : ");
    }
    while (getchar() != '\n');

    poidsTotal = poids[articleIndex] * quantite;
    volumeTotal = volume[articleIndex] * quantite;
    montantTotal = prixUnitaire[articleIndex] * quantite;

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

    montantTotal = prixUnitaire[articleIndex] * quantite;

    clientIndex = trouver_index_client(numeroClient, numeros, nombreClients);

    if (clientIndex != -1) {
        cagnottes[clientIndex] += 0.1 * montantTotal;
    }

    panier[*taillePanier] = reference;
    quantites[*taillePanier] = quantite;
    (*taillePanier)++;

    printf("Contenu du panier : ");
    for (int i = 0; i < *taillePanier; i++) {
        printf("%d ", panier[i]);
    }
    printf("\n");

    printf("Référence : %d\nQuantité : %d\n", reference, quantite);
    printf("Récap :\n");
    printf("Réf   Qté   Poids   Vol     PrixU   PoidsTot   VolTot   PrixTot   Cagnotte\n");
    printf("%d   %d     %.2f        %.2f      %.2f     %.2f           %.2f      %.2f      %.2f\n",
           reference, quantite, poids[articleIndex], volume[articleIndex],
           prixUnitaire[articleIndex], poidsTotal, volumeTotal, montantTotal,
           cagnottes[clientIndex]);
    printf("Prix total à payer: %.2f euros\n", montantTotal);
    printf("Cagnotte totale : %.2f euros\n", cagnottes[clientIndex]);
    printf("Volume utilise : %.2f litres\n", volumeTotal);
    printf("Volume restant : %.2f litres\n", volumeCoffre - volumeTotal);
    printf("Charge Actuelle: %.2f kg\n", poidsTotal);
    printf("Charge restante: %.2f kg\n", chargeMaximale - poidsTotal);

}


void supprimer_article_du_panier(int panier[], int quantites[], int *taillePanier, float cagnottes[], int numeroClient, int numeros[], int nombreClients, int references[], float prixUnitaire[]) {
    int reference, articleIndex;
    printf("Entrez la référence de l'article à supprimer : ");
    while (scanf("%d", &reference) != 1) {
        while (getchar() != '\n');
        printf("ERREUR : Veuillez entrer une référence valide (nombre) : ");
    }
    while (getchar() != '\n');

    articleIndex = trouver_index_article(reference, references, MAX_ARTICLES);

    while (articleIndex == -1) {
        printf("Article non trouvé dans le panier. Veuillez entrer une référence valide : ");
        while(scanf("%d", &reference) != 1) {
            while (getchar() != '\n');
            printf("ERREUR : Veuillez entrer une référence valide (nombre) : ");
        }
        articleIndex = trouver_index_article(reference, references, MAX_ARTICLES);
    }

    supprimer_article(panier, quantites, taillePanier, reference, numeroClient, numeros, nombreClients, references, prixUnitaire, cagnottes);


    printf("Article supprimé du panier avec succès.\n");
}


void affiche_recap_panier(int panier[], int taillePanier, int references[], float poids[], float volume[],
                          float prixUnitaire[], int quantites[], float cagnottes[], int numeroClient,
                          int numeros[], int nombreClients, float volumeCoffre, float chargeMaximale, float budget) {

    int reference, articleIndex, quantite, clientIndex;
    float poidsTotal = 0, volumeTotal = 0, montantTotal = 0, prixArticle = 0, poidsArticle = 0, volumeArticle = 0;
    char attentionDepassement[200] = "";

    printf("Contenu du panier : ");
    for (int i = 0; i < taillePanier; i++) {
        printf("%d ", panier[i]);
    }
    printf("\n");

    printf("Récap :\n");
    printf("Réf   Qté   Poids   Vol     PrixU   PoidsTot   VolTot   PrixTot\n");

    for (int i = 0; i < taillePanier; i++) {
        reference = panier[i];
        articleIndex = trouver_index_article(reference, references, MAX_ARTICLES);

        poidsArticle = poids[articleIndex];
        volumeArticle = volume[articleIndex];
        prixArticle = prixUnitaire[articleIndex];
        quantite = quantites[i];

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

    clientIndex = trouver_index_client(numeroClient, numeros, nombreClients);

    printf("Prix total à payer: %.2f euros\n", montantTotal);
    printf("Cagnotte totale : %.2f euros\n", cagnottes[clientIndex]);
    printf("Volume utilise : %.2f litres\n", volumeTotal);
    printf("Charge Actuelle: %.2f kg\n", poidsTotal);

    if (strlen(attentionDepassement) > 0) {
        printf("Attention : %s", attentionDepassement);
    }
}

void configurer_session_client(int numeros[], int suspendus[], int nombreClients, double *budget, float *volumeCoffre, float *chargeMaximale, int *numeroClient) {
    int indexClient, choixBudget = 0;

    printf("Veuillez saisir votre numéro de client : ");
    while (scanf("%d", numeroClient) != 1) {
        while (getchar() != '\n');
        printf("ERREUR : Veuillez entrer un numéro de client valide : ");
    }

    indexClient = trouver_index_client(*numeroClient, numeros, nombreClients);

    while (indexClient == -1) {
        printf("ERREUR : Veuillez entrer un numéro de client valide : ");
        while (scanf("%d", numeroClient) != 1) {
            while (getchar() != '\n');
            printf("ERREUR : Veuillez entrer un numéro de client valide : ");
        }
        indexClient = trouver_index_client(*numeroClient, numeros, nombreClients);
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

void modifier_quantite_article_panier(int panier[], int quantites[], int *taillePanier, float cagnottes[], int numeroClient, float prixUnitaire[], int references[], int nombreClients, int numeros[]) {

    int reference, quantite, articleIndex, clientIndex;
    float prixArticle = 0, ancienneQuantite = 0;

    printf("Entrez la référence de l'article : ");
    while (scanf("%d", &reference) != 1) {
        while (getchar() != '\n');
        printf("ERREUR : Veuillez entrer une référence valide (nombre) : ");
    }
    while (getchar() != '\n');

    articleIndex = trouver_index_article(reference, panier, *taillePanier);

    while (articleIndex == -1) {
        printf("Article non trouvé dans le panier. Veuillez entrer une référence valide.");
        while (scanf("%d", &reference) != 1) {
            while (getchar() != '\n');
            printf("ERREUR : Veuillez entrer une référence valide (nombre) : ");
        }

        articleIndex = trouver_index_article(reference, panier, *taillePanier);
    }

    printf("Entrez la quantité : ");
    while (scanf("%d", &quantite) != 1) {
        while (getchar() != '\n');
        printf("ERREUR : Veuillez entrer une quantité valide (nombre) : ");
    }
    while (getchar() != '\n');

    // Mettre à jour la cagnotte en fonction du changement de quantité
    prixArticle = prixUnitaire[trouver_index_article(reference, references, MAX_ARTICLES)];
    clientIndex = trouver_index_client(numeroClient, numeros, nombreClients);
    ancienneQuantite = quantites[articleIndex];
    cagnottes[clientIndex] -= (ancienneQuantite - quantite) * prixArticle * 0.1;

    quantites[articleIndex] = quantite;

    printf("Quantité modifiée avec succès.\n");
}

void reinitialiser_panier(int panier[], int quantites[], int *taillePanier, float cagnottes[], int numeroClient, int numeros[], int nombreClients, int references[], float prixUnitaire[]) {
    for (int i = 0; i < *taillePanier; i++) {
        supprimer_article(panier, quantites, taillePanier, panier[i], numeroClient, numeros, nombreClients, references, prixUnitaire, cagnottes);
    }
    *taillePanier = 0;
}

void deduire_cagnotte(int numeroClient, float montant, int numeros[], float cagnottes[], int nombreClients, int suspendus[]) {
    int clientIndex = -1;
    for (int i = 0; i < nombreClients; i++) {
        if (numeros[i] == numeroClient) {
            clientIndex = i;
            break;
        }
    }

    if (clientIndex == -1) {
        printf("Client non trouvé. Impossible de déduire la cagnotte.\n");
        return;
    }

    if (cagnottes[clientIndex] < montant) {
        printf("Cagnotte insuffisante. Impossible de déduire la cagnotte.\n");
        return;
    }

    cagnottes[clientIndex] -= montant;

    printf("Montant déduit de la cagnotte avec succès.\n");
}

void quitter_application(int panier[], int taillePanier, int references[], float poids[], float volume[],
                        float prixUnitaire[], int quantites[], float cagnottes[], int numeroClient,
                        int numeros[], int nombreClients, float budget, int suspendus[]) {

    int reference, articleIndex, quantite, clientIndex, choixCagnotte = 0;
    float montantTotal = 0, prixArticle = 0, montantDeduction = 0;
    char attentionDepassement[200] = "";

    for (int i = 0; i < taillePanier; i++) {
        reference = panier[i];
        articleIndex = trouver_index_article(reference, references, MAX_ARTICLES);

        prixArticle = prixUnitaire[articleIndex];
        quantite = quantites[i];

        montantTotal += prixArticle * quantite;

        if (budget > 0 && montantTotal > budget) {
            float depassement = montantTotal - budget;
            char message[100];
            sprintf(message, "Dépassement du budget autorisé de %.2f euros.\n", depassement);
            strcat(attentionDepassement, message);
        }
    }

    clientIndex = trouver_index_client(numeroClient, numeros, nombreClients);

    if (suspendus[clientIndex] == 1) {
        printf("Vous ne pourrez pas utiliser votre cagnotte car votre carte est suspendu.\n");
    }


    printf("Prix total à payer: %.2f euros\n", montantTotal);
    if (budget > 0) {
        printf("Budget : %.2f euros\n", budget);
    }

    if (budget > 0 && montantTotal > budget && cagnottes[clientIndex] < (montantTotal - budget)) {
        printf("Attention : %s", attentionDepassement);
        printf("Vous ne pourrez pas payer. De plus vous n'avez pas assez dans votre cagnotte pour la déduire et payer\n");
        printf("Montant de votre cagnotte %.2f\n", cagnottes[clientIndex]);
    }

    if (budget > 0 && montantTotal > budget && montantTotal < budget + cagnottes[clientIndex]) {
        printf("Attention : %s", attentionDepassement);
        printf("Vous ne pourrez pas payer, mais vous avez suffisamment dans votre cagnotte pour payer.\n");
        printf("Montant de votre cagnotte %.2f\n", cagnottes[clientIndex]);
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

            deduire_cagnotte(numeroClient, montantDeduction, numeros, cagnottes, nombreClients, suspendus);
            printf("Le montant a été déduit de votre cagnotte.\n");
            printf("Il vous reste %.2f euros dans votre cagnotte.\n", cagnottes[clientIndex]);
        }
    }
}

void menu_client(int *choix) {
    affiche_client();
    printf("Vous choisissez: ");
    while (scanf("%d", choix) != 1 || *choix < 0 || *choix > 9 || (*choix > 5 && *choix < 9)) {
        while (getchar() != '\n');
        printf("ERREUR : Veuillez entrer un choix valide : ");
    }
}

void global_client() {
    int choix, references[MAX_ARTICLES], numeros[MAX_CLIENTS], suspendus[MAX_CLIENTS], nombreArticles,
        nombreClients, numeroClient, quantites[MAX_ARTICLES], panier[MAX_ARTICLES], taillePanier = 0;

    float poids[MAX_ARTICLES], volume[MAX_ARTICLES], prixUnitaire[MAX_ARTICLES], cagnottes[MAX_CLIENTS],
          volumeCoffre, chargeMaximale;

    double budget = -1.0;

    nombreArticles = chargementArticles(references, poids, volume, prixUnitaire, MAX_ARTICLES);
    nombreClients = charger_clients(numeros, cagnottes, suspendus, MAX_CLIENTS);
    configurer_session_client(numeros, suspendus, nombreClients, &budget, &volumeCoffre, &chargeMaximale, &numeroClient);

    do {
        menu_client(&choix);

        switch (choix) {
            case 1:
                affiche_recap_panier(panier, taillePanier, references, poids, volume, prixUnitaire, quantites, cagnottes,
                                     numeroClient, numeros, nombreClients, volumeCoffre, chargeMaximale, budget);
                break;
            case 2:
                ajouter_article_au_panier(numeroClient, references, poids, volume, prixUnitaire, numeros, cagnottes,
                                          suspendus, nombreArticles, nombreClients, volumeCoffre, chargeMaximale, panier, quantites, &taillePanier, budget);
                break;
            case 3:
                supprimer_article_du_panier(panier, quantites, &taillePanier, cagnottes, numeroClient, numeros, nombreClients, references, prixUnitaire);
                break;
            case 4:
                modifier_quantite_article_panier(panier, quantites, &taillePanier, cagnottes, numeroClient, prixUnitaire, references, nombreClients, numeros);
                break;
            case 5:
                reinitialiser_panier(panier, quantites, &taillePanier, cagnottes, numeroClient, numeros, nombreClients, references, prixUnitaire);
                printf("Le panier a été réinitialisé.\n");
                break;
            case 9:
                quitter_application(panier, taillePanier, references, poids, volume, prixUnitaire, quantites, cagnottes, numeroClient, numeros, nombreClients, budget, suspendus);
                sauvegarde_clients(numeros, cagnottes, suspendus, nombreClients);
                printf("Au revoir !\n");
                return;
        }
    } while (choix != 9);
}
