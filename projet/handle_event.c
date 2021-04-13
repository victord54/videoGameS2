/**
 * @file handle_event.c
 * @author Victor Dallé / Yann Periney
 * @brief Module gérant les entrées utilisateur.
 * @version 0.1
 * @date 2021-04-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "handle_event.h"
void handle_events_menu(SDL_Event *event,world_t *world,menu_t *menu){
    //Uint8 *keystates;
    while( SDL_PollEvent(event)){
        
        //Si l'utilisateur a cliqué sur le X de la fenêtre
        if(event->type == SDL_QUIT){
            //On indique la fin du jeu
            world->gameover = 1;
            menu->menuover = 1;
        }
       
        //si une touche est appuyée
        if(event->type == SDL_KEYDOWN){
            //si la touche appuyée est 'z'
            if(event->key.keysym.sym == SDLK_z){
                
            }
            //si la touche appuyée est 's'
            if(event->key.keysym.sym == SDLK_s){
                
            }
            //si la touche appuyée est 'Up'
            if(event->key.keysym.sym == SDLK_UP){
                
            }
            //si la touche appuyée est 'Down'
            if(event->key.keysym.sym == SDLK_DOWN){
                /* Déplacement cadre vers le bas */
            }
            if(event->key.keysym.sym == SDLK_ESCAPE){
                //On indique la fin du jeu
                world->gameover = 0;
                menu->menuover = 1;
            }
        }
    }
}
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
                world->vaisseau.x+= MOVING_STEP;
              }
            
            //si la touche appuyée est 'Q'
            if(event->key.keysym.sym == SDLK_q){
                world->vaisseau.x-= MOVING_STEP;
            }

            if(event->key.keysym.sym == SDLK_ESCAPE){
            //On indique la fin du jeu
            world->gameover = 1;
            }

            if(event->key.keysym.sym == SDLK_z){
            //On indique la fin du jeu
            world->vy=world->vy+1;
            }

            if(event->key.keysym.sym == SDLK_s){
            //On indique la fin du jeu
            world->vy=world->vy-1;
            }
            out_of_screen(world);
        }
    }
}
