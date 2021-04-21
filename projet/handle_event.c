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

void menuselection(menu_t *menu){
    switch(menu->currentmenu){
            //Menu principale 
        case 1:
            switch(menu->currentoption){
                    //Jouer
                case 1:
                        //On quitte le menu pour lancer le jeux
                    menu->menuover = 1;
                break;
                    //Regle
                case 2:
                    //Afficher l'écran des régle  
                break;

                default:
                break;
            }
        break;

        //Menu 2 (Régle)

        //Menu 3 (Niveaux ??)


        default:
        break;


    }

}

void handle_events_menu(SDL_Event *event,world_t *world,menu_t *menu){
    while( SDL_PollEvent(event)){
        
        // Si l'utilisateur a cliqué sur le X de la fenêtre
        if(event->type == SDL_QUIT){
            // On indique la fin du jeu
            world->gameover = 1;
            menu->menuover = 1;
        }
       
        // Si une touche est appuyée
        if(event->type == SDL_KEYDOWN){
            if(event->key.keysym.sym == SDLK_z){
                if(menu->currentoption>1){
                    menu->currentoption--;
                }
            }
            if(event->key.keysym.sym == SDLK_s){
                if(menu->currentoption<menu->optionnumber){
                    menu->currentoption++;
                }
            }
            if(event->key.keysym.sym == SDLK_UP){
                if(menu->currentoption>1){
                    menu->currentoption--;
                }
            }
            if(event->key.keysym.sym == SDLK_DOWN){
                if(menu->currentoption<menu->optionnumber){
                    menu->currentoption++;
                }
            }
            if(event->key.keysym.sym == SDLK_ESCAPE){
                // On indique la fin du programme
                world->gameover = 1;
                menu->menuover = 1;
            }
            if(event->key.keysym.sym == SDLK_RETURN){
                menuselection(menu);
            }
        }
    }
}
void handle_events(SDL_Event *event, world_t *world){
    while( SDL_PollEvent(event)){
        
        // Si l'utilisateur a cliqué sur le X de la fenêtre
        if(event->type == SDL_QUIT){
            // On indique la fin du jeu
            world->gameover = 1;
        }
       
        // Si une touche est appuyée
        if(event->type == SDL_KEYDOWN){
            if(event->key.keysym.sym == SDLK_d){
                world->vaisseau.x+= MOVING_STEP;
            }

            if(event->key.keysym.sym == SDLK_q){
                world->vaisseau.x-= MOVING_STEP;
            }

            if(event->key.keysym.sym == SDLK_ESCAPE){
                //On indique la fin du jeu
                world->gameover = 1;
            }

            if(event->key.keysym.sym == SDLK_z){
                world->vy=world->vy+1;
            }

            if(event->key.keysym.sym == SDLK_s){
            world->vy=world->vy-1;
            }
            out_of_screen(world);
        }
    }
}



