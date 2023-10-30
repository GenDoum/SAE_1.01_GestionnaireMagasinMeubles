#include<stdio.h>
#include<stdlib.h>
#include "app/interface/interface_client.h"
#include "app/interface/interface_resp.h"
#include "app/core_logic/client.h"
#include "app/core_logic/responsable.h"

int choixInterface(void) {
    int choix;
    printf("Choix de l'interface: \n");
    printf("1. Interface 'responsable': Pour les responsables \n");
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

int main(){
    switch (choixInterface()) {
        case 1:
            global_resp();
            break;
        case 2:
            global_client();
            break;
    }

    return 0;
}