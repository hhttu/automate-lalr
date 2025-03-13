#ifndef TAE_H
#define TAE_H

#include "symbole.h"
#include <map>

using namespace std;

/**
 * @brief Enumération des types d'actions possibles dans la table d'analyse syntaxique.
 *
 * Cette énumération définit les différentes actions pouvant être effectuées 
 * lors de l'analyse syntaxique, notamment :
 * - `DECALAGE` : Déplacement vers un nouvel état.
 * - `REDUCTION` : Réduction selon une règle grammaticale.
 * - `ACCEPTER` : Acceptation de l'entrée comme correcte.
 * - `NON_TERMINAUX` : Action spécifique aux non-terminaux.
 * - `ERREUR` : Indique une erreur dans l'analyse.
 */
enum class TAEType {
    DECALAGE,
    REDUCTION,
    ACCEPTER,
    NON_TERMINAUX,
    ERREUR
};

class TAE {
// Classe représentant une action dans la table d'analyse syntaxique

    public:

        /**
         * @brief Constructeur avec initialisation des attributs.
         *
         * @param t Type d'action (`TAEType`).
         * @param v Valeur associée à l'action (par défaut `-1`).
         */
        TAE(TAEType t, int v = -1) : type(t), valeur(v) {};

        /** 
         * Constructeur par défaut et destructeur de la classe Regle.
         */
        TAE();
        ~TAE();

        /**
         * @brief Retourne le type de l'action.
         *
         * @return Le type `TAEType` de l'action.
         */
        TAEType getType() const { return type; }

        /**
         * @brief Retourne la valeur associée à l'action.
         *
         * @return Un entier représentant la valeur de l'action.
         */
        int getValue() const { return valeur; }

        /**
         * @brief Affiche les détails de l'action pour le débogage.
         *
         * Cette fonction affiche le type de l'action et sa valeur 
         * sur la sortie standard.
         */
        void afficher() const; 
    
    private:
        TAEType type;
        int valeur;

};

/**
 * @brief Définition de la table d'analyse syntaxique.
 *
 * La table d'analyse (`TableauAnalyse`) est une structure de données 
 * qui associe un état (`int`) à un ensemble d'actions (`TAE`) définies 
 * par un identificateur (`Identificateurs`).
 */
typedef map<int, map<Identificateurs, TAE>> TableauAnalyse;

/**
 * @brief Remplit la table d'analyse syntaxique.
 *
 * Cette fonction initialise et remplit la table d'analyse avec les différentes 
 * actions (`TAE`) nécessaires à l'analyse syntaxique d'un langage.
 *
 * @param table Référence vers la table d'analyse (`TableauAnalyse`).
 */
void remplirTable(TableauAnalyse &table);

/**
 * @brief Affiche le contenu de la table d'analyse syntaxique.
 *
 * Cette fonction parcourt et affiche chaque état de la table ainsi 
 * que les actions associées aux identificateurs.
 *
 * @param table Référence vers la table d'analyse à afficher.
 */
void afficherTable(const TableauAnalyse & table);

#endif // TAE_H
