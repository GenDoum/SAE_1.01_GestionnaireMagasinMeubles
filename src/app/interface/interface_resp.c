

#include <stdio.h>
#include <stdlib.h>
#include "interface_resp.h"
#include "../core_logic/responsable.h"
#include "../core_logic/client.h"

#define MAX_CLIENTS 100
#define MAX_ARTICLES 100
#define MAX_SIZE_MDP 21
#define MENU_QUIT 12


void affiche_resp(void) {
    printf("\n");
    printf("+-------------+\n");
    printf("|| Bonjour ! ||\n");
    printf("+-------------+\n");
    printf("\n");
    printf("+----------------------------------------------------------------+\n");
    printf("|| Que voulez-vous faire ?\t\t\t\t\t||\n");
    printf("||\t1 : Afficher les articles\t\t\t\t||\n");
    printf("||\t2 : Afficher un article\t\t\t\t\t||\n");
    printf("||\t3 : Afficher un client\t\t\t\t\t||\n");
    printf("||\t4 : Afficher les clients\t\t\t\t||\n");
    printf("||\t5 : Ajouter un article\t\t\t\t\t||\n");
    printf("||\t6 : Supprimer un article\t\t\t\t||\n");
    printf("||\t7 : Modifier un article\t\t\t\t\t||\n");
    printf("||\t8 : Ajouter un client\t\t\t\t\t||\n");
    printf("||\t9 : Modifier le statut du client\t\t\t||\n");
    printf("||\t10 : Supprimer un client\t\t\t\t||\n");
    printf("||\t11 : Modifier le mot de passe\t\t\t\t||\n");
    printf("||\t12 : Quittez.\t\t\t\t\t\t||\n");
    printf("+----------------------------------------------------------------+\n");
}

void affichArticles(int tRef[], float tPoids[], float tVol[], float tPrix[], int tLogique) {
    printf("\t Liste des articles\n\n");
    printf("\t Ref\t Poids\t Volume\t Prix\n");
    for (int i = 0; i < tLogique; ++i) {
        printf("\t %d\t  %.2f\t  %.2f\t  %.2f\n\n", tRef[i], tPoids[i], tVol[i], tPrix[i]);
    }
}


void affichUnArticle(int tRef[], float tPoids[], float tVol[], float tPrix[], int tLogique) {
    int ref;
    printf("\tQuelle est la référence de l'article à rechercher ?\n");
    while (scanf("%d", &ref) != 1 || ref <= 0) {
        printf("\tEntrez une référence valide\n");
        while (getchar() != '\n');
    }
    
    for (int i = 0; i < tLogique; ++i) {
        if (ref == tRef[i]) {
            printf("\t Ref\t Poids\t Volume\t Prix\n");
            printf("\t %d\t %.2f\t %.2f\t  %.2f\n\n", tRef[i], tPoids[i], tVol[i], tPrix[i]);
            return;
        }
    }
    printf("\t Article introuvable\n");
}


void affichUnClient(int tNumClient[], float tCagnotte[], int tSus[], int tLogique) {
    int numC;
    printf("\tVeuillez entrer le numéro du client à rechercher\n");
    while (scanf("%d", &numC) != 1 || numC <= 0) {
        printf("\t Veuillez entrez un numéro valide !\n");
        while (getchar() != '\n');
    }
    for (int i = 0; i < tLogique; ++i) {
        if (numC == tNumClient[i]) {
            printf("\t NumClient\t Cagnotte\t Etat\n");
            printf("\t %d\t\t %.2f\t\t %d\n\n", tNumClient[i], tCagnotte[i], tSus[i]);
            return;
        }
    }
    printf("\t Client introuvable\n");
}

void affichClients(int tNumClient[], float tCagnotte[], int tSus[], int tLogique) {
    printf("\t Liste des clients\n");
    printf("\t NumClient\t Cagnotte\t Etat\n");
    for (int i = 0; i < tLogique; ++i) {
        printf("\t %d\t\t %.2f\t\t %d\n\n", tNumClient[i], tCagnotte[i], tSus[i]);
    }
    printf("\t Fin de la liste !\n");
}

