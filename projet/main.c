/**
 * @file main.c
 * @author Mathieu Constant / Yann Periney / Victor Dallé
 * @brief Programme principal.
 * @version 0.1
 * @date 2021-03-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "main.h"

/**
 * \brief Programme principal qui implémente la boucle du jeu.
 * \param argc Taille du tableau argv.
 * \param argv Pointeur vers un tableau de char de taille argc.
 * \return int 0 s'il n'y a pas eu d'erreurs.
 */
int main( int argc, char* argv[] )
{
    SDL_Event event;
    world_t world;
    menu_t menu;
    textures_t textures;
    SDL_Renderer *renderer;
    SDL_Window *window;
    // Initialisation du jeu
    init(&window,&renderer,&textures,&world,&menu);
    
    while(!is_menu_over(&menu)){
        // Gestion des évènement
        handle_events_menu(&event,&world,&menu);
        
        // Rafraichissement de l'écran
        refresh_menu_graphics(renderer,&menu,&textures);

        // Pause de 8 ms pour controler la vitesse de rafraichissement
        pause(8);
    }
    while(!is_game_over(&world)){ // Tq le jeu n'est pas fini
        
        // Gestion des évènements
        handle_events(&event,&world,&menu);
   
        // Mise à jour des données liée à la physique du monde
        update_data(&world);

        // Rafraichissement de l'écran
        refresh_graphics(renderer, &world, &textures, &menu);
   
        // Pause de 8 ms pour controler la vitesse de rafraichissement
        pause(8);
    }
    while(!is_menu_quitte(&menu)){
        print_end(renderer, &textures);
        pause(3000);
        menu.quitte=1;
    }
    // Nettoyage final
    clean(window,renderer,&textures,&world);
    
    return 0;
}
