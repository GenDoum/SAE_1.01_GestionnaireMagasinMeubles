/**
* @file interface_resp.c
* @brief Implémentation des fonctions liées à l'interface du responsable.
*/

#include <stdio.h>
#include <stdlib.h>
#include "interface_resp.h"
#include "app/core_logic/responsable.h"
#include "app/core_logic/client.h"

#define MAX_CLIENTS 100
#define MAX_ARTICLES 100

/**
 * @brief Affiche le menu principal de l'interface du responsable.
 */
void affiche_resp(void) {
    printf("\n");
    printf("+-------------+\n");
    printf("|| Bonjour ! ||\n");
    printf("+-------------+\n");
    printf("\n");
    printf("+-----------------------------------------------------------------+\n");
    printf("|| Que voulez-vous faire ?\t\t\t\t\t\t\t||\n");
    printf("||\t1 : Afficher les articles\t\t\t\t\t\t||\n");
    printf("||\t2 : Afficher un article\t\t\t\t\t\t\t||\n");
    printf("||\t3 : Afficher un client\t\t\t\t\t\t\t||\n");
    printf("||\t4 : Afficher les clients\t\t\t\t\t\t||\n");
    printf("||\t5 : Ajouter un article\t\t\t\t\t\t\t||\n");
    printf("||\t6 : Supprimer un article\t\t\t\t\t\t||\n");
    printf("||\t7 : Modifier un article\t\t\t\t\t\t\t||\n");
    printf("||\t8 : Ajouter un client\t\t\t\t\t\t\t||\n");
    printf("||\t9 : Quittez.\t\t\t\t\t\t\t\t\t||\n");
    printf("+-----------------------------------------------------------------+\n");
}

/**
 * @brief Affiche la liste des articles.
 *
 * @param tRef - Tableau des références d'articles.
 * @param tPoids - Tableau des poids d'articles.
 * @param tVol - Tableau des volumes d'articles.
 * @param tPrix - Tableau des prix d'articles.
 * @param tLogique - Taille logique des tableaux.
 */
void affichArticles(int tRef[], float tPoids[], float tVol[], float tPrix[], int tLogique) {
    printf("\t Liste des articles\n\n");
    printf("\t Ref\t Poids\t Volume\t Prix\n");
    for (int i = 0; i < tLogique; ++i) {
        printf("\t %d\t  %.2f\t  %.2f\t  %.2f\n\n", tRef[i], tPoids[i], tVol[i], tPrix[i]);
    }
}

/**
 * @brief Affiche un article spécifique.
 *
 * @param tRef - Tableau des références d'articles.
 * @param tPoids - Tableau des poids d'articles.
 * @param tVol - Tableau des volumes d'articles.
 * @param tPrix - Tableau des prix d'articles.
 * @param tLogique - Taille logique des tableaux.
 */
void affichUnArticle(int tRef[], float tPoids[], float tVol[], float tPrix[], int tLogique) {
    int ref;
    printf("\tQuelle est la référence de l'article à rechercher ?\n");
    while (scanf("%d", &ref) != 1 || ref <= 0) {
        printf("\tEntrez une référence valide\n");
        while (getchar() != '\n');
    }
    printf("\t Ref\t Poids\t Volume\t Prix\n");
    for (int i = 0; i < tLogique; ++i) {
        if (ref == tRef[i]) {
            printf("\t %d\t %.2f\t %.2f\t  %.2f\n\n", tRef[i], tPoids[i], tVol[i], tPrix[i]);
            return;
        }
    }
    printf("\t Article introuvable\n");
}

/**
 * @brief Affiche un client spécifique.
 *
 * @param tNumClient - Tableau des numéros de client.
 * @param tCagnotte - Tableau des cagnottes des clients.
 * @param tSus - Tableau d'états des clients.
 * @param tLogique - Taille logique des tableaux.
 */