void affichAjoutArticle(int *ref, float *poids, float *volume, float *prix, int tRef[], int tLogArticle) {
    printf("\t Entrez la ref du nouveau produit\n");
    while (scanf("%d", ref) != 1 || *ref <= 0) {
        
        printf("\t Veuillez entrer une référence valide.\n");
        while (getchar() != '\n');
    }

    if ( trouver_index_article(*ref, tRef, tLogArticle) != -1)
    {
        return;
    }
    else
    {
        printf("\t Entrez le poids du nouveau produit\n");
        while (scanf("%f", poids) != 1 || *poids <= 0) 
        {
            printf("\t Veuillez entrer un poids valide.\n");
            while (getchar() != '\n');
        }

    printf("\t Entrez le volume du nouveau produit\n");
        while (scanf("%f", volume) != 1 || *volume <= 0) 
        {
            printf("\t Veuillez entrer un volume valide.\n");
            while (getchar() != '\n');
        }

    printf("\t Entrez le prix du nouveau produit\n");
        while (scanf("%f", prix) != 1 || *prix <= 0) 
        {
            printf("\t Veuillez entrer un prix valide.\n");
            while (getchar() != '\n');
        }
    }

    
}

void affichSupprimerArticle(int *ref) {
    printf("\t Quelle est la référence de l'article que vous voulez supprimer ?\n");
    while (scanf("%d", ref) != 1 || *ref <= 0) {
        printf("\t Veuillez entrer une référence valide.\n");
        while (getchar() != '\n');
    }
}


void affichModifierArticle(int *ref, float *poids, float *volume, float *prix) {
    printf("\t Quelle est la référence de l'article que vous voulez modifier ?\n");
    while (scanf("%d", ref) != 1 || *ref <= 0) {
        printf("\t Veuillez entrer une référence correcte !\n");
        while (getchar() != '\n');
    }

    printf("\t Quel est le nouveau poids à entrer ?\n");
    while (scanf("%f", poids) != 1 || *poids <= 0) {
        printf("\t Veuillez entrer un poids correct !\n");
        while (getchar() != '\n');
    }

    printf("\t Quel est le nouveau volume à entrer ?\n");
    while (scanf("%f", volume) != 1 || *volume <= 0) {
        printf("\t Veuillez entrer un volume correct !\n");
        while (getchar() != '\n');
    }

    printf("\t Quel est le nouveau prix à entrer ?\n");
    while (scanf("%f", prix) != 1 || *prix <= 0) {
        printf("\t Veuillez entrer un prix correct !\n");
        while (getchar() != '\n');
    }
}

void affichAjoutClient(int tNumClient[], int tLogique, int *numC) {
    printf("\t Veuillez entrer le numéro du nouveau client\n");
    while (scanf("%d", numC) != 1 || *numC <= 0) {
        printf("Entrez un numéro valide !\n");
        while (getchar() != '\n');
    }
    for (int i = 0; i < tLogique; ++i) {
        if (*numC == tNumClient[i]) {
            fprintf(stderr, "\t /!/ Client déjà existant. /!/\n");
            return;
        }
    }
}

int affichageConnexion(void)
{
    char mdpEnter[20];
    printf("Entrer le mot de passe responsable : ");
    scanf("%s", mdpEnter);

    int verif = decodageMDP(mdpEnter);
    
    if ( verif == 0 )
    {
        printf("+--------------------------------------------+\n");
        printf("|| Mot de passe correct, bienvenue patron ! ||\n");
        printf("+--------------------------------------------+\n");
        return 0;
    }
    else if ( verif == -1)
    {
        printf("\t Problème ouverture fichier !\n");
        return -1;
    }
    printf("+--------------------------------------------------+\n");
    printf("|| \tMot de passe incorrect, Au revoir ! \t||\n");
    printf("+--------------------------------------------------+\n");
    return -2;
}

