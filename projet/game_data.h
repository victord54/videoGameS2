/**
 * @file game_event.h
 * @author Victor Dallé / Yann Periney
 * @brief En-tête du module de gestion des évènements du jeu.
 * @version 0.1
 * @date 2021-04-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef DEF_GAME_EVENT_H
#define DEF_GAME_EVENT_H

#include "param.h"
#include "sdl2-light.h"

/* ========== FONCTIONS ========== */

/**
 * \brief La fonction indique si le jeu est fini en fonction des données du monde en mode normale.
 * \param world Les données du monde.
 * \return 1 si le jeu est fini, 0 sinon.
 */
int is_game_over(world_t *world);

/**
 * \brief La fonction indique si le programme est fini.
 * \param program Les données du program.
 * \return 1 si le jeu est fini, 0 sinon.
 */
int is_program_over(program_t* program);


/**
 * \brief La fonction met à jour les données en tenant compte de la physique du monde.
 * \param world Les données du monde.
 * \param menu Les données du menu.
 */
void update_data(world_t *world,menu_t *menu);

/**
 * \brief La fonction initialise les données d'un sprite selon les valeurs entrées.
 * \param sprite Pointeur vers sprite_t pour l'initialisation des données.
 * \param x Coordonnée x du sprite.
 * \param y Coordonnée y du sprite.
 * \param w Largeur du sprite.
 * \param h Hauteur du sprite.
 */
void init_sprite(sprite_t *sprite, int x, int y, int w, int h);

/**
 * \brief La fonction initialise les données d'un sprite de meteore selon les valeurs entrées.
 * \param sprite Pointeur vers sprite_t pour l'initialisation des données.
 * \param x Coordonnée x du sprite.
 * \param y Coordonnée y du sprite.
 * \param w Largeur du sprite.
 * \param h Hauteur du sprite.
 * \param screen_nbr L'ecran ou le meteore doit être placer
 */
void init_sprite_meteore(sprite_t *sprite, int x, int y, int w, int h,int screen_nbr);

/**
 * \brief La fonction initialise les données.
 * \param world Les données du monde.
 * \param menu Les données du menu.
 * \param program Les données du program.
 */
void init_data(world_t * world,menu_t *menu,program_t *program);

/**
 * \brief Fonction qui detecte si le vaisseau est hors de l'écran.
 * \param world Structure des données du monde.
 */
void out_of_screen(world_t *world);

/**
 * \brief Fonction qui detecte si deux sprite sont en collision.
 * \param sp1 premier sprite 
 * \param sp2 second prite 
 * \return 1 si collision est 0 si aucun collision.
 */
int sprites_collide(sprite_t *sp1, sprite_t *sp2);


/**
 * \brief Fonction qui change la vitesse du monde en cas de collision.
 * \param world Structure des données du monde.
 * \param sp1 premier sprite 
 * \param sp2 second prite 
 * \param make_disappear détermine la visibilité du premie sprite de la fonction
 */
void handle_sprites_collision(world_t *world,sprite_t *sp1, sprite_t *sp2,int *make_disappear,int *next_level);

/**
 * \brief Fonction qui change initalise les murs
 * \param world Structure des données du monde.
 */
void init_walls(world_t *world);

/**
 * \brief Fonction qui update la position de tout les murs
 * \param world Structure des données du monde.
 */
void update_walls(world_t *world);

/**
 * @brief Fonction qui teste si on a gagné.
 * 
 * @param world Le monde.
 * @return 1 si on a gagnier 2 si on a perdu.
 */
int is_finish(world_t *world);

/**
 * \brief Fonction qui charge le prochain niveaux.
 * \param world Structure des données du monde.
 */
void newlevel(world_t *world);

/**
 * \brief La fonction initialise les données du monde.
 * \param world Structure des données du monde.
*/ 
void init_world(world_t *world);

