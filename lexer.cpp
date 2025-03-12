#include "lexer.h"

Symbole * Lexer::Consulter() {
   if (!tampon) {

      if (tete==flux.length()) // fin de la chaîne -> symbole spécial de fin
         tampon = new Symbole(FIN);
      else
      {

         switch (flux[tete]) {
            case '(':
               tampon = new Symbole(OPENPAR);
               tete++;
               break;
            case ')':
               tampon = new Symbole(CLOSEPAR);
               tete++;
               break;
            case '*':
               tampon = new Symbole(MULT);
               tete++;
               break;
            case '+':
               tampon = new Symbole(PLUS);
               tete++;
               break;
            default:
               // cas d'un entier
               if (flux[tete]<='9' && flux[tete]>='0') { 
                  int resultat = flux[tete]-'0'; //transformation du caractère en entier

                  // Faire un while boucle pour lire tous les chiffres consécutifs et les convertir en entier
                  int i=1;
                  while (flux[tete+i]<='9' && flux[tete+i]>='0') {
                     resultat = resultat*10+(flux[tete+i]-'0');
                     i++;
                  }
                  tete = tete+i;
                  tampon = new Entier(resultat);
               }

               // caractère non reconnu
               else {
                  tampon = new Symbole(ERREUR);
               }
         }
      }
   }
   return tampon;
}

void Lexer::Avancer() {
   tampon = nullptr;
}