void affichUnClient(int tNumClient[], float tCagnotte[], int tSus[], int tLogique) {
    int numC;
    printf("\tVeuillez entrer le numéro du client à rechercher\n");
    while (scanf("%d", &numC) != 1 || numC <= 0) {
        printf("\t Veuillez entrez un numéro valide !\n");
        while (getchar() != '\n');
    }
    printf("\t NumClient\t Cagnotte\t Etat\n");
    for (int i = 0; i < tLogique; ++i) {
        if (numC == tNumClient[i]) {
            printf("\t %d\t\t %.2f\t %d\n\n", tNumClient[i], tCagnotte[i], tSus[i]);
            return;
        }
    }
    printf("Client introuvable\n");
}

/**
 * @brief Affiche la liste des clients.
 *
 * @param tNumClient - Tableau des numéros de client.
 * @param tCagnotte - Tableau des cagnottes des clients.
 * @param tSus - Tableau d'états des clients.
 * @param tLogique - Taille logique des tableaux.
 */
void affichClients(int tNumClient[], float tCagnotte[], int tSus[], int tLogique) {
    printf("\t Liste des clients\n");
    printf("\t NumClient\t Cagnotte\t Etat\n");
    for (int i = 0; i < tLogique; ++i) {
        printf("\t %d\t\t %.2f\t\t %d\n\n", tNumClient[i], tCagnotte[i], tSus[i]);
    }
    printf("\t Fin de la liste !\n");
}

/**
 * @brief Affiche les informations pour ajouter un nouvel article.
 *
 * @param[in, out] ref - Référence du nouvel article.
 * @param[in, out] poids - Poids du nouvel article.
 * @param[in, out] volume - Volume du nouvel article.
 * @param[in, out] prix - Prix du nouvel article.
 */
void affichAjoutArticle(int *ref, float *poids, float *volume, float *prix) {
    printf("\t Entrez la ref du nouveau produit\n");
    while (scanf("%d", ref) != 1 || *ref <= 0) {
        printf("\t Veuillez entrer une référence valide.\n");
        while (getchar() != '\n');
    }

    printf("\t Entrez le poids du nouveau produit\n");
    while (scanf("%f", poids) != 1 || *poids <= 0) {
        printf("\t Veuillez entrer un poids valide.\n");
        while (getchar() != '\n');
    }

    printf("\t Entrez le volume du nouveau produit\n");
    while (scanf("%f", volume) != 1 || *volume <= 0) {
        printf("\t Veuillez entrer un volume valide.\n");
        while (getchar() != '\n');
    }

    printf("\t Entrez le prix du nouveau produit\n");
    while (scanf("%f", prix) != 1 || *prix <= 0) {
        printf("\t Veuillez entrer un prix valide.\n");
        while (getchar() != '\n');
    }
}

/**
 * @brief Affiche les informations pour supprimer un article.
 *
 * @param[in, out] ref - Référence de l'article à supprimer.
 */
void affichSupprimerArticle(int *ref) {
    printf("\t Quelle est la référence de l'article que vous voulez supprimer ?\n");
    while (scanf("%d", ref) != 1 || *ref <= 0) {
        printf("\t Veuillez entrer une référence valide.\n");
        while (getchar() != '\n');
    }
}

/**
 * @brief Affiche les informations pour modifier un article.
 *
 * @param[in, out] ref - Référence de l'article à modifier.
 * @param[in, out] poids - Nouveau poids de l'article.
 * @param[in, out] volume - Nouveau volume de l'article.
 * @param[in, out] prix - Nouveau prix de l'article.
 */
