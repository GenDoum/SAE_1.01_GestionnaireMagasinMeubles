#include <stdio.h>
#include <stdlib.h>
#include "interface_resp.h"
#include "app/core_logic/responsable.h"
#include "app/core_logic/client.h"

#define MAX_CLIENTS 100
#define MAX_ARTICLES 100


void affiche_resp(void){
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
    printf("||\t5 : Ajouter un article \t \t \t \t \t || \n");
    printf("||\t6 : Supprimer un article \t \t \t \t || \n");
    printf("||\t7 : Modifier un article \t \t \t \t || \n");
    printf("||\t8 : Ajouter un client\t \t \t \t \t || \n");
    printf("||\t9 : Quittez. \t \t \t \t \t \t || \n");
    printf("+-----------------------------------------------------------------+\n");
}
/*
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
    printf("||\t5 : Supprimer un article \t \t \t \t || \n");
    printf("||\t6 : Modifier un article \t \t \t \t || \n");
    printf("||\t7 : Réinitialiser le panier. \t \t \t \t || \n");
    printf("+-----------------------------------------------------------------+\n");
}
*/
void affichArticles( int tRef[], float tPoids[], float tVol[], float tPrix[], int tLogique)
{
    printf("\t Liste des articles \n\n");
    printf("\t Ref\t Poids\t Volume\t Prix\n");
    for ( int i = 0; i < tLogique; ++i)
    {
        printf("\t %d\t  %.2f\t  %.2f\t  %.2f\n\n", tRef[i], tPoids[i], tVol[i], tPrix[i]);
    }
}

void affichUnArticle(int tRef[], float tPoids[], float tVol[], float tPrix[], int tLogique)
{
    int ref;
    printf("\tQuelle est la référence de l'article à rechercher ?\n");
    while(scanf("%d", &ref) != 1 || ref <= 0)
    {
        printf("\tEntrez une référence valide\n");
        while(getchar() != '\n');
    }
    printf("\t Ref\t Poids\t Volume\t Prix\n");
    for ( int i = 0; i < tLogique; ++i)
    {
        if ( ref == tRef[i] )
        {
            printf("\t %d\t %.2f\t %.2f\t  %.2f\n\n", tRef[i], tPoids[i], tVol[i], tPrix[i]);
            return;
        }
    }
    printf("\t Article introuvable\n");
}

void affichUnClient(int tNumClient[], float tCagnotte[], int tSus[], int tLogique)
{
    int numC;
    printf("\tVeuillez entrer le numéro du client à rechercher\n");
    while(scanf("%d", &numC) != 1 || numC <= 0)
    {
        printf("\t Veuillez entrez un numéro valide !\n");
        while(getchar() != '\n');
    }
    printf("\t NumClient\t Cagnotte\t Etat\n");
    for ( int i = 0; i < tLogique; ++i)
    {
        if ( numC == tNumClient[i] )
        {
            printf("\t %d\t\t %.2f\t %d\n\n", tNumClient[i], tCagnotte[i], tSus[i]);
            return;
        }
    }
    printf("Client introuvable\n");
}

void affichClients(int tNumClient[], float tCagnotte[], int tSus[], int tLogique)
{
    printf("\t Liste des clients\n");
    printf("\t NumClient\t Cagnotte\t Etat\n");
    for ( int i = 0; i < tLogique; ++i)
    {
        printf("\t %d\t\t %.2f\t\t %d\n\n", tNumClient[i], tCagnotte[i], tSus[i]);
    }
    printf("\t Fin de la liste ! \n");
}

void affichAjoutArticle(int *ref, float *poids, float *volume, float *prix)
{
    printf("\t Entrez la ref du nouveaux produit\n");
    while(scanf("%d", ref) != 1 || *ref <= 0)
    {
        printf("\t Veuillez entrer une référence valide.\n");
        while(getchar() != '\n');
    }

    printf("\t Entrez le poids du nouveaux produit\n");
    while(scanf("%f", poids) != 1 || *poids <= 0)
    {
        printf("\t Veuillez entrer un poids valide.\n");
    
        while(getchar() != '\n');
    }
    
    printf("\t Entrez le volume du nouveaux produit\n");
    while(scanf("%f", volume) != 1 || *volume <= 0)
    {
        printf("\t Veuillez entrer un volume valide.\n");
        while(getchar() != '\n');
    }
    
    printf("\t Entrez le prix du nouveaux produit\n");
    while(scanf("%f", prix) != 1 || *prix <= 0)
    {
        printf("\t Veuillez entrer un prix valide.\n"); 
        while(getchar() != '\n');
    }
}