/**
 * \brief La fonction initialise les données du menu.
 * \param menu Structure des données du menu.
 * \param menu_nbr Défini quel menu doit être initialiser
*/ 
void init_menu(menu_t *menu,int menu_nbr);

/**
 * \brief La fonction initialise les données du program.
 * \param program Structure des données du monde.
*/ 
void init_program(program_t *program);

/**
 * @brief Fonction qui initialise tous les murs du niveau 1.
 * 
 * @param world Les données du monde.
 */
void level_1(world_t *world);

/**
 * @brief Fonction qui initialise tous les murs du niveau 2.
 * 
 * @param world Les données du monde.
 */
void level_2(world_t *world);

/**
    \brief Fonction qui initialise le mode endless.
*/
void endless_mode(endless_t *bloc,world_t *world);

/**
 * \brief Fonction qui initialise les bloc du mode endless.
 * \param bloc Un bloc du mode endless.
 * \param meteore_groupe Le groupe de météore qui sera initialiser.
 * \param debut indique les entrées du bloc.
 * \param fin indique les sorties du bloc.
 * \param x Coordonnée x du sprite.
 * \param y Coordonnée y du sprite.
 * \param w Largeur du sprite.
 * \param h Hauteur du sprite.
 * \param meteore_number nombre de météore dans le bloc.
*/
void init_endless_bloc(endless_t *bloc, int meteore_groupe , int debut, int fin ,int x, int y, int w, int h,int meteore_number);


/**
 * \brief Fonction qui initialise les blocs
 * \param bloc Un bloc du mode endless.
*/
void bloc_init(endless_t *bloc);

/**
 * \brief Fonction qui initialise le bloc 1
 * \param bloc Un bloc du mode endless.
*/
void bloc_0(endless_t *bloc);

/**
 * \brief Fonction qui initialise le bloc 1
 * \param bloc Un bloc du mode endless.
*/
void bloc_1(endless_t *bloc);

/**
 * \brief Fonction qui initialise le bloc 2
 * \param bloc Un bloc du mode endless.
*/
void bloc_2(endless_t *bloc);

/**
 * \brief Fonction qui initialise le bloc 3
 * \param bloc Un bloc du mode endless.
*/
void bloc_3(endless_t *bloc);

/**
 * \brief Fonction qui initialise le bloc 4
 * \param bloc Un bloc du mode endless.
*/
void bloc_4(endless_t *bloc);

/**
 * \brief Fonction qui initialise le bloc 5
 * \param bloc Un bloc du mode endless.
*/
void bloc_5(endless_t *bloc);

/**
 * \brief Fonction qui initialise le bloc 6
 * \param bloc Un bloc du mode endless.
*/
void bloc_6(endless_t *bloc);

/**
 * \brief Fonction qui initialise le bloc 7
 * \param bloc Un bloc du mode endless.
*/
void bloc_7(endless_t *bloc);

/**
 * \brief Fonction qui initialise le bloc 8
 * \param bloc Un bloc du mode endless.
*/
void bloc_8(endless_t *bloc);

/**
 * \brief Fonction qui initialise le bloc 9
 * \param bloc Un bloc du mode endless.
*/
void bloc_9(endless_t *bloc);

/**
 * \brief Fonction qui initialise le bloc 10
 * \param bloc Un bloc du mode endless.
*/
void bloc_10(endless_t *bloc);

/**
 * \brief Fonction qui initialise le bloc 11
 * \param bloc Un bloc du mode endless.
*/
void bloc_11(endless_t *bloc);

/**
 * \brief Fonction qui initialise le bloc 12
 * \param bloc Un bloc du mode endless.
*/
void bloc_12(endless_t *bloc);

/**
 * \brief La fonction met à jour les données en tenant compte de la physique du monde en mode infinie.
 * \param world Les données du monde.
 * \param menu Les données du menu.
 */
void update_endless(world_t *world,menu_t *menu,endless_t *bloc);

#endif
