#ifndef SAE_101_CLIENT_H
#define SAE_101_CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include "../interface/interface_client.h"

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
 * @brief Supprime un article du panier du client.
 *
 * Cette fonction permet de supprimer un article du panier du client tout en metant a jour la cagnotte.
 *
 * @param panier
 * @param quantites
 * @param taillePanier
 * @param reference
 * @param numeroClient
 * @param numeros
 * @param nombreClients
 * @param references
 * @param prixUnitaire
 * @param cagnottes
 */
void supprimer_article(int panier[], int quantites[], int *taillePanier, int reference, int numeroClient, int numeros[], int nombreClients, int references[], float prixUnitaire[], float cagnottes[]);

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
