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
    public:
        Automate();
        ~Automate();
        
        void executer(Lexer lexer);

        void init();

        void afficherRegles();

    protected:
        stack<int> pileEtat;
        stack<Symbole*> pileSymbole;
        // TableauAnalyse TA;
        vector<Regle*> regles;

        void depiler(Symbole* s, int e);
        void empiler(int n, Symbole* s, int e);
        void emptyPiles();
};

#endif // AUTOMATE_H