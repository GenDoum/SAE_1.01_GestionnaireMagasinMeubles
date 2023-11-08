/**
 * @file interface_resp.h
 * @brief En-tête des fonctions liées à l'interface du responsable.
 */

#include <stdio.h>
#include <unistd.h>
#include "../core_logic/responsable.h"
#include "../core_logic/client.h"

/**
 * @brief Affiche la liste des articles.
 * 
 * @param tRef - Tableau des références des articles.
 * @param tPoids - Tableau des poids des articles.
 * @param tVol - Tableau des volumes des articles.
 * @param tPrix - Tableau des prix des articles.
 * @param tLogique - Nombre d'articles actuellement enregistrés.
 */
void affichArticles(int tRef[], float tPoids[], float tVol[], float tPrix[], int tLogique);

/**
 * @brief Affiche les informations d'un article spécifique.
 * 
 * @param tRef - Tableau des références des articles.
 * @param tPoids - Tableau des poids des articles.
 * @param tVol - Tableau des volumes des articles.
 * @param tPrix - Tableau des prix des articles.
 * @param tLogique - Nombre d'articles actuellement enregistrés.
 */
void affichUnArticle(int tRef[], float tPoids[], float tVol[], float tPrix[], int tLogique);

/**
 * @brief Affiche les informations d'un client spécifique.
 * 
 * @param tNumClient - Tableau des numéros de clients.
 * @param tCagnotte - Tableau des cagnottes des clients.
 * @param tSus - Tableau des états de suspension des clients.
 * @param tLogique - Nombre de clients actuellement enregistrés.
 */
void affichUnClient(int tNumClient[], float tCagnotte[], int tSus[], int tLogique);

/**
 * @brief Affiche la liste des clients.
 * 
 * @param tNumClient - Tableau des numéros de clients.
 * @param tCagnotte - Tableau des cagnottes des clients.
 * @param tSus - Tableau des états de suspension des clients.
 * @param tLogique - Nombre de clients actuellement enregistrés.
 */
void affichClients(int tNumClient[], float tCagnotte[], int tSus[], int tLogique);

/**
 * @brief Affiche les informations nécessaires pour ajouter un nouvel article.
 * 
 * @param ref - Référence du nouvel article.
 * @param poids - Poids du nouvel article.
 * @param volume - Volume du nouvel article.
 * @param prix - Prix du nouvel article.
 * @param tRef - Tableau de référence des articles.
 * @param tLogArticle - Taille logique du tableau des références.
 */
void affichAjoutArticle(int *ref, float *poids, float *volume, float *prix, int tRef[], int tLogArticle);

/**
 * @brief Affiche les informations nécessaires pour supprimer un article.
 * 
 * @param ref - Référence de l'article à supprimer.
 * @param tLogArticle - Taille logique du tableau des références.
 * @param tRef - Tableau des références.
 */
void affichSupprimerArticle(int *ref, int tLogArticle, int tRef[]);

/**
 * @brief Affiche les informations nécessaires pour modifier un article.
 * 
 * @param ref - Référence de l'article à modifier.
 * @param poids - Nouveau poids de l'article.
 * @param volume - Nouveau volume de l'article.
 * @param prix - Nouveau prix de l'article.
 */
void affichModifierArticle(int *ref, float *poids, float *volume, float *prix);

/**
 * @brief Affiche un message en cas de problème lors de la recherche d'un article.
 * 
 */
void problemRechercheArticle(void);

/**
 * @brief Affiche les informations nécessaires pour ajouter un nouveau client.
 *
 * @param tNumClient - Tableau des numéros de clients.
 * @param tLogique - Nombre de clients actuellement enregistrés.
 * @param numC - Numéro du nouveau client.
 */
void affichAjoutClient(int tNumClient[], int tLogique, int *numC);

/**
 * @brief Laisse le responsable choisir une option du menu.
 *
 * @param[in, out] choix - L'option choisie par le responsable.
 */
void menu_resp(int *choix);


/**
 * @brief Affiche les informations nécessaires pour entrer le mod de passe responsable.
 *
 * Cette fonction permet au responsable de confirmer son identité
*/
int affichageConnexion(void);

/**
 * @brief Affiche le menu qui permet de modifier l'état de la cagnotte d'un client.
 * 
*/
void affichModifClient(int tNumClient[], int tSus[], int tLogique);

/**
 * @brief Fonction principale de l'interface du responsable.
 *
 * Cette fonction permet au responsable d'effectuer diverses actions telles que la gestion des articles et des clients.
 */
void global_resp(void);

/**
 * @brief Affiche le menu principal de l'interface du responsable.
 */
void affiche_resp(void);

void creerReduc( int tRefReduc[], int tReduc[], int *tLogReduc, int tPhysiqueReduc, int tRef[], float tPrix[], int tLogArticle);
int affichSuprReduc(int tRefReduc[], int tLogReduc, int *indexReduc);
