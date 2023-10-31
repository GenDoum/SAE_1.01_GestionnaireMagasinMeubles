#ifndef SAE_101_CLIENT_H
#define SAE_101_CLIENT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @file client.h
 * @brief Fonctions liées à la gestion des clients et de leur panier.
 */

/**
 * @brief Charge les données des clients à partir d'un fichier.
 *
 * @param numeros - Tableau des numéros de clients.
 * @param cagnottes - Tableau des cagnottes des clients.
 * @param suspendues - Tableau des états de suspension des clients.
 * @param tPhysique - Taille du tableau physique.
 * @return Le nombre de clients chargés ou -1 en cas d'erreur.
 */
int charger_clients(int numeros[], float cagnottes[], int suspendues[], int tPhysique);


/**
 * @brief Sauvegarde les données clients dans un fichier.
 *
 * Cette fonction permet de sauvegarder les données clients, y compris les numéros de clients, les cagnottes,
 * et les états de suspension, dans un fichier texte.
 *
 * @param numeros - Tableau des numéros de clients.
 * @param cagnottes - Tableau des cagnottes des clients.
 * @param suspendus - Tableau des états de suspension des clients.
 * @param nombreClients - Nombre de clients.
 */
void sauvegarde_clients(int numeros[], float cagnottes[], int suspendus[], int nombreClients);

/**
 * @brief Ajoute un article au panier du client.
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
 * @param panier - Tableau des références des articles dans le panier.
 * @param quantites - Tableau des quantités de chaque article dans le panier.
 * @param taillePanier - Taille du panier.
 */
void supprimer_article_du_panier(int panier[], int quantites[], int *taillePanier);

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
 * @brief Modifie la quantité d'un article dans le panier du client.
 *
 * @param panier - Tableau des références des articles dans le panier.
 * @param quantites - Tableau des quantités de chaque article dans le panier.
 * @param taillePanier - Taille du panier.
 */
void modifier_quantite_article_panier(int panier[], int quantites[], int *taillePanier);

/**
 * @brief Réinitialise le panier du client.
 *
 * @param panier - Tableau des références des articles dans le panier.
 * @param quantites - Tableau des quantités de chaque article dans le panier.
 * @param taillePanier - Taille du panier.
 */
void reinitialiser_panier(int panier[], int quantites[], int *taillePanier);

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
 * @brief Recherche l'index de l'article dans le tableau des références.
 *
 * Cette fonction recherche l'index de l'article avec la référence donnée dans le tableau des références.
 *
 * @param reference - Référence de l'article à rechercher.
 * @param references - Tableau des références des articles.
 * @param nombreArticles - Nombre d'articles disponibles.
 * @return L'index de l'article s'il est trouvé, sinon -1.
 */
int trouver_index_article(int reference, int references[], int nombreArticles);

/**
 * @brief Trouve l'index d'un client dans le tableau des numéros de clients.
 *
 * Cette fonction recherche le numéro du client dans le tableau des numéros de clients
 * et retourne l'index du client s'il est trouvé.
 *
 * @param numeroClient - Numéro du client à rechercher.
 * @param numeros - Tableau des numéros de clients.
 * @param nombreClients - Nombre de clients dans le tableau.
 * @return L'index du client s'il est trouvé, -1 sinon.
 */
int trouver_index_client(int numeroClient, int numeros[], int nombreClients);

#endif // SAE_101_CLIENT_H
