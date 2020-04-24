/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Produit.cpp
 Auteur(s)   : Kylian Bourcoud, Anne Sophie Ganguillet, Carl Penalva
 Date        : 22.04.2020

 But         : implémentation de la classe produit

 Remarque(s) : -

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/
#include "produit.h"
#include "exceptions.h"
#include <iomanip>

using namespace std;

Produit::Produit(int no, const string& libelle, double prix)
   :no(no), libelle(libelle), prix(prix) {
   if(prix < 0.05) throw(PrixNonValide("Erreur dans Produit::Produit :\n"
                                          "le prix doit etre >= 5 cts !"));
}

ostream &operator<<(ostream &os, const Produit &p) {
   os << '(' << p.no << ", \"" << p.libelle << "\", "
   << fixed << setprecision(2) << p.prix << ')';
   return os;
}

void Produit::setPrix(double _prix) {
   if(_prix < 0.05) throw(PrixNonValide("Erreur dans Produit::setPrix :\n"
                                           "le prix doit etre >= 5 cts !"));
   prix = _prix;
}

double Produit::getPrix() const {
   return prix;
}

bool operator==(const Produit &lhs, const Produit &rhs) {
   return lhs.prix == rhs.prix and lhs.libelle == rhs.libelle and lhs.no == rhs.no ;
}


