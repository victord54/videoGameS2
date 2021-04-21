/**
 * @file menu_data.c
 * @author Victor Dallé / Yann Periney
 * @brief Module de gestion des évènements du menu du jeu.
 * @version 0.1
 * @date 2021-04-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include "menu_data.h"

int is_menu_over(menu_t *menu){
    return menu->menuover;
}

int is_menu_quitte(menu_t *menu){
    return menu->quitte;
}