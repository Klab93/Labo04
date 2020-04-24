/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : exceptions.h
 Auteur(s)   : Kylian Bourcoud, Anne Sophie Ganguillet, Carl Penalva
 Date        : 22.04.2020

 But         : exceptions utiles pour les classes Produit et Collection

 Remarque(s) : héritent de std::logic_error

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <exception>
#include <string>
class IndiceNonValide : public std::logic_error {
public:
   explicit IndiceNonValide(const char* s) : logic_error(s) {
   }
};

class PrixNonValide : public std::logic_error {
public:
   explicit PrixNonValide(const char* s) : logic_error(s) {
   }
};
#endif /* EXCEPTIONS_H */

