#include "automate.h"
#include "regle.h"
#include "symbole.h"


Symbole* evaluateRegle1(vector<Symbole>& v) {
    Expression& e = dynamic_cast<Expression&>(v[0]);
    return new Expression( NonTerminal::E_prime, e.getValue() );
}

Symbole* evaluateRegle2(vector<Symbole>& v) {
    Expression& e1 = dynamic_cast<Expression&>(v[0]);
    Expression& e2 = dynamic_cast<Expression&>(v[2]);
    return new Expression( NonTerminal::E, e1.getValue() + e2.getValue() );
}

Symbole* evaluateRegle3(vector<Symbole>& v) {
    Expression& e1 = dynamic_cast<Expression&>(v[0]);
    Expression& e2 = dynamic_cast<Expression&>(v[2]);
    return new Expression( NonTerminal::E, e1.getValue() * e2.getValue() );
}

Symbole* evaluateRegle4(vector<Symbole>& v) {
    return new Expression( NonTerminal::E, dynamic_cast<Expression&>(v[1]).getValue() );
}

Symbole* evaluateRegle5(vector<Symbole>& v) {
    return new Expression( NonTerminal::E, dynamic_cast<Entier&>(v[0]).getValue() );
}

void Automate::init() {
    // TODO: init tableau d'analyse (Thi Tho)
    // TableauAnalyse TA = NULL; 

    // TODO: add regles

    Regle r1 = Regle(
        NonTerminal::E_prime, 
        vector<Symbole>{ Expression(NonTerminal::E, 0) },
        evaluateRegle1 
    );

    Regle r2 = Regle(
        NonTerminal::E, 
        vector<Symbole>{ Expression(NonTerminal::E, 0), Symbole(PLUS), Expression(NonTerminal::E, 0) },
        evaluateRegle2
    );

    Regle r3 = Regle(
        NonTerminal::E, 
        vector<Symbole>{ Expression(NonTerminal::E, 0), Symbole(MULT), Expression(NonTerminal::E, 0) },
        evaluateRegle3
    );

    Regle r4 = Regle(
        NonTerminal::E, 
        vector<Symbole>{ Symbole(OPENPAR), Expression(NonTerminal::E, 0), Symbole(CLOSEPAR) },
        evaluateRegle4
    );

    Regle r5 = Regle(
        NonTerminal::E, 
        vector<Symbole>{ Entier(0) },
        evaluateRegle5
    );

    regles = vector<Regle>();
    regles.push_back(r1);
    regles.push_back(r2);
    regles.push_back(r3);
    regles.push_back(r4);
    regles.push_back(r5);
}

void Automate::afficherRegles() {
    for (auto &r : regles) {
        r.Affiche();
    }
}

void Automate::executer(Lexer lexer) {
    // TODO: empty 2 stacks (Thanh Tu)

    // algorithme
}

void Automate::depiler(Symbole& s, int e) {
    // TODO: implement (Thanh Tu)
}

void Automate::empiler(int n, Symbole& s, int e) {
    // TODO: implement (Son)
}

Automate::Automate() {
    //TODO
    // cout << "Constructeur Automate" << endl;
}

Automate::~Automate() {
    // TODO
    // cout << "Destructeur Automate" << endl;
}


