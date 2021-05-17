/**
 * @file param.h
 * @author Yann Periney / Victor Dallé
 * @brief Fichier en-tête avec toutes les constantes et les structures
 * @version 0.1
 * @date 2021-04-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#ifndef __PARAM__H__
#define __PARAM__H__

/* ======================== INCLUDE ======================== */
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <time.h>

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
#define MOVING_STEP 16


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
#define METEORITE_WALL_NUMBER 16

/**
 * @brief Nombre de blocs pour le mode infini
 * 
 */
#define ENDLESS_MODE_BLOC_NUMBER 10

/**
 * @brief Nombre d'écrans pour le mode infini
 * 
 */
#define ENDLESS_MODE_SCREEN_NUMBER 12

/* ====================== END DEFINE ====================== */

/* ======================== STRUCT ======================== */

/**
 * \brief Représentation pour stocker les textures nécessaires à l'affichage graphique.
*/
struct textures_s{
    SDL_Texture *background; /*!< Texture liée à l'image du fond de l'écran. */
    SDL_Texture *vaisseau; /*!< Texture liée à l'image du vaisseau. */
    SDL_Texture *arrival; /*!< Texture liée à l'image de la ligne d'arrivée. */
    SDL_Texture *meteorite; /*!< Texture liée à l'image d'un météorite. */
    TTF_Font *font; /*!< Texture liée à la police utilisée. */
    SDL_Texture *menu_background; /*!< Texture liée au background du menu. */
    SDL_Texture *rules; /*!< Texture liée aux règles du jeu. */
    SDL_Texture *menu1_select; /*!< Texture liée a la selection pour le menu 1. */
    SDL_Texture *menu_replay; /*!< Texture liée au replay du jeu. */
    SDL_Texture *fin; /*!< Texture liée à la fin du jeu. (si on a gagné) */
    SDL_Texture *finb; /*!< Texture liée à la fin du jeu (si on a perdu) */
    SDL_Texture *menu1_background; /*!< Texture liée au choix du niveau. */
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
  int num_screen; /*!< Ecran ou apparait le sprite. */
};
/**
 * \brief Type qui correspond à une texture.
 */
typedef struct sprite_s sprite_t;

/**
 * \brief Représentation des données du monde.
*/
struct world_s{
    int gameover; /*!< Champ indiquant si l'on est à la fin du jeu. */
    int levelstart; /*!< Indique le début d'un niveaux. */
    sprite_t vaisseau; /*!< Information du vaisseau. */
    sprite_t arrival; /*!< Information de la ligne d'arrivée. */
    int vy; /*!< Vitesse de déplacement verticale. */
    sprite_t mur[MAX_METEORITE_WALL_NUMBER]; /*!< Informations sur un mur d'astéroides. */
    int make_disappear; /*!< Informe si le vaisseau doit être visible ou pas */
    int levelnbr; /*!< Information sur le nombre de niveaux. */
    int level; /*!< Informe du niveaux a afficher. */
    endless_t endless_level[ENDLESS_MODE_BLOC_NUMBER]; /*!< Contient tous les blocs de météorites possibles. */
};
/**
 * \brief Type qui correspond aux données du monde.
 */
typedef struct world_s world_t;


/**
 * \brief Représentation des données du menu.
*/
struct menu_s{
  int menuover; /*!< Champ indiquant si l'on est à la fin du menu. */
  int menunumber; /*!< Nombre de menu. */
  int currentmenu; /*!< Le menu actuellement sélectionné. */
  int optionnumber; /*!< Nombre d'option sur le menu. */
  int currentoption; /*!< Option actuellement sélectionnée. */
  int time; /*!< Sauvegarde le temps d'execution du menu. */
  int quitte; /*!< Informe si l'on affiche l'ecran de fin. */
};
/**
 * \brief Type qui correspond aux données du menu.
 */
typedef struct menu_s menu_t;

/**
 * \brief Réprésentation des données du programme.
*/
struct program_s{
  int programover; /*!< Champ indiquand la fin du programme. */
  int restart; /*!< Champ indiquand le redémarage du jeux. */
  int mode; /*!< Champ indiquand le mode de jeux. */
};
/**
 * \brief Type qui correspond aux données du programme.
 */
typedef struct program_s program_t;

/**
 * @brief Structure pour avoir les infos d'un bloc de murs.
 * 
 */
struct endless_s
{
  int debut; /*!< position du début du bloc. */
  int fin; /*!< position de la fin du bloc. */ 
  sprite_t coord[20]; /*!< Coordonnées du sprite. */
  int meteore_number; /*!< Nombre de météores dans le bloc. */
};
/**
 * @brief Type qui correspond aux infos d'un bloc
 * 
 */
typedef struct endless_s endless_t;


/* ====================== END STRUCT ====================== */
/* ========================= LIB ========================== */


/* ======================= END LIB ======================== */

#endif
