#include <iostream>
#include "automate.h"
#include "regle.h"
#include "symbole.h"
#include "TAE.h"

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
    // Initialiser la table d'analyse
    remplirTable(TA);

    // Initialiser les règles
    Regle* r1 = new Regle(
        NonTerminal::E_prime, 
        vector<Symbole*>{ new Expression(NonTerminal::E, 0) },
        evaluateRegle1 
    );

    Regle* r2 = new Regle(
        NonTerminal::E, 
        vector<Symbole*>{ new Expression(NonTerminal::E, 0), new Symbole(PLUS), new Expression(NonTerminal::E, 0) },
        evaluateRegle2
    );

    Regle* r3 = new Regle(
        NonTerminal::E, 
        vector<Symbole*>{ new Expression(NonTerminal::E, 0), new Symbole(MULT), new Expression(NonTerminal::E, 0) },
        evaluateRegle3
    );

    Regle* r4 = new Regle(
        NonTerminal::E, 
        vector<Symbole*>{ new Symbole(OPENPAR), new Expression(NonTerminal::E, 0), new Symbole(CLOSEPAR) },
        evaluateRegle4
    );

    Regle* r5 = new Regle(
        NonTerminal::E, 
        vector<Symbole*>{ new Entier(0) },
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
    // Initialise la pile des états avec l'état initial (0)
    pileEtat.push(0);
    
    // Récupère le premier symbole analysé par le lexer
    Symbole * s = lexer.Consulter();

    bool endExecution = false, isValid = true;
    int topEtat, finalValue;
    Identificateurs identificateur;

    // Boucle pour traiter les symboles dans la chaîne d'entrée
    // jusqu'à ce que la chaîne soit acceptée ou invalidée.
    while (!endExecution && isValid) {

        // Récupère l'identificateur du symbole courant et l'état au sommet de la pile
        identificateur = s->getIdent();
        topEtat = pileEtat.top();

         // Vérifie si la table d'analyse (TA) contient une transition pour l'état et l'identificateur courants
        if (isContainIdentificateurKey(TA, topEtat, identificateur)) {

            // Récupère l'élément de transition correspondant et son type d'action et sa valeur associée
            TAE element = TA[topEtat][identificateur];
            TAEType type = element.getType();
            int valeur = element.getValue();
        
            // Exécute l'action en fonction du type d'élément trouvé
            switch (type)
            {
            case TAEType::DECALAGE:
                // Décalage : empile l'état et le symbole, puis avance dans le lexer
                depiler(s, valeur);
                lexer.Avancer();
                s = lexer.Consulter();
                break;
            case TAEType::REDUCTION:
                // Réduction : applique une règle de réduction en empilant un nouveau symbole
                empiler(regles[valeur-1]);
                break;
            case TAEType::ACCEPTER:
                // Acceptation : la chaîne d'entrée est reconnue
                endExecution = true;
                finalValue = dynamic_cast<Expression*>(pileSymbole.top())->getValue();
                break;
            case TAEType::ERREUR:
                // Erreur : la chaîne est invalide
                endExecution = false;
                isValid = false;
                break;
            default:
                break;
            }
        } else {
            // Aucun élément trouvé dans la table, la chaîne est invalide
            endExecution = false;
            isValid = false;
        }

    }

    // Affichage du résultat
    if (isValid) {
        cout << "Chaine validée" << endl;
        if (finalValue) {
            cout << "Value = " << finalValue << endl;
        }
    } else {
        cout << "Chaine invalidée" << endl;
    }

    emptyPiles(); // vide les piles après l'exécution
    delete s; // on supprime le dernier symbole
}

void Automate::depiler(Symbole* s, int e) {
    // Dépile un symbole et un état
    pileEtat.push(e);
    pileSymbole.push(s);
}

void Automate::empiler(Regle* regleReduction) {
    // Empile les piles en fonction de la règle de réduction

    // On dépile n symboles de la pile symbole
    int n = regleReduction->getNbSymboleDroite();
    vector<Symbole*> empilePiles = vector<Symbole*>(); // Piles à empiler, pour les supprimer après (delete)
    for (int i = 0; i < n; i++) {
        pileEtat.pop();
        empilePiles.push_back(pileSymbole.top());
        pileSymbole.pop();
    }

    // On empile le symbole de gauche qui est retourné par la fonction d'évaluation de la règle de réduction
    Symbole* s = regleReduction->evaluate(empilePiles);
    pileSymbole.push(s);

    // On détermine le nouvel état et on l'empile
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


// Definir les fonctions d'évaluation des règles

Symbole* evaluateRegle1(vector<Symbole*> v) { // E' -> E
    Expression* e = dynamic_cast<Expression*>(v[0]);
    return new Expression( NonTerminal::E_prime, e->getValue() );
}

Symbole* evaluateRegle2(vector<Symbole*> v) { // E -> E + E
    Expression* e1 = dynamic_cast<Expression*>(v[0]);
    Expression* e2 = dynamic_cast<Expression*>(v[2]);
    return new Expression( NonTerminal::E, e1->getValue() + e2->getValue() );
}

Symbole* evaluateRegle3(vector<Symbole*> v) { // E -> E * E
    Expression* e1 = dynamic_cast<Expression*>(v[0]);
    Expression* e2 = dynamic_cast<Expression*>(v[2]);
    return new Expression( NonTerminal::E, e1->getValue() * e2->getValue() );
}

Symbole* evaluateRegle4(vector<Symbole*> v) { // E -> (E)
    return new Expression( NonTerminal::E, dynamic_cast<Expression*>(v[1])->getValue() );
}

Symbole* evaluateRegle5(vector<Symbole*> v) { // E -> entier
    return new Expression( NonTerminal::E, dynamic_cast<Entier*>(v[0])->getValue() );
}