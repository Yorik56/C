#ifndef GAME_H
#define GAME_H

#define X 5
#define Y 5
#define X_LIMIT  X * 2
#define Y_LIMIT  Y * 5

#define NUMBER_OF_CHOICES 5
#define MAX_STRING_SIZE 5

    void app_start(void);
    void flushBuffer(void);

    //GESTION MAP
    void taille_map(int *x, int *y);
    void generation_map(char map[][Y_LIMIT], int *playerX, int *playerY);
    void creation_map(char map[][Y_LIMIT], int *playerX, int *playerY);
    void affiche_map(char map[][Y_LIMIT], int *playerX, int *playerY);

    //GESTION MENU
    void affiche_menu(char *move_cmd);

    //GESTION JOUEUR
    void deplacer_joueur(char *move_cmd, char map[][Y_LIMIT], int *playerX, int *playerY);

    //AFFICHAGE DES CASE ACCESSIBLES PAR LE JOUEUR
    int case_is_printable(int left, int *p_next_case, int compteurY);
    int case_in_limit(int compteurY);

    //CALCULS
    int multiple_of_3(int compteurY);

#endif