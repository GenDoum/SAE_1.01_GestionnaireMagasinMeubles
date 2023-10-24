#include "interface_client.h"
#include "app/core_logic/client.h"

void affiche_client(int a){
    printf("\n");
    printf("+-------------+ \n");
    printf("|| Bonjour ! ||\n") ;
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
    int choix, jour;
    menu_client(&choix, jour);
    switch (choix) {
        case 1:
            afficherDonneesClient();
            break;
        default:
            printf("Veuillez entrer un choix valide !\n");
            break;
    }
}