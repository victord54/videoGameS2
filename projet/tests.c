/**
 * \file tests.c
 * \brief Fichier de test pour les fonction de game_event
 * \author Periney Yann Victor Dallé
 * \version 1
 * \date 1 avril 2021
*/

#include "param.h"
#include "game_event.h"

/**
 * \brief Fonction qui affiche les coordonnées d'un sprite.
 * \param sprite Sprite cible du test.
 */
void print_sprite(sprite_t *sprite)
{
	printf("Position en x = %d \nPosition en y %d \nLargueur = %d \nHauteur = %d\n", sprite->x, sprite->y, sprite->w, sprite->h);
}

/**
 * \brief Fonction de test pour init_sprit
 * \param sprite Le sprite qui sera initialisé et testé.
 * \param x Position de l'abscisse.
 * \param y Position de l'ordonnée.
 * \param w Largeur du sprite.
 * \param h Hauteur du sprite.
 */
void test_init_sprite_param(sprite_t sprite, int x, int y, int w, int h){
	init_sprite(&sprite,x,y,w,h);
	print_sprite(&sprite);
}

void test_init_sprite(){
	sprite_t sprite_test;

	printf("=========================\n");
	test_init_sprite_param(sprite_test,50,50,90,90);
	printf("=========================\n");
	test_init_sprite_param(sprite_test,0,0,0,0);
	printf("=========================\n");
	test_init_sprite_param(sprite_test,-50,-50,-90,-90);
	printf("=========================\n");
	test_init_sprite_param(sprite_test,50,50,-90,-90);
	printf("=========================\n");
	test_init_sprite_param(sprite_test,-50,-50,90,90);
	printf("=========================\n");
}

void test_out_of_screen_param(world_t *world)
{
	out_of_screen(world);
	printf("x = %d \ny = %d\n",world->vaisseau.x, world->vaisseau.y);
	printf("=========================\n");
}

void test_out_of_screen()
{
	world_t world;
	world.vaisseau.x = 0;
	world.vaisseau.y = 0;
	test_out_of_screen_param(&world);
	world.vaisseau.x = 300;
	world.vaisseau.y = 0;
	test_out_of_screen_param(&world);
}



/**
 *  \brief Main pour le programme de test pour le module game_event.h 
 * \param argc Taille du tableau argv.
 * \param argv Pointeur vers un tableau de char de taille argc.
 * \return 0, si il n'y a pas eu d'erreurs.
 */
int main( int argc, char* argv[]){
	//test_init_sprite();

	test_out_of_screen();
	
    return 0;
}