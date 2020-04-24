/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : produit.cpp
 Auteur(s)   : Anne Sophie Ganguillet, Kylian Bourcoud, Carl Penalva
 Date        : 22.04.2020

 But         : classe qui représente des produits, représentés par un numéro, un
               libellé et un prix >= 5 ct
               possibilité d'afficher un produit et de tester l'égalité entre deux
               produits

 Remarque(s) : toutes les méthodes ont au moins un garantie forte


 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/
#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>
#include <iostream>

class Produit{

   friend std::ostream& operator <<(std::ostream& os, const Produit& p);
   friend bool operator ==(const Produit& lhs, const Produit& rhs);

public:

   // garantie forte
   // exception de type PrixNonValide envoyée si prix < 0.05
   Produit(int no, const std::string& libelle, double prix);

   //garantie forte
   // exception de type PrixNonValide envoyée si prix < 0.05
   void setPrix(double prix);

   //no-throw
   double getPrix() const;

private:
   int no;
   std::string libelle;
   double prix;
};

#endif /* PRODUIT_H */