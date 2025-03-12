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
    TAE();
    TAE(TAEType t, int v = -1) : type(t), valeur(v) {};
    ~TAE();

    // Accesseurs
    TAEType getType() const { return type; }
    int getValue() const { return valeur; }

    // Affichage pour débogage
    void afficher() const; 

};

// Définition de la table d’analyse (État → (Identificateur → Action TAE))
typedef map<int, map<Identificateurs, TAE>> TableauAnalyse;

void remplirTable(TableauAnalyse &table);
void afficherTable(const TableauAnalyse & table);

#endif // TAE_H
