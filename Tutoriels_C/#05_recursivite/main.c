#include <stdio.h>
#include <stdlib.h>
#define afficher printf

/*
    Factorielle de :
        3 -> 3 * 2 * 1 = 6
        5 -> 5 * 4 * 3 * 2 * 1 = 120

    Suite de Fibonacci
    ------------------

    1 1 2 3 5 8 13 21 34 ...

 */
void fonctionRecursiveA(int i)
{
    if(i == 10)
        return;
    afficher("Je suis une fonction recursive %d\n", i);
    fonctionRecursiveA(i +1);
}

unsigned long factorielleRecursiviteStandard(int n)
{
    if(n < 0)
        exit(EXIT_FAILURE);
    if(n == 0 || n == 1)
        return 1L;

    return n * factorielleRecursiviteStandard(n - 1);
}

unsigned long factorielleRecursiviteTerminale(int n, long res)
{
    if(n < 0)
        exit(EXIT_FAILURE);
    if(n == 0)
        return n;
    if(n == 1)
        return res;
    return factorielleRecursiviteTerminale(n - 1, n * res);
}

int fibonacci(int n)
{

    int i = 1, terme0 = 1, terme1 = 1, tmp;
    afficher("(%d) - (%d) -  ",terme0, terme1);
    if(n < 2)
        return 1;

    while (i < n)
    {
        tmp = terme0 + terme1;
        terme0 = terme1;
        terme1 = tmp;

        afficher("(%d) - ",terme1);
        i++;
    }

    return terme1;
}

int main(void)
{

    fonctionRecursiveA(0);

    afficher("La factorielleRecursiviteStandard est egale a : %d\n", factorielleRecursiviteStandard(3));
    afficher("La factorielleRecursiviteTerminale est egale a : %d\n", factorielleRecursiviteTerminale(3, 1));
    afficher("(%d)\n", fibonacci(42));

    return 0;
}