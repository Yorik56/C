# C

#

[C - Cours - FormationVidéo](https://www.youtube.com/playlist?list=PLrSOXFDHBtfEh6PCE39HERGgbbaIHhy4j)


# Pré requis
[Tutoriel Windows - installer MinGW](https://www.youtube.com/watch?v=y-i96kqT53A&list=RDCMUCS2e0hEJMhwd6bNscS60xTg&start_radio=1&rv=y-i96kqT53A&t=589)


## Compiler un fichier en C avec Gcc
```
	gcc variables.c -o variables
	
	# "variables.c" fichieren entrée
	# "variables" programme en sortie 
```

# Mots réservés

> [Langage C #3 - variables](https://www.youtube.com/watch?v=kKeGTDyvi1o)

Ces mots sont utilisés par le langage C et ne sont pas à employer pour nommer vos variables, structures, fonctions, ...

+ auto
+ bool
+ break
+ case
+ char
+ const
+ default
+ do
+ double
+ else
+ enum
+ extern
+ float
+ for
+ goto
+ if
+ int
+ long
+ register
+ return
+ short
+ signed
+ sizeof
+ static
+ struct
+ switch
+ typedef
+ union
+ unsigned
+ void
+ volatile
+ while

# Types de données

## Types simples

> [Langage C #3 - variables](https://www.youtube.com/watch?v=kKeGTDyvi1o)

⚠ Attention au type **char**, dont son usage ne garantit pas une occupation mémoire de 1 octet !

### Signés

|Syntaxe|Occupation mémoire|Fourchette de valeurs|
|:--:|:--:|:--:|
|char|?|?|
|signed char|1 octet|-128 à 127|
|short|2 octets|-32 768 à 32 767|
|int|2 octets / 4 octets|-32 768 / -2 147 483 648 à 32 767 / 2 147 483 647|
|long|4 octets|-2 147 483 648 à 2 147 483 647|
|long long|8 octets|-9 223 372 036 854 775 808 à 9 223 372 036 854 775 807|
|float|4 octets|-3,4.10<sup>38</sup> à 3,4.10<sup>38</sup>|
|double|8 octets|-1,7.10<sup>308</sup> à 1,7.10<sup>308</sup>|
|long double|10 octets|-1,1.10<sup>4932</sup> à 1,1.10<sup>4932</sup>|

### Non signés

|Syntaxe|Occupation mémoire|Fourchette de valeurs|
|:--:|:--:|:--:|
|unsigned char|1 octet|0 à 255|
|unsigned short|2 octets|0 à 65 535|
|unsigned int|2 octets / 4 octets|0 à 65 635 / 4 294 967 295|
|unsigned long|4 octets|0 à 4 294 967 295|
|unsigned long long|8 octets|0 à 18 446 744 073 709 551 615|

---

## Types étendus

> L'utilisation de ces types nécessite l'ajout de l'en-tête **stdint.h** à votre fichier source. De plus, étant optionnels, il n'y a aucune garantie de leur portabilité.

### Signés

|Fixe|Minimale|Maximale|Rapide|Correspondance|
|:--:|:--:|:--:|:--:|:--:|
|int8_t|int_least8_t|-|int_fast8_t|signed char|
|int16_t|int_least16_t|-|int_fast16_t|short|
|int32_t|int_least32_t|-|int_fast32_t|int|
|int64_t|int_least64_t|intmax_t|int_fast64_t|long long|

### Non signés

|Fixe|Minimale|Maximale|Rapide|Correspondance|
|:--:|:--:|:--:|:--:|:--:|
|uint8_t|uint_least8_t|-|uint_fast8_t|unsigned char|
|uint16_t|uint_least16_t|-|uint_fast16_t|unsigned short|
|uint32_t|uint_least32_t|-|uint_fast32_t|unsigned int|
|uint64_t|uint_least64_t|uintmax_t|uint_fast64_t|unsigned long long|
