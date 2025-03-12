#include <iostream>
#include "regle.h"

int Regle::getNbSymboleDroite() {
    return droite.size();
}

void Regle::Affiche() {
    cout << "Régle " << ": ";
    cout << NonTerminalEtiquettes[gauche] << " -> ";
    for (auto &s : droite) {
        s->Affiche();
        cout << " ";
    }
    cout << endl;
}

bool Regle::verifyParams(vector<Symbole*> params) {
    if (droite.size() != params.size()) {
        return false;
    }

    int paramsSize = params.size();
    for (size_t i = 0; i < paramsSize; i++) {
        if ( !Symbole::isSameIndent( *params[paramsSize-i-1], *droite[i]) ) {
            return false;
        }
    }
    return true;
}

Symbole* Regle::evaluate(vector<Symbole*> v) {
    if (!verifyParams(v)) {
        return new Symbole(ERREUR);
        throw "Erreur de paramètres"; // TODO: check if this erreur is thrown or not
    }
    return evaluateFunction(v);
}

Regle::~Regle() {
    // cout << "Destructeur Regle" << endl;
    for (auto &s : droite) {
        delete s;
    }
    droite.clear();
}

Regle::Regle() {
    // cout << "Constructeur Regle" << endl;
}