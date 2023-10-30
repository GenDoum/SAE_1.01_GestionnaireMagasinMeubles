/**
 * @file responsable.h
 * @brief Déclaration des fonctions de responsable.c.
 */

#include <stdio.h>

/**
 * @brief Charge les informations des articles à partir d'un fichier dans des tableaux.
 *
 * Cette fonction lit les informations des articles à partir du fichier "donnee/articles.txt" et les stocke
 * dans les tableaux tRef, tPoids, tVol, et tPrix.
 *
 * @param tRef Tableau des références d'articles.
 * @param tPoids Tableau des poids des articles.
 * @param tVol Tableau des volumes des articles.
 * @param tPrix Tableau des prix unitaires des articles.
 * @param tPhysique Taille physique des tableaux.
 * @return Le nombre d'articles chargés avec succès ou -1 en cas d'erreur.
 */
int chargementArticles(int tRef[], float tPoids[], float tVol[], float tPrix[], int tPhysique);

/**
 * @brief Sauvegarde les informations des articles dans un fichier.
 *
 * Cette fonction sauvegarde les informations des articles depuis les tableaux tRef, tPoids, tVol et tPrix
 * dans le fichier "donnee/articles.txt".
 *
 * @param tRef Tableau des références d'articles.
 * @param tPoids Tableau des poids des articles.
 * @param tVol Tableau des volumes des articles.
 * @param tPrix Tableau des prix unitaires des articles.
 * @param tLogique Taille logique des tableaux.
 */
void sauvegardArticles(int tRef[], float tPoids[], float tVol[], float tPrix[], int tLogique);

/**
 * @brief Ajoute un nouvel article aux tableaux d'articles.
 *
 * Cette fonction ajoute un nouvel article aux tableaux tRef, tPoids, tVol, et tPrix et incrémente la taille logique.
 *
 * @param tRef Tableau des références d'articles.
 * @param tPoids Tableau des poids des articles.
 * @param tVol Tableau des volumes des articles.
 * @param tPrix Tableau des prix unitaires des articles.
 * @param tLogique Taille logique des tableaux.
 * @param tPhysique Taille physique des tableaux.
 * @param ref Référence du nouvel article.
 * @param poids Poids du nouvel article.
 * @param volume Volume du nouvel article.
 * @param prix Prix unitaire du nouvel article.
 * @return 0 en cas de succès, -2 si le tableau est plein.
 */
int ajouterArticle(int tRef[], float tPoids[], float tVol[], float tPrix[], int *tLogique, int tPhysique, int ref, float poids, float volume, float prix);

/**
 * @brief Recherche une référence d'article dans le tableau tRef.
 *
 * Cette fonction recherche une référence d'article dans le tableau tRef et renvoie l'index si l'article est trouvé.
 *
 * @param tRef Tableau des références d'articles.
 * @param ref Référence de l'article à rechercher.
 * @param index Pointeur vers la variable pour stocker l'index de l'article trouvé.
 * @param tLogique Taille logique des tableaux.
 */
void rechercheRefArticle(int tRef[], int ref, int *index, int tLogique);

/**
 * @brief Supprime un article des tableaux d'articles.
 *
 * Cette fonction supprime un article des tableaux tRef, tPoids, tVol, et tPrix et met à jour la taille logique.
 *
 * @param tRef Tableau des références d'articles.
 * @param tPoids Tableau des poids des articles.
 * @param tVol Tableau des volumes des articles.
 * @param tPrix Tableau des prix unitaires des articles.
 * @param tLogique Pointeur vers la taille logique des tableaux.
 */
void supprimerArticle(int tRef[], float tPoids[], float tVol[], float tPrix[], int *tLogique);

/**
 * @brief Modifie les informations d'un article existant.
 *
 * Cette fonction permet de modifier les informations (poids, volume, prix) d'un article existant.
 *
 * @param tRef Tableau des références d'articles.
 * @param tPoids Tableau des poids des articles.
 * @param tVol Tableau des volumes des articles.
 * @param tPrix Tableau des prix unitaires des articles.
 * @param tLogique Taille logique des tableaux.
 */
void modifierArticle(int tRef[], float tPoids[], float tVol[], float tPrix[], int tLogique);

/**
 * @brief Ajoute un nouveau client aux tableaux de clients.
 *
 * Cette fonction ajoute un nouveau client aux tableaux tNumClient, tCagnotte et tSus et incrémente la taille logique.
 *
 * @param tNumClient Tableau des numéros de client.
 * @param tCagnotte Tableau des cagnottes des clients.
 * @param tSus Tableau des états de suspension des clients.
 * @param tLogique Pointeur vers la taille logique des tableaux.
 * @param tPhysique Taille physique des tableaux.
 */
void ajouterClient(int tNumClient[], float tCagnotte[], int tSus[], int *tLogique, int tPhysique);
