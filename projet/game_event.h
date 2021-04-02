/**
 * \file game_event.h
 * \brief Entête du module de gestions des événements
 * \author Victor Dallé
 * \version 1.0
 * \date 1 avril 2021
 */

#ifndef DEF_GAME_EVENT_H
#define DEF_GAME_EVENT_H

#include "param.h"
#include "sdl2-light.h"

/* ========== FONCTIONS ========== */

/**
 * \brief La fonction affiche les information (coordonées) d'un sprite.
 * \param sprite Variable de type sprite_t de laquelle on affiche les informations.
 */
void print_sprite(sprite_t *sprite);

/**
 * \brief La fonction indique si le jeu est fini en fonction des données du monde.
 * \param world Les données du monde.
 * \return 1 si le jeu est fini, 0 sinon.
 */
int is_game_over(world_t *world);

/**
 * \brief La fonction met à jour les données en tenant compte de la physique du monde.
 * \param world Les données du monde.
 */
void update_data(world_t *world);

/**
 * \brief La fonction gère les évènements ayant eu lieu et qui n'ont pas encore été traités.
 * \param event Paramètre qui contient les événements.
 * \param world Les données du monde.
 */
void handle_events(SDL_Event *event,world_t *world);

#endif