#include "automate.h"
#include "regle.h"
#include "symbole.h"
#include "TAE.h"
#include <iostream>

using namespace std;

Symbole* evaluateRegle1(vector<Symbole*> v);
Symbole* evaluateRegle2(vector<Symbole*> v);
Symbole* evaluateRegle3(vector<Symbole*> v);
Symbole* evaluateRegle4(vector<Symbole*> v);
Symbole* evaluateRegle5(vector<Symbole*> v);

bool isContainIdentificateurKey(TableauAnalyse& TA, int etat, Identificateurs identificateurs) {
    const auto& rowMap = TA[etat];
    return rowMap.find(identificateurs) != rowMap.end();
}

void Automate::init() {
    // TODO: init tableau d'analyse (Thi Tho)
    // TableauAnalyse TA = NULL; 

    Regle* r1 = new Regle(
        NonTerminal::E_prime, 
        vector<Symbole*>{ new Expression(NonTerminal::E, NULL) },
        evaluateRegle1 
    );

    Regle* r2 = new Regle(
        NonTerminal::E, 
        vector<Symbole*>{ new Expression(NonTerminal::E, NULL), new Symbole(PLUS), new Expression(NonTerminal::E, NULL) },
        evaluateRegle2
    );

    Regle* r3 = new Regle(
        NonTerminal::E, 
        vector<Symbole*>{ new Expression(NonTerminal::E, NULL), new Symbole(MULT), new Expression(NonTerminal::E, NULL) },
        evaluateRegle3
    );

    Regle* r4 = new Regle(
        NonTerminal::E, 
        vector<Symbole*>{ new Symbole(OPENPAR), new Expression(NonTerminal::E, NULL), new Symbole(CLOSEPAR) },
        evaluateRegle4
    );

    Regle* r5 = new Regle(
        NonTerminal::E, 
        vector<Symbole*>{ new Entier(NULL) },
        evaluateRegle5
    );

    regles = vector<Regle*>{r1, r2, r3, r4, r5};
    emptyPiles();
}

void Automate::afficherRegles() {
    for (auto &r : regles) {
        r->Affiche();
    }
}

void Automate::executer(Lexer lexer) {
    // TODO: empty 2 stacks (Thanh Tu)
    Symbole * s = lexer.Consulter();
    bool endExecution = false, isValid = true;
    int topEtat, finalValue = NULL;
    Identificateurs identificateurs;

    while (!endExecution && isValid && *s != FIN) {
        identificateurs = s->getIdent();
        topEtat = pileEtat.top();

        if (isContainIdentificateurKey(TA, topEtat, identificateurs)) {
            TAE element = TA[topEtat][identificateurs];

            // TAEType type = element.getType();
            // int valeur = element.getValue();

            // switch (TAEType)
            // {
            // case TAEType::DECALAGE:
            //     depiler(s, topEtat);
            //     s = lexer.Consulter();
            //     break;
            // case TAEType::REDUCTION:
            //     empiler(regles[valeur-1]);
            //     break;
            // case TAEType::ACCEPT:
            //     endExecution = true;
            //     finalValue = dynamic_cast<Expression*>(pileSymbole.top())->getValue();
            //     break;
            // case TAEType::ERREUR:
            //     endExecution = false;
            //     isValid = false;
            //     break;
            // default:
            //     break;
            // }
        } else {
            endExecution = false;
            isValid = false;
        }

    }

    if (isValid) {
        cout << "Chaine validée" << endl;
        if (finalValue) {
            cout << "Value = " << finalValue;
        }
    } else {
        cout << "Chaine invalidée";
    }

    emptyPiles();
}

void Automate::depiler(Symbole* s, int e) {
    // TODO: implement (Thanh Tu)
    pileEtat.push(e);
    pileSymbole.push(s);

    
}

void Automate::empiler(Regle* regleReduction) {
    // TODO: implement (Son), when empiler, remember to delete symbols -> not memory leak
    int n = regleReduction->getNbSymboleDroite();

    vector<Symbole*> empilePiles = vector<Symbole*>();
    for (int i = 0; i < n; i++) {
        pileEtat.pop();
        empilePiles.push_back(pileSymbole.top());
        pileSymbole.pop();
    }

    Symbole* s = regleReduction->evaluate(empilePiles);
    pileSymbole.push(s);

    int topEtat = pileEtat.top();
    int newEtat = TA[topEtat][s->getIdent()].getValue();
    pileEtat.push(newEtat);

    // delete symbols
    for (auto &s : empilePiles) {
        delete s;
    }
    empilePiles.clear();
}


void Automate::emptyPiles() {
    // Empty Pile etats
    pileEtat = stack<int>();

    // Empty Pile symboles
    while(!pileSymbole.empty()) {
        delete pileSymbole.top();
        pileSymbole.pop();
    }
    pileSymbole = stack<Symbole*>();
}

Automate::Automate() {
    // cout << "Constructeur Automate" << endl;
}

Automate::~Automate() {
    // cout << "Destructeur Automate" << endl;
    for (auto &r : regles) {
        delete r;
    }
    regles.clear();
    emptyPiles();
}



Symbole* evaluateRegle1(vector<Symbole*> v) {
    Expression* e = dynamic_cast<Expression*>(v[0]);
    return new Expression( NonTerminal::E_prime, e->getValue() );
}

Symbole* evaluateRegle2(vector<Symbole*> v) {
    Expression* e1 = dynamic_cast<Expression*>(v[0]);
    Expression* e2 = dynamic_cast<Expression*>(v[2]);
    return new Expression( NonTerminal::E, e1->getValue() + e2->getValue() );
}

Symbole* evaluateRegle3(vector<Symbole*> v) {
    Expression* e1 = dynamic_cast<Expression*>(v[0]);
    Expression* e2 = dynamic_cast<Expression*>(v[2]);
    return new Expression( NonTerminal::E, e1->getValue() * e2->getValue() );
}

Symbole* evaluateRegle4(vector<Symbole*> v) {
    return new Expression( NonTerminal::E, dynamic_cast<Expression*>(v[1])->getValue() );
}

Symbole* evaluateRegle5(vector<Symbole*> v) {
    return new Expression( NonTerminal::E, dynamic_cast<Entier*>(v[0])->getValue() );
}