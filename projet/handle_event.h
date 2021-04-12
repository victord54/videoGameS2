/**
 * @file handle_event.h
 * @author Victor Dallé
 * @brief Fichier .h du module handle_event
 * @version 0.1
 * @date 2021-04-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef DEF_HANDLE_EVENT_H
#define DEF_HANDLE_EVENT_H

/**
 * \brief La fonction gère les évènements ayant eu lieu et qui n'ont pas encore été traités.
 * \param event Paramètre qui contient les événements.
 * \param world Les données du monde.
 */
void handle_events(SDL_Event *event,world_t *world);

#endif