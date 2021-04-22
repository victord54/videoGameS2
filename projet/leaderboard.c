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

#include "leaderboard.h"

void record(int time)
{
    FILE* fichier = NULL;

    fichier = fopen("leaderboard.txt","a");
    char nom[20];
    char *enter = NULL;

    if (fichier != NULL) // Si on a réussi à charger le fichier on peut continuer
    {
        printf("Quel est votre nom ? ");
        if (fgets(nom,20, stdin) != NULL) // Saisie et verification de la saisie
        {
            enter = strchr(nom, '\n'); // On cherche le dernier caractère qui est un saut de ligne
            if (enter != NULL)
                *enter = '\0'; // On le remplace par un caractère de fin
        }
        
        fprintf(fichier, "%s a fini le jeu en %d secondes.\n", nom, time);
        fclose(fichier);
    }
    else
        printf("Impossible d'ouvir le fichier leaderboard.txt\n");
}