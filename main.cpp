#include <iostream>
#include "lexer.h"
#include "automate.h"


int main(void) {
   string chaine("(1+34)*123");

   Lexer l(chaine);

   // Automate& automate = Automate::getInstance();
   // automate.init();
   Automate automate = Automate();
   automate.init();
   automate.afficherRegles();


   // Symbole * s;
   // while(*(s=l.Consulter())!=FIN) {
   //    s->Affiche();
   //    cout<<endl;
   //    l.Avancer();
   // }
   return 0;
}

