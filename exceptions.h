/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : main.cpp
 Auteur(s)   : Anne Sophie Ganguillet, Kylian Bourcoud, Carl Penalva
 Date        : 22.04.2020

 But         :

 Remarque(s) :

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <exception>
#include <string>
class IndiceNonValide : public std::logic_error {
public:

   explicit IndiceNonValide(const std::string& s) : logic_error(s) {
   }

   explicit IndiceNonValide(const char* s) : logic_error(s) {
   }
};

class PrixNonValide : public std::logic_error {
public:

   explicit PrixNonValide(const std::string& s) : logic_error(s) {
   }

   explicit PrixNonValide(const char* s) : logic_error(s) {
   }
};
#endif /* EXCEPTIONS_H */

