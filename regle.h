#ifndef REGLE_H
#define REGLE_H

#include <vector>
#include <functional>

#include "symbole.h"

using namespace std;

class Regle {
    public:
        Regle();
        Regle(NonTerminal g, vector<Symbole*> d, function<Symbole*(vector<Symbole*>)>f) : gauche(g), droite(d), evaluateFunction(f) { }
        ~Regle();

        void Affiche();
        int getNbSymboleDroite();

        bool verifyParams(vector<Symbole*> params);
        Symbole* evaluate(vector<Symbole*> v);

    protected:
        NonTerminal gauche;
        vector<Symbole*> droite;
        function<Symbole*(vector<Symbole*>)> evaluateFunction;
};


#endif // REGLE_H