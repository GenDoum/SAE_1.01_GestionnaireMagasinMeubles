/**
 * @file interface_client.h
 * @brief Fichier d'en-tête pour les fonctions de l'interface client.
 *
 * Ce fichier d'en-tête définit les fonctions liées à l'interaction et à la gestion des clients.
 * Ces fonctions incluent des opérations telles que l'ajout d'articles au panier d'un client, la gestion du budget, etc.
 *
 * @author Hersan Mathéo
 */

#ifndef INTERFACE_CLIENT_H
#define INTERFACE_CLIENT_H

#include <stdio.h>
#include <string.h>
#include "../core_logic/client.h"
#include "../core_logic/responsable.h"
#include "../interface/interface_resp.h"

/**
 * @brief Afficher les informations du client.
 */
void affiche_client(void);

/**
 * @brief Ajouter des articles au panier du client.
 *
 * @param numClient - Le numéro du client.
 * @param tRef - Un tableau de références d'articles.
 * @param tPoids - Un tableau de poids d'articles.
 * @param tVol - Un tableau de volumes d'articles.
 * @param tPrixUnitaire - Un tableau de prix unitaires d'articles.
 * @param tNumClient - Un tableau de numéros d'articles.
 * @param tCagnotte - Un tableau de cagnottes.
 * @param tLogArticle - Le nombre total d'articles disponibles.
 * @param tLogClient - Le nombre total de clients.
 * @param volumeCoffre - La limite de volume pour le panier du client.
 * @param chargeMaximale - La limite de poids pour le panier du client.
 * @param tPanier - Le panier d'achat du client.
 * @param tQuantite - Un tableau de quantités d'articles dans le panier.
 * @param[out] tLogPanier - Un pointeur pour stocker la taille du panier.
 * @param budget - Le budget du client.
 */
void ajouter_article_au_panier(int numClient, int tRef[], float tPoids[], float tVol[], float tPrixUnitaire[],
                               int tNumClient[], float tCagnotte[], int tLogArticle, int tLogClient,
                               float volumeCoffre, float chargeMaximale, int tPanier[], int tQuantite[], int *tLogPanier, float budget);

/**
 * @brief Supprimer un article du panier du client.
 *
 * @param tPanier - Le panier d'achat du client.
 * @param tQuantite - Un tableau de quantités d'articles dans le panier.
 * @param[out] tLogPanier - Un pointeur pour stocker la taille du panier.
 * @param tCagnotte - Un tableau de cagnottes.
 * @param numClient - Le numéro du client.
 * @param tNumClient - Un tableau de numéros d'articles.
 * @param tLogClient - Le nombre total de clients.
 * @param tRef - Un tableau de références d'articles.
 * @param tPrixUnitaire - Un tableau de prix unitaires d'articles.
 */
void supprimer_article_du_panier(int tPanier[], int tQuantite[], int *tLogPanier, float tCagnotte[], int numClient, int tNumClient[], int tLogClient, int tRef[], float tPrixUnitaire[]);

/**
 * @brief Afficher un récapitulatif du panier du client.
 *
 * @param tPanier - Le panier d'achat du client.
 * @param tLogPanier - La taille du panier.
 * @param tRef - Un tableau de références d'articles.
 * @param tPoid - Un tableau de poids d'articles.
 * @param tVol - Un tableau de volumes d'articles.
 * @param tPrixUnitaire - Un tableau de prix unitaires d'articles.
 * @param tQuantite - Un tableau de quantités d'articles dans le panier.
 * @param tCagnotte - Un tableau de cagnottes.
 * @param numClient - Le numéro du client.
 * @param tNumClient - Un tableau de numéros d'articles.
 * @param tLogClient - Le nombre total de clients.
 * @param volumeCoffre - La limite de volume pour le panier du client.
 * @param chargeMaximale - La limite de poids pour le panier du client.
 * @param budget - Le budget du client.
 */
void affiche_recap_panier(int tPanier[], int tLogPanier, int tRef[], float tPoid[], float tVol[],
                          float tPrixUnitaire[], int tQuantite[], float tCagnotte[], int numClient,
                          int tNumClient[], int tLogClient, float volumeCoffre, float chargeMaximale, float budget);

