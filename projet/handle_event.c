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

void menu_selection(menu_t *menu,program_t *program){
    switch(menu->currentmenu){
            //Menu principal
        case 1:
            switch(menu->currentoption){
                    //Jouer
                case 1:
                        //On quitte le menu pour lancer le jeu
                    menu->currentmenu = 3;
                break;
                    //Règle
                case 2:
                    menu;
                break;

                default:
                break;
            }
         break;
            //Menu 2 (Règles)
        case 2:
            menu->currentmenu = 3;
        break;
            //Menu 3 (Niveau)
        case 3:
            switch(menu->currentoption){
                    //Jouer au niveau
                case 1:
                    menu->menuover = 1;
                    program->mode = 0;
                break;
                    //Jouer infini
                case 2:
                    menu->menuover = 1;
                    program->mode = 1;
                break;

                default:
                break;
            }
        break;
            //Menu 4 (Fin du jeu)
        case 4:
            switch(menu->currentoption){
                    //Restart
                case 1:
                    program->restart=1;
                    menu->menuover=1;
                break;
                    //Quitter
                case 2:
                    program->programover=1;
                    menu->menuover=1;
                break;
                default:
                break;
            }
        break;
        default:
        break;
    }
}

void handle_events_menu(SDL_Event *event,world_t *world,menu_t *menu,program_t *program){
    while( SDL_PollEvent(event)){
        
        // Si l'utilisateur a cliqué sur le X de la fenêtre
        if(event->type == SDL_QUIT){
            // On indique la fin du jeu
            world->gameover = 1;
            menu->menuover = 1;
            menu->quitte = 1;
            program->programover=1;
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
                menu->quitte = 1;
                program->programover=1;
            }
            if(event->key.keysym.sym == SDLK_RETURN){
                menu_selection(menu,program);
            }
        }
    }
}
void handle_events(SDL_Event *event, world_t *world,menu_t *menu,program_t *program){
    while( SDL_PollEvent(event)){
        
        // Si l'utilisateur a cliqué sur le X de la fenêtre
        if(event->type == SDL_QUIT){
            // On indique la fin du jeu
            world->gameover = 1;
            menu->quitte = 1;
            program->programover=1;
        }
       
        // Si une touche est appuyée
        if(event->type == SDL_KEYDOWN){
            if(event->key.keysym.sym == SDLK_d){
                world->vaisseau.x+= MOVING_STEP;
            }
            if(event->key.keysym.sym == SDLK_RIGHT){
                world->vaisseau.x+= MOVING_STEP;
            }

            if(event->key.keysym.sym == SDLK_q){
                world->vaisseau.x-= MOVING_STEP;
            }
            if(event->key.keysym.sym == SDLK_LEFT){
                world->vaisseau.x-= MOVING_STEP;
            }

            if(event->key.keysym.sym == SDLK_z){
                world->vy=world->vy+1;
            }
            if(event->key.keysym.sym == SDLK_UP){
                world->vy=world->vy+1;
            }

            if(event->key.keysym.sym == SDLK_s){
                world->vy=world->vy-1;
            }
            if(event->key.keysym.sym == SDLK_DOWN){
                world->vy=world->vy-1;
            }

            if(event->key.keysym.sym == SDLK_ESCAPE){
                //On indique la fin du jeu
                world->gameover = 1;
                menu->quitte = 1;
                program->programover=1;
            }
            out_of_screen(world);
        }
    }
}



