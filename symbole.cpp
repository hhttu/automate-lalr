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
   cout<<"("<<valeur<<")";
}

bool Symbole::isSameIndent(Symbole& s1, Symbole& s2) {
   // si l'un des symboles est une erreur, retourner faux
   if (s1.ident == ERREUR || s2.ident == ERREUR) {
      return false;
   }

   // si les deux symboles ne sont pas des expressions, retourner vrai si les valeurs sont égales
   if (s1.ident != EXPRESSION && s2.ident != EXPRESSION) {
      return s1.ident == s2.ident;
   }
   
   // si les deux symboles sont des expressions, retourner vrai si les non terminaux sont identiques
   return s1.ident == s2.ident && dynamic_cast<Expression&>(s1).getNT() == dynamic_cast<Expression&>(s2).getNT();
}

