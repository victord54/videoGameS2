/**
 * @file graphic.h
 * @author Victor Dallé / Yann Periney
 * @brief En-tête du module gérant la partie graphique du jeu.
 * @version 0.1
 * @date 2021-04-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef DEF_GRAPHIC_H
#define DEF_GRAPHIC_H

#include "param.h"
#include "sdl2-light.h"
#include "game_data.h"
#include "sdl2-ttf-light.h"
#include "leaderboard.h"

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
 * \param menu Utile pour gérer le timer
 */
void refresh_graphics(SDL_Renderer *renderer, world_t *world,textures_t *textures, menu_t *menu);

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
 * \param menu Le menu.
 * \param program Les données du programme 
 */
void init(SDL_Window **window, SDL_Renderer ** renderer, textures_t *textures, world_t * world,menu_t *menu,program_t* program);

/**
 * \brief La fonction applique la texture des murs
 * \param renderer Le renderer.
 * \param textures Les textures.
 * \param world Le monde.
 */
void apply_walls(SDL_Renderer *renderer,textures_t *textures,world_t * world);

/**
 * @brief Fonction qui applique un background à la fin du jeu si on a gagné
 * 
 * @param renderer Le renderer.
 * @param textures Les textures.
 */
void print_end(SDL_Renderer *renderer, textures_t *textures);

/**
 * @brief Fonction qui applique un background à la fin du jeu si on a perdu
 * 
 * @param renderer Le renderer.
 * @param textures Les textures.
 */
void print_end_b(SDL_Renderer *renderer, textures_t *textures);


/**
 * \brief La fonction qui commence un niveaux
 * \param renderer Le renderer.
 * \param textures Les textures.
 * \param world Le monde.
 * \param menu Le menu.
 */
void level_start(SDL_Renderer *renderer,world_t *world,textures_t *textures);

/**
 * \brief La fonction auxiliaire qui rafréchi l'écran
 * \param renderer Le renderer.
 * \param textures Les textures.
 * \param world Le monde.
 * \param menu Le menu.
 */
void level_start_aux(SDL_Renderer *renderer,world_t *world,textures_t *textures);
/**
 * @brief Gère le timer et l'état de win ou de lose.
 * 
 * @param menu Le menu.
 * @param textures Les textures.
 * @param renderer Le renderer.
 * @param world Les données du monde.
 */
void timerWinLoseState(menu_t *menu, textures_t *textures, SDL_Renderer *renderer, world_t *world);

#endif