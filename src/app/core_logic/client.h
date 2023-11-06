/**
 * @file client.h
 * @brief Fichier d'en-tête pour les fonctions de gestion des clients.
 *
 * Ce fichier d'en-tête définit les fonctions liées à la gestion des clients, telles que le chargement des clients, la sauvegarde, etc.
 *
 * @author Hersan Mathéo
 */

#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include "../interface/interface_client.h"

/**
 * @brief Charger les données des clients depuis un fichier.
 *
 * @param numeros - Un tableau de numéros de clients.
 * @param cagnottes - Un tableau de cagnottes des clients.
 * @param suspendues - Un tableau d'état des clients suspendus.
 * @param tPhysique - La taille physique du tableau des clients.
 *
 * @return Le nombre de clients chargés depuis le fichier.
 */
int charger_clients(int numeros[], float cagnottes[], int suspendues[], int tPhysique);

/**
 * @brief Sauvegarder les données des clients dans un fichier.
 *
 * @param numeros - Un tableau de numéros de clients.
 * @param cagnottes - Un tableau de cagnottes des clients.
 * @param suspendus - Un tableau d'état des clients suspendus.
 * @param nombreClients - Le nombre total de clients.
 */
void sauvegarde_clients(int numeros[], float cagnottes[], int suspendus[], int nombreClients);

/**
 * @brief Supprimer un article du panier du client.
 *
 * @param panier - Le panier d'achat du client.
 * @param quantites - Un tableau de quantités d'articles dans le panier.
 * @param[out] taillePanier - Un pointeur pour stocker la taille du panier.
 * @param reference - La référence de l'article à supprimer.
 * @param numeroClient - Le numéro du client.
 * @param numeros - Un tableau de numéros de clients.
 * @param nombreClients - Le nombre total de clients.
 * @param references - Un tableau de références d'articles.
 * @param prixUnitaire - Un tableau de prix unitaires d'articles.
 * @param cagnottes - Un tableau de cagnottes des clients.
 */
void supprimer_article(int panier[], int quantites[], int *taillePanier, int reference, int numeroClient, int numeros[], int nombreClients, int references[], float prixUnitaire[], float cagnottes[]);

/**
 * @brief Trouver l'index d'une référence d'article dans un tableau.
 *
 * @param reference - La référence de l'article à rechercher.
 * @param references - Un tableau de références d'articles.
 * @param nombreArticles - Le nombre total d'articles.
 *
 * @return L'index de la référence dans le tableau ou -1 si la référence n'est pas trouvée.
 */
int trouver_index_article(int reference, int references[], int nombreArticles);

/**
 * @brief Trouver l'index d'un numéro de client dans un tableau.
 *
 * @param numeroClient - Le numéro de client à rechercher.
 * @param numeros - Un tableau de numéros de clients.
 * @param nombreClients - Le nombre total de clients.
 *
 * @return L'index du numéro de client dans le tableau ou -1 si le numéro de client n'est pas trouvé.
 */
int trouver_index_client(int numeroClient, int numeros[], int nombreClients);

#endif // CLIENT_H
