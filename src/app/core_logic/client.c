/**
 * @file client.c
 * @brief Fonctions liées à la gestion des clients et de leur panier.
 */

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
 * @brief Sauvegarde les données clients dans un fichier.
 *
 * Cette fonction permet de sauvegarder les données clients, y compris les numéros de clients, les cagnottes,
 * et les états de suspension, dans un fichier texte.
 *
 * @param numeros - Tableau des numéros de clients.
 * @param cagnottes - Tableau des cagnottes des clients.
 * @param suspendus - Tableau des états de suspension des clients.
 * @param nombreClients - Nombre de clients.
 */
void sauvegarde_clients(int numeros[], float cagnottes[], int suspendus[], int nombreClients) {
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

/**
 * @brief Recherche l'index de l'article dans le tableau des références.
 *
 * Cette fonction recherche l'index de l'article avec la référence donnée dans le tableau des références.
 *
 * @param reference - Référence de l'article à rechercher.
 * @param references - Tableau des références des articles.
 * @param nombreArticles - Nombre d'articles disponibles.
 * @return L'index de l'article s'il est trouvé, sinon -1.
 */
int trouver_index_article(int reference, int references[], int nombreArticles) {
    for (int i = 0; i < nombreArticles; i++) {
        if (references[i] == reference) {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Trouve l'index d'un client dans le tableau des numéros de clients.
 *
 * Cette fonction recherche le numéro du client dans le tableau des numéros de clients
 * et retourne l'index du client s'il est trouvé.
 *
 * @param numeroClient - Numéro du client à rechercher.
 * @param numeros - Tableau des numéros de clients.
 * @param nombreClients - Nombre de clients dans le tableau.
 * @return L'index du client s'il est trouvé, -1 sinon.
 */
int trouver_index_client(int numeroClient, int numeros[], int nombreClients) {
    for (int i = 0; i < nombreClients; i++) {
        if (numeros[i] == numeroClient) {
            return i;  // Retourne l'index du client si trouvé
        }
    }
    return -1;  // Retourne -1 si le client n'est pas trouvé
}

/**
 * @brief Supprime un article du panier du client.
 *
 * Cette fonction permet de supprimer un article du panier du client tout en metant a jour la cagnotte.
 *
 * @param panier
 * @param quantites
 * @param taillePanier
 * @param reference
 * @param numeroClient
 * @param numeros
 * @param nombreClients
 * @param references
 * @param prixUnitaire
 * @param cagnottes
 */
void supprimer_article(int panier[], int quantites[], int *taillePanier, int reference, int numeroClient, int numeros[], int nombreClients, int references[], float prixUnitaire[], float cagnottes[]) {
    int articleIndex, clientIndex, quantite = 0;
    articleIndex = trouver_index_article(reference, references, MAX_ARTICLES);
    for (int i = 0; i < *taillePanier; i++) {
        if (panier[i] == reference) {
            quantite = quantites[i];
            for (int j = i; j < *taillePanier - 1; j++) {
                panier[j] = panier[j + 1];
                quantites[j] = quantites[j + 1];
            }
            break;
        }
    }

    (*taillePanier)--;

    clientIndex = trouver_index_client(numeroClient, numeros, nombreClients);

    if (clientIndex != -1) {
        float montantTotal = prixUnitaire[articleIndex] * quantite;
        cagnottes[clientIndex] -= 0.1 * montantTotal;
    }

}
