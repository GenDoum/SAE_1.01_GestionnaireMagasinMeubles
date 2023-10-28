//
// Created by Mathéo Hersan on 16/10/2023.
//

#ifndef SAE_101_CLIENT_H
#define SAE_101_CLIENT_H

#include<stdio.h>
#include<stdlib.h>

int charger_clients(int numeros[], float cagnottes[], int suspendues[], int tPhysique);
void ajouter_article_au_panier(int numeroClient, int references[], float poids[], float volume[], float prixUnitaire[],
                               int numeros[], float cagnottes[], int suspendues[], int nombreArticles, int nombreClients,
                               float volumeCoffre, float chargeMaximale, int panier[], int quantites[], int *taillePanier);
void supprimer_article_du_panier(int panier[], int *taillePanier);
void affiche_recap_panier(int panier[], int taillePanier, int references[], float poids[], float volume[],
                          float prixUnitaire[], int quantites[]);
#endif //SAE_101_CLIENT_H