void affichModifClient(int tNumClient[], int tSus[], int tLogique)
{
    int choix, numC;
    printf("\tEntrez le numéro du client : ");
    while( scanf("%d", &numC) != 1 || numC <=0 )
    {
        printf("\t Entrez une valeur valide ! \n");
        while (getchar() != '\n');
    }
    
    for ( int i = 0; i <=  tLogique; i++)
    {
        if ( numC == tNumClient[i] )
        {
            if ( tSus[i] == 0 )
            {
                printf("\t La cagnotte du client n'est pas suspendu, voulez-vous le suspendre ?\n ( Oui = 0 / Non = 1 )\n ");
                while(scanf("%d", &choix) != 1 || choix < 0 || choix > 1)
                {
                    printf("\t Veuillez entrer un choix valide ! \n");
                    while (getchar() != '\n');
                }
                if ( choix == 0 )
                {
                    tSus[i] = 1;
                    printf("\t La cagnotte est maintenant suspendu\n");
                    return;
                }
                else
                {
                    printf("\t La cagnotte n'a pas été changé. Au revoir ! \n");
                    return;
                }
            }
            else
            {
                printf("\t La cagnotte du client %d est suspendue, voulez-vous l'activer à nouveau ?\n ( Oui = 0 / Non = 1 )\n", tNumClient[i]);
                while(scanf("%d", &choix) != 1 || choix < 0 || choix > 1)
                {
                    printf("\t Veuillez entrer un choix valide ! \n");
                    while (getchar() != '\n');
                }
                if ( choix == 0 )
                {
                    tSus[i] = 0;
                    printf("\t La cagnotte n'est plus suspendu\n");
                    return;
                }
                else
                {
                    printf("\t La cagnotte n'a pas été changé. Au revoir ! \n");
                    return;
                }
            }
        }
    }
    printf("\t Le client %d n'a pas été trouvé. \n", numC);
    return;
}


void suppressionClient(int tNumClient[], float tCagnotte[], int tSus[], int *tLogique)
{
    int choix, numC;
    printf("\tEntrez le numéro du client : ");
    while( scanf("%d", &numC) != 1 || numC <=0 )
    {
        printf("\t Entrez une valeur valide ! \n");
        while (getchar() != '\n');
    }
    
    
    for ( int i = 0; i <  *tLogique; ++i)
    {
        if ( numC == tNumClient[i] )
        {
            printf("\tÊtes-vous sur de vouloir supprimer ce client ? ( Oui = 0 / Non = 1 )\n");
            while(scanf("%d", &choix) != 1 || choix < 0 || choix > 1)
            {
                printf("\t Veuillez entrer un choix valide ! \n");
            }
            if ( choix == 0 )
            {
                while ( i < *tLogique-1 )
                {
                    tNumClient[i] = tNumClient[i+1];
                    tCagnotte[i] = tCagnotte[i+1];
                    tSus[i] = tSus[i+1];
                    i++;
                }
                printf("Le client %d a été supprimé.\n", tNumClient[i]);
                (*tLogique)--;
                return;
            }
            else
            {
                printf("\t Le client %d n'a pas été supprimé.\n", tNumClient[i]);
                return;
            }
        }
    }
    printf("\t Le client %d n'a pas été trouvé. \n", numC);
    return;
}

