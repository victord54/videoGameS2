/**
 * \file game_event.c
 * \brief Module de gestions des événements
 * \author Victor Dallé
 * \version 1.0
 * \date 1 avril 2021
 */

#include "game_event.h"

int is_game_over(world_t *world){
    return world->gameover;
}

void update_data(world_t *world){
    world->arrival.y += world->vy;
    for(int i=0;i<METEORITE_WALL_NUMBER;i++){
        world->mur[i].y += world->vy;
    }
        //On utilise not_disappear quand la collision ne doit pas changer l'affichage
    int not_disappear;
    for(int i=0;i<METEORITE_WALL_NUMBER;i++){
        handle_sprites_collision(world, &world->mur[i], &world->vaisseau,&world->make_disappear);
    }
    handle_sprites_collision(world, &world->arrival, &world->vaisseau,&not_disappear);
}

void handle_events(SDL_Event *event, world_t *world){
    //Uint8 *keystates;
    while( SDL_PollEvent(event)){
        
        //Si l'utilisateur a cliqué sur le X de la fenêtre
        if(event->type == SDL_QUIT){
            //On indique la fin du jeu
            world->gameover = 1;
        }
       
        //si une touche est appuyée
        if(event->type == SDL_KEYDOWN){
            //si la touche appuyée est 'D'
            if(event->key.keysym.sym == SDLK_d){
                printf("La touche D est appuyée\n");
                world->vaisseau.x+= MOVING_STEP;
              }
            
            //si la touche appuyée est 'Q'
            if(event->key.keysym.sym == SDLK_q){
                printf("La touche Q est appuyée\n");
                world->vaisseau.x-= MOVING_STEP;
            }

            if(event->key.keysym.sym == SDLK_ESCAPE){
            //On indique la fin du jeu
            printf("La touche ECHAP est appuyée\n");
            world->gameover = 1;
            }

            if(event->key.keysym.sym == SDLK_z){
            //On indique la fin du jeu
            printf("La touche Z est appuyée\n");
            world->vy=world->vy+1;
            }

            if(event->key.keysym.sym == SDLK_s){
            //On indique la fin du jeu
            printf("La touche S est appuyée\n");
            world->vy=world->vy-1;
            }

            out_of_screen(world);
        }
    }
}

void init_sprite(sprite_t *sprite, int x, int y, int w, int h){
	sprite->x=x;
	sprite->y=y;
	sprite->w=w;
	sprite->h=h;
}

void init_data(world_t * world){
    // On n'est pas à la fin du jeu
    world->gameover = 0;
    world->make_disappear=0;

	// Initialisation du vaisseau
	init_sprite(&world->vaisseau,SCREEN_WIDTH/2 - SHIP_SIZE/2,SCREEN_HEIGHT - SHIP_SIZE*2,SHIP_SIZE,SHIP_SIZE);

    // Initialisation de la ligne d'arrivée
    init_sprite(&world->arrival,0,FINISH_LINE_HEIGHT-SCREEN_HEIGHT,SCREEN_WIDTH,FINISH_LINE_HEIGHT);

    // Initialisation de la vy
    world->vy = INITIAL_SPEED;

    // Initialisation d'un mur de météorites.
        //taille d'un ecran 9*14
        //position x du mur 
        //position y du mur 
        //nombre de meteore en x
        //nombre de meteore en y
    init_sprite(&world->mur[0],0*METEORITE_SIZE,3*METEORITE_SIZE,3*METEORITE_SIZE,6*METEORITE_SIZE);
    init_sprite(&world->mur[1],6*METEORITE_SIZE,3*METEORITE_SIZE,3*METEORITE_SIZE,6*METEORITE_SIZE);
    init_sprite(&world->mur[2],3*METEORITE_SIZE,9*METEORITE_SIZE-SCREEN_HEIGHT,6*METEORITE_SIZE,4*METEORITE_SIZE);
    init_sprite(&world->mur[3],0*METEORITE_SIZE,2*METEORITE_SIZE-SCREEN_HEIGHT,6*METEORITE_SIZE,4*METEORITE_SIZE);
}

void out_of_screen(world_t *world)
{
    if (world->vaisseau.x < 0)
    {
        world->vaisseau.x = 0;
    }

    if (world->vaisseau.x + SHIP_SIZE > SCREEN_WIDTH)
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
    
    if ((x2 > x1 && x2 < x1 + w1) || (x2 + w2 > x1 && x2 + w2 < x1 + w1))
    {
        col_x = 1;
    }

    if ((y2 > y1 && y2 < y1 + h1) || (y2 + h2 > y1 && y2 + h2 < y1 + h1))
    {
        col_y = 1;
    }
    
    if (col_x && col_y)
    {
        return 1;
    }
    return 0;
}

void handle_sprites_collision(world_t *world,sprite_t *sp1, sprite_t *sp2, int *make_disappear){
    if (sprites_collide(sp1,sp2)){
        world->vy=0;

        *make_disappear=1;
    }
}