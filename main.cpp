#include <iostream>
#include "lexer.h"
#include "automate.h"
#include "TAE.h"

int main(void) {
   // definir l'automate
   Automate automate = Automate();
   automate.init();

   // definir la chaine
   string chaine("(112+213)*213+213*12");
   Lexer l(chaine);

   // analyser la chaine et afficher le resultat
   automate.executer(l);

   return 0;
}

