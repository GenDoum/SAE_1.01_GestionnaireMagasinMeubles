/**
 * @file interface_client.h
 * @brief En-tête des fonctions liées à l'interface client.
 */

#include <stdio.h>
#include "../core_logic/client.h"
#include "../core_logic/responsable.h"

/**
 * @brief Affiche le menu principal de l'interface client.
 */
void affiche_client();

/**
 * @brief Laisse l'utilisateur choisir une option du menu.
 *
 * @param[in, out] choix - L'option choisie par l'utilisateur.
 */
void menu_client(int *choix);


/**
 * @brief Ajoute un article au panier du client.
 *
 * Cette fonction permet d'ajouter un article au panier du client.
 *
 * @param numeroClient - Numéro du client.
 * @param references - Tableau des références des articles.
 * @param poids - Tableau des poids des articles.
 * @param volume - Tableau des volumes des articles.
 * @param prixUnitaire - Tableau des prix unitaires des articles.
 * @param numeros - Tableau des numéros de clients.
 * @param cagnottes - Tableau des cagnottes des clients.
 * @param suspendues - Tableau des états de suspension des clients.
 * @param nombreArticles - Nombre d'articles disponibles.
 * @param nombreClients - Nombre de clients.
 * @param volumeCoffre - Volume total du coffre.
 * @param chargeMaximale - Charge maximale du coffre.
 * @param panier - Tableau des références des articles dans le panier.
 * @param quantites - Tableau des quantités de chaque article dans le panier.
 * @param taillePanier - Taille du panier.
 * @param budget - Budget du client.
 */
void ajouter_article_au_panier(int numeroClient, int references[], float poids[], float volume[], float prixUnitaire[],
                               int numeros[], float cagnottes[], int suspendues[], int nombreArticles, int nombreClients,
                               float volumeCoffre, float chargeMaximale, int panier[], int quantites[], int *taillePanier, float budget);


/**
 * @brief Supprime un article du panier du client.
 *
 * Cette fonction permet de supprimer un article du panier du client.
 *
 * @param panier - Tableau des références des articles dans le panier.
 * @param quantites - Tableau des quantités de chaque article dans le panier.
 * @param taillePanier - Taille du panier.
 */
//void supprimer_article_du_panier(int panier[], int quantites[], int *taillePanier, float prixUnitaire[], int clientIndex, float cagnottes[]);

void supprimer_article_du_panier(int panier[], int quantites[], int *taillePanier, float cagnottes[], int numeroClient, int numeros[], int nombreClients, int references[], float prixUnitaire[]);

/**
 * @brief Affiche un récapitulatif du contenu du panier.
 *
 * Cette fonction permet d'afficher un récapitulatif détaillé du contenu du panier du client, y compris les références des articles,
 * les quantités, les poids, les volumes, les prix unitaires, les totaux de poids, de volume, de prix, et la cagnotte du client.
 *
 * @param panier - Tableau des références des articles dans le panier.
 * @param taillePanier - Taille du panier.
 * @param references - Tableau des références des articles.
 * @param poids - Tableau des poids des articles.
 * @param volume - Tableau des volumes des articles.
 * @param prixUnitaire - Tableau des prix unitaires des articles.
 * @param quantites - Tableau des quantités de chaque article dans le panier.
 * @param cagnottes - Tableau des cagnottes des clients.
 * @param numeroClient - Numéro du client.
 * @param numeros - Tableau des numéros de clients.
 * @param nombreClients - Nombre de clients.
 * @param volumeCoffre - Volume total du coffre.
 * @param chargeMaximale - Charge maximale du coffre.
 */

void affiche_recap_panier(int panier[], int taillePanier, int references[], float poids[], float volume[],
                          float prixUnitaire[], int quantites[], float cagnottes[], int numeroClient,
                          int numeros[], int nombreClients, float volumeCoffre, float chargeMaximale);

/**
 * @brief Affiche le récapitulatif du panier.
 *
 * Cette fonction affiche le récapitulatif du panier, y compris les références, les poids, les volumes, les prix unitaires, elle permet d'initialiser la session du client.
 *
 * @param numeros
 * @param suspendus
 * @param nombreClients
 * @param budget
 * @param volumeCoffre
 * @param chargeMaximale
 * @param numeroClient
 */
void configurer_session_client(int numeros[], int suspendus[], int nombreClients, double *budget, float *volumeCoffre, float *chargeMaximale, int *numeroClient);


/**
 * @brief Modifie la quantité d'un article dans le panier du client.
 *
 * Cette fonction permet de modifier la quantité d'un article dans le panier du client tout en mettant à jour la cagnotte.
 *
 * @param panier - Tableau des références des articles dans le panier.
 * @param quantites - Tableau des quantités de chaque article dans le panier.
 * @param taillePanier - Taille du panier.
 * @param cagnottes - Tableau des cagnottes des clients.
 * @param numeroClient - Numéro du client.
 * @param prixUnitaire - Tableau des prix unitaires des articles.
 * @param references - Tableau des références des articles.
 * @param nombreClients - Nombre de clients.
 * @param numeros - Tableau des numéros de clients.
 */
void modifier_quantite_article_panier(int panier[], int quantites[], int *taillePanier, float cagnottes[], int numeroClient, float prixUnitaire[], int references[], int nombreClients, int numeros[]);

/**
 * @brief Réinitialise le panier du client.
 *
 * @param panier - Tableau des références des articles dans le panier.
 * @param quantites - Tableau des quantités de chaque article dans le panier.
 * @param taillePanier - Taille du panier.
 */
void reinitialiser_panier(int panier[], int quantites[], int *taillePanier, float cagnottes[], int numeroClient, int numeros[], int nombreClients, int references[], float prixUnitaire[]);

/**
 * @brief Déduit un montant de la cagnotte du client.
 *
 * @param numeroClient - Numéro du client.
 * @param montant - Montant à déduire de la cagnotte.
 * @param numeros - Tableau des numéros de clients.
 * @param cagnottes - Tableau des cagnottes des clients.
 * @param nombreClients - Nombre de clients.
 * @param suspendus - Tableau des états de suspension des clients.
 */
void deduire_cagnotte(int numeroClient, float montant, int numeros[], float cagnottes[], int nombreClients, int suspendus[]);


/**
 * @brief Fonction principale de l'interface client.
 *
 * Cette fonction permet aux clients d'utiliser l'application pour gérer leur panier
 * et effectuer des opérations telles que l'ajout, la suppression ou la modification
 * d'articles dans le panier.
 */
void global_client();

