/**
 * @file responsable.c
 * @brief Définition des fonctions de responsable.c.
 */

#include <stdio.h>
#include <stdlib.h>
#include "responsable.h"
#include "../interface/interface_resp.h"

/**
 * @brief Charge les informations des articles à partir d'un fichier dans des tableaux.
 *
 * Cette fonction lit les informations des articles à partir du fichier "donnee/articles.txt" et les stocke
 * dans les tableaux tRef, tPoids, tVol, et tPrix.
 *
 * @param tRef Tableau des références d'articles.
 * @param tPoids Tableau des poids des articles.
 * @param tVol Tableau des volumes des articles.
 * @param tPrix Tableau des prix unitaires des articles.
 * @param tPhysique Taille physique des tableaux.
 * @return Le nombre d'articles chargés avec succès ou -1 en cas d'erreur.
 */
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

/**
 * @brief Sauvegarde les informations des articles dans un fichier.
 *
 * Cette fonction sauvegarde les informations des articles depuis les tableaux tRef, tPoids, tVol et tPrix
 * dans le fichier "donnee/articles.txt".
 *
 * @param tRef Tableau des références d'articles.
 * @param tPoids Tableau des poids des articles.
 * @param tVol Tableau des volumes des articles.
 * @param tPrix Tableau des prix unitaires des articles.
 * @param tLogique Taille logique des tableaux.
 */
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

/**
 * @brief Ajoute un nouvel article aux tableaux d'articles.
 *
 * Cette fonction ajoute un nouvel article aux tableaux tRef, tPoids, tVol, et tPrix et incrémente la taille logique.
 *
 * @param tRef Tableau des références d'articles.
 * @param tPoids Tableau des poids des articles.
 * @param tVol Tableau des volumes des articles.
 * @param tPrix Tableau des prix unitaires des articles.
 * @param tLogique Taille logique des tableaux.
 * @param tPhysique Taille physique des tableaux.
 * @param ref Référence du nouvel article.
 * @param poids Poids du nouvel article.
 * @param volume Volume du nouvel article.
 * @param prix Prix unitaire du nouvel article.
 * @return 0 en cas de succès, -2 si le tableau est plein.
 */
int ajouterArticle( int tRef[], float tPoids[], float tVol[], float tPrix[], int *tLogique, int tPhysique, int ref, float poids, float volume, float prix)
{
    int i = *tLogique;
    affichAjoutArticle(&ref, &poids, &volume, &prix);
    if ( *tLogique == tPhysique)
    {
        fprintf(stderr,"Tableau plein !");
        return -2;
    }
    tRef[i] = ref;
    tPoids[i] = poids;
    tVol[i] = volume;
    tPrix[i] = prix;
    (*tLogique)++;
    return 0;
}

/**
 * @brief Recherche une référence d'article dans le tableau tRef.
 *
 * Cette fonction recherche une référence d'article dans le tableau tRef et renvoie l'index si l'article est trouvé.
 *
 * @param tRef Tableau des références d'articles.
 * @param ref Référence de l'article à rechercher.
 * @param index Pointeur vers la variable pour stocker l'index de l'article trouvé.
 * @param tLogique Taille logique des tableaux.
 */
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

/**
 * @brief Supprime un article des tableaux d'articles.
 *
 * Cette fonction supprime un article des tableaux tRef, tPoids, tVol, et tPrix et met à jour la taille logique.
 *
 * @param tRef Tableau des références d'articles.
 * @param tPoids Tableau des poids des articles.
 * @param tVol Tableau des volumes des articles.
 * @param tPrix Tableau des prix unitaires des articles.
 * @param tLogique Pointeur vers la taille logique des tableaux.
 */
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
    *tLogique -= 1;
}

/**
 * @brief Modifie les informations d'un article existant.
 *
 * Cette fonction permet de modifier les informations (poids, volume, prix) d'un article existant.
 *
 * @param tRef Tableau des références d'articles.
 * @param tPoids Tableau des poids des articles.
 * @param tVol Tableau des volumes des articles.
 * @param tPrix Tableau des prix unitaires des articles.
 * @param tLogique Taille logique des tableaux.
 */
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

/**
 * @brief Ajoute un nouveau client aux tableaux de clients.
 *
 * Cette fonction ajoute un nouveau client aux tableaux tNumClient, tCagnotte et tSus et incrémente la taille logique.
 *
 * @param tNumClient Tableau des numéros de client.
 * @param tCagnotte Tableau des cagnottes des clients.
 * @param tSus Tableau des états de suspension des clients.
 * @param tLogique Pointeur vers la taille logique des tableaux.
 * @param tPhysique Taille physique des tableaux.
 */
void ajouterClient(int tNumClient[], float tCagnotte[], int tSus[], int *tLogique, int tPhysique)
{
    int numC = 0;
    affichAjoutClient(tNumClient, *tLogique, &numC);

    tNumClient[*tLogique] = numC;
    tCagnotte[*tLogique] = 0;
    tSus[*tLogique] = 0;
    (*tLogique)++;
    return;

}