Projet de ISN

  
  
  
  
  

Cacher une image dans une autre

  
  
  
  
  
  

Maximilien nowak

  

Table des matière :

1 - Objectif

2 - traduction de l’objectif en problematique

3 - présentation du la stéganographie

4 - Utilisation de la stéganographie

-   qu'est ce que l'image du format .ppm
    

-   utilisation du LSB en stéganographie
    

5 - exemple

6 - explication du code

-   explication initialisation
    

-   explication du main
    
-   explication de la fonction chiffre
    
-   explication de la fonction steno
    

7 - annexe

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  


----------


1 - Objectif

Notre objectif est de cacher une image dans une autre pour que l’information passe de façon sécurisée d’un point A à un point B.

  
  


----------


2 - Traduction en problematique

Nous devons donc trouver une solution à cette problématique : Comment cacher une image dans une autre grâce au science du numérique et de l’informatique ?

Nous répondrons donc à cette problématique grâce à la stéganographie, et au langage informatique.

  

je m’occupe la partie création de l’image alors que mon camarades lui s’occupe de la récupération de l’image

  


----------


3 - Présentation de la stéganographie

La stéganographie est le fait de cacher un message dans un autre. il ne faut pas confondre stéganographie et cryptographie car dans le premiere le message n’est pas visible alors que dans la cryptographie le message n’est pas compréhensible.

  
  


----------


