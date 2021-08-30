#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define afficher printf
#define BUFFER_SIZE 5

/*
    LISTE NOIRE   : gets(), atoi(), atol(), atod(), fflush(stdin)
    LISTE GRISE   : scanf(), fscanf()
    LISTE BLANCHE : fgets(), strtol(), strtod()

    Long int strtol(const char *str, char**endpr, int base)
    int scanf(const char *format, ...);

    ------------------

    chaine en C : blablablabla\0

    Expression régulière -> %[]
*/

void flush_input_buffer(void)
{
    int c = 0;

    while (c != '\n' && c != EOF)
        c = getchar();
}

char *input_read(char *str, int size)
{
    char *data;

    data = fgets(str, size, stdin);

    if(data)
    {
        size_t len = strlen(str) - 1;

        if(str[len] == '\n')
            str[len] = '\0';
        else
        {
            fscanf(stdin, "%*[^\n]");
            fgetc(stdin);
        }
    }

    return data;
}

int main(void)
{
    int age = 0;
    int x = 0, y = 0;
    int ret, ret2, ret3, ret4, ret5, ret6;
    char buffer[BUFFER_SIZE + 1] = {0},
    buffer2[BUFFER_SIZE + 1] = {0},
    buffer3[BUFFER_SIZE + 1] = {0},
    buffer4[BUFFER_SIZE + 1] = {0},
    buffer5[BUFFER_SIZE + 1] = {0};
    char letter;
    long int number = 0;

    /* Prompt1 */

    /*
    afficher("Prompt1:\n");
    afficher("Quel age as-tu ?");
    ret = scanf("%d", &age);

    afficher("Tu as %d ans\n", age);
    afficher("Retour: %d\n", ret);*/

    /* Prompt2 */

    /*afficher("Prompt2:\n");
    afficher("Indiquez x et y: \n");
    ret2 = scanf("%d / %d", &x, &y);

    afficher("X: %d et Y: %d\n", x, y);
    afficher("Retour: %d\n", ret2);*/

    /* Prompt3 */

    /*afficher("Prompt3:\n");
    afficher("Mot en 5 lettres: \n");
    ret3 = scanf("%5s", buffer);

    afficher("Mot saisi: %s\n", buffer);
    afficher("Retour: %d\n", ret3);*/

    /* Prompt4 */

    /*afficher("Prompt4:
");
    afficher("Une lettre: ");
    ret4 = scanf(" %c", &letter);

    afficher("Lettre saisie: %c\n", letter);
    afficher("Retour: %d\n", ret4);*/

    /* Prompt5 */
    /*afficher("Prompt5:\n");
    afficher("Que des a, b ou c: ");
    ret5 = scanf("%5[abc]", buffer2);

    afficher("Mot saisi: %s\n", buffer2);
    afficher("Retour: %d\n", ret5);*/

    /* Prompt6 */

    /* afficher("Prompt6:\n");
    fgets(buffer3, BUFFER_SIZE + 1 , stdin);

    number = strtol(buffer3, NULL, 10);

    afficher("Nombre: %ld\n", number);*/

    /* Prompt7 */
    /*afficher("Prompt7:\n");
    afficher("Mot en 5 lettres: \n");
    fgets(buffer4, BUFFER_SIZE + 1 , stdin);
    afficher("Chaine: %s\n", buffer4);

    flush_input_buffer();
    afficher("-----------\n");

    afficher("Mot en 5 lettres: \n");
    fgets(buffer4, BUFFER_SIZE + 1 , stdin);

    afficher("Chaine: %s\n", buffer4);*/

    /* Prompt8 */

    afficher("Prompt8:\n");
    afficher("Mot en 5 lettres: ");
    input_read(buffer5, BUFFER_SIZE + 1);
    afficher("%s\n", buffer5);

    afficher("-----------\n");

    afficher("Mot en 5 lettres: ");
    input_read(buffer5, BUFFER_SIZE + 1);
    afficher("%s\n", buffer5);



    return 0;
}