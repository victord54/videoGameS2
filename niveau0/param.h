/**
 * \file param.h
 * \brief Répértoire des different constante,librerie et structure utiliser
 * \author Periney Yann
 * \version 1
 * \date 28 mars 2021
*/

#ifndef __param_h__
#define __param_h__


		//Librerie utiliser
	//Librerie de base

#include <stdio.h>
#include <stdlib.h>

	//Librerie d'affichage

#include <SDL2/SDL.h>


		//Constante

/**
 * \brief Largeur de l'écran
*/
#define SCREEN_WIDTH 320

/**
 * \brief Hauteur de l'écran
*/
#define SCREEN_HEIGHT 240

/**
 * \brief Taille du sprite
*/
#define SPRITE_SIZE 32

/**
 * \brief Pas de déplacement du sprite
*/
#define MOVING_STEP 10


		//Structure utiliser

/**
 * \brief Représentation pour stocker les textures nécessaires à l'affichage graphique
*/
struct textures_s{
    SDL_Texture* background; /*!< Texture liée à l'image du fond de l'écran. */
    SDL_Texture* sprite; /*!< Texture liée au personnage. */
    /* A COMPLETER */
};
/**
 * \brief Type qui correspond aux textures du jeu
*/
typedef struct textures_s textures_t;


/**
 * \brief Représentation du monde du jeu
*/
struct world_s{
    int gameover; /*!< Champ indiquant si l'on est à la fin du jeu */
    int x; /*!< Coordonnée x du personnage. */
    int y; /*!< Coordonnée y du personnage. */
};
/**
 * \brief Type qui correspond aux données du monde
 */
typedef struct world_s world_t;



#endif