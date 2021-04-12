/**
 * \file graphic.c
 * \brief Entête du module gérant l'affichage SDL2
 * \author Victor Dallé
 * \version 1.0
 * \date 1 avril 2021
 */

#ifndef DEF_GRAPHIC_H
#define DEF_GRAPHIC_H

#include "param.h"
#include "sdl2-light.h"
#include "game_event.h"

/* ========== FONCTIONS ========== */
/**
 * \brief La fonction nettoie les textures.
 * \param textures Les textures.
*/
void clean_textures(textures_t *textures);

/**
 * \brief La fonction initialise les textures nécessaires à l'affichage graphique du jeu.
 * \param screen La surface correspondant à l'écran de jeu.
 * \param textures Les textures du jeu.
*/
void  init_textures(SDL_Renderer *renderer, textures_t *textures);

/**
 * \brief La fonction applique un sprite au renderer.
 * \param renderer Renderer vers lequel on envoie les textures et les sprites.
 * \param texture Texture envoyée vers le renderer.
 * \param sprite Sprite envoyé vers le renderer.
 * \param make_disappear Déside si le sprite et afficher ou pas.
 */
void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite,int make_disappear);

/**
 * \brief La fonction applique la texture du fond sur le renderer lié à l'écran de jeu.
 * \param renderer Le renderer.
 * \param texture La texture liée au fond.
*/
void apply_background(SDL_Renderer *renderer, SDL_Texture *texture);

/**
 * \brief La fonction applique la texture des meteorite sur le renderer
 * \param textures Les textures.
 * \param renderer Le renderer lié à l'écran de jeu.
 * \param world Les données du monde.
 * \param x La position du mur sur l'axe des abscisses.
 * \param y La position du mur sur l'axe des ordonnées.
 * \param height La longueur du mur.
 * \param width La largeur du mur.
 */
void apply_wall(textures_t *textures,SDL_Renderer *renderer,world_t *world,int x,int y,int height,int width);

/**
 * \brief La fonction rafraichit l'écran en fonction de l'état des données du monde.
 * \param renderer Le renderer lié à l'écran de jeu.
 * \param world Les données du monde.
 * \param textures Les textures.
 */
void refresh_graphics(SDL_Renderer *renderer, world_t *world,textures_t *textures);

/**
 * \brief La fonction nettoie les données du monde.
 * \param world Les données du monde.
 */
void clean_data(world_t *world);

/**
* \brief La fonction nettoie le jeu: nettoyage de la partie graphique (SDL), nettoyage des textures, nettoyage des données.
* \param window La fenêtre du jeu.
* \param renderer Le renderer.
* \param textures Les textures.
* \param world Le monde.
*/
void clean(SDL_Window *window, SDL_Renderer * renderer, textures_t *textures, world_t * world);

/**
 * \brief La fonction initialise le jeu: initialisation de la partie graphique (SDL), chargement des textures, initialisation des données.
 * \param window La fenêtre du jeu.
 * \param renderer Le renderer.
 * \param textures Les textures.
 * \param world Le monde.
 */
void init(SDL_Window **window, SDL_Renderer ** renderer, textures_t *textures, world_t * world);

/**
 * \brief La fonction applique la texture des murs
 * \param renderer Le renderer.
 * \param textures Les textures.
 * \param world Le monde.
 */
void apply_walls(SDL_Renderer **renderer,textures_t *textures,world_t * world);
#endif