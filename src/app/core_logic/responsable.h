#include<stdio.h>

int chargementArticles(int tRef[], float tPoids[], float tVol[], float tPrix[], int tPhysique);
void sauvegardArticles(int tRef[], float tPoids[], float tVol[], float tPrix[], int tLogique);
int ajouterArticle( int tRef[], float tPoids[], float tVol[], float tPrix[], int *tLogique, int tPhysique, int ref, float poids, float volume, float prix);