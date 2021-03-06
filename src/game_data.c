/**
 * @file game_event.c
 * @author Victor Dallé / Yann Periney
 * @brief Module de gestion des évènements du jeu.
 * @version 0.1
 * @date 2021-04-01
 * Mise à jour des données liée à la physique du monde mode normal
 * @copyright Copyright (c) 2021
 * 
 */

#include "game_data.h"

int is_game_over(world_t *world){
    return world->gameover;
}

int is_program_over(program_t* program){
    return program->programover;
}


void update_data(world_t *world,menu_t *menu){
    world->arrival.y += world->vy; // Fait descendre la ligne d'arrivée
    update_walls(world); // Fait descendre les murs
    menu->currentmenu=4;

    //On utilise not_disappear quand la collision ne doit pas changer l'affichage
    int not_disappear;
    int next_level=0;
    
    //collision avec les métèorite 
    for(int i=0;i<METEORITE_WALL_NUMBER;i++){
        handle_sprites_collision(world, &world->mur[i], &world->vaisseau,&world->make_disappear,&next_level); // Vérifie une collision sur le nombre de murs du tableau pour faire disparaitre le vaisseau
    }
    //collision avec ligne d'arrivé
    handle_sprites_collision(world, &world->arrival, &world->vaisseau,&not_disappear,&next_level); // Vérifie la collision avec la ligne d'arrivée pour ne pas faire disparaître le vaisseau
    if(next_level){
        newlevel(world);
    }
}

void init_sprite(sprite_t *sprite, int x, int y, int w, int h){
	sprite->x=x;
	sprite->y=y;
	sprite->w=w;
	sprite->h=h;
}

void init_sprite_meteore(sprite_t *sprite, int x, int y, int w, int h,int screen_nbr){
	sprite->x=x*METEORITE_SIZE+6;
	sprite->y=y*METEORITE_SIZE-SCREEN_HEIGHT*screen_nbr;
	sprite->w=w*METEORITE_SIZE;
	sprite->h=h*METEORITE_SIZE;
}

void init_data(world_t * world,menu_t *menu,program_t *program){
    init_world(world);
    init_menu(menu,1);
    init_program(program);
}

