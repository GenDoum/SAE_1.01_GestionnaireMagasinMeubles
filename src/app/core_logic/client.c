#include "client.h"

#define MAX_ARTICLES 100
#define MAX_CLIENTS 100

int charger_clients(int tNumCLient[], float tCagnotte[], int tSus[], int tPhysique) {
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
        tNumCLient[i] = numero;
        tCagnotte[i] = cagnotte;
        tSus[i] = suspendue;
        i++;
    }
    fclose(fe);
    return i;
}

void sauvegarde_clients(int tNumClient[], float tCagnotte[], int tSus[], int tLogClient) {
    FILE *fe;
    fe = fopen("donnee/client.txt", "w");
    if (fe == NULL) {
        perror("fopen");
        return;
    }
    for (int i = 0; i < tLogClient; i++) {
        fprintf(fe, "%d %.2f %d\n", tNumClient[i], tCagnotte[i], tSus[i]);
    }
    fclose(fe);
}

int trouver_index_article(int reference, int tRef[], int tLogArticle) {
    for (int i = 0; i < tLogArticle; i++) {
        if (tRef[i] == reference) {
            return i;
        }
    }
    return -1;
}

int trouver_index_client(int numClient, int tNumClient[], int tLogClient) {
    for (int i = 0; i < tLogClient; i++) {
        if (tNumClient[i] == numClient) {
            return i;
        }
    }
    return -1;
}

void supprimer_article(int tPanier[], int tQuantite[], int *tLogPanier, int reference, int numClient, int tNumClient[],
                       int tLogClient, int tRef[], float tPrixUnitaire[], float tCagnotte[]) {
    int articleIndex, clientIndex, quantite = 0;
    articleIndex = trouver_index_article(reference, tRef, MAX_ARTICLES);
    for (int i = 0; i < *tLogPanier; i++) {
        if (tPanier[i] == reference) {
            quantite = tQuantite[i];
            for (int j = i; j < *tLogPanier - 1; j++) {
                tPanier[j] = tPanier[j + 1];
                tQuantite[j] = tQuantite[j + 1];
            }
            break;
        }
    }

    (*tLogPanier)--;

    clientIndex = trouver_index_client(numClient, tNumClient, tLogClient);

    if (clientIndex != -1) {
        float montantTotal = tPrixUnitaire[articleIndex] * quantite;
        tCagnotte[clientIndex] -= 0.1 * montantTotal;
    }
}

void verifInt(int *var) {
    while (scanf("%d", var) != 1 || *var < 0) {
        fprintf(stderr, "\x1B[31mERREUR : Veuillez entrer une valeur valide (entier positif) :\x1B[0m ");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
}


void verifFloat(float *var) {
    while (scanf("%f", var) != 1 || *var < 0) {
        fprintf(stderr, "\x1B[31mERREUR : Veuillez entrer une valeur valide (valeur positive) :\x1B[0m ");
        while (getchar() != '\n');
    }
}