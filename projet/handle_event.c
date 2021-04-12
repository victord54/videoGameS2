/**
 * @file handle_event.c
 * @author Victor Dallé
 * @brief Fichier .c du module handle_event
 * @version 0.1
 * @date 2021-04-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "handle_event.h"

void handle_events(SDL_Event *event, world_t *world){
    //Uint8 *keystates;
    while( SDL_PollEvent(event)){
        
        //Si l'utilisateur a cliqué sur le X de la fenêtre
        if(event->type == SDL_QUIT){
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

            out_of_screen(world);
        }
    }
}
