#ifndef TAE_H
#define TAE_H

#include "symbole.h"
#include <map>

using namespace std;

enum class TAEType {
    DECALAGE,
    REDUCTION,
    ACCEPTER,
    NON_TERMINAUX,
    ERREUR
};

class TAE {
private:
    TAEType type;
    int valeur;

public:
    // Constructeur
    TAE(TAEType t, int v = -1) : type(t), valeur(v) {}

    // Accesseurs
    TAEType getType() const { return type; }
    int getValeur() const { return valeur; }

    // Affichage pour débogage
    void afficher() const {
        string typeStr;
        switch (type) {
            case TAEType::DECALAGE: typeStr = "DECALAGE"; break;
            case TAEType::REDUCTION: typeStr = "REDUCTION"; break;
            case TAEType::ACCEPTER: typeStr = "ACCEPTER"; break;
            case TAEType::NON_TERMINAUX: typeStr = "NON_TERMINAUX"; break;
            case TAEType::ERREUR: typeStr = "ERREUR"; break;
        }
        cout << "Type: " << typeStr;
        if (valeur != -1) cout << ", Valeur: " << valeur;
        cout << endl;
    }
};

// Définition de la table d’analyse (État → (Identificateur → Action TAE))
typedef map<int, map<Identificateurs, TAE>> TableauAnalyse;

void remplirTable(TableauAnalyse &table);
void afficherTable(const TableauAnalyse & table);

#endif // TAE_H
