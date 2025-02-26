#pragma once

#include <string>
using namespace std;

enum NonTerminal { E, E_prime };

const string NonTerminalEtiquettes[] = { "E", "E'" };

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPRESSION };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPRESSION" };

class Symbole {
   /// Classe de base pour les symboles de l'automate

   public:
      /**
       * @brief Constructeur pour la classe Symbole.
       * 
       * Initaliser avec un identificateur.
       * 
       * @param[in] i {Identificateur} Identificateur du symbole.
       */
      Symbole(Identificateurs i) : ident(i) {  }

      /**
       * @brief Destructeur pour la classe Symbole
       * 
       * Rien à faire
       */
      virtual ~Symbole() { }

      /**
       * @brief Opérateur convertissant le symbole en un entier
       * 
       * @return {Identificateurs} Identificateur du symbole
       */
      operator int() const { return ident; }

      /**
       * @brief Affiche le symbole
       * 
       * Affiche l'identificateur du symbole
       */
      virtual void Affiche();

      /**
       * @brief Retourne l'identificateur du symbole
       * 
       * @return {Identificateurs} Identificateur du symbole
       */
      Identificateurs getIdent() const { return ident; }

      /**
       * @brief Vérifie si deux symboles ont le même identificateur
       * 
       * @param[in] s1 {Symbole&} Premier symbole
       * @param[in] s2 {Symbole&} Deuxième symbole
       * @return {bool} Vrai si les deux symboles ont le même identificateur, faux sinon
       */
      static bool isSameIndent(Symbole& s1, Symbole& s2);

   protected:
      Identificateurs ident;
};

class Entier : public Symbole {
   /// Classe pour les symboles qui sont les entiers

   public:
      /**
       * @brief Constructeur pour la classe Entier
       * 
       * Initaliser avec un entier.
       *
       * @param[in] v {int} Valeur de l'entier.
       */
      Entier(int v) : Symbole(INT), valeur(v) { }

      /**
       * @brief Destructeur pour la classe Entier
       * 
       * Rien à faire
       */
      ~Entier() { }

      /**
       * @brief Affiche le symbole
       * 
       * Affiche la valeur de l'entier et l'identificateur INT
       */
      virtual void Affiche();

      /**
       * @brief Retourne la valeur de l'entier
       * 
       * @return {int} Valeur de l'entier
       */
      int getValue() const { return valeur; }

   protected:
      int valeur;
};

class Expression : public Symbole {
   /// Classe pour les symboles qui sont les expressions

   public:
      /**
       * @brief Constructeur pour la classe Expression
       * 
       * Initaliser avec un non terminal et une valeur.
       *
       * @param[in] NT {NonTerminal} Non terminal de l'expression.
       * @param[in] v {int} Valeur de l'expression.
       */
      Expression(NonTerminal NT, int v) : Symbole(EXPRESSION), NT(NT), valeur(v) { }

      /**
       * @brief Destructeur pour la classe Expression
       * 
       * Rien à faire
       */
      ~Expression() {}

      /**
       * @brief Affiche le symbole
       * 
       * Affiche le non terminal et la valeur de l'expression
       */
      virtual void Affiche();

      /**
       * @brief Retourne la valeur de l'expression
       * 
       * @return {int} Valeur de l'expression
       */
      int getValue() const { return valeur; }

      /**
       * @brief Retourne le non terminal de l'expression
       * 
       * @return {NonTerminal} Non terminal de l'expression
       */
      NonTerminal getNT() const { return NT; }

   protected:
      NonTerminal NT;
      int valeur;
};