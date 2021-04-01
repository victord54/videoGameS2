#include "param.h"
#include "graphic.h"
/**
 * \brief La fonction nettoie les textures.
 * \param textures Les textures.
*/
void clean_textures(textures_t *textures){
    clean_texture(textures->background);
    clean_texture(textures->vaisseau);
    clean_texture(textures->arrival);
    clean_texture(textures->meteorite);
}



/**
 * \brief La fonction initialise les textures nécessaires à l'affichage graphique du jeu.
 * \param screen La surface correspondant à l'écran de jeu.
 * \param textures Les textures du jeu.
*/
void  init_textures(SDL_Renderer *renderer, textures_t *textures){
    textures->background = load_image( "ressources/space-background.bmp",renderer);
    textures->vaisseau = load_image( "ressources/spaceship.bmp",renderer);
    textures->arrival = load_image( "ressources/finish_line.bmp",renderer);
    textures->meteorite = load_image( "ressources/meteorite.bmp",renderer);

}


/**
 * \brief La fonction applique la texture du fond sur le renderer lié à l'écran de jeu.
 * \param renderer Le renderer.
 * \param texture La texture liée au fond.
*/
void apply_background(SDL_Renderer *renderer, SDL_Texture *texture){
    if(texture != NULL){
      apply_texture(texture, renderer, 0, 0);
    }
}

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

void apply_wall(textures_t *textures,SDL_Renderer *renderer,world_t *world,int x,int y,int height,int width){
	for (int i = 0; i < height; i++){
     		for (int j = 0; j < width; j++){
			apply_texture(textures->meteorite, renderer,x+j*METEORITE_SIZE,y+i*METEORITE_SIZE);
		}
	}
}


/**
 * \brief La fonction rafraichit l'écran en fonction de l'état des données du monde.
 * \param renderer Le renderer lié à l'écran de jeu.
 * \param world Les données du monde.
 * \param textures Les textures.
 */
void refresh_graphics(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    
    //on vide le renderer
    clear_renderer(renderer);
    
    //application des textures dans le renderer
	apply_background(renderer, textures->background);
	apply_sprite(renderer, textures->vaisseau, &world->vaisseau);
   	apply_sprite(renderer, textures->arrival, &world->arrival);
	apply_wall(textures,renderer,world, world->mur.x,world->mur.y,7,3);

    // on met à jour l'écran
    update_screen(renderer);
}



/**
* \brief La fonction nettoie le jeu: nettoyage de la partie graphique (SDL), nettoyage des textures, nettoyage des données.
* \param window La fenêtre du jeu.
* \param renderer Le renderer.
* \param textures Les textures.
* \param world Le monde.
*/
void clean(SDL_Window *window, SDL_Renderer * renderer, textures_t *textures, world_t * world){
    clean_data(world);
    clean_textures(textures);
    clean_sdl(renderer,window);
}



/**
 * \brief La fonction initialise le jeu: initialisation de la partie graphique (SDL), chargement des textures, initialisation des données.
 * \param window La fenêtre du jeu.
 * \param renderer Le renderer.
 * \param textures Les textures.
 * \param world Le monde.
 */
void init(SDL_Window **window, SDL_Renderer ** renderer, textures_t *textures, world_t * world){
    init_sdl(window,renderer,SCREEN_WIDTH, SCREEN_HEIGHT);
    init_data(world);
    init_textures(*renderer,textures);
}