4 - Utilisation de la stéganographie

  
![](https://lh3.googleusercontent.com/ZiDw71GWNf7rNKz0_WzCEgcsDmgEEDju_yGrh20QiIOtG5jHMbBAEWU8uPLQJtCTzuDfsGU7K9al-_3bT534dzoqp8z4YMyOeC3ZSse0GDeVt4yDj9PWcs8Gd0fnO1cwgdFyz7Lb)

Avant de parler de l’utilisation de la stéganographie nous allons vous présenter une image de type .ppm ou une portable pixmap. L’image se trouvant sur la gauche en est une. nous pouvons donc voir qu'à première vu rien ne change par rapport à un image normal nous allons zoomer dessus pour aller plus en détaille

![](https://lh5.googleusercontent.com/x_xjRFGkZKk80ddBe_pVt0MJgEwbV1bmyvRA4Ibb_3fq1-Yj9o2ghgpjymhQAJMmvquHzROSy60W6LO80P3VWuynALeiKsoMsm-d66Aj4bwg3j9fJziAhDh95bd_BaFRKm_x2r0z)

Voici donc l’image zoomée on peut voir qu’il y a pleins de carré qui sont les pixels la composant.

Allons maintenant ouvrir le fichier de cette image pour voir comme est codé l’image :

  

P3

250 250 255
64 152 223 64 152 223 64 152 223 64 152 223 ...

P3 signifie que les couleurs de l’image sont collé en ASCII

250 signifie le nombre de colonne et du ligne, ici l’image est donc carré

255 est la valeur max d’une couleur.

nous pouvons voir après une suite de chiffre, c’est tout simplement les pixel de l’image. car pour que l’image soit en couleur il faut 3 niveau de couleur :

-   le rouge
    
-   le vert
    
-   le bleu
![](https://lh4.googleusercontent.com/ElCh959pNEo-32_g-iAYy0zYgSAcJjzkz-ioWwothBl0EA7eNTjYPV-lmalOtxZWBIyHfawfrwjnNl9t22ZjZyFCRX7pt7ZDSyG-ToRLOVbG5K_McPYOUWDQX23hXRiASegk7qpG)
    
d'où l'appellation RVB ou en anglais RGB, cela nous donne pour le premier pixel de l’image R : 64, V : 152, B : 223

Sachant cela maintenant nous pouvons rentrer dans le dur du sujet : La stéganographie et l’informatique.

Fondamentalement chaque information est codée en binaire en informatique, donc les niveau de couleur de l’image sont codés eux aussi en 0 et 1.

prenons le niveau de couleur rouge du premier pixel de l’image du dessus, on la code sur 1 octet soit 8 bit :

base 10 : 64

base2 : 01000000

la méthode du least Significant Bit ou LSB et le fait de prendre les 4 bit de poids faible “0100 0000”  qu’on peut voir ici en gras et de les remplace par les 4 “Most Significant Bit” ou MSB de l’image qu’on veut cacher. On fait c’est pas chaque pixel et chaque niveau de couleur des deux image. cela impacte peu l’image de visible et l’image cacher certe il y auras de perte mais elles ne seront que peu visible, la seul limitation est que les deux image doivent être de la même taille.

  
  


----------


5 - Exemple

Sois deux image ayant pour niveau de rouge pour le premier pixel :

64 et 234

  

niveau de rouge visible :

Base 10 : 64

base 2 : 0100  0000

souligné sont les LSB a remplacer

  
  
  

niveau de rouge cachée :

base 10 : 234

base 2 : 1110 1010

surligné sont les MSB a mettre a la place des LSB du niveau de rouge visible

  
  

Niveau de rouge final :

base 2: 0100 1110

base 10 : 78

  

avec des image entière cela donne :

  

image visible :

![](https://lh5.googleusercontent.com/U0hi7okS4iztWHQb_j-ynFXHCFjnr_RRaFdVstB7IGGRiO9a3c99RBJDkAT05VKV177724ghnSIapQuMamWOMKAtu5OaH295oX0N3uFIdImCuRxqo-H2_qQiMhmtjDCdT7oH6l0m)

  

image à cacher :

![](https://lh6.googleusercontent.com/0XMU8X9bKqiYZ_CB_P6z8_IvCB_ikVKq_dC_fXMBlnGj4vMpLA__oZRgPLMVaMXU94G5YCupDGvIqXqft0gJH67HWBj6fb6SPHKH41F6G4C50th3-QeLlWm0My0zfMf_UeCj2mbk)

résultat :

![](https://lh5.googleusercontent.com/NgQZNkblFtkdmPNbgsm4bOpP1YvgsKreswAs4dsoQxp_PKNQQf01RKmLZBEEpLNihSr75ELW-YvN1xC_sHqT6KrmBqm_ZAfLFC8N_ydSqCgLqxt4jNaxoPNDLadACeix8TFJindt)

  

Le résultat est presque le même que l’image visible. on a donc cacher l’image voulu dedans avec le méthode du LSB

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  


----------


6 - explication du code

pour commencer je tiens à préciser que le langage utilisé est le c++, il convient mieux à ce type de projet car ajoute des fonction qui facilite la lecture et l'écriture de fichier et la conversion en binaire. et que ma partie est celle de la création de l’image et non celle de retrouver l’image cachée.

    #include `<iostream>`
    #include <bitset>
    #include <fstream>
    #include <string>
    #include <math.h>
    #include <vector>

  

std::string image\_visible("image\_vacances.ppm");

std::string image\_cacher("image\_bomb\_code\_csgo.ppm");

  

ici nous commençons par inclure dans notre projet :

-   iostream : permet l'interaction avec la console
    
-   bitset : permet la conversion en binaire et manipulation du résultat
    
-   fstream : permet la lecture et l'écriture de fichier
    
-   string : permet de gérer des caractère/mot/phrases
    
-   math.h : permet d’introduire de fonction mathématique
    
-   vector : permet la création de tableau dynamique
    

  

nous mettons aussi en scope global image\_visible et image\_cacher contenant l’emplacement des images. ici le chemin d'accès et directement le nom de l’image car le programme et l’image sont dont le même dossier.

  
  

![](https://lh5.googleusercontent.com/wZFTSaLNqNoJIzE4WvmpHGRrpJ43U_CdyiMmX6kCUGHlkTvKs3KnMQNsTIo2C1Csua7476r-zqacjxa7DysmGOg-0wlyborjm6qIklv1kbSNldgZx6Yv5z-XA3vn0sQukf2nokds)

nous images sont de 250 pixels par 250 pixels soit 62500 pixel soit 187 500 niveau de couleur.

nous créons donc deux tableau de 187500 int grâce au std::vector qui fonctionne de cette façon :

  

    vector<type> nom(taille)

  

pourquoi utiliser un tableau dynamique plutôt qu’un tableau statique ? le tableau dynamique permet d’utiliser plus de variable et se limite au niveau de ram du système alors que un tableau statique a un cap de 4Mo et si nous le dépassons cela produit une erreur du type “stack overflow” et le programme crash.

  

`std::ifstream flux_visible (image_visible)` initialise un flux de lecture de fichier.

chiffre et steno sont deux fonction créer par mes soins que je vais explique.

  
  

![](https://lh3.googleusercontent.com/iWciXa1qbkM6UC6UzAHqA4yLY9ETaaKIijsn8iI2ynx-wM9TGJAHSM8lfEqqrfDjZeVFgLWD_FbdMnWZB7289Xv0Qigif6iFSABbwiNAZl4HoWqwaa1ffFLSCMaQbDg0HInD6J5j)

Nous créons ici une fonction chiffre.

nous introduction comme paramètre de cette fonction un flux de lecture x et tableau dynamique y.

le sigle “&” avant les nom de paramètre de la fonction veux dire qu’on passe par référence. Le passage par référence permet utilise une même variable sous plusieur nom et donc d'éviter la copie du cette variable si nous n’étions pas passé par référence.

Ici la boucle while permet de lire le début du fichier donc de passer outre : P3 250 250 255 qui n’est que l'initialisation de l’image.

  

    x >> fichier

  

x étant le flux de lecture on peut donc lire et associer la valeur lu a fichier. le “>>” permet de lire mot par mot sans prendre compte des espaces.

  

    nombre = atoi(fichier.c_str())

  

fichier étant un string et nombre un int atoi permet de convertir le string en nombre.

  

la boucle permet de for elle permet l’ammasage des données et les stockent dans le tableau dynamique y.

`std::cout` permet d'écrire dans la console et std::endl permet un retour à la ligne.

  

![](https://lh5.googleusercontent.com/7-Hg03koo4sm_hll6FbT06RK1AaS5pS1YUrtRbhtPF9gOdEBl65D3C02OFI8wrFuq-muNsSy6fXJXEAgVDDixdFuhTZSWmvP5zqblJqUCPbtIghp3-quxhrSVvW9gJBK5QEkyb7t)

  

la fonction steno est une fonction void car elle n’as rien besoin de renvoyer elle sert juste a écrire l’image final. les paramettre de cette fonction sont deux tableau dynamique avec encore une fois passage par référence.

  

std::ofstream flux_secret permet de créer un flux d'écriture donc

`Flux_secret << “P3 250 250 255” << std::endl;` va écrire P3 250 250 255 dans le fichier image_secret.ppm et faire une retoure a la ligne.

  

passons maintenant à la boucle for, nous commençons par utiliser une fonction std::bitset qui fonction comme cela :

  

    bitset<nombre de bit>nom(variable à passer en binaire)
    bitset<8>visible_binaire(visible[i])

  

nous créons donc une nouvelle variable visible_binaire codé sur 8 bits et qui convertit la variable visible en binaire. de plus elle crée automatiquement un tableau où seront stockés les 0 et .

  

![](https://lh6.googleusercontent.com/5piZJJ8iRFNLZb7r_ItLuxX3G7wvgZIiqaczY0iO5XUZdpuvxZYW3Y4alIoOfy9-VAhpiKBzBEAEhja9qE8UVtd7MRJMuqSftZErZilrMGNNzTSGOszlVpz0LK0S526DFat-BhZC)

  

cette partie dans la boucle permet le fonctionnement de la méthode LSB

il faut aussi comprendre que la fonction bitset créer un tableau ou dans un tableau de 8 case les 4 première seront les LSB.

  

couleur nous permet calculer la valeur du niveau de couleur grâce au tableau créé par la fonction bitset. de plus `<math.h>` interviens ici pour le pow() qui fonction de cette façon :

    pow(chiffre, puissance)

et à la fin nous écrivons dans le document la valeur du niveau de couleur.

![](https://lh5.googleusercontent.com/zAU_yQLYZGrW0Q5aLM862tAZ16Vh7n_GbPBV73UEViMZFQ9QFCwf4QTid5iSKmOah4Ylv96td1KfUAaUJert58ROnPn712stTvS49SvcbwknbwHFwpMbs_uyEun9-CcAkQhVHL5S)

ici tout on ne parle pas réellement de pixel mais plutôt de niveau de couleur donc tout les 9 niveau de couleur il y a un retour à la ligne car une limitation des images .ppm et de 70 caractère par ligne. on fait donc tout les 9 tours de la boucle for un retour à la ligne.

***je n'utilise pas de maloc ou de pointeur dans ce programme***
