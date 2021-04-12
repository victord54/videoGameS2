/**
 * @file log.c
 * @author Victor Dallé
 * @brief Module gérant le stockage de l'historique des parties.
 * @version 0.1
 * @date 2021-04-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "log.h"

void record(int time)
{
    FILE* fichier = NULL;

    fichier = fopen("log_games.txt","a");
    char nom[20];
    char *enter = NULL;

    if (fichier != NULL)
    {
        printf("Quel est votre nom ? ");
        if (fgets(nom,20, stdin) != NULL)
        {
            enter = strchr(nom, '\n');
            if (enter != NULL)
                *enter = '\0';
        }
        
        fprintf(fichier, "%s a fini le niveau en %d secondes.\n",nom,time);
        fclose(fichier);
    }
    else
        printf("Impossible d'ouvir le fichier log_games.txt\n");
}