#pragma once

#include <string>
using namespace std;

enum NonTerminal { E, E_prime };

const string NonTerminalEtiquettes[] = { "E", "E'" };

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPRESSION };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPRESSION" };

class Symbole {
   public:
      Symbole(Identificateurs i) : ident(i) {  }
      virtual ~Symbole() { }

      operator int() const { return ident; }
      virtual void Affiche();

      static bool isSameIndent(Symbole& s1, Symbole& s2);

   protected:
      Identificateurs ident;
};

class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT), valeur(v) { }
      ~Entier() { }

      virtual void Affiche();
      int getValue() const { return valeur; }

   protected:
      int valeur;
};

class Expression : public Symbole {
   public:
      Expression(NonTerminal NT, int v) : Symbole(EXPRESSION), NT(NT), valeur(v) { }
      ~Expression() {}

      virtual void Affiche();
      int getValue() const { return valeur; }
      NonTerminal getNT() const { return NT; }

   protected:
      NonTerminal NT;
      int valeur;
};