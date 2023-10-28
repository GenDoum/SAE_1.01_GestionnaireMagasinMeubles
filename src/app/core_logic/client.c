#include <stdio.h>

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



void ajouter_article_au_panier(int numeroClient, int references[], float poids[], float volume[], float prixUnitaire[],
                               int numeros[], float cagnottes[], int suspendues[], int nombreArticles, int nombreClients,
                               float volumeCoffre, float chargeMaximale) {
    int reference, quantite;
    printf("Entrez la référence de l'article : ");
    scanf("%d", &reference);
    printf("Entrez la quantité : ");
    scanf("%d", &quantite);

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

void supprimer_article_du_panier(int panier[], int *taillePanier) {
    int reference;
    printf("Interface utilisateur : Entrez la référence de l'article à supprimer : ");
    scanf("%d", &reference);

    int articleIndex = -1;
    for (int i = 0; i < *taillePanier; i++) {
        if (panier[i] == reference) {
            articleIndex = i;
            break;
        }
    }

    if (articleIndex == -1) {
        printf("Interface utilisateur : Article non trouvé dans le panier. Veuillez entrer une référence valide.\n");
        return;
    }

    for (int i = articleIndex; i < (*taillePanier - 1); i++) {
        panier[i] = panier[i + 1];
    }

    (*taillePanier)--;

    printf("Article supprimé du panier avec succès.\n");
}