void affichModifMDP(void)
{
    int choix, decalage;
    char newMDP[MAX_SIZE_MDP], confirmMDP[MAX_SIZE_MDP];
    printf("\t /!/ Vous entrez dans le menu de modification du mot de passe /!/\n");
    printf("\t Êtes-vous sur de vouloir changer le mot de passe ?\n Si oui, entrez 0 et sinon entrez 1\n");
    while (scanf("%d", &choix) !=1 || choix < 0 || choix > 1)
    {
        printf("/!/ Entrez une valeur valide /!/");
        while (getchar() != '\n');
    }
    if ( choix == 1 )
    {
        printf("\t Vous quittez le menu de modification du mot de passe.\n");
        return;
    }
    else
    {
        printf("Veuillez entrer le nouveau mot de passe.\n\n\tMAXIXMUM 20 CARACTERES ET SEULEMENT DES LETTRES\n\t");
        while (scanf("%s", newMDP) != 1)
        {
            printf("Veuillez recommencer la saisie : ");
            while (getchar() != '\n');
        }

        for ( int verif = 0; newMDP[verif] != '\0'; verif++)
        {
            if ( verif > 20 )
            {
                printf("\t /!/ Mot de passe trop long /!/ \n");
                return;
            }
        }

        printf("Veuillez entrer à nouveau le mot de passe.\n\t");
        while (scanf("%s", confirmMDP) != 1)
        {
            printf("Veuillez recommencer la saisie : ");
            while (getchar() != '\n');
        }
        
        printf("\t Veuillez entrer le nouveau décalage\n");
        while (scanf("%d", &decalage) != 1 || decalage < 0)
        {
            printf("\t Veuillez entrer un nombre valide : ");
            while (getchar() != '\n');
        }
        int verif = verifModifMDP(newMDP, confirmMDP, decalage);  
        if ( verif == 0 )
        {
            printf("\t Mot de passe modifié !\n");
            return;
        }
        else
        {
            printf("\t/!/ Erreur lors du changement de mot de passe. /!/\n");
            return;
        }
    }
}
/*
void appliquerReduc( int tRefProm[], int tReduc[], int *tLogReduc, int tPhysiqueReduc)
{
    int i, ref;
    printf("\tA quel article voulez-vous ajouter une promotion ?\n");
    while (scanf("%d", &ref) !=1 || ref < 0)
    {
        fprintf("\t Entrez une référence correcte !\n");
    }
    if ()
}
*/

void menu_resp(int *choix) {
    affiche_resp();
    printf("Vous choisissez: ");
    while (scanf("%d", choix) != 1 || *choix < 0 || *choix > MENU_QUIT) {
        while (getchar() != '\n');
        affiche_resp();
        printf("Veuillez entrer un choix valide : ");
    }
}

void global_resp(void) {
    int choix, ref = 0;
    float poids = 0, volume = 0, prix = 0;
    int tRef[MAX_ARTICLES];
    float tPoids[MAX_ARTICLES];
    float tVol[MAX_ARTICLES];
    float tPrix[MAX_ARTICLES];
    int tNumClient[MAX_CLIENTS];
    float tCagnotte[MAX_CLIENTS];
    int tSus[MAX_CLIENTS];

    int tLogArticle = chargementArticles(tRef, tPoids, tVol, tPrix, MAX_ARTICLES);
    int tLogClient = charger_clients(tNumClient, tCagnotte, tSus, MAX_CLIENTS);
    // system("clear");
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
                ajouterArticle(tRef, tPoids, tVol, tPrix, &tLogArticle, MAX_ARTICLES, ref, poids, volume, prix);
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
                affichModifClient(tNumClient, tSus, tLogClient);
                break;
            case 10:
                suppressionClient(tNumClient, tCagnotte ,tSus , &tLogClient);
                break;
            case 11:
                affichModifMDP();
                break;
            case 12:
                sauvegardArticles(tRef, tPoids, tVol, tPrix, tLogArticle);
                sauvegarde_clients(tNumClient, tCagnotte, tSus, tLogClient);
                printf("Sauvegarde des articles effectuée.\n");
                printf("Sauvegarde des clients effectuée.\n");
                printf("Au revoir !\n");
                return;
            default:
                printf("Veuillez entrer un choix valide ! \n");
                break;
        }
    } while (choix != MENU_QUIT);
    
}
