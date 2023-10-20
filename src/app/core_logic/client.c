//
// Created by Mathéo Hersan on 16/10/2023.
//

#include "client.h"

void chargerClient(int tNumClient[], float tCagnotte[], int tSus[], int *tLogique)
{
    FILE *fic;
    int i;
    fic = fopen("donnee/client.txt", "r");
    if (fic == NULL)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    while (fscanf(fic, "%d %f %d", &tNumClient[*tLogique], &tCagnotte[*tLogique], &tSus[*tLogique]) != EOF)
    {
        (*tLogique)++;
    }
    fclose(fic);
}