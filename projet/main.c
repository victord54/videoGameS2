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
    srand(time(NULL));
    // Initialisation des variables
    world_t world;
    menu_t menu;
    textures_t textures;
    program_t program;
    endless_t bloc[ENDLESS_MODE_SCREEN_NUMBER];

    SDL_Renderer *renderer;
    SDL_Window *window;
    SDL_Event event;
        // Initialisation du jeu
        init(&window,&renderer,&textures,&world,&menu,&program);
        endless_mode(bloc,&world);
    while(!is_program_over(&program)){
        
        while((!is_menu_over(&menu))&&(program.restart==0)){
            // Gestion des évènement
            handle_events_menu(&event,&world,&menu,&program);
        
            // Rafraichissement de l'écran
            refresh_menu_graphics(renderer,&menu,&textures);
            
            // Pause de 8 ms pour controler la vitesse de rafraichissement
            pause(8);
        }
        
        while(!is_game_over(&world)){ // Tq le jeu n'est pas fini
        
            // Gestion des évènements
            handle_events(&event,&world,&menu,&program);

            switch(program.mode){
                case 0:
                    // Mise à jour des données liée à la physique du monde mode normal
                    update_data(&world,&menu);
                break;
                case 1:
                    // Mise à jour des données liée à la physique du monde mode infinie
                    /*
                    WIP
                    update_endless(&world,&menu,bloc);
                    */
                    update_data(&world,&menu);
                break;
            }
            

            // Rafraichissement de l'écran
            refresh_graphics(renderer, &world, &textures, &menu);
    
            // Pause de 8 ms pour controler la vitesse de rafraichissement
            pause(8);
        }
        
        init_menu(&menu,4);
        while((!is_menu_over(&menu))&&(!is_menu_quitte(&menu))){
            // Gestion des évènement
            handle_events_menu(&event,&world,&menu,&program);
            // Rafraichissement de l'écran
            refresh_menu_graphics(renderer,&menu,&textures);
            // Pause de 8 ms pour controler la vitesse de rafraichissement
            pause(8);
            if(program.restart==1){
                init_world(&world);
            }
        }
    }
    if(!is_menu_quitte(&menu)){
        // Affichage de l'écran de fin
        if (is_finish(&world) == 1)
        {
            print_end(renderer, &textures);
            pause(3000);
        }
        else
        {
            print_end_b(renderer, &textures);
            pause(3000);
        }
        
    }
    // Nettoyage final
    clean(window,renderer,&textures,&world);
    exit(0);
    return 0;
}
