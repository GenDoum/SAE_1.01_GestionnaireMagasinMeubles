/**
 * @file interface_client.c
 * @brief Implémentation des fonctions liées à l'interface client.
 */

#include "interface_client.h"
#define MAX_ARTICLES 100
#define MAX_CLIENTS 100

/**
 * @brief Affiche le menu principal de l'interface client.
 */
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

/**
 * @brief Laisse l'utilisateur choisir une option du menu.
 *
 * @param[in, out] choix - L'option choisie par l'utilisateur.
 */
void menu_client(int *choix) {
    affiche_client();
    printf("Vous choisissez: ");
    while (scanf("%d", choix) != 1 || *choix < 0 || *choix > 9) {
        while (getchar() != '\n');
        printf("ERREUR : Veuillez entrer un choix valide : ");
    }
}

/**
 * @brief Ajoute un article au panier du client.
 *
 * Cette fonction permet d'ajouter un article au panier du client.
 *
 * @param numeroClient - Numéro du client.
 * @param references - Tableau des références des articles.
 * @param poids - Tableau des poids des articles.
 * @param volume - Tableau des volumes des articles.
 * @param prixUnitaire - Tableau des prix unitaires des articles.
 * @param numeros - Tableau des numéros de clients.
 * @param cagnottes - Tableau des cagnottes des clients.
 * @param suspendues - Tableau des états de suspension des clients.
 * @param nombreArticles - Nombre d'articles disponibles.
 * @param nombreClients - Nombre de clients.
 * @param volumeCoffre - Volume total du coffre.
 * @param chargeMaximale - Charge maximale du coffre.
 * @param panier - Tableau des références des articles dans le panier.
 * @param quantites - Tableau des quantités de chaque article dans le panier.
 * @param taillePanier - Taille du panier.
 * @param budget - Budget du client.
 */
