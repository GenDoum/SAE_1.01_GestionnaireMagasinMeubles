/**
 * @file client.c
 * @brief Fonctions liées à la gestion des clients et de leur panier.
 */

#include <stdio.h>
#include "client.h"

#define MAX_ARTICLES 100
#define MAX_CLIENTS 100

/**
 * @brief Charge les données des clients à partir d'un fichier.
 *
 * Cette fonction permet de charger les données des clients à partir d'un fichier.
 *
 * @param numeros - Tableau des numéros de clients.
 * @param cagnottes - Tableau des cagnottes des clients.
 * @param suspendues - Tableau des états de suspension des clients.
 * @param tPhysique - Taille du tableau physique.
 * @return Le nombre de clients chargés ou -1 en cas d'erreur.
 */
int charger_clients(int numeros[], float cagnottes[], int suspendues[], int tPhysique) {
    int i = 0, numero, suspendue;
    float cagnotte;
    FILE *fe;
    fe = fopen("donnee/client.txt", "r");
    if (fe == NULL) {
        perror("fopen");
        return -1;
    }
    while (fscanf(fe, "%d %f %d", &numero, &cagnotte, &suspendue) == 3) {
        if (i == tPhysique) {
            fprintf(stderr, "Tableau plein");
            break;
        }
        numeros[i] = numero;
        cagnottes[i] = cagnotte;
        suspendues[i] = suspendue;
        i++;
    }
    fclose(fe);
    return i;
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
 */
void ajouter_article_au_panier(int numeroClient, int references[], float poids[], float volume[], float prixUnitaire[],
                               int numeros[], float cagnottes[], int suspendues[], int nombreArticles, int nombreClients,
                               float volumeCoffre, float chargeMaximale, int panier[], int quantites[], int *taillePanier) {
    int reference, quantite;

    printf("Entrez la référence de l'article : ");
    while (scanf("%d", &reference) != 1) {
        while (getchar() != '\n');
        printf("ERREUR : Veuillez entrer une référence valide (nombre) : ");
    }
    while (getchar() != '\n');

    printf("Entrez la quantité : ");
    while (scanf("%d", &quantite) != 1) {
        while (getchar() != '\n');
        printf("ERREUR : Veurillez entrer une quantité valide (nombre) : ");
    }
    while (getchar() != '\n');

    int articleIndex = -1;
    for (int i = 0; i < nombreArticles; i++) {
        if (references[i] == reference) {
            articleIndex = i;
            break;
        }
    }

    if (articleIndex == -1) {
        printf("Article non trouvé. Veuillez entrer une référence valide.\n");
        return;
    }

    for (int i = 0; i < *taillePanier; i++) {
        if (panier[i] == reference) {
            printf("Cet article est déjà dans le panier.\n");
            return;
        }
    }

    float poidsTotal = poids[articleIndex] * quantite;
    float volumeTotal = volume[articleIndex] * quantite;

    if (poidsTotal > chargeMaximale) {
        printf("Désolé, dépassement de la charge autorisée.\n");
    } else if (volumeTotal > volumeCoffre) {
        printf("Désolé, dépassement du volume autorisé.\n");
    } else {
        float montantTotal = prixUnitaire[articleIndex] * quantite;

        int clientIndex = -1;
        for (int i = 0; i < nombreClients; i++) {
            if (numeros[i] == numeroClient) {
                clientIndex = i;
                break;
            }
        }

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
void supprimer_article_du_panier(int panier[], int quantites[], int *taillePanier) {
    int reference;
    printf("Entrez la référence de l'article à supprimer : ");
    while (scanf("%d", &reference) != 1) {
        while (getchar() != '\n');
        printf("ERREUR : Veuillez entrer une référence valide (nombre) : ");
    }
    while (getchar() != '\n');

    int articleIndex = -1;
    for (int i = 0; i < *taillePanier; i++) {
        if (panier[i] == reference) {
            articleIndex = i;
            break;
        }
    }

    if (articleIndex == -1) {
        printf("Article non trouvé dans le panier. Veuillez entrer une référence valide.\n");
        return;
    }

    for (int i = articleIndex; i < (*taillePanier - 1); i++) {
        panier[i] = panier[i + 1];
        quantites[i] = quantites[i + 1];
    }

    (*taillePanier)--;

    printf("Article supprimé du panier avec succès.\n");
}


/**
 * @brief Affiche un récapitulatif du contenu du panier.
 *
 * Cette fonction permet d'afficher un récapitulatif du contenu du panier.
 *
 * @param panier - Tableau des références des articles dans le panier.
 * @param taillePanier - Taille du panier.
 * @param references - Tableau des références des articles.
 * @param poids - Tableau des poids des articles.
 * @param volume - Tableau des volumes des articles.
 * @param prixUnitaire - Tableau des prix unitaires des articles.
 * @param quantites - Tableau des quantités de chaque article dans le panier.
 */
void affiche_recap_panier(int panier[], int taillePanier, int references[], float poids[], float volume[],
                          float prixUnitaire[], int quantites[]) {
    printf("Réf   Qté   Poids   Vol     PrixU   PoidsTot   VolTot   PrixTot\n");
    float poidsTotal = 0, volumeTotal = 0, montantTotal = 0;
    for (int i = 0; i < taillePanier; i++) {
        int reference = panier[i];
        int articleIndex = -1;
        for (int j = 0; j < MAX_ARTICLES; j++) {
            if (references[j] == reference) {
                articleIndex = j;
                break;
            }
        }

        if (articleIndex == -1) {
            printf("Article non trouvé. Veuillez entrer une référence valide.\n");
            return;
        }

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

    printf("Prix total à payer: %.2f euros\n", montantTotal);
    printf("Volume utilise : %.2f litres\n", volumeTotal);
    printf("Charge Actuelle: %.2f kg\n", poidsTotal);
}

/**
 * @brief Modifie la quantité d'un article dans le panier du client.
 *
 * Cette fonction permet de modifier la quantité d'un article dans le panier du client.
 *
 * @param panier - Tableau des références des articles dans le panier.
 * @param quantites - Tableau des quantités de chaque article dans le panier.
 * @param taillePanier - Taille du panier.
 */
void modifier_quantite_article_panier(int panier[], int quantites[], int *taillePanier) {
    int reference, quantite;

    printf("Entrez la référence de l'article : ");
    while (scanf("%d", &reference) != 1) {
        while (getchar() != '\n');
        printf("ERREUR : Veuillez entrer une référence valide (nombre) : ");
    }
    while (getchar() != '\n');

    int articleIndex = -1;
    for (int i = 0; i < *taillePanier; i++) {
        if (panier[i] == reference) {
            articleIndex = i;
            break;
        }
    }

    if (articleIndex == -1) {
        printf("Article non trouvé dans le panier. Veuillez entrer une référence valide.\n");
        return;
    }

    printf("Entrez la quantité : ");
    while (scanf("%d", &quantite) != 1) {
        while (getchar() != '\n');
        printf("ERREUR : Veuillez entrer une quantité valide (nombre) : ");
    }
    while (getchar() != '\n');

    quantites[articleIndex] = quantite;

    printf("Quantité modifiée avec succès.\n");
}

/**
 * @brief Réinitialise le panier du client.
 *
 * Cette fonction permet de réinitialiser le panier du client.
 *
 * @param panier - Tableau des références des articles dans le panier.
 * @param quantites - Tableau des quantités de chaque article dans le panier.
 * @param taillePanier - Taille du panier.
 */
void reinitialiser_panier(int panier[], int quantites[], int *taillePanier) {
    *taillePanier = 0;
    printf("Panier réinitialisé avec succès.\n");
}

/**
 * @brief Déduit un montant de la cagnotte du client.
 *
 * Cette fonction permet de déduire un montant de la cagnotte du client.
 *
 * @param numeroClient - Numéro du client.
 * @param montant - Montant à déduire de la cagnotte.
 * @param numeros - Tableau des numéros de clients.
 * @param cagnottes - Tableau des cagnottes des clients.
 * @param nombreClients - Nombre de clients.
 * @param suspendus - Tableau des états de suspension des clients.
 */
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

    FILE *fe;
    fe = fopen("donnee/client.txt", "w");
    if (fe == NULL) {
        perror("fopen");
        return;
    }
    for (int i = 0; i < nombreClients; i++) {
        fprintf(fe, "%d %.2f %d\n", numeros[i], cagnottes[i], suspendus[i]);
    }
    fclose(fe);
}