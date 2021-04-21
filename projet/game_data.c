/**
 * @file game_event.c
 * @author Victor Dallé / Yann Periney
 * @brief Module de gestion des évènements du jeu.
 * @version 0.1
 * @date 2021-04-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "game_data.h"

int is_game_over(world_t *world){
    return world->gameover;
}

void update_data(world_t *world){
    world->arrival.y += world->vy; // Fait descendre la ligne d'arrivée
    update_walls(world); // Fait descendre les murs

    //On utilise not_disappear quand la collision ne doit pas changer l'affichage
    int not_disappear;
    
    for(int i=0;i<METEORITE_WALL_NUMBER;i++){
        handle_sprites_collision(world, &world->mur[i], &world->vaisseau,&world->make_disappear); // Vérifie une collision sur le nombre de murs du tableau pour faire disparaitre le vaisseau
    }
    handle_sprites_collision(world, &world->arrival, &world->vaisseau,&not_disappear); // Vérifie la collision avec la ligne d'arrivée pour ne pas faire disparaître le vaisseau
}

void init_sprite(sprite_t *sprite, int x, int y, int w, int h){
	sprite->x=x;
	sprite->y=y;
	sprite->w=w;
	sprite->h=h;
}
void init_sprite_meteore(sprite_t *sprite, int x, int y, int w, int h,int screen_nbr){
	sprite->x=x*METEORITE_SIZE;
	sprite->y=y*METEORITE_SIZE-SCREEN_HEIGHT*screen_nbr;
	sprite->w=w*METEORITE_SIZE;
	sprite->h=h*METEORITE_SIZE;
}

void init_data(world_t * world,menu_t *menu){
    // On n'est pas à la fin du jeu
    world->gameover=0;
    // Le sprite doit être visible
    world->make_disappear=0;
    // On est pas a la fin du menu
    menu->menuover=0;
    // On définit le nombre total de menu 
    menu->menunumber=1;
    // On commence au premier menu
    menu->currentmenu=1;
    // On définit le nombre d'option du premier menu
    menu->optionnumber=2;
    // On est a la premiére option du menu
    menu->currentoption=1;
	// Initialisation du vaisseau
	init_sprite(&world->vaisseau,SCREEN_WIDTH/2 - SHIP_SIZE/2,SCREEN_HEIGHT - SHIP_SIZE*2,SHIP_SIZE,SHIP_SIZE);

    // Initialisation de la ligne d'arrivée
    init_sprite(&world->arrival,0,FINISH_LINE_HEIGHT-SCREEN_HEIGHT*3-METEORITE_SIZE,SCREEN_WIDTH,FINISH_LINE_HEIGHT);

    // Initialisation de la vy
    world->vy = INITIAL_SPEED;

    // Initialisation d'un mur de météorites.
    init_walls(world);
}

void out_of_screen(world_t *world)
{
    if (world->vaisseau.x < 0) // Si le vaisseau sort à gauche on le replace
    {
        world->vaisseau.x = 0;
    }

    if (world->vaisseau.x + SHIP_SIZE > SCREEN_WIDTH) // Si le vaisseau sort à droite on le replace
    {
        world->vaisseau.x = SCREEN_WIDTH - SHIP_SIZE;
    }
}

int sprites_collide(sprite_t *sp1, sprite_t *sp2){
    int tempx,tempy,x1,x2,y1,y2,w1,w2,h1,h2,col_x = 0,col_y = 0;
    x1=sp1->x;
    y1=sp1->y;
    w1=sp1->w;
    h1=sp1->h;
    x2=sp2->x;
    y2=sp2->y;
    w2=sp2->w;
    h2=sp2->h;
    
    if ((x2 > x1 && x2 < x1 + w1) || (x2 + w2 > x1 && x2 + w2 < x1 + w1)) // Si le coté gauche ou droit du sprite2 est entre les cotés du sprite1
    {
        col_x = 1;
    }

    if ((y2 > y1 && y2 < y1 + h1) || (y2 + h2 > y1 && y2 + h2 < y1 + h1)) // Si le coté sup ou inf du sprite2 est entre les cotés sup et inf du sprite1
    {
        col_y = 1;
    }
    
    if (col_x && col_y) // Si il y a une collision en x et en y
    {
        return 1;
    }
    return 0;
}

void handle_sprites_collision(world_t *world,sprite_t *sp1, sprite_t *sp2, int *make_disappear){
    if (sprites_collide(sp1,sp2)){
        world->vy=0;
        world->gameover = 1;
        *make_disappear=1;
    }
}

void init_walls(world_t *world){

    // Taille d'un ecran 9*14
    // Position x du mur, position y du mur, nombre de meteore en x, nombre de meteore en y ,numero de l'ecran 
    
    /* ===== Placement meteorite niveau 1 ===== */
    // Écran 1
    init_sprite_meteore(&world->mur[0],0,2,3,6,0);
    init_sprite_meteore(&world->mur[1],6,2,3,6,0);

    // Écran 2
    init_sprite_meteore(&world->mur[2],0,3,6,3,1);
    init_sprite_meteore(&world->mur[3],3,9,6,3,1);

    // Écran 3
    init_sprite_meteore(&world->mur[4],0,1,3,1,2);
    init_sprite_meteore(&world->mur[5],6,1,3,1,2);
    init_sprite_meteore(&world->mur[6],3,5,6,3,2);
    init_sprite_meteore(&world->mur[7],6,8,3,6,2);
    init_sprite_meteore(&world->mur[8],0,11,3,3,2);

    // Écran 4
    init_sprite_meteore(&world->mur[9],2,0,2,1,3);
    init_sprite_meteore(&world->mur[10],0,4,2,1,3);
    init_sprite_meteore(&world->mur[11],2,8,2,1,3);
    init_sprite_meteore(&world->mur[12],0,13,2,1,3);
    init_sprite_meteore(&world->mur[13],4,0,1,13,3);
    init_sprite_meteore(&world->mur[14],5,4,3,1,3);
    init_sprite_meteore(&world->mur[15],7,13,2,1,3);
}

void update_walls(world_t *world){
    // Update de la postion y de tous les sprite du mur de météorites
    for(int i=0;i<METEORITE_WALL_NUMBER;i++){
        world->mur[i].y=world->vy+world->mur[i].y;
    }
}

int is_finish(world_t *world)
{
    // Si il y a eu une collision et que le vaisseau est au niveau de la ligne d'arrivée
    if (world->gameover && world->vaisseau.y <= world->arrival.y+FINISH_LINE_HEIGHT)
        return 1; // 1 = gagné
    // Si il y a eu collision et que le vaisseau est en dessous de la ligne d'arrivée (graphiquement)
    else if (world->gameover && world->vaisseau.y > world->arrival.y+FINISH_LINE_HEIGHT)
        return 2; // 2 = perdu
    return 0;
}