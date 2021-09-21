/**
 * @file log.h
 * @author Victor Dallé
 * @brief En-tête du module gérant le stockage de l'historique des parties.
 * @version 0.1
 * @date 2021-04-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef DEF_LOG_H
#define DEF_LOG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphic.h"

/**
 * @brief Fonction qui permet d'enregistrer le score des joueurs.
 * 
 * @param time Temps qu'à mis le joueur à finir le niveau.
 */
void record(int time);

#endif