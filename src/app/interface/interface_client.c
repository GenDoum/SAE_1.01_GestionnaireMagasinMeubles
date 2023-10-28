#include "interface_client.h"
#include "app/core_logic/client.h"
#include "app/core_logic/responsable.h"

#define MAX_ARTICLES 100
#define MAX_CLIENTS 100

void affiche_client(int a) {
    printf("\n");
    printf("+-------------+ \n");
    printf("|| Bonjour ! ||\n");
    printf("+-------------+ \n");
    printf("\n");
    printf("+-----------------------------------------------------------------+\n");
    printf("|| Que voulez-vous faire ? \t \t \t \t \t || \n");
    printf("||\t1 : Afficher le récapitulatif du panier. \t \t || \n");
    printf("||\t2 : Ajouter un article du panier. \t \t \t || \n");
    printf("||\t3 : Supprimer un article du panier. \t \t \t || \n");
    printf("||\t4 : Modifier la quantité d'un article du panier. \t || \n");
    printf("||\t5 : Réinitialiser le panier. \t \t \t \t || \n");
    printf("+-----------------------------------------------------------------+\n");
}

/*
* Sert à lancer le menu et faire choisir l'utilisateur
*/
void menu_client(int *choix, int jour) {
    affiche_client(jour);
    printf("Vous choisissez: ");
    while (scanf("%d", choix) != 1 || *choix < 0 || *choix > 5) {
        while (getchar() != '\n');  // Nettoie le tampon d'entrée en cas de saisie invalide
        affiche_client(jour);
        printf("Veuillez entrer un choix valide : ");
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
    int suspendus[MAX_CLIENTS];  // Ajout du tableau des clients suspendus
    int nombreArticles, nombreClients;
    float volumeCoffre, chargeMaximale;
    int numeroClient;

    nombreArticles = chargementArticles(references, poids, volume, prixUnitaire, MAX_ARTICLES);
    nombreClients = charger_clients(numeros, cagnottes, suspendus, MAX_CLIENTS);

    menu_client(&choix, jour);
    switch (choix) {
        case 1:
            affiche_client(jour);
            break;
        case 2:
            // Ajouter la logique d'interface pour ajouter un article au panier ici
            ajouter_article_au_panier(numeroClient, references, poids, volume, prixUnitaire, numeros, cagnottes,
                                      suspendus, nombreArticles, nombreClients, volumeCoffre, chargeMaximale);
            break;
        case 3:
            // Ajouter la logique d'interface pour supprimer un article du panier ici
            //supprimer_article_du_panier(panier, &taillePanier);
            break;
        default:
            printf("Veuillez entrer un choix valide !\n");
            break;
    }
}
