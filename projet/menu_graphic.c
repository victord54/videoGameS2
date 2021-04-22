/**
 * @file menu_graphic.h
 * @author Victor Dallé / Yann Periney
 * @brief Module de gestion des évènements du jeu.
 * @version 0.1
 * @date 2021-04-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include "menu_graphic.h"
#include "graphic.h"

void refresh_menu_graphics(SDL_Renderer *renderer, menu_t *menu, textures_t *textures){

  menu->time = SDL_GetTicks(); // Variable liée au timer
  // On vide le renderer
  clear_renderer(renderer);
  // Application d'une texture du menu sur le renderer
  apply_menu(renderer,menu,textures);
  // Application de la texture de séléction
  apply_select(renderer,menu,textures);
  // on met à jour l'écran
  update_screen(renderer);
}

void apply_menu(SDL_Renderer *renderer, menu_t *menu, textures_t *textures){
    switch(menu->currentmenu){
      case 1:
        apply_background(renderer, textures->menu_background); // Affichage jouer + règles
      break;
      case 2:
        apply_background(renderer, textures->rules); // Affichage des règles
      break;
      case 3:
        apply_background(renderer, textures->menu_replay); // Affichage de rejouer + quitter

      default:
        apply_background(renderer, textures->menu_replay); // Affichage du background seul
      break;
    }
}

void apply_select(SDL_Renderer *renderer, menu_t *menu, textures_t *textures){
    switch(menu->currentmenu){
            //Menu principal
        case 1:
            switch(menu->currentoption){
                    //Jouer
                case 1:
                    apply_texture(textures->menu1_select,renderer,36,143);
                break;
                    //Règles
                case 2:
                    apply_texture(textures->menu1_select,renderer,36,253);
                break;
                default:
                break;
            }
        break;
        	//Menu 2 (Règles)
        case 2:
          apply_texture(textures->menu1_select,renderer,36,353);
        break;
        	//Menu 3 (Niveau)
        case 3:
        	
        break;
          //Menu 4 (Restart)
        case 4:
          switch(menu->currentoption){
                    //Restart
                case 1:
                    apply_texture(textures->menu1_select,renderer,36,143);
                break;
                    //Quitter
                case 2:
                    apply_texture(textures->menu1_select,renderer,36,253);
                break;
                default:
                break;
            }
        break;
        default:
        break;
    }
}