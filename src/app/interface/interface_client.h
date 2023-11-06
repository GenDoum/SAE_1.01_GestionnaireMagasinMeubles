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
void affiche_client();

/**
 * @brief Afficher le menu du client et enregistrer le choix de l'utilisateur.
 *
 * @param[out] choix - Un pointeur pour stocker le choix de l'utilisateur.
 */
void menu_client(int *choix);

/**
 * @brief Ajouter des articles au panier du client.
 *
 * @param numeroClient - Le numéro du client.
 * @param references - Un tableau de références d'articles.
 * @param poids - Un tableau de poids d'articles.
 * @param volume - Un tableau de volumes d'articles.
 * @param prixUnitaire - Un tableau de prix unitaires d'articles.
 * @param numeros - Un tableau de numéros d'articles.
 * @param cagnottes - Un tableau de cagnottes.
 * @param suspendues - Un tableau d'articles suspendus.
 * @param nombreArticles - Le nombre total d'articles disponibles.
 * @param nombreClients - Le nombre total de clients.
 * @param volumeCoffre - La limite de volume pour le panier du client.
 * @param chargeMaximale - La limite de poids pour le panier du client.
 * @param panier - Le panier d'achat du client.
 * @param quantites - Un tableau de quantités d'articles dans le panier.
 * @param[out] taillePanier - Un pointeur pour stocker la taille du panier.
 * @param budget - Le budget du client.
 */
void ajouter_article_au_panier(int numeroClient, int references[], float poids[], float volume[], float prixUnitaire[],
                               int numeros[], float cagnottes[], int suspendues[], int nombreArticles, int nombreClients,
                               float volumeCoffre, float chargeMaximale, int panier[], int quantites[], int *taillePanier, float budget);

/**
 * @brief Supprimer un article du panier du client.
 *
 * @param panier - Le panier d'achat du client.
 * @param quantites - Un tableau de quantités d'articles dans le panier.
 * @param[out] taillePanier - Un pointeur pour stocker la taille du panier.
 * @param cagnottes - Un tableau de cagnottes.
 * @param numeroClient - Le numéro du client.
 * @param numeros - Un tableau de numéros d'articles.
 * @param nombreClients - Le nombre total de clients.
 * @param references - Un tableau de références d'articles.
 * @param prixUnitaire - Un tableau de prix unitaires d'articles.
 */
void supprimer_article_du_panier(int panier[], int quantites[], int *taillePanier, float cagnottes[], int numeroClient, int numeros[], int nombreClients, int references[], float prixUnitaire[]);

/**
 * @brief Afficher un récapitulatif du panier du client.
 *
 * @param panier - Le panier d'achat du client.
 * @param taillePanier - La taille du panier.
 * @param references - Un tableau de références d'articles.
 * @param poids - Un tableau de poids d'articles.
 * @param volume - Un tableau de volumes d'articles.
 * @param prixUnitaire - Un tableau de prix unitaires d'articles.
 * @param quantites - Un tableau de quantités d'articles dans le panier.
 * @param cagnottes - Un tableau de cagnottes.
 * @param numeroClient - Le numéro du client.
 * @param numeros - Un tableau de numéros d'articles.
 * @param nombreClients - Le nombre total de clients.
 * @param volumeCoffre - La limite de volume pour le panier du client.
 * @param chargeMaximale - La limite de poids pour le panier du client.
 * @param budget - Le budget du client.
 */
void affiche_recap_panier(int panier[], int taillePanier, int references[], float poids[], float volume[],
                          float prixUnitaire[], int quantites[], float cagnottes[], int numeroClient,
                          int numeros[], int nombreClients, float volumeCoffre, float chargeMaximale, float budget);

