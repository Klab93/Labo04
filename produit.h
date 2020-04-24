/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : produit.h
 Auteur(s)   : Kylian Bourcoud, Anne Sophie Ganguillet, Carl Penalva
 Date        : 22.04.2020

 But         : classe qui représente des produits, représentés par un numéro, un
               libellé et un prix >= 5 ct
               La classe fourni les outils suivants :
               - Un constructeur prenant un numéro, un libellé et un prix en
               paramètre.
               - des accesseurs pour le prix (get et set)
               - un opérateur d'écriture sur un flux de sortie <<
               - un opérateur de comparaison d'égalité ==

 Remarque(s) : toutes les méthodes ont au moins un garantie forte
               le constructeur et la méthode setPrix peuvent lever une exception


 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/
#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>
#include <iostream>

class Produit{

   // opérateur d'écriture sur un flux
   friend std::ostream& operator <<(std::ostream& os, const Produit& p);

   //opérateur de comparaison d'égalité
   friend bool operator ==(const Produit& lhs, const Produit& rhs);

public:

   // constructeur
   // garantie forte :
   // exception de type PrixNonValide envoyée si prix < 0.05
   // après la levée de l'exception, l'objet se trouve dans l'état initialisé aux
   // valeurs données en paramètres (donc état connu)
   Produit(int no, const std::string& libelle, double prix);

   // modifier le prix
   // garantie forte
   // exception de type PrixNonValide envoyée si prix < 0.05
   void setPrix(double prix);

   // getter pour le prix
   // no-throw
   double getPrix() const noexcept;

private:
   int no;              // numéro
   std::string libelle; // libellé
   double prix;         // prix
};

#endif /* PRODUIT_H */