#ifndef REGLE_H
#define REGLE_H

#include <vector>
#include <functional>

#include "symbole.h"

using namespace std;

class Regle {
    /// Classe de base pour les regles de l'automate

    public:

        /** 
         * Constructeur par défault pour la classe Regle.
         */
        Regle();

        /** 
         * Constructeur pour la classe Regle.
         * 
         * Initaliser avec un non terminal, une liste de symboles et une fonction d'évaluation.
         * 
         * @param[in] g {NonTerminal} Non terminal du côté gauche de la règle.
         * @param[in] d {vector<Symbole*>} Liste de symboles du côté droit de la règle.
         * @param[in] f {function<Symbole*(vector<Symbole*>)>} Fonction d'évaluation de la règle.
         * 
         * Par exemple, pour la règle E -> E + E, on peut avoir:
         * g = NonTerminal::E
         * d = { new Expression(NonTerminal::E, NULL), new Symbole(PLUS), new Expression(NonTerminal::E, NULL) }
         * f = return new Expression( NonTerminal::E, e1->getValue() + e2->getValue() );
         */
        Regle(NonTerminal g, vector<Symbole*> d, function<Symbole*(vector<Symbole*>)>f) : gauche(g), droite(d), evaluateFunction(f) { }

        /** 
         * Affiche la règle.
         */
        ~Regle();

        /** 
         * Affiche la règle.
         */
        void Affiche();

        /** 
         * Retourne le nombre de symboles du côté droit de la règle.
         * 
         * @return {int} Nombre de symboles du côté droit de la règle.
         */
        int getNbSymboleDroite();

        /** 
         * Vérifie si les paramètres passés correspondent à la règle.
         * 
         * @param[in] params {vector<Symbole*>} Liste de symboles à vérifier.
         * 
         * @return {bool} Vrai si les paramètres correspondent à la règle, faux sinon.
         */
        bool verifyParams(vector<Symbole*> params);

        /** 
         * Évalue la règle avec les paramètres passés.
         * 
         * @param[in] v {vector<Symbole*>} Liste de symboles à évaluer.
         * 
         * @return {Symbole*} Résultat de l'évaluation.
         */
        Symbole* evaluate(vector<Symbole*> v);

    protected:
        NonTerminal gauche; // Non terminal du côté gauche de la règle
        vector<Symbole*> droite; // Liste de symboles du côté droit de la règle
        function<Symbole*(vector<Symbole*>)> evaluateFunction; // Fonction d'évaluation de la règle
};


#endif // REGLE_H