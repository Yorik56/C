#include <stdio.h>
#include <string.h>
#define afficher printf

/*
    //Remplacer "struct Player" par "Player"
    typedef struct Player Player;

    (*monPointeur).un_champ = X;
    monPointeur->un_champ = X; //Même chose
*/

//Remplacer "struct Player{...}" par "Player"
typedef struct Player
{
    signed char username[256];
    int hp;
    int mp;
} Player;

/*------------------------------------------------------------------------------------*/

void create_player(Player *p){
    strcpy(p->username, "Zorro");
    p->hp = 100;
    p->mp = 80;
}

/*------------------------------------------------------------------------------------*/

int main(void)
{
    Player player1 = {"Jason", 100,100};
    Player player2 = {"", 0,0};

    //*********************************************************************************
    afficher("//Creation du joueur 1//\n");
    afficher("Affichage du joueur 1: \n");
    afficher("Nom du joueur : %s\n", player1.username);
    afficher("Points de vie : %d | Points de Magie: %d \n", player1.hp, player1.mp);

    afficher("-> Utilisation de strcpy \n");
    strcpy(player1.username, "Naoki");
    player1.hp -= 50;
    afficher("Affichage du joueur 1: \n");
    afficher("Nom du joueur : %s\n", player1.username);
    afficher("Points de vie : %d | Points de Magie: %d \n", player1.hp, player1.mp);

    //*********************************************************************************
    afficher("//Creation du joueur 2 via une fonction//\n");
    create_player(&player2);

    afficher("Affichage du joueur 2: \n");
    afficher("Nom du joueur : %s\n", player2.username);
    afficher("Points de vie : %d | Points de Magie: %d \n", player2.hp, player2.mp);

    //*********************************************************************************

    afficher("//Tableau de joueurs//\n");
    Player tableau_joueurs[2];
    tableau_joueurs[0] = player1;
    tableau_joueurs[1] = player2;

    strcpy(tableau_joueurs[0].username, "Luffy");
    tableau_joueurs[1].mp = 90;

    afficher("Affichage du joueur 1: \n");
    afficher("Nom du joueur : %s\n", tableau_joueurs[0].username);
    afficher("Points de vie : %d | Points de Magie: %d \n", tableau_joueurs[0].hp, tableau_joueurs[0].mp);

    afficher("Affichage du joueur 2, créé via une fonction: \n");
    afficher("Nom du joueur : %s\n", tableau_joueurs[1].username);
    afficher("Points de vie : %d | Points de Magie: %d \n", tableau_joueurs[1].hp, tableau_joueurs[1].mp);

    return 0;
}