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
 *  \brief Fonction de test pour init_sprit
 * \param sprite Le sprite qui sera initialiser et tester 
 * \param x Position sur les abcisses
 * \param y Position sur les ordonnées
 * \param w Largeur du sprit
 * \param h Hauteur du sprite
 */
void test_init_sprite_param(textures_t *sprite,int x,int y,int w,int h){
	init_sprite(&sprite,x,y,w,h);
	print_sprite(&sprite);
}

void test_init_sprite(){
	textures_t sprite_test;

	printf("=========================\n");
	test_init_sprite_param(&sprite_test,50,50,90,90);
	printf("=========================\n");
	test_init_sprite_param(&sprite_test,0,0,0,0);
	printf("=========================\n");
	test_init_sprite_param(&sprite_test,-50,-50,-90,-90);
	printf("=========================\n");
	test_init_sprite_param(&sprite_test,50,50,-90,-90);
	printf("=========================\n");
	test_init_sprite_param(&sprite_test,-50,-50,90,90);
	printf("=========================\n");
}



/**
 *  \brief Main pour le programme de test pour le module game_event.h 
 * \param argc Taille du tableau argv.
 * \param argv Pointeur vers un tableau de char de taille argc.
 * \return 0, si il n'y a pas eu d'erreurs.
 */
int main( int argc, char* argv[]){


	test_init_sprite();


    return 0;
}