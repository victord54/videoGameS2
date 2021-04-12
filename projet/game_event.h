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
 * \brief La fonction initialise les données d'un sprite selon les valeurs entrées.
 * \param sprite Pointeur vers sprite_t pour l'initialisation des données.
 * \param x Coordonnée x du sprite.
 * \param y Coordonnée y du sprite.
 * \param w Largeur du sprite.
 * \param h Hauteur du sprite.
 */
void init_sprite(sprite_t *sprite, int x, int y, int w, int h);

/**
 * \brief La fonction initialise les données d'un sprite de meteore selon les valeurs entrées.
 * \param sprite Pointeur vers sprite_t pour l'initialisation des données.
 * \param x Coordonnée x du sprite.
 * \param y Coordonnée y du sprite.
 * \param w Largeur du sprite.
 * \param h Hauteur du sprite.
 * \param screen_nbr L'ecran ou le meteore doit être placer
 */
void init_sprite_meteore(sprite_t *sprite, int x, int y, int w, int h,int screen_nbr);

/**
 * \brief La fonction initialise les données du monde du jeu.
 * \param world Les données du monde.
 */
void init_data(world_t * world);

/**
 * \brief Fonction qui detecte si le vaisseau est hors de l'écran.
 * \param world Structure des données du monde.
 */
void out_of_screen(world_t *world);

/**
 * \brief Fonction qui detecte si deux sprite sont en collision.
 * \param sp1 premier sprite 
 * \param sp2 second prite 
 * \return 1 si collision est 0 si aucun collision.
 */
int sprites_collide(sprite_t *sp1, sprite_t *sp2);


/**
 * \brief Fonction qui change la vitesse du monde en cas de collision.
 * \param world Structure des données du monde.
 * \param sp1 premier sprite 
 * \param sp2 second prite 
 * \param make_disappear détermine la visibilité du premie sprite de la fonction
 */
void handle_sprites_collision(world_t *world,sprite_t *sp1, sprite_t *sp2,int *make_disappear);

/**
 * \brief Fonction qui change initalise les murs
 * \param world Structure des données du monde.
 */
void init_walls(world_t *world);

/**
 * \brief Fonction qui update la position de tout les murs
 * \param world Structure des données du monde.
 */
void update_walls(world_t *world);

#endif
