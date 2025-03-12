#pragma once

#include <string>
#include "symbole.h"
using namespace std;

class Lexer {
   /// Classe pour le lexer

   public:
      /**
       * @brief Constructeur pour la classe Lexer
       * 
       * Initaliser avec une chaine de caractères. Tete est initialisé à 0 (debut de la chaine) et tampon à nullptr.
       * 
       * @param[in] s {string} Chaine de caractères à analyser.
       */
      Lexer(string s) : flux(s), tete(0), tampon(nullptr) { }
      ~Lexer() { }

      /**
       * @brief Retourne le symbole suivant
       * 
       * Si le tampon est vide (nullptr), on analyse le prochain symbole de la chaine et on le retourne.
       * Sinon, on retourne le symbole dans le tampon.
       * 
       * @return {Symbole*} Symbole suivant
       */
      Symbole * Consulter();

      /**
       * @brief Avance le tampon
       * 
       * Met le tampon à nullptr pour forcer la fonction Consulter() à analyser le prochain symbole.
       */
      void Avancer();

   protected:
      string flux; // Chaine de caractères à analyser
      int tete; // Position actuelle dans la chaine
      Symbole * tampon; // Symbole actuel
};
