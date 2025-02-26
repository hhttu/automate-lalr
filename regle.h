#include "symbole.h"
#include <vector>
using namespace std;

class Regle {
    public:
        Regle(int i, NonTerminal g, vector<Symbole> d) : id(i), gauche(g), droite(d) { }
        ~Regle() { }
        virtual void Affiche();
        int getNbSymboleDroite();

        static Symbole* evaluateRegle(int id, vector<Symbole&> v) {
            //TODO: check input v of function depends on id
            //TODO: test function
            switch (id)
            {
            case 0:
                Expression& e = dynamic_cast<Expression&>(v[0]);
                return new Expression( NonTerminal::E_prime, e.getValue() ); // TODO: remember to free memory
            case 1:
                Expression& e1 = dynamic_cast<Expression&>(v[0]);
                Expression& e2 = dynamic_cast<Expression&>(v[2]);
                return new Expression( NonTerminal::E, e1.getValue() + e2.getValue() ); //TODO: remember to free memory
            case 2:
                Expression& e1 = dynamic_cast<Expression&>(v[0]);
                Expression& e2 = dynamic_cast<Expression&>(v[2]);
                return new Expression( NonTerminal::E, e1.getValue() * e2.getValue() ); //TODO: remember to free memory
            case 3:
                return new Expression( NonTerminal::E, dynamic_cast<Expression&>(v[1]).getValue() ); //TODO: remember to free memory
            case 4:
                return new Expression( NonTerminal::E, dynamic_cast<Entier&>(v[0]).getValue() ); //TODO: remember to free memory
            default:
                break;
            }
        };

    protected:
        int id;
        NonTerminal gauche;
        vector<Symbole> droite;
};