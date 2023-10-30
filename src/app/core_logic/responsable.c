#include <stdio.h>
#include <stdlib.h>
#include "responsable.h"
#include "../interface/interface_resp.h"

int chargementArticles(int tRef[], float tPoids[], float tVol[], float tPrix[], int tPhysique)
{
    int i=0, ref;
    float volume, poids, prix;
    FILE * fe;
    fe = fopen("donnee/articles.txt", "r");
    if ( fe == NULL)
    {
        perror("fopen");
        return -1;
    }
    while ( fscanf(fe,"%d %f %f %f", &ref, &poids, &volume, &prix) == 4)
    {
        if ( i == tPhysique )
        {
            fprintf(stderr,"Tableau plein");
        }
        tRef[i] = ref;
        tPoids[i] = poids;
        tVol[i] = volume;
        tPrix[i] = prix;
        i++;
    }
    return i;
}

void sauvegardArticles(int tRef[], float tPoids[], float tVol[], float tPrix[], int tLogique)
{
    int i;
    FILE * fe;
    fe = fopen("donnee/articles.txt", "w");
    if ( fe == NULL)
    {
        perror("fopen");
        return;
    }
    for ( i = 0; i < tLogique; i++)
    {
        fprintf(fe,"%d %f %f %f\n", tRef[i], tPoids[i], tVol[i], tPrix[i]);
    }
    fclose(fe);
}



int ajouterArticle( int tRef[], float tPoids[], float tVol[], float tPrix[], int *tLogique, int tPhysique, int ref, float poids, float volume, float prix)
{
    int i = *tLogique;
    affichAjoutArticle(&ref, &poids, &volume, &prix);
    if ( *tLogique == tPhysique)
    {
        fprintf(stderr,"Tableau plein !");
        return -2;
    }

    // SI on trie pas par ref c'est ca
    tRef[i] = ref;
    tPoids[i] = poids;
    tVol[i] = volume;
    tPrix[i] = prix;
    return 0;

}

void rechercheRefArticle(int tRef[], int ref, int *index, int tLogique)
{
    for (int i = 0; i<tLogique; i++)
    {
        if ( ref == tRef[i] )
        {
            *index = i;
            return;
        }
    }
    *index = -1;
    return;
}



void supprimerArticle(int tRef[], float tPoids[], float tVol[], float tPrix[], int *tLogique)
{
    int ref, index;
    affichSupprimerArticle(&ref);
    rechercheRefArticle(tRef, ref, &index, *tLogique);

    for( int i = index; i< *tLogique-1; ++i)
    {
        tRef[i] = tRef[i+1];
        tPoids[i] = tPoids[i+1];
        tVol[i] = tVol[i+1];
        tPrix[i] = tPrix[i+1];
    }
    *tLogique -= 1;
}

void modifierArticle(int tRef[], float tPoids[], float tVol[], float tPrix[], int tLogique)
{
    int ref, index;
    float poids, volume, prix;
    affichModifierArticle( &ref, &poids, &volume, &prix);
    rechercheRefArticle(tRef, ref, &index, tLogique);

    tPoids[index] = poids;
    tVol[index] = volume;
    tPrix[index] = prix;

}