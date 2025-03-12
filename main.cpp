#include <iostream>
#include "lexer.h"
#include "automate.h"
#include "TAE.h"

int main(void) {
   string chaine("1+(34**123)");

   Lexer l(chaine);

   Automate automate = Automate();
   automate.init();
   // automate.afficherRegles();

   automate.executer(l);
   return 0;
}

