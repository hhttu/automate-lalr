#include <iostream>
#include <map>
#include "TAE.h"

void remplirTable(TableauAnalyse &table) {
    // État 0
    table[0][EXPRESSION] = TAE(TAEType::NON_TERMINAUX, 1);
    table[0][OPENPAR] = TAE(TAEType::DECALAGE, 2);
    table[0][INT] = TAE(TAEType::DECALAGE, 3);

    // État 1
    table[1][PLUS] = TAE(TAEType::DECALAGE, 4);
    table[1][MULT] = TAE(TAEType::DECALAGE, 5);
    table[1][FIN] = TAE(TAEType::ACCEPTER);

    // État 2
    table[2][EXPRESSION] = TAE(TAEType::NON_TERMINAUX, 6);
    table[2][OPENPAR] = TAE(TAEType::DECALAGE, 2);
    table[2][INT] = TAE(TAEType::DECALAGE, 3);

    // État 3
    table[3][PLUS] = TAE(TAEType::REDUCTION, 5);
    table[3][MULT] = TAE(TAEType::REDUCTION, 5);
    table[3][CLOSEPAR] = TAE(TAEType::REDUCTION, 5);
    table[3][FIN] = TAE(TAEType::REDUCTION, 5);

    // État 4
    table[4][EXPRESSION] = TAE(TAEType::NON_TERMINAUX, 7);
    table[4][OPENPAR] = TAE(TAEType::DECALAGE, 2);
    table[4][INT] = TAE(TAEType::DECALAGE, 3);

    // État 5
    table[5][EXPRESSION] = TAE(TAEType::NON_TERMINAUX, 8);
    table[5][OPENPAR] = TAE(TAEType::DECALAGE, 2);
    table[5][INT] = TAE(TAEType::DECALAGE, 3);

    // État 6
    table[1][PLUS] = TAE(TAEType::DECALAGE, 4);
    table[1][MULT] = TAE(TAEType::DECALAGE, 5);
    table[1][CLOSEPAR] = TAE(TAEType::DECALAGE, 9);

    // État 7
    table[7][PLUS] = TAE(TAEType::REDUCTION, 2);
    table[7][MULT] = TAE(TAEType::DECALAGE, 5);
    table[7][CLOSEPAR] = TAE(TAEType::REDUCTION, 2);
    table[7][FIN] = TAE(TAEType::REDUCTION, 2);

    // État 8
    table[8][PLUS] = TAE(TAEType::REDUCTION, 3);
    table[8][MULT] = TAE(TAEType::REDUCTION, 3);
    table[8][CLOSEPAR] = TAE(TAEType::REDUCTION, 3);
    table[8][FIN] = TAE(TAEType::REDUCTION, 3);

    // État 9
    table[9][PLUS] = TAE(TAEType::REDUCTION, 4);
    table[9][MULT] = TAE(TAEType::REDUCTION, 4);
    table[9][CLOSEPAR] = TAE(TAEType::REDUCTION, 4);
    table[9][FIN] = TAE(TAEType::REDUCTION, 4);
}

void afficherTable(const TableauAnalyse& table) {
    for (const auto& etat : table) {
        std::cout << "État " << etat.first << ":\n";
        for (const auto& transition : etat.second) {
            std::cout << "  Symbole: " << transition.first << " -> ";
            transition.second.afficher();
        }
    }
}
