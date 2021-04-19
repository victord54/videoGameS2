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


#include "menu_graphic.h"
#include "graphic.h"

void refresh_menu_graphics(SDL_Renderer *renderer, menu_t *menu, textures_t *textures){

  int lastTime = 0, currentTime; // Variables liées au timer
  currentTime = SDL_GetTicks();

  // On vide le renderer
  clear_renderer(renderer);

  // Application des textures dans le renderer
	apply_background(renderer, textures->menu_background);

  // on met à jour l'écran
  update_screen(renderer);
}