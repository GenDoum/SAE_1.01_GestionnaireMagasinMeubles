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
 * @brief Fonction principale de l'interface client.
 *
 * Cette fonction permet aux clients d'utiliser l'application pour gérer leur panier
 * et effectuer des opérations telles que l'ajout, la suppression ou la modification
 * d'articles dans le panier.
 */
void global_client();
