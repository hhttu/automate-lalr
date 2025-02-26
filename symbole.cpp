#include "symbole.h"
#include <iostream>

void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}

void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}

void Expression::Affiche() {
   cout<<NonTerminalEtiquettes[NT];
   // if (valeur != NULL) {
   cout<<"("<<valeur<<")";
   // }
}

bool Symbole::isSameIndent(Symbole& s1, Symbole& s2) {
   if (s1.ident == ERREUR || s2.ident == ERREUR) {
      return false;
   }

   if (s1.ident != EXPRESSION && s2.ident != EXPRESSION) {
      return s1.ident == s2.ident;
   }
   
   return s1.ident == s2.ident && dynamic_cast<Expression&>(s1).getNT() == dynamic_cast<Expression&>(s2).getNT();
}