void affichSupprimerArticle(int *ref)
{
    printf("\t Quel est la référence de l'article voulez-vous supprimez\n");
    while(scanf("%d", ref ) != 1 || *ref <= 0)
    {
        printf("\t Veuillez entrer une référence valide.\n");
        while(getchar() != '\n');
    }
}

void affichModifierArticle(int *ref, float *poids, float *volume, float *prix)
{


    printf("\t Quel est la référence de l'article voulez-vous modifier ?\n");
    while(scanf("%d", ref) != 1 || *ref <=0)
    {
        printf("\tVeuillez entrer une référence correcte !\n");
        while (getchar() != '\n');
    }

    printf("\t Quel est le nouveau poids à entrer ?\n");
    while(scanf("%f", poids) != 1 || *poids <= 0)
    {
        printf("\t Veuillez entrer un poids correct !\n");
        while (getchar() != '\n');
    }

    printf("\t Quel est le nouveau volume à entrer ?\n");
    while(scanf("%f", volume) != 1 || *volume <= 0)
    {
        printf("\t Veuillez entrer un volume correct !\n");
        while (getchar() != '\n');
    }

    printf("\t Quel est le nouveau prix à entrer ?\n");
    while(scanf("%f", prix) != 1 || *prix <= 0)
    {
        printf("\t Veuillez entrer un prix correct !\n");
        while (getchar() != '\n');
    }
}

void affichAjoutClient(int tNumClient[], int tLogique, int *numC)
{
    printf("\t Veuillez entrer le numéro du nouveau client\n");
    while(scanf("%d", numC) != 1 || *numC <= 0)
    {
        printf("Entrez un numéro valide !\n");
        while(getchar() != '\n');
    }
    for ( int i = 0 ; i < tLogique; ++i)
    {
        if ( *numC == tNumClient[i] )
        {
            fprintf(stderr,"\t Client déjà existant.\n");
            return;
        }
    }
}

/*
void menu_resp(int *choix, int jour) {
    affiche_resp();
    //affiche_resp(jour);
    printf("Vous choisissez: ");
    while (scanf("%d", choix) != 1 || *choix < 0 || *choix > 5) {
        while (getchar() != '\n');
        affiche_resp(jour);
        printf("Veuillez entrer un choix valide : ");
    }
}
*/

void menu_resp(int *choix) {
    affiche_resp();
    //affiche_resp(jour);
    printf("Vous choisissez: ");
    while (scanf("%d", choix) != 1 || *choix < 0 || *choix > 9) {
        while (getchar() != '\n');
        affiche_resp();
        printf("Veuillez entrer un choix valide : ");
    }
}

void global_resp(){
    int choix, ref = 0;
    float poids = 0, volume = 0 , prix = 0;
    int tRef[MAX_ARTICLES];
    float tPoids[MAX_ARTICLES];
    float tVol[MAX_ARTICLES];
    float tPrix[MAX_ARTICLES];
    int tNumClient[MAX_CLIENTS];
    float tCagnotte[MAX_CLIENTS];
    int tSus[MAX_CLIENTS];

    int tLogArticle = chargementArticles(tRef, tPoids, tVol, tPrix, MAX_ARTICLES);
    int tLogClient = charger_clients(tNumClient, tCagnotte, tSus, MAX_CLIENTS);

    do {


        menu_resp(&choix);
        switch (choix) {
            case 1:
                affichArticles(tRef, tPoids, tVol, tPrix, tLogArticle);
                break;
            case 2:
                affichUnArticle(tRef, tPoids, tVol, tPrix, tLogArticle);
                break;
            case 3:
                affichUnClient(tNumClient, tCagnotte, tSus, tLogClient);
                break;
            case 4:
                affichClients(tNumClient, tCagnotte, tSus, tLogClient);
                break;
            case 5:
                ajouterArticle(tRef,  tPoids, tVol, tPrix, &tLogArticle, MAX_ARTICLES, ref, poids, volume, prix);
                break;
            case 6:
                supprimerArticle(tRef, tPoids, tVol, tPrix, &tLogArticle);
                break;
            case 7:
                modifierArticle(tRef, tPoids, tVol, tPrix, tLogArticle);
                break;
            case 8:
                ajouterClient(tNumClient, tCagnotte, tSus, &tLogClient, MAX_CLIENTS);
                break;
            case 9:
                sauvegardArticles(tRef, tPoids, tVol, tPrix, tLogArticle);
                affichArticles(tRef, tPoids, tVol, tPrix, tLogArticle);
                return;
            default:
                printf("Veuillez entrer un choix valide ! \n");
                break;
        }
    } while (choix != 9);
    
}