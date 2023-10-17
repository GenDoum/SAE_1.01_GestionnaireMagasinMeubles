#include<stdio.h>
#include<stdlib.h>
#include "app/interface/interface_client.h"
#include "app/interface/interface_resp.h"
#include "app/core_logic/client.h"

int choixInterface(void) {
    int choix;
    printf("Choix de l'interface: \n");
    printf("• Interface 'responsable' (0, par défaut): Permet de tout faire, via un menu interactif \n");
    printf("• Interface 'Client'       (1)            : Permet de \n");
    printf("Tout autre nombre saisit mène au choix par défaut.\n");
    printf("Vous choisissez l'interface n°: ");
    scanf("%d", &choix);
    if (choix < 0 || choix > 1) choix = 0;
    switch (choix) {
        case 0: printf("Vous avez choisit l'interface par défaut.\n"); break;
        case 1: printf("Vous avez choisit d'effectuer les tests.\n");
    }
    return choix;
}

int main(){
    switch (choixInterface()) {
        case 1: global_client();
    }
    return 0;
}
