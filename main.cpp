#include <iostream>
#include "lexer.h"
#include "automate.h"
#include "TAE.h"

int main(void) {
   Automate automate = Automate();
   automate.init();

   string chaine("(112+213)*213+213*12");
   Lexer l(chaine);
   automate.executer(l);

   return 0;
}