void ajouter_article_au_panier(int numeroClient, int references[], float poids[], float volume[], float prixUnitaire[],
                               int numeros[], float cagnottes[], int suspendues[], int nombreArticles, int nombreClients,
                               float volumeCoffre, float chargeMaximale, int panier[], int quantites[], int *taillePanier, float budget) {

    int reference, quantite, articleIndex;
    float poidsTotal, montantTotal, volumeTotal, depassementCharge = 0, depassementVolume, depassementBudget = 0;

    while (1) {
        printf("Entrez la référence de l'article : ");
        while (scanf("%d", &reference) != 1) {
            while (getchar() != '\n');
            printf("ERREUR : Veuillez entrer une référence valide (nombre) : ");
        }
        while (getchar() != '\n');

        articleIndex = trouver_index_article(reference, references, nombreArticles);

        if (articleIndex == -1) {
            printf("ERREUR : Article non trouvé. Veuillez entrer une référence valide.\n");
        } else {
            break;
        }
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
    } else {
        float montantTotal = prixUnitaire[articleIndex] * quantite;

        int clientIndex = trouver_index_client(numeroClient, numeros, nombreClients);

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
}


/**
 * @brief Supprime un article du panier du client.
 *
 * Cette fonction permet de supprimer un article du panier du client.
 *
 * @param panier - Tableau des références des articles dans le panier.
 * @param quantites - Tableau des quantités de chaque article dans le panier.
 * @param taillePanier - Taille du panier.
 */
void supprimer_article_du_panier(int panier[], int quantites[], int *taillePanier, float cagnottes[], int numeroClient, int numeros[], int nombreClients, int references[], float prixUnitaire[]) {
    int reference;
    printf("Entrez la référence de l'article à supprimer : ");
    while (scanf("%d", &reference) != 1) {
        while (getchar() != '\n');
        printf("ERREUR : Veuillez entrer une référence valide (nombre) : ");
    }
    while (getchar() != '\n');

    int articleIndex = trouver_index_article(reference, references, MAX_ARTICLES);

    if (articleIndex == -1) {
        printf("Article non trouvé dans le panier. Veuillez entrer une référence valide.\n");
        return;
    }

    supprimer_article(panier, quantites, taillePanier, reference, numeroClient, numeros, nombreClients, references, prixUnitaire, cagnottes);


    printf("Article supprimé du panier avec succès.\n");
}


/**
 * @brief Affiche un récapitulatif du contenu du panier.
 *
 * Cette fonction permet d'afficher un récapitulatif détaillé du contenu du panier du client, y compris les références des articles,
 * les quantités, les poids, les volumes, les prix unitaires, les totaux de poids, de volume, de prix, et la cagnotte du client.
 *
 * @param panier - Tableau des références des articles dans le panier.
 * @param taillePanier - Taille du panier.
 * @param references - Tableau des références des articles.
 * @param poids - Tableau des poids des articles.
 * @param volume - Tableau des volumes des articles.
 * @param prixUnitaire - Tableau des prix unitaires des articles.
 * @param quantites - Tableau des quantités de chaque article dans le panier.
 * @param cagnottes - Tableau des cagnottes des clients.
 * @param numeroClient - Numéro du client.
 * @param numeros - Tableau des numéros de clients.
 * @param nombreClients - Nombre de clients.
 * @param volumeCoffre - Volume total du coffre.
 * @param chargeMaximale - Charge maximale du coffre.
 */
void affiche_recap_panier(int panier[], int taillePanier, int references[], float poids[], float volume[],
                          float prixUnitaire[], int quantites[], float cagnottes[], int numeroClient,
                          int numeros[], int nombreClients, float volumeCoffre, float chargeMaximale) {
    printf("Contenu du panier : ");
    for (int i = 0; i < taillePanier; i++) {
        printf("%d ", panier[i]);
    }
    printf("\n");

    printf("Récap :\n");
    printf("Réf   Qté   Poids   Vol     PrixU   PoidsTot   VolTot   PrixTot\n");

    float poidsTotal = 0, volumeTotal = 0, montantTotal = 0;

    for (int i = 0; i < taillePanier; i++) {
        int reference = panier[i];
        int articleIndex = trouver_index_article(reference, references, MAX_ARTICLES);

        float poidsArticle = poids[articleIndex];
        float volumeArticle = volume[articleIndex];
        float prixArticle = prixUnitaire[articleIndex];
        int quantite = quantites[i];

        printf("%d\t %d\t %.2f\t %.2f\t %.2f\t %.2f\t %.2f\t %.2f\n",
               reference, quantite, poidsArticle, volumeArticle,
               prixArticle, poidsArticle * quantite, volumeArticle * quantite, prixArticle * quantite);

        poidsTotal += poidsArticle * quantite;
        volumeTotal += volumeArticle * quantite;
        montantTotal += prixArticle * quantite;
    }

    int clientIndex = trouver_index_client(numeroClient, numeros, nombreClients);

    printf("Prix total à payer: %.2f euros\n", montantTotal);
    printf("Cagnotte totale : %.2f euros\n", cagnottes[clientIndex]);
    printf("Volume utilise : %.2f litres\n", volumeTotal);
    printf("Volume restant : %.2f litres\n", volumeCoffre - volumeTotal);
    printf("Charge Actuelle: %.2f kg\n", poidsTotal);
    printf("Charge restante: %.2f kg\n", chargeMaximale - poidsTotal);
}

/**
 * @brief Affiche le récapitulatif du panier.
 *
 * Cette fonction affiche le récapitulatif du panier, y compris les références, les poids, les volumes, les prix unitaires, elle permet d'initialiser la session du client.
 *
 * @param numeros
 * @param suspendus
 * @param nombreClients
 * @param budget
 * @param volumeCoffre
 * @param chargeMaximale
 * @param numeroClient
 */
void configurer_session_client(int numeros[], int suspendus[], int nombreClients, float *budget, float *volumeCoffre, float *chargeMaximale, int *numeroClient) {
    printf("Veuillez saisir votre numéro de client : ");
    while (scanf("%d", numeroClient) != 1) {
        while (getchar() != '\n');
        printf("ERREUR : Veuillez entrer un numéro de client valide : ");
    }

    int indexClient = trouver_index_client(*numeroClient, numeros, nombreClients);

    if (indexClient == -1) {
        printf("Client non trouvé. Impossible d'utiliser l'application.\n");
        return;
    }

    if (suspendus[indexClient] == 1) {
        printf("Le client est suspendu et ne peut pas utiliser l'application.\n");
        return;
    }

    printf("Voulez-vous définir un budget à ne pas dépasser ? (1 pour Oui, 0 pour Non) : ");
    int choixBudget;
    scanf("%d", &choixBudget);

    if (choixBudget == 1) {
        printf("Entrez le budget à ne pas dépasser : ");
        while (scanf("%f", budget) != 1 || *budget <= 0) {
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


/**
 * @brief Fonction principale de l'interface client.
 *
 * Cette fonction permet aux clients d'utiliser l'application pour gérer leur panier
 * et effectuer des opérations telles que l'ajout, la suppression ou la modification
 * d'articles dans le panier.
 */
void global_client() {
    int choix;
    int references[MAX_ARTICLES];
    float poids[MAX_ARTICLES];
    float volume[MAX_ARTICLES];
    float prixUnitaire[MAX_ARTICLES];
    int numeros[MAX_CLIENTS];
    float cagnottes[MAX_CLIENTS];
    int suspendus[MAX_CLIENTS];
    int nombreArticles, nombreClients;
    float volumeCoffre, chargeMaximale;
    int numeroClient;
    int quantites[MAX_ARTICLES];
    int panier[MAX_ARTICLES];
    int taillePanier = 0;
    float budget = -1.0;

    nombreArticles = chargementArticles(references, poids, volume, prixUnitaire, MAX_ARTICLES);
    nombreClients = charger_clients(numeros, cagnottes, suspendus, MAX_CLIENTS);
    configurer_session_client(numeros, suspendus, nombreClients, &budget, &volumeCoffre, &chargeMaximale, &numeroClient);

    do {
        menu_client(&choix);

        switch (choix) {
            case 1:
                affiche_recap_panier(panier, taillePanier, references, poids, volume, prixUnitaire, quantites, cagnottes,
                                     numeroClient, numeros, nombreClients, volumeCoffre, chargeMaximale);
                break;
            case 2:
                ajouter_article_au_panier(numeroClient, references, poids, volume, prixUnitaire, numeros, cagnottes,
                                          suspendus, nombreArticles, nombreClients, volumeCoffre, chargeMaximale, panier, quantites, &taillePanier, budget);
                break;
            case 3:
                supprimer_article_du_panier(panier, quantites, &taillePanier, cagnottes, numeroClient, numeros, nombreClients, references, prixUnitaire);
                break;
            case 4:
                modifier_quantite_article_panier(panier, quantites, &taillePanier);
                break;
            case 5:
                reinitialiser_panier(panier, quantites, &taillePanier, cagnottes, numeroClient, numeros, nombreClients, references, prixUnitaire);
                printf("Le panier a été réinitialisé.\n");
                break;
            case 9:
                printf("Voulez-vous déduire de votre cagnotte avant de quitter ? (1 pour Oui, 0 pour Non) : ");
                int choixCagnotte;
                scanf("%d", &choixCagnotte);
                if (choixCagnotte == 1) {
                    float montant;
                    printf("Entrez le montant à déduire de votre cagnotte : ");
                    scanf("%f", &montant);

                    deduire_cagnotte(numeroClient, montant, numeros, cagnottes, nombreClients, suspendus);

                    printf("Le montant a été déduit de votre cagnotte.\n");
                }

                sauvegarde_clients(numeros, cagnottes, suspendus, nombreClients);
                printf("Au revoir !\n");
                return;
            default:
                printf("Veuillez entrer un choix valide !\n");
                break;
        }
    } while (choix != 9);
}
