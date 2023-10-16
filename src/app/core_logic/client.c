//
// Created by Mathéo Hersan on 16/10/2023.
//

#include "client.h"

void afficherDonneesClient() {
    FILE *fichier = fopen("donnee/client.txt", "r");
    int numeroClient;
    float cagnotte;
    int suspendu;

    if (fichier == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    while (fscanf(fichier, "%d%f%d", &numeroClient, &cagnotte, &suspendu) == 3) {
        printf("Client %d, Cagnotte %.2f, Suspendu: %s\n",
               numeroClient, cagnotte, (suspendu == 0) ? "Non" : "Oui");
    }

    fclose(fichier);
}