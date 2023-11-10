#include "interface_resp.h"

#define MAX_CLIENTS 100
#define MAX_ARTICLES 100
#define MAX_REDUCTION 100
#define MAX_SIZE_MDP 21
#define MENU_QUIT 14

void affiche_resp(void) {
    printf("\n");
    printf("+-------------+\n");
    printf("|| Bonjour ! ||\n");
    printf("+-------------+\n");
    printf("\n");
    printf("+----------------------------------------------------------------+\n");
    printf("|| Que voulez-vous faire ?\t\t\t\t\t||\n");
    printf("|| \t\t - Clients -\t\t\t\t\t||\n");
    printf("||\t\t\t\t\t\t\t\t||\n");
    printf("||\t1 : Afficher un client\t\t\t\t\t||\n");
    printf("||\t2 : Afficher les clients\t\t\t\t||\n");
    printf("||\t3 : Ajouter un client\t\t\t\t\t||\n");
    printf("||\t4 : Supprimer un client\t\t\t\t\t||\n");
    printf("||\t5 : Modifier le statut du client\t\t\t||\n");
    printf("||\t\t\t\t\t\t\t\t||\n");
    printf("|| \t\t - Articles -\t\t\t\t\t||\n");
    printf("||\t\t\t\t\t\t\t\t||\n");
    printf("||\t6 : Afficher un article\t\t\t\t\t||\n");
    printf("||\t7 : Afficher les articles\t\t\t\t||\n");
    printf("||\t8 : Ajouter un article\t\t\t\t\t||\n");
    printf("||\t9 : Supprimer un article\t\t\t\t||\n");
    printf("||\t10 : Modifier un article\t\t\t\t||\n");
    printf("||\t\t\t\t\t\t\t\t||\n");
    printf("|| \t\t - Réductions -\t\t\t\t\t||\n");
    printf("||\t\t\t\t\t\t\t\t||\n");
    printf("||\t11 : Ajouter réduction\t\t\t\t\t||\n");
    printf("||\t12 : Supprimer réduction\t\t\t\t||\n");
    printf("||\t\t\t\t\t\t\t\t||\n");
    printf("|| \t\t - Autres -\t\t\t\t\t||\n");
    printf("||\t\t\t\t\t\t\t\t||\n");
    printf("||\t13 : Modifier le mot de passe\t\t\t\t||\n");
    printf("||\t14 : Quittez.\t\t\t\t\t\t||\n");
    printf("+----------------------------------------------------------------+\n");
}

void affichArticles(int tRef[], float tPoids[], float tVol[], float tPrix[], int tLogique) {
    printf("\t Liste des articles\n\n");
    printf("\t Ref\t\t Poids\t\t Volume\t\t Prix\n");
    for (int i = 0; i < tLogique; ++i) {
        printf("\t %d\t\t  %.2f\t\t  %.2f\t\t  %.2f\n\n", tRef[i], tPoids[i], tVol[i], tPrix[i]);
    }
}


void affichUnArticle(int tRef[], float tPoids[], float tVol[], float tPrix[], int tLogique) {
    int ref;
    printf("Entrez la référence de l'article à rechercher : ");
    verifInt(&ref);

    for (int i = 0; i < tLogique; ++i) {
        if (ref == tRef[i]) {
            printf("\t Ref\t\t Poids\t\t Volume\t\t Prix\n");
            printf("\t %d\t\t %.2f\t\t %.2f\t\t  %.2f\n\n", tRef[i], tPoids[i], tVol[i], tPrix[i]);
            return;
        }
    }
    printf("\t Article introuvable\n");
}


