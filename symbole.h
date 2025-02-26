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

      static bool isSameIndent(Symbole& s1, Symbole& s2) {
         if (s1.ident == ERREUR || s2.ident == ERREUR) {
            return false;
         }

         if (s1.ident != EXPRESSION && s2.ident != EXPRESSION) {
            return s1.ident == s2.ident;
         }
         
         return s1.ident == s2.ident; //&& dynamic_cast<Expression&>(s1).getNT() == dynamic_cast<Expression&>(s2).getNT();
      }

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
      ~Expression() { }
      virtual void Affiche();
      int getValue() const { return valeur; }
      NonTerminal getNT() const { return NT; }

   protected:
      NonTerminal NT;
      int valeur;
};