/**
 * @file main.c
 * @brief Programme principal pour choisir une interface et lancer l'application.
 */

#include <stdio.h>
#include "app/interface/interface_client.h"
#include "app/interface/interface_resp.h"
#include "app/core_logic/responsable.h"

/**
 * @brief Fonction permettant à l'utilisateur de choisir une interface.
 *
 * L'utilisateur peut choisir entre l'interface "responsable" ou "client" en saisissant 1 ou 2.
 * Cette fonction vérifie que l'entrée de l'utilisateur est valide.
 *
 * @return Le choix de l'interface (1 pour responsable, 2 pour client).
 */
int choixInterface(void) {
    int choix;
    printf("Choix de l'interface: \n");
    printf("1. Interface 'responsable': Pour les responsables\n");
    printf("2. Interface 'Client'     : Pour les clients\n");

    while (1) {
        printf("Vous choisissez l'interface n°: ");
        if (scanf("%d", &choix) != 1 || (choix < 1 || choix > 2)) {
            printf("ERREUR : Veuillez entrer un choix valide (1 ou 2) : ");
            while (getchar() != '\n');
        } else {
            break;
        }
    }

    switch (choix) {
        case 1: printf("Vous avez choisi l'interface responsable.\n"); break;
        case 2: printf("Vous avez choisi l'interface client.\n"); break;
    }

    return choix;
}

/**
 * @brief Fonction principale du programme.
 *
 * Cette fonction permet à l'utilisateur de choisir une interface à lancer (responsable ou client)
 * en utilisant la fonction choixInterface(), puis elle lance l'interface correspondante.
 *
 * @return 0 si le programme s'est exécuté avec succès.
 */
int main(void) {
    int verif;
    switch (choixInterface()) {
        case 1:
            verif = affichageConnexion();
            if ( verif == 0)
            {
                global_resp();
                break;
            }
            break;
        case 2:
            global_client();
            break;
    }

    return 0;
}
