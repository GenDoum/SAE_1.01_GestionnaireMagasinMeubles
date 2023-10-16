#include<stdio.h>
#include<stdlib.h>
#include "app/interface/interface_client.h"
#include "app/interface/interface_resp.h"
#include "app/core_logic/client.h"

int main(){
    int choix;

    menu(&choix);
    afficherDonneesClient();
}
