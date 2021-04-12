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
 * \brief Fonction de test_param pour init_sprite.
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


/**
 * @brief Fonction de test pour la sortie de l'écran du vaisseau.
 * @param world Données du monde.
 */
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
 * @brief Fonction de test pour la collision de 2 sprites.
 * @param sprite1 Premier sprite.
 * @param sprite2 Deuxième sprite.
 */
void test_sprites_collide_param(sprite_t sprite1,sprite_t sprite2){
	if(sprites_collide(&sprite1,&sprite2)==0){
		printf("	Pas de collision.\n");
	}
	if(sprites_collide(&sprite1,&sprite2)==1){
		printf("	Collision.\n");
	}
	print_sprite(&sprite1);
	print_sprite(&sprite2);
	printf("=========================\n");
}

void test_sprites_collide(){
	sprite_t spr1,spr2;
		//Pas de colision avec même zone x
	spr1.x=1;
	spr1.y=1;
	spr1.h=2;
	spr1.w=2;
	spr2.x=2;
	spr2.y=4;
	spr2.h=2;
	spr2.w=2;
	test_sprites_collide_param(spr1,spr2);

		//Pas de colision avec même zone y
	spr2.x=4;
	spr2.y=2;
	test_sprites_collide_param(spr1,spr2);

	spr1.w=4;
	spr2.x=2;
	spr2.y=4;
	test_sprites_collide_param(spr1,spr2);

		//Test de colision
	spr2.x=2;
	spr2.y=2;
	test_sprites_collide_param(spr1,spr2);
}

/**
 * @brief Fonction de test effectuant des modifs sur data world lors d'une collision.
 * @param world Données du monde.
 * @param spr1 Premier sprite.
 * @param spr2 Deuxième sprite.
 * @param disp disparition (bool) du vaisseau.
 */
void test_handle_sprites_collision_param(world_t world,sprite_t spr1, sprite_t spr2,int disp){
	handle_sprites_collision(&world,&spr1,&spr2,&world.make_disappear);
	if(world.vy!=0){
		printf("	Pas de collision\n");
	}
	if(world.vy==0){
		printf("	Collision\n");
	}
	printf("Vitesse du monde vy=%d\n",world.vy);
	printf("world.make_disappear=%d\n",world.make_disappear);
	print_sprite(&spr1);
	print_sprite(&spr2);
	printf("=========================\n");
}

void test_handle_sprites_collision(){
	world_t world;
	sprite_t spr1,spr2;
	

	//Test de collision
	world.vy=10;
	world.make_disappear=0;
	//Collision
	spr1.x=0;
	spr1.y=0;
	spr1.h=7;
	spr1.w=3;
	spr2.x=1;
	spr2.y=3;
	spr2.h=1;
	spr2.w=1;

	test_handle_sprites_collision_param(world,spr1,spr2,world.make_disappear);

	//Pas de collision
	spr2.x=5;
	spr2.y=2;
	test_handle_sprites_collision_param(world,spr1,spr2,world.make_disappear);

	//Pas de collision
	spr2.x=2;
	spr2.y=5;
	test_handle_sprites_collision_param(world,spr1,spr2,world.make_disappear);
}

void test_update_walls_param(world_t *world){


}
void test_update_walls(){
	world_t monde;

	monde->mur[10];
}

/**
 *  \brief Main pour le programme de test pour le module game_event.h 
 * \param argc Taille du tableau argv.
 * \param argv Pointeur vers un tableau de char de taille argc.
 * \return 0, si il n'y a pas eu d'erreurs.
 */
int main( int argc, char* argv[]){
	//test_init_sprite();

	//test_out_of_screen();
	
	//test_sprites_collide();

	//test_handle_sprites_collision();
    
	return 0;
}