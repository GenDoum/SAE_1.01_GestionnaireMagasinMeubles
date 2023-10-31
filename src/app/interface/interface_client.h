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
void configurer_session_client(int numeros[], int suspendus[], int nombreClients, float *budget, float *volumeCoffre, float *chargeMaximale, int *numeroClient);

/**
 * @brief Fonction principale de l'interface client.
 *
 * Cette fonction permet aux clients d'utiliser l'application pour gérer leur panier
 * et effectuer des opérations telles que l'ajout, la suppression ou la modification
 * d'articles dans le panier.
 */
void global_client();

