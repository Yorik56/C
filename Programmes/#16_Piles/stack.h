#ifndef __STACK__H_
#define __STACK__H_

    /* Type booléen */
    typedef enum
    {
        false, //0
        true  //1
    }Bool;

    /* Définition d' un Joueur */
    typedef struct Player{
        char name[25];
        int  niveau;
    }Player;


    /* Définition d' une pile */
    typedef struct StackElement
    {
        Player pp;
        struct StackElement *next;
    }StackElement, *Stack;

    /* Prototypes de fonctions */
    Stack new_stack(void);
    Bool is_empty_stack(Stack st);
    void print_stack(Stack st);
    Stack push_stack(Stack st, Player p);
    Stack pop_stack(Stack st);
    Player top_stack(Stack st);
    int stack_length(Stack st);
    Stack clear_stack(Stack st);

#endif