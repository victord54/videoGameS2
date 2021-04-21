/**
 * @file menu_data.h
 * @author Victor Dallé / Yann Periney
 * @brief En-tête du module de gestion des évènements du menu du jeu.
 * @version 0.1
 * @date 2021-04-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#ifndef DEF_MENU_DATA_H
#define DEF_MENU_DATA_H

#include "param.h"
#include "sdl2-light.h"

/* ========== FONCTIONS ========== */

/**
 * \brief La fonction indique si le menu est fini.
 * \param menu Les données du menu.
 * \return 1 si le jeu est fini, 0 sinon.
 */
int is_menu_over(menu_t *menu);

/**
 * \brief La fonction indique si on a quitter par menu.
 * \param menu Les données du menu.
 * \return 1 si le jeu est fini, 0 sinon.
 */
int is_menu_quitte(menu_t *menu);
#endif