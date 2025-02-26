#include <iostream>
#include "regle.h"

int Regle::getNbSymboleDroite() {
    return droite.size();
}

void Regle::Affiche() {
    cout << "Régle " << ": ";
    cout << NonTerminalEtiquettes[gauche] << " -> ";
    for (auto &s : droite) {
        s.Affiche();
        cout << " ";
    }
    cout << endl;
}

bool Regle::verifyParams(vector<Symbole>& params) {
    if (droite.size() != params.size()) {
        return false;
    }

    for (size_t i = 0; i < droite.size(); i++) {
        if ( !Symbole::isSameIndent(params[i], droite[i]) ) {
            return false;
        }
    }
    return true;
}

Symbole* Regle::evaluate(vector<Symbole>& v) {
    return evaluateFunction(v);
}

Regle::~Regle() {
    // cout << "Destructeur Regle" << endl;
}

Regle::Regle() {
    // cout << "Constructeur Regle" << endl;
}