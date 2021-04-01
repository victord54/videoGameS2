#ifndef DEF_GRAPHIC_H
#define DEF_GRAPHIC_H

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

#endif