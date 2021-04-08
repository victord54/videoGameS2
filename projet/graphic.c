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

void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite,int make_disappear){

if(make_disappear==0){
	    apply_texture(texture, renderer, sprite->x,sprite->y);
    }
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
	apply_sprite(renderer, textures->vaisseau, &world->vaisseau,world->make_disappear);
   	apply_sprite(renderer, textures->arrival,&world->arrival,0);
    for(int i=0;i<2;i++){  
	    apply_wall(textures,renderer,world, world->mur[i].x,world->mur[i].y,world->mur[i].h/METEORITE_SIZE,world->mur[i].w/METEORITE_SIZE);
    }
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