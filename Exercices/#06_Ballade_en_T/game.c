#include <stdio.h>
#include <string.h>
#include "game.h"

#define afficher printf



void app_start(void)
{
    //Déclarations des variables
    char map[X_LIMIT][Y_LIMIT];
    char cmd = 'm';
    char *move_cmd = &cmd;
    int position_x = 1, position_y = 3;
    //Déclarations des pointeurs
    int *playerX = &position_x, *playerY = &position_y;

    generation_map(map, playerX, playerY);
    affiche_map(map, playerX, playerY);

    do {
            affiche_map(map, playerX, playerY);
            affiche_menu(move_cmd);
            deplacer_joueur(move_cmd, map, playerX, playerY);
    }while(*move_cmd != 'q');
}

//GESTION MAP--------------------------------------------------------------------------------
void generation_map(char map[][Y_LIMIT], int *playerX, int *playerY)
{
    creation_map(map, playerX, playerY);
}

void creation_map(char map[][Y_LIMIT], int *playerX, int *playerY)
{
    // Déclaration et initialisation de variables
    int left = 1;
    int zeroIsPrintable;
    int caseIsPrintable;
    int next_case = 0;

    // Création et initialisation de pointeurs
    int *p_next_case = &next_case;

    for (int compteurX = 0; compteurX < X_LIMIT; compteurX++) {
        for (int compteurY = 0; compteurY < Y_LIMIT; compteurY++) {
            zeroIsPrintable = multiple_of_3(compteurY);
            if ((compteurX == 0 && zeroIsPrintable) || (compteurX == X_LIMIT -1 && zeroIsPrintable)  || (compteurY == 0) || (compteurY == Y_LIMIT -1))
            {
                strcpy(&map[compteurX][compteurY], "0");
            }
            else
            {
                caseIsPrintable = case_is_printable(left, p_next_case, compteurY);
                if(caseIsPrintable && (compteurX != 0) && (compteurX != X_LIMIT -1))
                {
                    if(left == 1)
                    {
                        strcpy(&map[compteurX][compteurY], "[");
                        left = 0;
                    }
                    else
                    {
                        strcpy(&map[compteurX][compteurY], "]");
                        left = 1;
                    }
                }
                else
                {
                    if(compteurX == *playerX && compteurY == *playerY)
                    {
                        strcpy(&map[compteurX][compteurY], "T");
                    }
                    else
                    {
                        strcpy(&map[compteurX][compteurY], " ");
                    }
                }
            }
        }
    }
}

void affiche_map(char map[][Y_LIMIT], int *playerX, int *playerY)
{
    for (int compteurX = 0; compteurX < X_LIMIT; compteurX++) {
        for (int compteurY = 0; compteurY < Y_LIMIT; compteurY++) {
            afficher("%c", map[compteurX][compteurY]);
        }
        afficher("\n");
    }
}

//GESTION MENU
void affiche_menu(char *move_cmd)
{
    afficher("[Deplacer le joueur] up: u | right : r | down : d | left : l | quitter : q\nChoix : ");
    scanf("%c", move_cmd);
    flushBuffer();
}

//GESTION JOUEUR
void deplacer_joueur(char *move_cmd , char map[][Y_LIMIT], int *playerX, int *playerY) {
    switch (*move_cmd) {
        case 'q':
            afficher("Au revoir!\n");
            break;
        case 'u':
            map[*playerX][*playerY] = ' ';
            if (*playerX - 1 != 0) {
                (*playerX)--;
                map[*playerX][*playerY] = 'T';
                break;
            } else {
                *playerX = X_LIMIT - 2;
                map[*playerX][*playerY] = 'T';
                break;
            }
        case 'r':
            map[*playerX][*playerY] = ' ';
            if(*playerY + 3 == Y_LIMIT -1){
                *playerY = 3;
                map[*playerX][*playerY] = 'T';
                break;
            } else {
                *playerY = *playerY + 3;
                map[*playerX][*playerY] = 'T';
                break;
            }
        case 'd':
            map[*playerX][*playerY] = ' ';
            if (*playerX + 1 < X_LIMIT -1) {
                (*playerX)++;
                map[*playerX][*playerY] = 'T';
                break;
            } else {
                *playerX = 1;
                map[*playerX][*playerY] = 'T';
                break;
            }
            break;
        case 'l':
            map[*playerX][*playerY] = ' ';
            if(*playerY - 3 == 0){
                *playerY = Y_LIMIT - 4;
                map[*playerX][*playerY] = 'T';
                break;
            } else {
                *playerY = *playerY - 3;
                map[*playerX][*playerY] = 'T';
                break;
            }

        default:
            afficher("Commande incorrecte !\n");
            break;
    }
}

//AFFICHAGE DES CASE ACCESSIBLES PAR LE JOUEUR------------------------------------------------

int case_is_printable(int left, int *p_next_case, int compteurY)
{
    int is_in_case_limit = case_in_limit(compteurY);

    if((*p_next_case == 0)  &&  (left == 1) && is_in_case_limit){
       *p_next_case =  1;
        return 1;
    }
    else if((*p_next_case == 0) && (left == 0) && is_in_case_limit){
        *p_next_case =  0;
        return 1;
    }
    else if(*p_next_case == 1)
    {
        *p_next_case = 0;
        return 0;
    }
}

int case_in_limit(int compteurY)
{
    if ((compteurY != 1) && (compteurY != Y_LIMIT - 2))
        return 1;
    return 0;
}

//CALCULS-------------------------------------------------------------------------------------
int multiple_of_3(int compteurY)
{
    if((compteurY % 3 == 0) || (compteurY == 0))
    {
        return 1;
    }
    return 0;
}



/*------------------------------------------------------------------------------------------------*/

void flushBuffer(void)
{
    int c = 0;
    while(c != '\n' && c != EOF)
        c = getchar();
}