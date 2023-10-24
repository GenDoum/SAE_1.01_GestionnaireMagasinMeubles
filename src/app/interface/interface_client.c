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
>>>>>>> 91542d8 (fixed some bugs on resp. Added global_resp and added error handling for char)
    affiche_client(jour);
    printf("Vous choisissez: ");
    while (scanf("%d", choix) != 1 || *choix < 0 || *choix > 5) {
        while (getchar() != '\n');  // Nettoie le tampon d'entrée en cas de saisie invalide
        affiche_client(jour);
        printf("Veuillez entrer un choix valide : ");
    }
}

void demander_article(int reference, float poids, float volume, int prixUnitaire){

    printf("Vous avez choisi d'ajouter un article au panier.\n");
    printf("Veuillez entrer la référence de l'article que vous souhaitez ajouter au panier : ");
    scanf("%d", &reference);
    printf("Veuillez entrer le poids de l'article que vous souhaitez ajouter au panier : ");
    scanf("%f", &poids);
    printf("Veuillez entrer le volume de l'article que vous souhaitez ajouter au panier : ");
    scanf("%f", &volume);
    printf("Veuillez entrer le prix unitaire de l'article que vous souhaitez ajouter au panier : ");
    scanf("%d", &prixUnitaire);
    printf("L'article a bien été ajouté au panier.\n");
    printf("Voici le récapitulatif du panier : \n");
    printf("Référence : %d \n", reference);
    printf("Poids : %f \n", poids);
    printf("Volume : %f \n", volume);
    printf("Prix unitaire : %d \n", prixUnitaire);
}

void global_client(){
    int choix, jour = 0, reference = 0;
    float poids = 0.0, volume = 0.0, prixUnitaire = 0.0;
    menu_client(&choix, jour);
    switch (choix) {
        case 1:
            affiche_client(jour);
            break;
        case 2:
            demander_article(reference, poids, volume, prixUnitaire);
            break;
        default:
            printf("Veuillez entrer un choix valide !\n");
            break;
    }
}