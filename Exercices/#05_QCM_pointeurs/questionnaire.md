# Questionnaire sur les pointeurs:

> 1. Quelles sont la/les bonne(s) syntaxe(s) pour déclarer un pointeur sur un nombre entier (int) ? 

- [ ] a : int ptr_number;
- [x] b : int *number;
- [ ] c : int* number;
- [ ] d : int &number;

> 2. Quelle valeur possède par défaut un pointeur non initialisé ?

- [x] a : n'importe quoi
- [ ] b : NULL
- [ ] c : 0


> 3. Que stock un pointeur ?

- [ ] a : une valeur
- [x] b : une adresse
- [x] c : un autre pointeur


> 4. Sachant "int nb = 4 et int pNb = &nb", donner les deux méthodes pour accéder à la valeur 4 ?

> Réponse : "print nb et print pNb"

> 5. Quel passage d'argument évite la copie des données ?

- [x] a : passage par adresse -> void someFunction(int *data)
- [ ] b : passage par valeur -> void someFunction(int data)

> 6. Quel drapeau (flag) est utilisé pour afficher des adresses dans un printf() ?

- [ ] a : %u
- [ ] b : %a
- [x] c : %p


> Correction : 

> 1 : X --> Réponse : B et C

> 2 : V --> Réponse : A, n' importe quoi

> 3 : V --> Réponse : B, une adresse

> 4 : X --> Réponse : print("%d ou %d", nb, *pNb)

> 5 : V --> Réponse : A

> 6 : V --> Réponse : C, %p


