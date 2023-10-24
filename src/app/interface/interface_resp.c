#include <stdio.h>
#include "interface_resp.h"

void affiche_resp(int a){
    printf("\n");
    printf("+-------------+ \n");
    printf("|| Bonjour ! ||\n") ;
    printf("+-------------+ \n");
    printf("\n");
    printf("+-----------------------------------------------------------------+\n");
    printf("|| Que voulez-vous faire ? \t \t \t \t \t || \n");
    printf("||\t1 : Afficher les articles \t \t \t \t || \n");
    printf("||\t2 : Afficher un article \t \t \t \t || \n");
    printf("||\t3 : Afficher un client \t \t \t \t \t || \n");
    printf("||\t4 : Afficher les clients \t \t \t \t || \n");
    printf("||\t5 : Réinitialiser le panier. \t \t \t \t || \n");
    printf("+-----------------------------------------------------------------+\n");
}

void affichArticles( int tRef[], float tPoids[], float tVol[], float tPrix[], int tLogique)
{
    int i;
    printf("______________________________________\n");
    printf("\t Liste des articles \n\n");
    for ( i = 0; i < tLogique; ++i)
    {
        printf("\t %d  %.2f  %.2f  %.2f\n\n", tRef[i], tPoids[i], tVol[i], tPrix[i]);
    }
}

void affichUnArticle(int tRef[], float tPoids[], float tVol[], float tPrix[], int tLogique, int val)
{
    int i;
    for ( i = 0; i < tLogique; ++i)
    {
        if ( val == tRef[i] )
        {
            printf("\t %d  %.2f  %.2f  %.2f\n\n", tRef[i], tPoids[i], tVol[i], tPrix[i]);
            return;
        }
    }
    fprintf(stderr, "Article introuvable");
    printf("Article introuvable");
    return;
}

void affichUnClient(int tNumClient[], float tCagnotte[], int tSus[], int tLogique, int val)
{
    int i;
    for ( i = 0; i < tLogique; ++i)
    {
        if ( val == tNumClient[i] )
        {
            printf("\t %d %.2f %d\n\n", tNumClient[i], tCagnotte[i], tSus[i]);
        }
    }
    fprintf(stderr, "Client introuvable");
    printf("Client introuvable");
}

void affichUnClients(int tNumClient[], float tCagnotte[], int tSus[], int tLogique, int val) {
    int i;
    for (i = 0; i < tLogique; ++i) {
        printf("\t %d %.2f %d\n\n", tNumClient[i], tCagnotte[i], tSus[i]);
    }
    fprintf(stderr, "Client introuvable");
    printf("Client introuvable");
}

void affichAjoutArticle(int *ref, float *poids, float *volume, float *prix)
{
    printf("Entrez la ref du nouveaux produit");
    scanf("%d", ref);
    if ( ref < 0 )
    {
        while ( ref < 0 )
        {
            printf("Entrez un nombre correct !");
            scanf("%d", ref);
        }
    }
    printf("Entrez le poids du nouveaux produit");
    scanf("%f", poids);
        if ( poids < 0 )
    {
        while ( poids < 0 )
        {
            printf("Entrez un nombre correct !");
            scanf("%f", poids);
        }
    }
    printf("Entrez le volume du nouveaux produit");
    scanf("%f", poids);
        if ( poids < 0 )
    {
        while ( poids < 0 )
        {
            printf("Entrez un nombre correct !");
            scanf("%f", poids);
        }
    }
    printf("Entrez le prix du nouveaux produit");
    scanf("%f", prix);
        if ( prix < 0 )
    {
        while ( prix < 0 )
        {
            printf("Entrez un nombre correct !");
            scanf("%f", prix);
        }
    }
}


void menu_resp(int *choix, int jour) {
    affiche_resp(jour);
    printf("Vous choisissez: ");
    while (scanf("%d", choix) != 1 || *choix < 0 || *choix > 5) {
        while (getchar() != '\n');  // Nettoie le tampon d'entrée en cas de saisie invalide
        affiche_resp(jour);
        printf("Veuillez entrer un choix valide : ");
    }
}

void global_resp(){
    int choix, a = 0, tRef[100], tLogique = 0;
    float tPoids[100], tVol[100], tPrix[100];
    menu_resp(&choix, a);
    switch (choix) {
        case 1:
            affichArticles(tRef, tPoids, tVol, tPrix, tLogique);
            break;
        default:
            printf("Veuillez entrer un choix valide ! \n");
            break;
    }
}

