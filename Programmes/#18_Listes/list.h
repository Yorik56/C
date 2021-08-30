#ifndef __LIST__h__
#define __LIST__h__

    /* Définition du type Booléen */
    typedef enum {
        false,
        true
    }Bool;

    /* Définition d' une liste */
    typedef struct ListElement
    {
        int value;
        struct ListElement *next;
    }ListElement, *List;

    /* Prototypes */
    List new_list(void);
    Bool is_empty_list(List li);
    void print_list(List li);
    int list_length(List li);
    List push_back_list(List li, int x);
    List push_front_list(List li, int x);
    List pop_back_list(List li);
    List pop_front_list(List li);
    List list_clear(List li);
    /* first element*/
    /* find element by index, by value*/


#endif