/**
 * @brief Configurer la session client.
 *
 * @param numeros - Un tableau de numéros de clients.
 * @param suspendus - Un tableau d'état des clients suspendus.
 * @param nombreClients - Le nombre total de clients.
 * @param[out] budget - Un pointeur pour stocker le budget du client.
 * @param[out] volumeCoffre - Un pointeur pour stocker la limite de volume du panier du client.
 * @param[out] chargeMaximale - Un pointeur pour stocker la limite de poids du panier du client.
 * @param[out] numeroClient - Un pointeur pour stocker le numéro du client.
 */
void configurer_session_client(int numeros[], int suspendus[], int nombreClients, double *budget, float *volumeCoffre, float *chargeMaximale, int *numeroClient);

/**
 * @brief Modifier la quantité d'un article dans le panier du client.
 *
 * @param panier - Le panier d'achat du client.
 * @param quantites - Un tableau de quantités d'articles dans le panier.
 * @param[out] taillePanier - Un pointeur pour stocker la taille du panier.
 * @param cagnottes - Un tableau de cagnottes.
 * @param numeroClient - Le numéro du client.
 * @param prixUnitaire - Un tableau de prix unitaires d'articles.
 * @param references - Un tableau de références d'articles.
 * @param nombreClients - Le nombre total de clients.
 * @param numeros - Un tableau de numéros d'articles.
 */
void modifier_quantite_article_panier(int panier[], int quantites[], int *taillePanier, float cagnottes[], int numeroClient, float prixUnitaire[], int references[], int nombreClients, int numeros[]);

/**
 * @brief Réinitialiser le panier du client.
 *
 * @param panier - Le panier d'achat du client.
 * @param quantites - Un tableau de quantités d'articles dans le panier.
 * @param[out] taillePanier - Un pointeur pour stocker la taille du panier.
 * @param cagnottes - Un tableau de cagnottes.
 * @param numeroClient - Le numéro du client.
 * @param numeros - Un tableau de numéros d'articles.
 * @param nombreClients - Le nombre total de clients.
 * @param references - Un tableau de références d'articles.
 * @param prixUnitaire - Un tableau de prix unitaires d'articles.
 */
void reinitialiser_panier(int panier[], int quantites[], int *taillePanier, float cagnottes[], int numeroClient, int numeros[], int nombreClients, int references[], float prixUnitaire[]);

/**
 * @brief Déduire un montant de la cagnotte du client.
 *
 * @param numeroClient - Le numéro du client.
 * @param montant - Le montant à déduire de la cagnotte.
 * @param numeros - Un tableau de numéros de clients.
 * @param cagnottes - Un tableau de cagnottes.
 * @param nombreClients - Le nombre total de clients.
 * @param suspendus - Un tableau d'état des clients suspendus.
 */
void deduire_cagnotte(int numeroClient, float montant, int numeros[], float cagnottes[], int nombreClients, int suspendus[]);

/**
 * @brief Quitter l'application client.
 *
 * @param panier - Le panier d'achat du client.
 * @param taillePanier - La taille du panier.
 * @param references - Un tableau de références d'articles.
 * @param poids - Un tableau de poids d'articles.
 * @param volume - Un tableau de volumes d'articles.
 * @param prixUnitaire - Un tableau de prix unitaires d'articles.
 * @param quantites - Un tableau de quantités d'articles dans le panier.
 * @param cagnottes - Un tableau de cagnottes.
 * @param numeroClient - Le numéro du client.
 * @param numeros - Un tableau de numéros d'articles.
 * @param nombreClients - Le nombre total de clients.
 * @param budget - Le budget du client.
 * @param suspendus - Un tableau d'état des clients suspendus.
 */
void quitter_application(int panier[], int taillePanier, int references[], float poids[], float volume[],
                         float prixUnitaire[], int quantites[], float cagnottes[], int numeroClient,
                         int numeros[], int nombreClients, float budget, int suspendus[]);

/**
 * @brief Exécute l'ensemble des fonctions de l'interface client.
 */
void global_client();

#endif // INTERFACE_CLIENT_H
