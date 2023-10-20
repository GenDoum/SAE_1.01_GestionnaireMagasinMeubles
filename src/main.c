#include<stdio.h>
#include<stdlib.h>
#include "app/interface/interface_client.h"
#include "app/interface/interface_resp.h"
#include "app/core_logic/client.h"

int choixInterface(void) {
    int choix;
    printf("Choix de l'interface: \n");
    printf("1. Interface 'responsable': Pour les responsables \n");
    printf("2. Interface 'Client'     : Pour les clients\n");
    printf("Vous choisissez l'interface n°: ");
    scanf("%d", &choix);
    if (choix < 0 || choix > 1) {
        fprintf(stderr,"Veuillez entrer un choix valide ! \n");
    }
    switch (choix) {
        case 1: printf("Vous avez choisit l'interface responsable.\n"); break;
        case 2: printf("Vous avez choisit l'interface client.\n");
    }
    return choix;
}

int main(){
    switch (choixInterface()) {
        //case 1: global_resp();
        case 2: global_client();
    }
    return 0;
}
