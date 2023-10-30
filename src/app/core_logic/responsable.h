#include<stdio.h>

int chargementArticles(int tRef[], float tPoids[], float tVol[], float tPrix[], int tPhysique);
void sauvegardArticles(int tRef[], float tPoids[], float tVol[], float tPrix[], int tLogique);
int ajouterArticle( int tRef[], float tPoids[], float tVol[], float tPrix[], int *tLogique, int tPhysique, int ref, float poids, float volume, float prix);
void rechercheRefArticle(int tRef[], int ref, int *index, int tLogique);
void supprimerArticle(int tRef[], float tPoids[], float tVol[], float tPrix[], int *tLogique);
void modifierArticle(int tRef[], float tPoids[], float tVol[], float tPrix[], int tLogique);
void ajouterClient(int tNumClient[], float tCagnotte[], int tSus[], int *tLogique, int tPhysique);