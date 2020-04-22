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
#include "produit.h"


using namespace std;

Produit::Produit(int no, const string& libelle, double prix)
   :no(no), libelle(libelle), prix(prix) {}

ostream &operator<<(ostream &os, const Produit &p) {
   os << '(' << p.no << ", " << p.libelle << ", " << p.prix << ')';
   return os;
}

void Produit::setPrix(double _prix) {
   prix = _prix;
}

bool operator==(const Produit &lhs, const Produit &rhs) {
   return lhs.prix == rhs.prix and lhs.libelle == rhs.libelle and lhs.no == rhs.no ;
}