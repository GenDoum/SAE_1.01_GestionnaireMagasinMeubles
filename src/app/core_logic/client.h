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
 * @param tNumClient - Un tableau de numéros de clients.
 * @param tCagnotte - Un tableau de cagnottes des clients.
 * @param tSus - Un tableau d'état des clients suspendus.
 * @param tPhysique - La taille physique du tableau des clients.
 *
 * @return Le nombre de clients chargés depuis le fichier.
 */
int charger_clients(int tNumClient[], float tCagnotte[], int tSus[], int tPhysique);

/**
 * @brief Sauvegarder les données des clients dans un fichier.
 *
 * @param tNumClient - Un tableau de numéros de clients.
 * @param tCagnotte - Un tableau de cagnottes des clients.
 * @param tSus - Un tableau d'état des clients suspendus.
 * @param tLogClient - Le nombre total de clients.
 */
void sauvegarde_clients(int tNumClient[], float tCagnotte[], int tSus[], int tLogClient);

/**
 * @brief Trouver l'index d'une référence d'article dans un tableau.
 *
 * @param reference - La référence de l'article à rechercher.
 * @param tRef - Un tableau de références d'articles.
 * @param tLogArticle - Le nombre total d'articles.
 *
 * @return L'index de la référence dans le tableau ou -1 si la référence n'est pas trouvée.
 */
int trouver_index_article(int reference, int tRef[], int tLogArticle);

/**
 * @brief Trouver l'index d'un numéro de client dans un tableau.
 *
 * @param numClient - Le numéro de client à rechercher.
 * @param tNumClient - Un tableau de numéros de clients.
 * @param tLogClient - Le nombre total de clients.
 *
 * @return L'index du numéro de client dans le tableau ou -1 si le numéro de client n'est pas trouvé.
 */
int trouver_index_client(int numClient, int tNumClient[], int tLogClient);

/**
 * @brief Supprimer un article du panier du client.
 *
 * @param tPanier - Le panier d'achat du client.
 * @param tQuantite - Un tableau de quantités d'articles dans le panier.
 * @param[out] tLogPanier - Un pointeur pour stocker la taille du panier.
 * @param reference - La référence de l'article à supprimer.
 * @param numClient - Le numéro du client.
 * @param tNumClient - Un tableau de numéros de clients.
 * @param tLogClient - Le nombre total de clients.
 * @param tRef - Un tableau de références d'articles.
 * @param tPrixUnitaire - Un tableau de prix unitaires d'articles.
 * @param tCagnotte - Un tableau de cagnottes des clients.
 */
void supprimer_article(int tPanier[], int tQuantite[], int *tLogPanier, int reference, int numClient, int tNumClient[], int tLogClient, int tRef[], float tPrixUnitaire[], float tCagnotte[]);

/**
 * @brief Vérifie l'entrée utilisateur pour un entier.
 *
 * @param var une variable de type int
 */
void verifInt(int *var);

/**
 * @brief Vérifie l'entrée utilisateur pour un float.
 *
 * @param var une variable de type float
 */
void verifFloat(float *var);

#endif // CLIENT_H