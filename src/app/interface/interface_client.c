#include "interface_client.h"

void affiche_client(){
    printf("\n");
    printf("--------------- \n");
    printf("|| Bonjour ! ||\n") ;
    printf("--------------- \n");
    printf("\n");
    printf("-------------------------------------------------------------------\n");
    printf("|| Que voulez-vous faire ? \t \t \t \t \t || \n") ;
    printf("||\t1 : Afficher le récapitulatif du panier. \t \t || \n") ;
    printf("-------------------------------------------------------------------\n");
}

/*
* Sert à lancer le menu et faire choisir l'utilisateur
*/
void menu(int *choix) {
    affiche_client();
    printf("Vous choisissez: ");
    scanf("%d", choix);

    while (*choix == 1)
    {
        affiche_client();
        printf("Vous choisissez: ");
        printf("Veuillez entrer un choix valide ! \n");
        scanf("%d", choix);
    }
}