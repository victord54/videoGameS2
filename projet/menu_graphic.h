/**
 * @file menu_graphic.h
 * @author Victor Dallé / Yann Periney
 * @brief Module de gestion des évènements du jeu.
 * @version 0.1
 * @date 2021-04-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */



#ifndef DEF_MENU_GRAPHIC_H
#define DEF_MENU_GRAPHIC_H

#include "param.h"
#include "sdl2-light.h"

/* ========== FONCTIONS ========== */

/**
 * @brief Fonction qui applique la texture du menu sur le renderer lié à l'écran de jeu.
 * 
 * @param renderer Le renderer.
 * @param menu Paramétre du menu.
 * @param texture La texture liée au fond.
 */
void refresh_menu_graphics(SDL_Renderer *renderer, menu_t *menu, textures_t *textures);

/**
 * \brief Fonction qui applique la texture du menu
 * \param renderer Le renderer.
 * \param menu Paramétre du menu.
 * \param texture La texture liée au fond.
 */
void apply_menu(SDL_Renderer *renderer, menu_t *menu, textures_t *textures);

/**
 * \brief Fonction qui applique la texture du selecteur au menu
 * \param renderer Le renderer.
 * \param menu Paramétre du menu.
 * \param texture La texture liée au fond.
 */
void apply_select(SDL_Renderer *renderer, menu_t *menu, textures_t *textures);

#endif