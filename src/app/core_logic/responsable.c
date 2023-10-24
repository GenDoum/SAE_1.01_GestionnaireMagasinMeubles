#include <stdio.h>
#include "responsable.h"

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

void sauvegadArticles(int tRef[], float tPoids[], float tVol[], float tPrix[], float tLogique)
{
    int i;
    FILE * fe;
    fe = fopen("articles.txt","w");
    if ( fe == NULL )
    {
        perror("fopen");
        return -1;
    }
    
    for ( i = 0; i < tLogique; ++i)
    {
        fwritef(fe,"%d\t %.2f\t %.2f\t %.2f\n", );
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
    
}