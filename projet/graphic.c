/**
 * \file graphic.c
 * \brief Module gérant l'affichage SDL2
 * \author Victor Dallé
 * \version 1.0
 * \date 1 avril 2021
 */

#include "graphic.h"

void clean_textures(textures_t *textures){
    clean_texture(textures->background);
    clean_texture(textures->vaisseau);
    clean_texture(textures->arrival);
    clean_texture(textures->meteorite);
}

void  init_textures(SDL_Renderer *renderer, textures_t *textures){
    textures->background = load_image("ressources/space-background.bmp",renderer);
    textures->vaisseau = load_image("ressources/spaceship.bmp",renderer);
    textures->arrival = load_image("ressources/finish_line.bmp",renderer);
    textures->meteorite = load_image("ressources/meteorite.bmp",renderer);

}

void init_sprite(sprite_t *sprite, int x, int y, int w, int h){
	sprite->x=x;
	sprite->y=y;
	sprite->w=w;
	sprite->h=h;
}

void init_data(world_t * world){
    // On n'est pas à la fin du jeu
    world->gameover = 0;

	// Initialisation du vaisseau
	init_sprite(&world->vaisseau,SCREEN_WIDTH/2 - SHIP_SIZE/2,SCREEN_HEIGHT - SHIP_SIZE*2,SHIP_SIZE,SHIP_SIZE);

    // Initialisation de la ligne d'arrivée
    init_sprite(&world->arrival,0,FINISH_LINE_HEIGHT,SCREEN_WIDTH,FINISH_LINE_HEIGHT);

    // Initialisation de la vy
    world->vy = INITIAL_SPEED;

    // Initialisation d'un mur de météorites.
    init_sprite(&world->mur, SCREEN_WIDTH/2 - 3*METEORITE_SIZE/2, SCREEN_HEIGHT/2 - 7*METEORITE_SIZE/2, METEORITE_SIZE, METEORITE_SIZE);
}

void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite){
	apply_texture(texture, renderer, sprite->x,sprite->y);
}

void apply_background(SDL_Renderer *renderer, SDL_Texture *texture){
    if(texture != NULL){
      apply_texture(texture, renderer, 0, 0);
    }
}

void apply_wall(textures_t *textures,SDL_Renderer *renderer,world_t *world,int x,int y,int height,int width){
	for (int i = 0; i < height; i++){
     		for (int j = 0; j < width; j++){
			apply_texture(textures->meteorite, renderer,x+j*METEORITE_SIZE,y+i*METEORITE_SIZE);
		}
	}
}

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

void clean_data(world_t *world){
    /* Utile uniquement si vous avez fait de l'allocation dynamique (malloc); la fonction ici doit permettre de libérer la mémoire (free) */ 
}

void clean(SDL_Window *window, SDL_Renderer * renderer, textures_t *textures, world_t * world){
    clean_data(world);
    clean_textures(textures);
    clean_sdl(renderer,window);
}

void init(SDL_Window **window, SDL_Renderer ** renderer, textures_t *textures, world_t * world){
    init_sdl(window,renderer,SCREEN_WIDTH, SCREEN_HEIGHT);
    init_data(world);
    init_textures(*renderer,textures);
}