void affichUnClient(int tNumClient[], float tCagnotte[], int tSus[], int tLogique) {
    int numC;
    printf("Veuillez entrer le numéro du client à rechercher : ");

    verifInt(&numC);

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
    int articleIndex;
    printf("Entrez la ref du nouveau produit : ");

    verifInt(ref);

    articleIndex = trouver_index_article(*ref, tRef, tLogArticle);

    while (articleIndex != -1) {
        fprintf(stderr, "\x1B[31mERREUR : Article déjà présent. Veuillez entrer une référence valide :\x1B[0m ");
        verifInt(ref);
        articleIndex = trouver_index_article(*ref, tRef, tLogArticle);
    }

    printf("Entrez le poids du nouveau produit : ");
    verifFloat(poids);

    printf("Entrez le volume du nouveau produit : ");
    verifFloat(volume);

    printf("Entrez le prix du nouveau produit : ");
    verifFloat(prix);


}

void affichSupprimerArticle(int *ref, int tLogArticle, int tRef[]) 
{
    printf("Entrez la référence de l'article que vous voulez supprimer : ");
    verifInt(ref);
    
    int index = trouver_index_article(*ref, tRef, tLogArticle);
    while (index == -1) {
        fprintf(stderr, "\x1B[31mERREUR : Article inexistant. Veuillez entrer un numéro valide :\x1B[0m ");
        verifInt(ref);
        index = trouver_index_article(*ref, tRef, tLogArticle);
    }

    printf("\033[32mL'article %d a été supprimé avec succès.\033[0m\n", tRef[index]);

}

void affichModifierArticle(int *ref, float *poids, float *volume, float *prix) {
    printf("\t Quelle est la référence de l'article que vous voulez modifier ?\n");
    verifInt(ref);

    printf("\t Quel est le nouveau poids à entrer ?\n");
    verifFloat(poids);

    printf("\t Quel est le nouveau volume à entrer ?\n");
    verifFloat(volume);

    printf("\t Quel est le nouveau prix à entrer ?\n");
    verifFloat(prix);
}

void affichAjoutClient(int tNumClient[], int tLogique, int *numC) {
    int clientIndex;
    printf("Veuillez entrer le numéro du nouveau client : ");
    verifInt(numC);

    clientIndex = trouver_index_client(*numC, tNumClient, tLogique);

    while (clientIndex != -1) {
        fprintf(stderr, "\x1B[31mERREUR : Client déjà existant. Veuillez entrer un numéro valide :\x1B[0m ");
        verifInt(numC);
        clientIndex = trouver_index_client(*numC, tNumClient, tLogique);
    }

}

int affichageConnexion(void)
{
    char mdpEnter[20];
    char* mdp= getpass("Entrer le mot de passe responsable : ");
//    printf("Entrer le mot de passe responsable : ");
//    scanf("%s", mdpEnter);

    strcpy(mdpEnter, mdp);

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
    int choix, numC, indexClient;
    printf("Entrez le numéro du client : ");
    verifInt(&numC);

    indexClient = trouver_index_client(numC, tNumClient, tLogique);

    while ( indexClient == -1 )
    {
        fprintf(stderr, "\x1B[31mERREUR : Client non trouvé. Veuillez entrer un numéro valide :\x1B[0m ");
        verifInt(&numC);
        indexClient = trouver_index_client(numC, tNumClient, tLogique);
    }

    if ( tSus[indexClient] == 0)
    {
        printf("La cagnotte du client n'est pas suspendu, voulez-vous le suspendre ? ( Oui = 1 / Non = 0 ) : ");
        while(scanf("%d", &choix) != 1 || choix < 0 || choix > 1)
        {
            fprintf(stderr, "\x1B[31mERREUR : Veuillez entrer un choix valide ! : \x1B[0m");
            while (getchar() != '\n');
        }
        if ( choix == 1 )
        {
            tSus[indexClient] = 1;
            printf("La cagnotte est maintenant suspendu\n");
            return;
        }
        else
        {
            printf("La cagnotte n'a pas été changé. Au revoir ! \n");
            return;
        }
    }
    else
    {
        printf("La cagnotte du client %d est suspendue, voulez-vous l'activer à nouveau ? ( Oui = 1 / Non = 0 ) : ", tNumClient[indexClient]);
        while(scanf("%d", &choix) != 1 || choix < 0 || choix > 1)
        {
            fprintf(stderr, "\x1B[31mERREUR : Veuillez entrer un choix valide ! : \x1B[0m");
            while (getchar() != '\n');
        }
        if ( choix == 1 )
        {
            tSus[indexClient] = 0;
            printf("La cagnotte n'est plus suspendu\n");
            return;
        }
        else
        {
            printf("La cagnotte n'a pas été changé. Au revoir ! \n");
            return;
        }
    }
}


