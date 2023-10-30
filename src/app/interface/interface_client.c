#include "interface_client.h"
#include "app/core_logic/client.h"
#include "app/core_logic/responsable.h"

#define MAX_ARTICLES 100
#define MAX_CLIENTS 100

void affiche_client() {
    printf("\n");
    printf("+-------------+ \n");
    printf("|| Bonjour ! ||\n");
    printf("+-------------+ \n");
    printf("\n");
    printf("+-----------------------------------------------------------------+\n");
    printf("|| Que voulez-vous faire ? \t \t \t \t \t || \n");
    printf("||\t1 : Afficher le récapitulatif du panier. \t \t || \n");
    printf("||\t2 : Ajouter un article au panier. \t \t \t || \n");
    printf("||\t3 : Supprimer un article du panier. \t \t \t || \n");
    printf("||\t4 : Modifier la quantité d'un article du panier. \t || \n");
    printf("||\t5 : Réinitialiser le panier. \t \t \t \t || \n");
    printf("||\t9 : Quitter. \t \t \t \t \t \t || \n");
    printf("+-----------------------------------------------------------------+\n");
}

/*
* Sert à lancer le menu et faire choisir l'utilisateur
*/
void menu_client(int *choix) {
    affiche_client();
    printf("Vous choisissez: ");
    while (scanf("%d", choix) != 1 || *choix < 0 || *choix > 9) {
        while (getchar() != '\n');
        printf("ERREUR : Veuillez entrer un choix valide : ");
    }
}

void global_client() {
    int choix, jour = 0;
    int references[MAX_ARTICLES];
    float poids[MAX_ARTICLES];
    float volume[MAX_ARTICLES];
    float prixUnitaire[MAX_ARTICLES];
    int numeros[MAX_CLIENTS];
    float cagnottes[MAX_CLIENTS];
    int suspendus[MAX_CLIENTS];
    int nombreArticles, nombreClients;
    float volumeCoffre, chargeMaximale;
    int numeroClient;
    int quantites[MAX_ARTICLES];
    int panier[MAX_ARTICLES];
    int taillePanier = 0;

    nombreArticles = chargementArticles(references, poids, volume, prixUnitaire, MAX_ARTICLES);
    nombreClients = charger_clients(numeros, cagnottes, suspendus, MAX_CLIENTS);

    printf("Veuillez saisir la taille disponible du véhicule (en litres) : ");
    while (scanf("%f", &volumeCoffre) != 1 || volumeCoffre <= 0) {
        while (getchar() != '\n');
        printf("ERREUR : Veuillez entrer une taille de coffre valide (en litres) : ");
    }

    printf("Veuillez saisir la charge maximale autorisée (en kg) : ");
    while (scanf("%f", &chargeMaximale) != 1 || chargeMaximale <= 0) {
        while (getchar() != '\n');
        printf("ERREUR : Veuillez entrer une charge maximale valide (en kg) : ");
    }

    printf("Veuillez saisir votre numéro de client : ");
    while (scanf("%d", &numeroClient) != 1) {
        while (getchar() != '\n');
        printf("ERREUR : Veuillez entrer un numéro de client valide : ");
    }

    int indexClient = -1;
    for (int i = 0; i < nombreClients; i++) {
        if (numeros[i] == numeroClient) {
            indexClient = i;
            break;
        }
    }

    if (indexClient == -1) {
        printf("Client non trouvé. Impossible d'utiliser l'application.\n");
        return;
    }

    if (suspendus[indexClient] == 1) {
        printf("Le client est suspendu et ne peut pas utiliser l'application.\n");
        return;
    }

    do{
        menu_client(&choix);

        switch (choix) {
            case 1:
                affiche_recap_panier(panier, taillePanier, references, poids, volume, prixUnitaire, quantites);
                break;
            case 2:
                ajouter_article_au_panier(numeroClient, references, poids, volume, prixUnitaire, numeros, cagnottes,
                                          suspendus, nombreArticles, nombreClients, volumeCoffre, chargeMaximale, panier, quantites, &taillePanier);
                break;
            case 3:
                supprimer_article_du_panier(panier, quantites, &taillePanier);
                break;
            case 4:
                modifier_quantite_article_panier(panier, quantites, &taillePanier);
                break;
            case 5:
                reinitialiser_panier(panier, quantites, &taillePanier);
                break;
            case 9:
                printf("Au revoir !\n");
                return;
            default:
                printf("Veuillez entrer un choix valide !\n");
                break;
        }
    }while(choix != 9);
}

