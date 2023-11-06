#include "client.h"

#define MAX_ARTICLES 100
#define MAX_CLIENTS 100

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

int trouver_index_article(int reference, int references[], int nombreArticles) {
    for (int i = 0; i < nombreArticles; i++) {
        if (references[i] == reference) {
            return i;
        }
    }
    return -1;
}

int trouver_index_client(int numeroClient, int numeros[], int nombreClients) {
    for (int i = 0; i < nombreClients; i++) {
        if (numeros[i] == numeroClient) {
            return i;
        }
    }
    return -1;
}

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