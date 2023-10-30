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
 */
void ajouter_article_au_panier(int numeroClient, int references[], float poids[], float volume[], float prixUnitaire[],
                               int numeros[], float cagnottes[], int suspendues[], int nombreArticles, int nombreClients,
                               float volumeCoffre, float chargeMaximale, int panier[], int quantites[], int *taillePanier);

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
 * @param panier - Tableau des références des articles dans le panier.
 * @param taillePanier - Taille du panier.
 * @param references - Tableau des références des articles.
 * @param poids - Tableau des poids des articles.
 * @param volume - Tableau des volumes des articles.
 * @param prixUnitaire - Tableau des prix unitaires des articles.
 * @param quantites - Tableau des quantités de chaque article dans le panier.
 */
void affiche_recap_panier(int panier[], int taillePanier, int references[], float poids[], float volume[],
                          float prixUnitaire[], int quantites[]);

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

#endif // SAE_101_CLIENT_H
