#include <iostream>
#include <map>

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
    TAE(TAEType t, int v = -1) : type(t), valeur(v) {}

    TAEType getType() const { return type; }
    int getValeur() const { return valeur; }

    void afficher() const {
        std::string typeStr;
        switch (type) {
            case TAEType::DECALAGE: typeStr = "DECALAGE"; break;
            case TAEType::REDUCTION: typeStr = "REDUCTION"; break;
            case TAEType::ACCEPTER: typeStr = "ACCEPTER"; break;
            case TAEType::NON_TERMINAUX: typeStr = "NON_TERMINAUX"; break;
            case TAEType::ERREUR: typeStr = "ERREUR"; break;
        }
        std::cout << typeStr;
        if (valeur != -1) std::cout << " " << valeur;
        std::cout << std::endl;
    }
};

// Définition de la table d'analyse : état -> (symbole -> action TAE)
using TableAnalyse = std::map<int, std::map<char, TAE>>;

void remplirTable(TableAnalyse &table) {
    // État 0
    table[0]['E'] = TAE(TAEType::DECALAGE, 1);
    table[0]['('] = TAE(TAEType::DECALAGE, 2);
    table[0]['v'] = TAE(TAEType::DECALAGE, 3);

    // État 1
    table[1]['+'] = TAE(TAEType::DECALAGE, 4);
    table[1]['$'] = TAE(TAEType::ACCEPTER);

    // État 2
    table[2]['E'] = TAE(TAEType::DECALAGE, 5);
    table[2]['('] = TAE(TAEType::DECALAGE, 2);
    table[2]['v'] = TAE(TAEType::DECALAGE, 3);

    // État 3
    table[3]['+'] = TAE(TAEType::REDUCTION, 5);
    table[3]['*'] = TAE(TAEType::REDUCTION, 5);
    table[3][')'] = TAE(TAEType::REDUCTION, 5);
    table[3]['$'] = TAE(TAEType::REDUCTION, 5);

    // État 4
    table[4]['E'] = TAE(TAEType::DECALAGE, 6);
    table[4]['('] = TAE(TAEType::DECALAGE, 2);
    table[4]['v'] = TAE(TAEType::DECALAGE, 3);

    // État 5
    table[5][')'] = TAE(TAEType::DECALAGE, 7);
    table[5]['+'] = TAE(TAEType::DECALAGE, 4);
    table[5]['*'] = TAE(TAEType::DECALAGE, 8);

    // État 6
    table[6]['+'] = TAE(TAEType::REDUCTION, 1);
    table[6]['*'] = TAE(TAEType::DECALAGE, 8);
    table[6][')'] = TAE(TAEType::REDUCTION, 1);
    table[6]['$'] = TAE(TAEType::REDUCTION, 1);

    // État 7
    table[7]['+'] = TAE(TAEType::REDUCTION, 4);
    table[7]['*'] = TAE(TAEType::REDUCTION, 4);
    table[7][')'] = TAE(TAEType::REDUCTION, 4);
    table[7]['$'] = TAE(TAEType::REDUCTION, 4);

    // État 8
    table[8]['E'] = TAE(TAEType::DECALAGE, 9);
    table[8]['('] = TAE(TAEType::DECALAGE, 2);
    table[8]['v'] = TAE(TAEType::DECALAGE, 3);

    // État 9
    table[9]['+'] = TAE(TAEType::REDUCTION, 3);
    table[9]['*'] = TAE(TAEType::REDUCTION, 3);
    table[9][')'] = TAE(TAEType::REDUCTION, 3);
    table[9]['$'] = TAE(TAEType::REDUCTION, 3);
}

void afficherTable(const TableAnalyse& table) {
    for (const auto& etat : table) {
        std::cout << "État " << etat.first << ":\n";
        for (const auto& transition : etat.second) {
            std::cout << "  Symbole: " << transition.first << " -> ";
            transition.second.afficher();
        }
    }
}

int main() {
    TableAnalyse tableAnalyse;
    remplirTable(tableAnalyse);
    afficherTable(tableAnalyse);
    return 0;
}
