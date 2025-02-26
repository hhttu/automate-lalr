#include <iostream>
#include "regle.h"

int Regle::getNbSymboleDroite() {
    return droite.size();
}

void Regle::Affiche() {
    cout << "Régle " << id << ": ";
    cout << (char) gauche;
    cout << " -> ";
    for (auto &s : droite) {
        s.Affiche();
        cout << " ";
    }
    cout << endl;
}