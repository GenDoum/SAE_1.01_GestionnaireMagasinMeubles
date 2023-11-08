/**
 * @file responsable.c
 * @brief Définition des fonctions de responsable.c.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "responsable.h"
#include "../interface/interface_resp.h"

#define MAX_SIZE_MDP 21

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
        fprintf(stderr, "\n Problème ouverture ficher\n");
        return;
    }
    
    for ( i = 0; i < tLogique; i++)
    {
        fprintf(fe,"\t %d\t  %.2f\t %.2f\t %.2f\n", tRef[i], tPoids[i], tVol[i], tPrix[i]);
    }
    fclose(fe);
}

int ajouterArticle( int tRef[], float tPoids[], float tVol[], float tPrix[], int *tLogique, int tPhysique, int ref, float poids, float volume, float prix)
{
    int i = *tLogique;
    affichAjoutArticle(&ref, &poids, &volume, &prix, tRef, *tLogique);
    if ( *tLogique == tPhysique)
    {
        fprintf(stderr,"Tableau plein !");
        return -2;
    }
    for ( int j = 0; j < *tLogique; ++j )
    {
        if ( ref == tRef[j] )
        {
            fprintf(stderr, "\t /!/ Article déjà existant. /!/ \n");
            return -1;
        }
    }
    tRef[i] = ref;
    tPoids[i] = poids;
    tVol[i] = volume;
    tPrix[i] = prix;
    (*tLogique)++;
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
    fprintf(stderr, "\t Article non trouvé.\n");
    *index = -1;
    return;
}

void supprimerArticle(int tRef[], float tPoids[], float tVol[], float tPrix[], int *tLogique)
{
    int ref, index;
    affichSupprimerArticle(&ref);
    rechercheRefArticle(tRef, ref, &index, *tLogique);

    for( int i = index; i < *tLogique-1; ++i)
    {
        tRef[i] = tRef[i+1];
        tPoids[i] = tPoids[i+1];
        tVol[i] = tVol[i+1];
        tPrix[i] = tPrix[i+1];
    }
    (*tLogique)--;
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

void ajouterClient(int tNumClient[], float tCagnotte[], int tSus[], int *tLogique)
{
    int numC = 0;
    affichAjoutClient(tNumClient, *tLogique, &numC);

    tNumClient[*tLogique] = numC;
    tCagnotte[*tLogique] = 0;
    tSus[*tLogique] = 0;
    (*tLogique)++;
    return;

}


void dechiffrerCesar(char *texte, int decalage) {
    int i;
    int longueur = strlen(texte);
    for (i = 0; i < longueur; ++i) {
        if (texte[i] >= 'a' && texte[i] <= 'z') {
            texte[i] = 'a' + (texte[i] - 'a' + decalage) % 26;
        } else if (texte[i] >= 'A' && texte[i] <= 'Z') {
            texte[i] = 'A' + (texte[i] - 'A' + decalage) % 26;
        }
    }
}


int decodageMDP(char *mdpEnter)
{
    int decalage;
    char mdpRead[20];
    FILE *fe;
    fe = fopen("donnee/mdp.txt","r");
    if ( fe == NULL )
    {
        return -1;
    }

    fscanf(fe, "%s %d", mdpRead, &decalage);
    fclose(fe);

    dechiffrerCesar(mdpEnter, decalage);

    if ( strcmp(mdpRead, mdpEnter) == 0 )
    {
        return 0;
    }
    else
    {
        return -2;
    }
}

void chiffrementCesar(char *mdp, int decalage) {
    int i;
    int longueur = strlen(mdp);
    for (i = 0; i < longueur; ++i) 
        {
        if (mdp[i] >= 'a' && mdp[i] <= 'z') {
            mdp[i] = 'a' + (mdp[i] - 'a' + decalage) % 26;
        } else if (mdp[i] >= 'A' && mdp[i] <= 'Z') 
        {
            mdp[i] = 'A' + (mdp[i] - 'A' + decalage) % 26;
        }
    }
}

int verifModifMDP(char *mdp, char *confirmMDP, int decalage)
{
    if ( strcmp(mdp, confirmMDP) == 0 )
    {
        enregistrerMotDePasse(mdp, decalage);
        return 0;
    }
    fprintf(stderr, "\tLes mot de passe ne sont pas identiques !\n");
    return -1;
    
}

int enregistrerMotDePasse(char *mdp, int decalage) 
{
    FILE *fe;
    fe = fopen("donnee/mdp.txt", "w");
    if (fe == NULL) 
    {
        fprintf(stderr,"Erreur lors de l'ouverture du fichier.\n");
        return -1;
    }

    chiffrementCesar(mdp, decalage);

    fprintf(fe,"%s %d", mdp, decalage);
    fclose(fe);
    return 0;
}

int chargementReduc( int tRefProm[], int tReduc[], int tPhysique)
{
    int i = 0, ref, reduc;
    FILE *fe;
    fe = fopen("donnee/promotion.txt", "r");
    if ( fe == NULL )
    {
        fprintf(fe, "Problème ouverture fichier");
        return -1;
    }
    while ( i < tPhysique && fscanf(fe, "%d %d", &ref, &reduc) == 2 )
    {
        tRefProm[i] = ref;
        tReduc[i] = reduc;
        ++i;
    }
    fclose(fe);
    return i;
}

void sauvegardeReduc( int tRefReduc[], int tReduc[], int tLogReduc)
{
    FILE * fe;
    fe = fopen("donnee/promotion.txt", "w");
    if ( fe == NULL )
    {
        fprintf(stderr, "Problème ouverture fichier.\n");
        return;
    }

    for ( int i = 0; i < tLogReduc; ++i)
    {
        fprintf(fe, "%d\t%d\n", tRefReduc[i], tReduc[i]);
    }
    fclose(fe);
    return;
}

float retrouvePrix(float prixReduit, int reduction)
{
    printf("BLABLA%d", reduction);
    return prixReduit / (1.0 - (reduction / 100.0));
}

void suppressionReduc(int tRefReduc[], int tReduc[], int *tLogReduc, int tRef[], float tPrix[], int tLogArticle)
{
    int indexReduc, indexPrix, ref;
    float temp;
    ref = affichSuprReduc( tRefReduc, *tLogReduc, &indexReduc);
    for ( int i = indexReduc; i < *tLogReduc-1; ++i)
    {
        tRefReduc[i] = tRefReduc[i+1];
        tReduc[i] = tReduc[i+1];
    }

    --(*tLogReduc);
    indexPrix = trouver_index_article(ref, tRef, tLogArticle);
   tPrix[indexPrix] = retrouvePrix(tPrix[indexPrix], tReduc[indexReduc]);

}