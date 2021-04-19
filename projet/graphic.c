/**
 * @file graphic.c
 * @author Victor Dallé / Yann Periney
 * @brief Module gérant la partie graphique du jeu.
 * @version 0.1
 * @date 2021-04-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "graphic.h"

void clean_textures(textures_t *textures){
    clean_texture(textures->background);
    clean_texture(textures->vaisseau);
    clean_texture(textures->arrival);
    clean_texture(textures->meteorite);
    clean_texture(textures->menu_background);
    clean_font(textures->font);
}

void init_textures(SDL_Renderer *renderer, textures_t *textures){
    textures->background = load_image("ressources/space-background.bmp",renderer);
    textures->vaisseau = load_image("ressources/spaceship.bmp",renderer);
    textures->arrival = load_image("ressources/finish_line.bmp",renderer);
    textures->meteorite = load_image("ressources/meteorite.bmp",renderer);
    textures->font = load_font("ressources/arial.ttf",14);
    textures->menu_background = load_image("ressources/menu0.bmp",renderer);
}

void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite,int make_disappear){

if(make_disappear==0){ // Apparition du sprite si il n'y a pas eu de collision
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
            // Applique i*j fois la texture pour créer le mur de météorites
            apply_texture(textures->meteorite, renderer,x+j*METEORITE_SIZE,y+i*METEORITE_SIZE);
        }
	}
}

void refresh_graphics(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    int lastTime = 0, currentTime; // Variables liées au timer
    char str[20]; // String pour formater le texte affiché à l'écran
    currentTime = SDL_GetTicks(); // Donne la valeur en milisecondes du temps d'éxécution de la librairie SDL

    clear_renderer(renderer); // On vide le renderer

    // Application des textures dans le renderer
	apply_background(renderer, textures->background);
	apply_sprite(renderer, textures->vaisseau, &world->vaisseau,world->make_disappear);
   	apply_sprite(renderer, textures->arrival,&world->arrival,0);
    apply_walls(renderer,textures,world);

    if (!world->gameover) // Affichage du temps à l'écran
    {
        lastTime = currentTime;
        sprintf(str, "Time : %d",lastTime/1000); // La division par 1000 sert à n'afficher que les secondes
        apply_text(renderer, 0, 0, 200, 60, str, textures->font);
    }

    if (is_finish(world) == 1) // Si on a gagné
    {
        lastTime = currentTime/1000;
        apply_text(renderer, SCREEN_WIDTH/2-50, SCREEN_HEIGHT/2-30, 100, 60, "Win !", textures->font);
    }
    if (is_finish(world) == 2) // Si on a perdu
    {
        lastTime = currentTime;
        apply_text(renderer, SCREEN_WIDTH/2-50, SCREEN_HEIGHT/2-30, 100, 60, "Lost !", textures->font);
    }

    // on met à jour l'écran
    update_screen(renderer);

    if (is_finish(world) == 1) // Si on a gagné, on inscrit le nom du joueur pour enregistrer le score
    {
        record(lastTime);
    }
    
    if (is_finish(world) == 2)
    {
        pause(2000);
    }
}

void clean_data(world_t *world){
    /* Utile uniquement si vous avez fait de l'allocation dynamique (malloc); la fonction ici doit permettre de libérer la mémoire (free) */ 
}

void clean(SDL_Window *window, SDL_Renderer * renderer, textures_t *textures, world_t * world){
    clean_data(world);
    clean_textures(textures);
    clean_sdl(renderer,window);
}

void init(SDL_Window **window, SDL_Renderer ** renderer, textures_t *textures, world_t * world,menu_t *menu){
    init_sdl(window,renderer,SCREEN_WIDTH, SCREEN_HEIGHT);
    init_data(world,menu);
    init_ttf();
    init_textures(*renderer,textures);
}

void apply_walls(SDL_Renderer *renderer, textures_t *textures, world_t * world){
    for(int i=0;i<METEORITE_WALL_NUMBER;i++){
        // Applique la texture autant de fois qu'il a de murs de météorites
	    apply_wall(textures,renderer,world, world->mur[i].x,world->mur[i].y,world->mur[i].h/METEORITE_SIZE,world->mur[i].w/METEORITE_SIZE);
    }
}