void suppressionClient(int tNumClient[], float tCagnotte[], int tSus[], int *tLogique) {
    int choix, numC, indexClient;
    printf("Entrez le numéro du client : ");
    verifInt(&numC);

    indexClient = trouver_index_client(numC, tNumClient, *tLogique);

    while (indexClient == -1)
    {
        fprintf(stderr, "\x1B[31mERREUR : Client %d non trouvé. Veuillez entrer un numéro valide :\x1B[0m ", numC);
        verifInt(&numC);
        indexClient = trouver_index_client(numC, tNumClient, *tLogique);
    }

    printf("Êtes-vous sur de vouloir supprimer ce client ? ( Oui = 1 / Non = 0 ) : ");
    while (scanf("%d", &choix) != 1 || choix < 0 || choix > 1) {
        fprintf(stderr, "\x1B[31mERREUR : Veuillez entrer un choix valide ! : \x1B[0m");
    }

    if (choix == 1) {
        while (indexClient < *tLogique - 1) {
            tNumClient[indexClient] = tNumClient[indexClient + 1];
            tCagnotte[indexClient] = tCagnotte[indexClient + 1];
            tSus[indexClient] = tSus[indexClient + 1];
            indexClient++;
        }
        printf("\033[32mLe client %d a été supprimé avec succès.\033[0m\n", numC);
        (*tLogique)--;
        return;
    } else {
        printf("\t Le client %d n'a pas été supprimé.\n", numC);
        return;
    }

}

void affichModifMDP(void)
{
    int choix, decalage;
    char newMDP[MAX_SIZE_MDP], confirmMDP[MAX_SIZE_MDP];
    printf("\t /!/ Vous entrez dans le menu de modification du mot de passe /!/\n");
    printf("\t Êtes-vous sur de vouloir changer le mot de passe ?\n Si oui, entrez 1 et sinon entrez 0\n");
    while (scanf("%d", &choix) !=1 || choix < 0 || choix > 1)
    {
        fprintf(stderr, "\x1B[31mERREUR : /!/ Entrez une valeur valide : /!/ \x1B[0m");
        while (getchar() != '\n');
    }
    if ( choix == 0 )
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
            printf("\t\033[32mMot de passe modifié avec succès!\033[0m\n");
            return;
        }
        else
        {
            printf("\t/!/ Erreur lors du changement de mot de passe. /!/\n");
            return;
        }
    }
}

void creerReduc( int tRefReduc[], int tReduc[], int *tLogReduc, int tPhysiqueReduc, int tRef[], float tPrix[], int tLogArticle)
{
    int indexPrix, ref;
    float reduc;

    if ( *tLogReduc == tPhysiqueReduc)
    {
        fprintf(stderr, "\x1B[31mERREUR : Tableau pleins !\n \x1B[0m");
        return;
    }

    printf("A quel article voulez-vous ajouter une promotion : ");
    verifInt(&ref);

    int verif = trouver_index_article(ref, tRef, tLogArticle);

    while ( (verif = trouver_index_article(ref, tRef, tLogArticle)) == -1 )
    {
        printf("\x1B[31mERREUR : Entrez une référence existante ! : \x1B[0m");
        verifInt(&ref);
    }

    int verifReducExistante = trouver_index_article(ref, tRefReduc, tLogArticle);

    while ( (verifReducExistante = trouver_index_article(ref, tRefReduc, tLogArticle)) != -1 )
    {
        printf("\x1B[31mERREUR : Cet article est déjà en promotion ! : \x1B[0m");
        verifInt(&ref);
    }
    
    printf("Entrez le pourcentage pourcentage : ");
    while (scanf("%f", &reduc) !=1 || reduc < 0 || reduc > 100)
    {
        printf("\x1B[31mERREUR : Entrez un nombre correcte ! : \x1B[0m");
        while (getchar() != '\n');
    }

    indexPrix = trouver_index_article(ref, tRef, tLogArticle);
    tPrix[indexPrix] = tPrix[indexPrix]*(1-reduc/100);
    tReduc[*tLogReduc] = reduc;
    tRefReduc[*tLogReduc] = ref;
    printf("\n\t\033[32mModification réussi !\033[0m\n\n");
    ++(*tLogReduc);
}