/**
 * @brief Configurer la session client.
 *
 * @param tNumClient - Un tableau de numéros de clients.
 * @param tLogClient - Le nombre total de clients.
 * @param[out] budget - Un pointeur pour stocker le budget du client.
 * @param[out] volumeCoffre - Un pointeur pour stocker la limite de volume du panier du client.
 * @param[out] chargeMaximale - Un pointeur pour stocker la limite de poids du panier du client.
 * @param[out] numClient - Un pointeur pour stocker le numéro du client.
 */
void configurer_session_client(int tNumClient[], int tLogClient, double *budget, float *volumeCoffre, float *chargeMaximale, int *numClient);

/**
 * @brief Modifier la quantité d'un article dans le panier du client.
 *
 * @param tPanier - Le panier d'achat du client.
 * @param tQuantite - Un tableau de quantités d'articles dans le panier.
 * @param[out] tLogPanier - Un pointeur pour stocker la taille du panier.
 * @param tCagnotte - Un tableau de cagnottes.
 * @param numClient - Le numéro du client.
 * @param tPrixUnitaire - Un tableau de prix unitaires d'articles.
 * @param tRef - Un tableau de références d'articles.
 * @param tLogClient - Le nombre total de clients.
 * @param tNumClient - Un tableau de numéros client.
 */
void modifier_quantite_article_panier(int tPanier[], int tQuantite[], int *tLogPanier, float tCagnotte[], int numClient, float tPrixUnitaire[], int tRef[], int tLogClient, int tNumClient[]);

/**
 * @brief Réinitialiser le panier du client.
 *
 * @param tPanier - Le panier d'achat du client.
 * @param tQuantite - Un tableau de quantités d'articles dans le panier.
 * @param[out] tLogPanier - Un pointeur pour stocker la taille du panier.
 * @param tCagnotte - Un tableau de cagnottes.
 * @param numClient - Le numéro du client.
 * @param tNumClient - Un tableau de numéros de client.
 * @param tLogClient - Le nombre total de clients.
 * @param tRef - Un tableau de références d'articles.
 * @param tPrixUnitaire - Un tableau de prix unitaires d'articles.
 */
void reinitialiser_panier(int tPanier[], int tQuantite[], int *tLogPanier, float tCagnotte[], int numClient, int tNumClient[], int tLogClient, int tRef[], float tPrixUnitaire[]);

/**
 * @brief Déduire un montant de la cagnotte du client.
 *
 * @param numClient - Le numéro du client.
 * @param montant - Le montant à déduire de la cagnotte.
 * @param tNumClient - Un tableau de numéros de clients.
 * @param tCagnotte - Un tableau de cagnottes.
 * @param tLogClient - Le nombre total de clients.
 * @param tSus - Un tableau d'état des clients suspendus.
 */
void deduire_cagnotte(int numClient, float montant, int tNumClient[], float tCagnotte[], int tLogClient);

/**
 * @brief Quitter l'application client.
 *
 * @param tPanier - Le panier d'achat du client.
 * @param tLogPanier - La taille du panier.
 * @param tRef - Un tableau de références d'articles.
 * @param tPoid - Un tableau de poids d'articles.
 * @param tVol - Un tableau de volumes d'articles.
 * @param tPrixUnitaire - Un tableau de prix unitaires d'articles.
 * @param tQuantite - Un tableau de quantités d'articles dans le panier.
 * @param tCagnotte - Un tableau de cagnottes.
 * @param numClient - Le numéro du client.
 * @param tNumClient - Un tableau de numéros de clients.
 * @param tLogClient - Le nombre total de clients.
 * @param budget - Le budget du client.
 * @param tSus - Un tableau d'état des clients suspendus.
 */
void quitter_application(int tPanier[], int tLogPanier, int tRef[], float tPoid[], float tVol[],
                         float tPrixUnitaire[], int tQuantite[], float tCagnotte[], int numClient,
                         int tNumClient[], int tLogClient, float budget, int tSus[]);

/**
 * @brief Afficher le menu du client et enregistrer le choix de l'utilisateur.
 *
 * @param[out] choix - Un pointeur pour stocker le choix de l'utilisateur.
 */
void menu_client(int *choix);

/**
 * @brief Exécute l'ensemble des fonctions de l'interface client.
 */
void global_client(void);

#endif // INTERFACE_CLIENT_H
