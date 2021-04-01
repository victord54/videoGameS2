/**
 * \file game_event.c
 * \brief Module de gestions des événements
 * \author Victor Dallé
 * \version 1.0
 * \date 1 avril 2021
 */

#include "game_event.h"

void init_sprite(sprite_t *sprite, int x, int y, int w, int h){
	sprite->x=x;
	sprite->y=y;
	sprite->w=w;
	sprite->h=h;
}

void print_sprite(sprite_t *sprite){
	printf("Position en x = %d\nPosition en y = %d\nLargeur du sprite = %d\nHauteur du sprite = %d\n",sprite->x,sprite->y,sprite->w,sprite->h);
}

void init_data(world_t * world){
    // On n'est pas à la fin du jeu
    world->gameover = 0;

	// Initialisation du vaisseau
	init_sprite(&world->vaisseau,SCREEN_WIDTH/2 - SHIP_SIZE/2,SCREEN_HEIGHT - SHIP_SIZE*2,SHIP_SIZE,SHIP_SIZE);

    // Initialisation de la ligne d'arrivée
    init_sprite(&world->arrival,0,FINISH_LINE_HEIGHT,SCREEN_WIDTH,FINISH_LINE_HEIGHT);

    // Position initiale du sprite vaisseau
    print_sprite(&world->vaisseau);
    printf("=======================\n");

    // Position initiale du sprite arrival
    print_sprite(&world->arrival);
    printf("=======================\n");

    // Initialisation de la vy
    world->vy = INITIAL_SPEED;

    // Initialisation d'un mur de météorites.
    init_sprite(&world->mur, SCREEN_WIDTH/2 - 3*METEORITE_SIZE/2, SCREEN_HEIGHT/2 - 7*METEORITE_SIZE/2, METEORITE_SIZE, METEORITE_SIZE);

}

void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite){
	apply_texture(texture, renderer, sprite->x,sprite->y);
}

void clean_data(world_t *world){
    /* Utile uniquement si vous avez fait de l'allocation dynamique (malloc); la fonction ici doit permettre de libérer la mémoire (free) */ 
}

int is_game_over(world_t *world){
    return world->gameover;
}

void update_data(world_t *world){
    world->arrival.y += world->vy;
    world->mur.y += world->vy;

}

void handle_events(SDL_Event *event,world_t *world){
    Uint8 *keystates;
    while( SDL_PollEvent( event ) ) {
        
        //Si l'utilisateur a cliqué sur le X de la fenêtre
        if(event->type == SDL_QUIT) {
            //On indique la fin du jeu
            world->gameover = 1;
        }
       
        //si une touche est appuyée
        if(event->type == SDL_KEYDOWN){
            //si la touche appuyée est 'D'
            if(event->key.keysym.sym == SDLK_d){
                printf("La touche D est appuyée\n");
                world->vaisseau.x+= MOVING_STEP;
              }
            
            //si la touche appuyée est 'Q'
            if(event->key.keysym.sym == SDLK_q){
                printf("La touche Q est appuyée\n");
                world->vaisseau.x-= MOVING_STEP;
            }

            if(event->key.keysym.sym == SDLK_ESCAPE){
            //On indique la fin du jeu
            printf("La touche ECHAP est appuyée\n");
            world->gameover = 1;
            }

            if(event->key.keysym.sym == SDLK_z){
            //On indique la fin du jeu
            printf("La touche Z est appuyée\n");
            world->vy=world->vy+1;
            }

            if(event->key.keysym.sym == SDLK_s){
            //On indique la fin du jeu
            printf("La touche S est appuyée\n");
            world->vy=world->vy-1;
            }

            print_sprite(&world->vaisseau); // Affichage coordonnées à chaque déplacement
            printf("=======================\n");
        }
    }
}