int affichSuprReduc(int tRefReduc[], int tLogReduc, int *indexReduc)
{
    int ref;
    printf("Entrez la référence de l'article auquel il faut supprimer la réduction : ");
    verifInt(&ref);

    while( ( *indexReduc = trouver_index_article(ref, tRefReduc, tLogReduc) )== -1 )
    {
        printf("\x1B[31mERREUR : Entrez une référence qui a une réduction ! : \x1B[0m");
        verifInt(&ref);
    }
    printf("\n\t\033[32mSuppression réussi !\033[0m\n");
    return ref;
}

void menu_resp(int *choix) {
    affiche_resp();
    printf("Vous choisissez: ");
    while (scanf("%d", choix) != 1 || *choix < 0 || *choix > MENU_QUIT) {
        while (getchar() != '\n');
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
    int tRefReduc[MAX_REDUCTION];
    int tReduc[MAX_REDUCTION];

    int tLogArticle = chargementArticles(tRef, tPoids, tVol, tPrix, MAX_ARTICLES);
    int tLogClient = charger_clients(tNumClient, tCagnotte, tSus, MAX_CLIENTS);
    int tLogReduc = chargementReduc(tRefReduc, tReduc, MAX_REDUCTION);
    //system("clear");
    do {
        menu_resp(&choix);
        switch (choix) {


            case 1:
                affichUnClient(tNumClient, tCagnotte, tSus, tLogClient);
                break;
            case 2:
                affichClients(tNumClient, tCagnotte, tSus, tLogClient);
                break;
            case 3:
                ajouterClient(tNumClient, tCagnotte, tSus, &tLogClient);
                break;
            case 4:
                suppressionClient(tNumClient, tCagnotte ,tSus , &tLogClient);
                break;
            case 5:
                affichModifClient(tNumClient, tSus, tLogClient);
                break;
            case 6:
                affichUnArticle(tRef, tPoids, tVol, tPrix, tLogArticle);
                break;
            case 7:
                affichArticles(tRef, tPoids, tVol, tPrix, tLogArticle);
                break;
            case 8:
                ajouterArticle(tRef, tPoids, tVol, tPrix, &tLogArticle, MAX_ARTICLES, ref, poids, volume, prix);
                break;
            case 9:
                supprimerArticle(tRef, tPoids, tVol, tPrix, &tLogArticle);
                break;
            case 10:
                modifierArticle(tRef, tPoids, tVol, tPrix, tLogArticle);
                break;
            case 11:
                creerReduc( tRefReduc, tReduc, &tLogReduc, MAX_REDUCTION, tRef, tPrix, tLogArticle);
                break;
            case 12:
                suppressionReduc(tRefReduc, tReduc, &tLogReduc, tRef, tPrix, tLogArticle);
                break;
            case 13:
                affichModifMDP();
                break;
            case 14:
                sauvegardArticles(tRef, tPoids, tVol, tPrix, tLogArticle);
                sauvegarde_clients(tNumClient, tCagnotte, tSus, tLogClient);
                sauvegardeReduc(tRefReduc, tReduc, tLogReduc);
                printf("Sauvegarde des articles effectuée.\n");
                printf("Sauvegarde des clients effectuée.\n");
                printf("Sauvegarde des réductions effectuée.\n");
                printf("Au revoir !\n");
                return;
            default:
                printf("Veuillez entrer un choix valide ! \n");
                break;
        }
    } while (choix != MENU_QUIT);

}
