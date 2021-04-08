/**
 * \file param.h
 * \brief Fichier qui contient les different constante librerie et structure
 * \author Periney Yann
 * \version 1
 * \date 1 avril 2021
*/


#ifndef __PARAM__H__
#define __PARAM__H__

/* ======================== INCLUDE ======================== */
#include <SDL2/SDL.h>

/* ======================== END INCLUDE ==================== */

/* ======================== DEFINE ======================== */
/**
 * \brief Largeur de l'écran de jeu.
 */
#define SCREEN_WIDTH 300

/**
 * \brief Hauteur de l'écran de jeu.
 */
#define SCREEN_HEIGHT 480


/**
 * \brief Taille d'un vaisseau.
 */
#define SHIP_SIZE 32


/**
 * \brief Taille d'un météorite.
*/
#define METEORITE_SIZE 32


/**
 * \brief Hauteur de la ligne d'arrivée.
 */
#define FINISH_LINE_HEIGHT 10


/**
 * \brief Pas de déplacement horizontal du vaisseau.
*/
#define MOVING_STEP 10


/**
  * \brief Vitesse initiale de déplacement vertical des éléments du jeu.
*/
#define INITIAL_SPEED 2

/**
 * \brief Nombre de mur de météorite.
 */
#define MAX_METEORITE_WALL_NUMBER 20
/**
 * \brief Nombre de mur de météorite.
 */
#define METEORITE_WALL_NUMBER 4

/* ====================== END DEFINE ====================== */

/* ======================== STRUCT ======================== */

/**
 * \brief Représentation pour stocker les textures nécessaires à l'affichage graphique.
*/
struct textures_s{
    SDL_Texture* background; /*!< Texture liée à l'image du fond de l'écran. */
    SDL_Texture* vaisseau; /*!< Texture liée à l'image du vaisseau. */
    SDL_Texture* arrival; /*!< Texture liée à l'image de la ligne d'arrivée. */
    SDL_Texture* meteorite; /*!< Texture liée à l'image d'un météorite. */
};
/**
 * \brief Type qui correspond aux textures du jeu.
*/
typedef struct textures_s textures_t;

/**
 * \brief Représentation d'une texture du jeu.
*/
struct sprite_s{
	int x; /*!< Position du sprite sur x. */
	int y; /*!< Position du sprite sur y. */
	int w; /*!< Largeur du sprite. */
	int h; /*!< Hauteur du sprite. */
};
/**
 * \brief Type qui correspond à une texture.
 */
typedef struct sprite_s sprite_t;

/**
 * \brief Représentation du monde du jeu.
*/
struct world_s{
    int gameover; /*!< Champ indiquant si l'on est à la fin du jeu. */
    sprite_t vaisseau; /*!< Information du vaisseau. */
    sprite_t arrival; /*!< Information de la ligne d'arrivée. */
    int vy; /*!< Vitesse de déplacement verticale. */
    sprite_t mur[MAX_METEORITE_WALL_NUMBER]; /*!< Informations sur un mur d'astéroides. */
    int make_disappear; /*!< Informe si le vaisseau doit être visible ou pas */
};
/**
 * \brief Type qui correspond aux données du monde.
 */
typedef struct world_s world_t;

/* ====================== END STRUCT ====================== */
/* ========================= LIB ========================== */


/* ======================= END LIB ======================== */

#endif