void affichModifierArticle(int *ref, float *poids, float *volume, float *prix) {
    printf("\t Quelle est la référence de l'article que vous voulez modifier ?\n");
    while (scanf("%d", ref) != 1 || *ref <= 0) {
        printf("\t Veuillez entrer une référence correcte !\n");
        while (getchar() != '\n');
    }

    printf("\t Quel est le nouveau poids à entrer ?\n");
    while (scanf("%f", poids) != 1 || *poids <= 0) {
        printf("\t Veuillez entrer un poids correct !\n");
        while (getchar() != '\n');
    }

    printf("\t Quel est le nouveau volume à entrer ?\n");
    while (scanf("%f", volume) != 1 || *volume <= 0) {
        printf("\t Veuillez entrer un volume correct !\n");
        while (getchar() != '\n');
    }

    printf("\t Quel est le nouveau prix à entrer ?\n");
    while (scanf("%f", prix) != 1 || *prix <= 0) {
        printf("\t Veuillez entrer un prix correct !\n");
        while (getchar() != '\n');
    }
}

/**
 * @brief Affiche les informations pour ajouter un nouveau client.
 *
 * @param[in] tNumClient - Tableau des numéros de client.
 * @param[in] tLogique - Taille logique des tableaux.
 * @param[in, out] numC - Numéro du nouveau client.
 */
void affichAjoutClient(int tNumClient[], int tLogique, int *numC) {
    printf("\t Veuillez entrer le numéro du nouveau client\n");
    while (scanf("%d", numC) != 1 || *numC <= 0) {
        printf("Entrez un numéro valide !\n");
        while (getchar() != '\n');
    }
    for (int i = 0; i < tLogique; ++i) {
        if (*numC == tNumClient[i]) {
            fprintf(stderr, "\t Client déjà existant.\n");
            return;
        }
    }
}

/**
 * @brief Fonction de menu pour le responsable.
 *
 * @param[in, out] choix - L'option choisie par le responsable.
 */
void menu_resp(int *choix) {
    affiche_resp();
    printf("Vous choisissez: ");
    while (scanf("%d", choix) != 1 || *choix < 0 || *choix > 9) {
        while (getchar() != '\n');
        affiche_resp();
        printf("Veuillez entrer un choix valide : ");
    }
}

/**
 * @brief Fonction principale de l'interface du responsable.
 */
void global_resp() {
    int choix, ref = 0;
    float poids = 0, volume = 0, prix = 0;
    int tRef[MAX_ARTICLES];
    float tPoids[MAX_ARTICLES];
    float tVol[MAX_ARTICLES];
    float tPrix[MAX_ARTICLES];
    int tNumClient[MAX_CLIENTS];
    float tCagnotte[MAX_CLIENTS];
    int tSus[MAX_CLIENTS];

    int tLogArticle = chargementArticles(tRef, tPoids, tVol, tPrix, MAX_ARTICLES);
    int tLogClient = charger_clients(tNumClient, tCagnotte, tSus, MAX_CLIENTS);

    do {
        menu_resp(&choix);
        switch (choix) {
            case 1:
                affichArticles(tRef, tPoids, tVol, tPrix, tLogArticle);
                break;
            case 2:
                affichUnArticle(tRef, tPoids, tVol, tPrix, tLogArticle);
                break;
            case 3:
                affichUnClient(tNumClient, tCagnotte, tSus, tLogClient);
                break;
            case 4:
                affichClients(tNumClient, tCagnotte, tSus, tLogClient);
                break;
            case 5:
                ajouterArticle(tRef, tPoids, tVol, tPrix, &tLogArticle, MAX_ARTICLES, ref, poids, volume, prix);
                break;
            case 6:
                supprimerArticle(tRef, tPoids, tVol, tPrix, &tLogArticle);
                break;
            case 7:
                modifierArticle(tRef, tPoids, tVol, tPrix, tLogArticle);
                break;
            case 8:
                ajouterClient(tNumClient, tCagnotte, tSus, &tLogClient, MAX_CLIENTS);
                break;
            case 9:
                sauvegardArticles(tRef, tPoids, tVol, tPrix, tLogArticle);
                printf("Sauvegarde des articles effectuée.\n");
                printf("Au revoir !\n");
                return;
            default:
                printf("Veuillez entrer un choix valide ! \n");
                break;
        }
    } while (choix != 9);
    
}