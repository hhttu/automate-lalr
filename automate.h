#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <stack>
#include <vector>
#include "symbole.h"
#include "regle.h"
#include "lexer.h"
#include "TAE.h"
using namespace std;

class Automate {
    /// Classe représentant un automate syntaxique

    public:

        /** 
         * Constructeur par défaut et destructeur de la classe Automate
         */
        Automate();
        ~Automate();
        
        /** 
         * Exécute l'automate en analysant la chaîne donnés par le lexer
         * 
         * @param[in] lexer {Lexer} Analyseur lexical fournissant la chaîne
         */
        void executer(Lexer lexer);

        /** 
         * Initialise l'automate en réinitialisant les piles et les règles.
         */
        void init();

        /** 
         * Affiche les règles utilisées par l'automate.
         */
        void afficherRegles();

    protected:
        stack<int> pileEtat;
        stack<Symbole*> pileSymbole;
        TableauAnalyse TA;
        vector<Regle*> regles;

        /** 
         * Dépile un symbole et un état.
         * 
         * @param[in] s {Symbole*} Symbole à dépiler.
         * @param[in] e {int} État correspondant.
         */
        void depiler(Symbole* s, int e);

        /** 
         * Empile les piles en fonction de la règle de réduction
         * 
         * @param[in] regleReduction {Regle*} Règle de réduction à utiliser
         */
        void empiler(Regle* regleReduction);

        /** 
         * Vide les piles de l'automate.
         */
        void emptyPiles();
};

#endif // AUTOMATE_H