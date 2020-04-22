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
#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>
#include <iostream>

class Produit{

   friend std::ostream& operator <<(std::ostream& os, const Produit& p);

public:

   Produit(int no, const std::string& libelle, double prix);

   void setPrix(double prix);

private:
   int no;
   std::string libelle;
   double prix;
};

#endif /* PRODUIT_H */