void out_of_screen(world_t *world)
{
    if (world->vaisseau.x < 6) // Si le vaisseau sort à gauche on le replace
    {
        world->vaisseau.x = 6;
    }

    if (world->vaisseau.x + SHIP_SIZE > SCREEN_WIDTH-6) // Si le vaisseau sort à droite on le replace
    {
        world->vaisseau.x = SCREEN_WIDTH - SHIP_SIZE-6;
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

void handle_sprites_collision(world_t *world,sprite_t *sp1, sprite_t *sp2, int *make_disappear,int *next_level){
    if (sprites_collide(sp1,sp2)){ // Si il y a collision en x et en y
        world->vy=0;
        world->gameover = 1;
        *make_disappear=1;
        if((world->level<world->levelnbr)&&(is_finish(world)==1)){ // Si on est pas au dernier niveau et qu'on a gagné on passe au niveau suivant
            *next_level=1;
        }
    }
}

void init_walls(world_t *world){

    // Taille d'un ecran 9*14
    // Position x du mur, position y du mur, nombre de meteore en x, nombre de meteore en y ,numero de l'ecran 
    
    switch(world->level){
        case 1:
            /* ===== Placement meteorite niveau 1 ===== */
            level_1(world);
        break;
        case 2:
            /* ===== Placement meteorite niveau 2 ===== */
            level_2(world);
        break;
        default:
            /* ===== Placement meteorite niveau 1 ===== */
        break;
    }
    
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

void newlevel(world_t *world){
    world->gameover=0;
    //On commence un nouveaux niveaux
    world->levelstart=1;
    // On charge le prochain niveaux
    world->level++;
    // Initialisation du vaisseau
    init_sprite(&world->vaisseau,SCREEN_WIDTH/2 - SHIP_SIZE/2,SCREEN_HEIGHT - SHIP_SIZE*2,SHIP_SIZE,SHIP_SIZE);
    // Initialisation de la vy
    world->vy = INITIAL_SPEED;
    // Initialisation de la ligne d'arrivée
    init_sprite(&world->arrival,0,FINISH_LINE_HEIGHT-SCREEN_HEIGHT*3-METEORITE_SIZE,SCREEN_WIDTH,FINISH_LINE_HEIGHT);
    // Initialisation d'un mur de météorites
    init_walls(world);
}

void init_world(world_t* world){
    // On n'est pas à la fin du jeu
    world->gameover=0;
    //On commence un niveau
    world->levelstart=1;
    // Le sprite doit être visible
    world->make_disappear=0;
    // Nombre de niveaux
    world->levelnbr=2;
    // On commence au niveau 1
    world->level=1;
    // Initialisation de la vy
    world->vy = INITIAL_SPEED;
    // Initialisation du vaisseau
    init_sprite(&world->vaisseau,SCREEN_WIDTH/2 - SHIP_SIZE/2,SCREEN_HEIGHT - SHIP_SIZE*2,SHIP_SIZE,SHIP_SIZE);
    // Initialisation de la ligne d'arrivée
    init_sprite(&world->arrival,0,FINISH_LINE_HEIGHT-SCREEN_HEIGHT*3-METEORITE_SIZE,SCREEN_WIDTH,FINISH_LINE_HEIGHT);
    // Initialisation d'un mur de météorites.
    init_walls(world);
}

void init_menu(menu_t* menu,int menu_nbr){
    switch(menu_nbr){
        case 1:
            // On est pas a la fin du menu
            menu->menuover=0;
            // On définit le nombre total de menu 
            menu->menunumber=4;
            // On cest au menu 1
            menu->currentmenu=1;
            // On définit le nombre d'option du menu
            menu->optionnumber=2;
            // On est a la premiére option du menu
            menu->currentoption=1;
            // On affiche le menu de base.
            menu->quitte=0;
        break;
        case 3:
            // On est pas a la fin du menu
            menu->menuover=0;
            // On cest au menu 3
            menu->currentmenu=3;
            // On définit le nombre d'option du menu
            menu->optionnumber=3;
            // On est a la premiére option du menu
            menu->currentoption=1;
        break;
        case 4:
            // On est pas a la fin du menu
            menu->menuover=0;
            // On cest au menu 4
            menu->currentmenu=4;
            // On définit le nombre d'option du menu
            menu->optionnumber=2;
            // On est a la premiére option du menu
            menu->currentoption=1;
        break;
    }
}

void init_program(program_t *program){
    // On est pas a la fin du jeu
    program->programover=0;
    // On ne rédémarre pas le jeu au départ.
    program->restart=0;
    // On débute le programme en mode 0 (normal)
    program->mode=0;
}


void level_1(world_t *world)
{
    // Écran 1
    init_sprite_meteore(&world->mur[0],0,2,3,6,0);
    init_sprite_meteore(&world->mur[1],6,2,3,6,0);
    init_sprite_meteore(&world->mur[16],0,15,9,1,0);

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
    init_sprite_meteore(&world->mur[12],0,13,2,3,3);
    init_sprite_meteore(&world->mur[13],4,0,1,13,3);
    init_sprite_meteore(&world->mur[14],5,4,3,1,3);
    init_sprite_meteore(&world->mur[15],7,13,2,3,3);
}

void level_2(world_t *world)
{
    // Écran 1
    init_sprite_meteore(&world->mur[0],3,2,3,3,0);
    init_sprite_meteore(&world->mur[1],4,4,1,3,0);
    init_sprite_meteore(&world->mur[16],0,15,9,1,0);
    
    // Écran 2
    init_sprite_meteore(&world->mur[2],0,5,3,8,1);
    init_sprite_meteore(&world->mur[3],6,5,3,8,1);

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
    init_sprite_meteore(&world->mur[12],0,13,2,3,3);
    init_sprite_meteore(&world->mur[13],4,0,1,13,3);
    init_sprite_meteore(&world->mur[14],5,4,3,1,3);
    init_sprite_meteore(&world->mur[15],7,13,2,3,3);
}

void endless_mode(endless_t *bloc,world_t *world)
{

    bloc_init(bloc);
    
    world->actual_bloc[0]=bloc[0];

    world->actual_bloc[0]=bloc[randint(1,13)];
    
}

void init_endless_bloc(endless_t *bloc,int meteore_groupe, int debut, int fin ,int x, int y, int w, int h,int meteore_number)
{
    bloc->coord[meteore_groupe].x = x;
    bloc->coord[meteore_groupe].y = y;
    bloc->coord[meteore_groupe].w = w;
    bloc->coord[meteore_groupe].h = h;
    bloc->debut = debut;
    bloc->fin = fin;
}
void bloc_init(endless_t *bloc){
    bloc_0(bloc);
    bloc_1(bloc);
    bloc_2(bloc);
    bloc_3(bloc);
    bloc_4(bloc);
    bloc_5(bloc);
    bloc_6(bloc);
    bloc_7(bloc);
    bloc_8(bloc);
    bloc_9(bloc);
    bloc_10(bloc);
    bloc_11(bloc);
    bloc_12(bloc);
    
    
}

void bloc_0(endless_t *bloc){
/*
    AIDE debut/fin   
    0 rien
    1 droite
    2 milieu
    3 gauche
    4 milieu+ droite
    5 gauche+ droite
    6 gauche+ milieu
*/
        //vide
    init_endless_bloc(&bloc[0],0,0,0,0,0,0,0,0);
}
void bloc_1(endless_t *bloc){
        //droite
    init_endless_bloc(&bloc[1],1,1,1,0,0,6,14,1);
}
void bloc_2(endless_t *bloc){
        //milieu
    init_endless_bloc(&bloc[2],1,2,2,0,0,3,14,2);
    init_endless_bloc(&bloc[2],2,2,2,6,0,3,14,2);
}
void bloc_3(endless_t *bloc){
        //gauche
    init_endless_bloc(&bloc[3],1,3,3,3,0,6,14,1);
}
void bloc_4(endless_t *bloc){
        //milieu+droite
    init_endless_bloc(&bloc[4],1,4,4,0,0,3,14,1);
}
void bloc_5(endless_t *bloc){
        //gauche+droite
    init_endless_bloc(&bloc[5],1,5,5,3,0,3,14,1);
}
void bloc_6(endless_t *bloc){
        //gauche+milieu
    init_endless_bloc(&bloc[6],1,6,6,6,0,3,14,1);
}
void bloc_7(endless_t *bloc){
        //gauche vers milieu
    init_endless_bloc(&bloc[7],1,3,2,0,0,3,3,3);
    init_endless_bloc(&bloc[7],2,3,2,6,0,3,14,3);
    init_endless_bloc(&bloc[7],3,3,2,3,11,0,0,3);
}
void bloc_8(endless_t *bloc){
        //gauche vers droite 
    init_endless_bloc(&bloc[8],1,3,1,0,0,6,3,2);
    init_endless_bloc(&bloc[8],2,3,1,3,11,6,3,2);
}
void bloc_9(endless_t *bloc){
        //milieu vers gauche
    init_endless_bloc(&bloc[9],1,2,3,3,0,6,3,3);
    init_endless_bloc(&bloc[9],2,2,3,6,3,3,11,3);
    init_endless_bloc(&bloc[9],3,2,3,0,11,3,3,3);
}
void bloc_10(endless_t *bloc){
        //milieu vers droite
    init_endless_bloc(&bloc[10],1,2,1,0,0,6,3,3);
    init_endless_bloc(&bloc[10],2,2,1,0,3,3,11,3);
    init_endless_bloc(&bloc[10],3,2,1,6,11,3,3,3);
}
void bloc_11(endless_t *bloc){
        //droite vers milieu
    init_endless_bloc(&bloc[11],1,1,2,0,0,3,14,3);
    init_endless_bloc(&bloc[11],2,1,2,3,11,3,3,3);
    init_endless_bloc(&bloc[11],3,1,2,6,0,3,3,3);
}
void bloc_12(endless_t *bloc){
        //droite vers gauche
    init_endless_bloc(&bloc[12],1,1,3,3,0,6,3,2);
    init_endless_bloc(&bloc[12],2,1,3,0,11,6,3,2);
}

void update_endless(world_t *world,menu_t *menu,endless_t *bloc){
    int actuel_ending=0;
    int temp_debut=0;
    int temp;

    //menu rejouer 
    menu->currentmenu=4;

    //update bloc meteore (A faire)
    

    if(world->actual_bloc[0].coord[0].y>SCREEN_HEIGHT){
        actuel_ending=world->actual_bloc[0].fin;
        if(actuel_ending==0){
            world->actual_bloc[0]=bloc[randint(0,13)];
        }
        if(actuel_ending==1){
            world->actual_bloc[0]=bloc[randint(0,13)];
            temp_debut=world->actual_bloc[0].debut;
            while((temp_debut!=0)||(temp_debut!=1)||(temp_debut!=4)||(temp_debut!=5)){
                world->actual_bloc[0]=bloc[randint(0,13)];
            }
            for(int i=0;i<world->actual_bloc[0].meteore_number;i++){
                world->actual_bloc[0].coord[i].y=world->actual_bloc[0].coord[i].y+SCREEN_HEIGHT;
            }
        }
        if(actuel_ending==2){
            //(0,2,4,6)
            world->actual_bloc[0]=bloc[randint(0,13)];
            temp_debut=world->actual_bloc[0].debut;
            while((temp_debut!=0)||(temp_debut!=2)||(temp_debut!=4)||(temp_debut!=6)){
                world->actual_bloc[0]=bloc[randint(0,13)];
            }
            for(int i=0;i<world->actual_bloc[0].meteore_number;i++){
                world->actual_bloc[0].coord[i].y=world->actual_bloc[0].coord[i].y+SCREEN_HEIGHT;
            }
        }
        if(actuel_ending==3){
            //(0,3,5,6)
            world->actual_bloc[0]=bloc[randint(0,13)];
            temp_debut=world->actual_bloc[0].debut;
            while((temp_debut!=0)||(temp_debut!=3)||(temp_debut!=5)||(temp_debut!=6)){
                world->actual_bloc[0]=bloc[randint(0,13)];
            }
            for(int i=0;i<world->actual_bloc[0].meteore_number;i++){
                world->actual_bloc[0].coord[i].y=world->actual_bloc[0].coord[i].y+SCREEN_HEIGHT;
            }
        }
        if(actuel_ending==4){
            //(0,1,2,4,5,6)
            world->actual_bloc[0]=bloc[randint(0,13)];
            temp_debut=world->actual_bloc[0].debut;
            while((temp_debut!=0)||(temp_debut!=1)||(temp_debut!=2)||(temp_debut!=4)||(temp_debut!=5)||(temp_debut!=6)){
                world->actual_bloc[0]=bloc[randint(0,13)];
            }
            for(int i=0;i<world->actual_bloc[0].meteore_number;i++){
                world->actual_bloc[0].coord[i].y=world->actual_bloc[0].coord[i].y+SCREEN_HEIGHT;
            }
        }
        if(actuel_ending==5){
            //(0,1,3,4,5,6)
            world->actual_bloc[0]=bloc[randint(0,13)];
            temp_debut=world->actual_bloc[0].debut;
            while((temp_debut!=0)||(temp_debut!=1)||(temp_debut!=3)||(temp_debut!=4)||(temp_debut!=5)||(temp_debut!=6)){
                world->actual_bloc[0]=bloc[randint(0,13)];
            }
            for(int i=0;i<world->actual_bloc[0].meteore_number;i++){
                world->actual_bloc[0].coord[i].y=world->actual_bloc[0].coord[i].y+SCREEN_HEIGHT;
            }
        }
        if(actuel_ending==6){
            //(0,2,3,4,5,6)
            world->actual_bloc[0]=bloc[randint(0,13)];
            temp_debut=world->actual_bloc[0].debut;
            while((temp_debut!=0)||(temp_debut!=2)||(temp_debut!=3)||(temp_debut!=4)||(temp_debut!=5)||(temp_debut!=6)){
                world->actual_bloc[0]=bloc[randint(0,13)];
            }
            for(int i=0;i<world->actual_bloc[0].meteore_number;i++){
                world->actual_bloc[0].coord[i].y=world->actual_bloc[0].coord[i].y+SCREEN_HEIGHT;
            }
        }
    }
    
    if(world->actual_bloc[1].coord[0].y>SCREEN_HEIGHT){
        actuel_ending=world->actual_bloc[1].fin;
        if(actuel_ending==0){
            world->actual_bloc[0]=bloc[randint(0,13)];
        }
        if(actuel_ending==1){
            world->actual_bloc[1]=bloc[randint(0,13)];
            temp_debut=world->actual_bloc[1].debut;
            while((temp_debut!=0)||(temp_debut!=1)||(temp_debut!=4)||(temp_debut!=5)){
                world->actual_bloc[1]=bloc[randint(0,13)];
            }
            for(int i=0;i<world->actual_bloc[1].meteore_number;i++){
                world->actual_bloc[1].coord[i].y=world->actual_bloc[1].coord[i].y+SCREEN_HEIGHT;
            }
        }
        if(actuel_ending==2){
            //(0,2,4,6)
            world->actual_bloc[1]=bloc[randint(0,13)];
            temp_debut=world->actual_bloc[0].debut;
            while((temp_debut!=0)||(temp_debut!=2)||(temp_debut!=4)||(temp_debut!=6)){
                world->actual_bloc[1]=bloc[randint(0,13)];
            }
            for(int i=0;i<world->actual_bloc[1].meteore_number;i++){
                world->actual_bloc[1].coord[i].y=world->actual_bloc[1].coord[i].y+SCREEN_HEIGHT;
            }
        }
        if(actuel_ending==3){
            //(0,3,5,6)
            world->actual_bloc[1]=bloc[randint(0,13)];
            temp_debut=world->actual_bloc[0].debut;
            while((temp_debut!=0)||(temp_debut!=3)||(temp_debut!=5)||(temp_debut!=6)){
                world->actual_bloc[1]=bloc[randint(0,13)];
            }
            for(int i=0;i<world->actual_bloc[0].meteore_number;i++){
                world->actual_bloc[1].coord[i].y=world->actual_bloc[1].coord[i].y+SCREEN_HEIGHT;
            }
        }
        if(actuel_ending==4){
            //(0,1,2,4,5,6)
            world->actual_bloc[1]=bloc[randint(0,13)];
            temp_debut=world->actual_bloc[1].debut;
            while((temp_debut!=0)||(temp_debut!=1)||(temp_debut!=2)||(temp_debut!=4)||(temp_debut!=5)||(temp_debut!=6)){
                world->actual_bloc[1]=bloc[randint(0,13)];
            }
            for(int i=0;i<world->actual_bloc[1].meteore_number;i++){
                world->actual_bloc[1].coord[i].y=world->actual_bloc[1].coord[i].y+SCREEN_HEIGHT;
            }
        }
        if(actuel_ending==5){
            //(0,1,3,4,5,6)
            world->actual_bloc[1]=bloc[randint(0,13)];
            temp_debut=world->actual_bloc[1].debut;
            while((temp_debut!=0)||(temp_debut!=1)||(temp_debut!=3)||(temp_debut!=4)||(temp_debut!=5)||(temp_debut!=6)){
                world->actual_bloc[1]=bloc[randint(0,13)];
            }
            for(int i=0;i<world->actual_bloc[1].meteore_number;i++){
                world->actual_bloc[1].coord[i].y=world->actual_bloc[1].coord[i].y+SCREEN_HEIGHT;
            }
        }
        if(actuel_ending==6){
            //(0,2,3,4,5,6)
            world->actual_bloc[1]=bloc[randint(0,13)];
            temp_debut=world->actual_bloc[0].debut;
            while((temp_debut!=0)||(temp_debut!=2)||(temp_debut!=3)||(temp_debut!=4)||(temp_debut!=5)||(temp_debut!=6)){
                world->actual_bloc[1]=bloc[randint(0,13)];
            }
            for(int i=0;i<world->actual_bloc[1].meteore_number;i++){
                world->actual_bloc[1].coord[i].y=world->actual_bloc[1].coord[i].y+SCREEN_HEIGHT;
            }
        }
    }
    
    //update bloc actuel
    for(int i=0;i<world->actual_bloc[0].meteore_number;i++){
        world->actual_bloc[0].coord[i].y = world->actual_bloc[0].coord[i].y+world->vy;
    }
    for(int i=0;i<world->actual_bloc[1].meteore_number;i++){
        world->actual_bloc[0].coord[i].y = world->actual_bloc[1].coord[i].y-world->vy;
    }
    
    //update collision 
    
    for(int i=0;i<world->actual_bloc[0].meteore_number;i++){
        handle_sprites_collision(world,&world->actual_bloc[0].coord[i],&world->vaisseau,&world->make_disappear,&temp);
    }
    for(int i=0;i<world->actual_bloc[1].meteore_number;i++){
        handle_sprites_collision(world,&world->actual_bloc[1].coord[i],&world->vaisseau,&world->make_disappear,&temp);
    }

}

int randint(int a, int b)
{
    return a + rand() % (b-a);
}