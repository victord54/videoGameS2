/**
 * @file handle_event.h
 * @author Victor Dallé / Yann Periney
 * @brief En-tête du module gérant les entrées utilisateur.
 * @version 0.1
 * @date 2021-04-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef DEF_HANDLE_EVENT_H
#define DEF_HANDLE_EVENT_H



#include <SDL2/SDL.h>
#include "param.h"
#include "game_data.h"

/**
 * \brief La fonction qui gère les évènement celon le menu et les option choissi.
 * \param menu Les données du menu.
 */
void menuselection(menu_t *menu);

/**
 * \brief La fonction gère les évènements ayant eu lieu dans le menu et qui n'ont pas encore été traités.
 * \param event Paramètre qui contient les événements.
 * \param world Les données du monde.
 * \param menu Les données du menu.
 */
void handle_events_menu(SDL_Event *event,world_t *world,menu_t *menu);
/**
 * \brief La fonction gère les évènements ayant eu lieu et qui n'ont pas encore été traités.
 * \param event Paramètre qui contient les événements.
 * \param world Les données du monde.
 */
void handle_events(SDL_Event *event,world_t *world,menu_t *menu);



#endif
