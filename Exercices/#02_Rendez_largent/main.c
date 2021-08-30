#include <stdio.h>
#define afficher printf

/*
    EXERCICE C #2
    [Révision : jusqu' à la séance 6 - conditions]
    > Écrire un programme de rendu de monnaie. En saisissant le montant total des achats puis la somme
    donnée, indiquez la monnaie à rendre (en billets de 20euros, 10euros, 5euros et pièces de 2euros et 1euros)

    > Indications :
     - S' assurer que la somme de données est bien supérieure à la somme des achats
     - Gérer le cas où on aurait payé un montant égal aux achats
     - Rendre le moins de billets/pièces possible (25euros de monnaie -> 1 billet de 20euros + 1 billet de 5euros)
     - l' opérateur % (modulo) sera utile pour cet exercice
*/

void calculRenduMonnaie(int montantTotal, int sommeDonnee)
{
    int sommeARendre = 0;

    if(sommeDonnee < montantTotal)
    {
        afficher("Le compte n'y est pas ! il faut encore payer %d euros !!", montantTotal - sommeDonnee);
    }
    else if(sommeDonnee == montantTotal)
    {
        afficher("Le compte est bon ! merci et a bientot! ");
    }
    else if(sommeDonnee > montantTotal)
    {
        afficher("Nous vous devons : ");
        sommeARendre = sommeDonnee - montantTotal;
        if(sommeARendre %20 != 0)
        {
            if(sommeARendre / 20 > 0)
                afficher("%d billet(s) de 20euros, ", sommeARendre / 20);
            sommeARendre %= 20;
            if(sommeARendre %10 != 0)
            {
                if(sommeARendre / 10 > 0)
                    afficher("%d billet(s) de 10euros, ", sommeARendre / 10);
                sommeARendre %= 10;
                if(sommeARendre %5 != 0)
                {
                    if(sommeARendre / 5 > 0)
                        afficher("%d billet(s) de 5euros, ", sommeARendre / 5);
                    sommeARendre %= 5;
                    if(sommeARendre %2 != 0)
                    {
                        if(sommeARendre / 2 > 0)
                            afficher("%d piece(s) de 2euros, ", sommeARendre / 2);
                        sommeARendre %= 2;

                        afficher("%d piece(s) de 1euros.", sommeARendre / 1);
                    }
                    else
                    {
                        afficher("%d piece(s) de 2euros.", sommeARendre / 2);
                    }
                }
                else
                {
                    afficher("%d billet(s) de 5euros.", sommeARendre / 5);
                }
            }
            else
            {
                afficher("%d billet(s) de 10euros.", sommeARendre / 10);
            }
        }
        else
        {
            afficher("%d billet(s) de 20euros.", sommeARendre / 20);
        }
    }




}

int main(void)
{
    /* Initialisation de variables */
    unsigned int montantTotal = 0;
    unsigned int sommeDonnee = 0;

    /* Récupération des données en entrée */
    afficher("Montant total des achats :\n");
    scanf("%d", &montantTotal);
    afficher("Somme donnee :\n");
    scanf("%d", &sommeDonnee);

    /* Affichage des donnée en entrée */
    afficher("Montant total : %d | Somme donnee : %d\n", montantTotal, sommeDonnee);
    calculRenduMonnaie(montantTotal, sommeDonnee);

    return 0;
}