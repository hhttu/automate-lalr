# automate-lalr

## Aperçu

`automate-lalr` est un projet C++ qui implémente un analyseur syntaxique Look-Ahead LR (LALR). L'analyseur analyse et évalue des expressions arithmétiques impliquant l'addition, la multiplication et les parenthèses, suivant la technique de l'analyse LALR.

## Fonctionnalités

- **Analyse des expressions arithmétiques** : Gère les expressions avec addition (`+`), multiplication (`*`) et parenthèses.
- **Look-Ahead LR (LALR)** : Technique d'analyse efficace conçue pour un sous-ensemble de grammaires hors-contexte.
- **Détection des fuites de mémoire** : Intégré avec Valgrind pour garantir que le programme est exempt de fuites de mémoire.

## Structure du projet

Le projet est organisé comme suit :

- **`automate.cpp` / `automate.h`** : Implémente la logique principale de l'analyseur LALR.
- **`lexer.cpp` / `lexer.h`** : Implémente l'analyseur lexical (lexer) qui tokenize la chaîne d'entrée en symboles.
- **`symbole.cpp` / `symbole.h`** : Définit les symboles utilisés par le lexer et l'analyseur.
- **`regle.cpp` / `regle.h`** : Contient les règles de grammaire et les fonctions d'évaluation pour l'analyse.
- **`TAE.cpp` / `TAE.h`** : Implémente la Table d'Analyse (TAE), qui guide le processus de décision de l'analyseur.
- **`main.cpp`** : Le point d'entrée du programme, qui initialise le lexer et l'analyseur et déclenche le processus d'analyse.
- **`Makefile`** : Définit le processus de compilation à l'aide de `make`.
- **`valgrind.txt`** : Sortie de Valgrind, utilisée pour vérifier les problèmes de mémoire lors de l'exécution.

## Installation

### Prérequis

Assurez-vous d'avoir les éléments suivants installés :

- Un compilateur C++ (par exemple, g++)
- Make
- Valgrind (pour la vérification des fuites de mémoire)

### Compilation du projet

Pour compiler le projet, exécutez la commande suivante dans le terminal :

```sh
make
```

Cela compilera tous les fichiers source et générera l'exécutable `main`.

### Exécution du projet

Une fois le projet compilé, exécutez-le en utilisant la commande suivante :

```sh
./main
```

Le programme vous demandera une expression arithmétique, puis l'analysera et l'évaluera.

### Vérification des fuites de mémoire

Pour vérifier les fuites de mémoire à l'aide de Valgrind, exécutez la commande suivante :

```sh
make leak
```

Cela exécutera le programme avec Valgrind, et les résultats seront enregistrés dans le fichier `valgrind.txt`.

## Contributeurs

Ce projet a été développé par les étudiants suivants du groupe 4IF-2 :

- **VU Thi Tho**
- **HUYNH Huu Thanh Tu**
- **NGO Truong Son**