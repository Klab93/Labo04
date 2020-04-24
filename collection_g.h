/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : collection_g.h
 Auteur(s)   : Kylian Bourcoud, Anne Sophie Ganguillet, Carl Penalva
 Date        : 22.04.2020

 But         : Mettre à disposition une classe Collection générique modélisant une
               collection et permettant d'effectuer diverses manipulation sur
               celle-ci.
               La classe fourni les outils suivants :
               - Une surcharge de l'opérateur << permettant d'afficher une collection
               - Un constructeur par défaut.
               - Une méthode void ajouter(T element) permettant d'ajouter un élément
                 à la collection.
               - Une méthode T& get(size_t indice) permettant d'accéder en
                 lecture/écriture à un élément de la collection.
               - Une méthode size_t taille() retournant la taille de la collection;
               - Une méthode bool contient(const T& element) permettant de savoir si
                 la collection contient un certain élément.
               - Une méthode void vider() permettant de vider la collection.
               - Une méthode void parcourir(unaryFunc) permettant de parcourir
                 la collection en appliquant unaryFunc à chacun de ses éléments.

 Remarque(s) : La classe ne peut être utilisée qu'avec des conteneurs
               mettant à disposition les méthodes push_back(), size(), back(),
               clear(), empty(), begin() et end().
               La méthode get() lève une exception du type IndiceNonValide si
               l'indice passé en paramètre est supérieur ou égal à la taille
               de la collection.
               La méthode ajouter() peut lever les exceptions de push_back().


 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#ifndef COLLECTION_G_H
#define COLLECTION_G_H
#include <iostream>
#include <memory>
template <typename T, template <typename, typename = std::allocator<T>>
class Conteneur>
class Collection;

// Surcharge de l'opérateur de flux permettant d'afficher une collection
template <typename T, template <typename, typename = std::allocator<T>>
class Conteneur>
std::ostream& operator<<(std::ostream& lhs,
        const Collection<T, Conteneur>& rhs);

template <typename T, template <typename, typename = std::allocator<T>>
class Conteneur>
class Collection {
   // Déclaration d'amitié de l'opérateur de flux
   friend std::ostream& operator<< <T, Conteneur>(std::ostream& lhs,
           const Collection<T, Conteneur>& rhs);
public:
   // Constructeur par défaut
   Collection() = default;

   // Ajoute à la fin de la collection un nouvel élément
   // Garantie forte car utilisation de push_back()
   void ajouter(T element);

   // Retourne l'élément à l'indice de la collection
   // Exception indice non-valide si indice >= taille
   // L'exception prends en compte une collection vide
   T& get(size_t indice);

   // Retourne la taille de la collection
   // Garantie no-throw
   size_t taille() const noexcept;

   // Vérifie si un élement est dans un un conteneur
   // Renvoie true si il y'est
   // garantie no-throw
   bool contient(const T& element) const;

   // vide complétement la collection
   // garantie no-throw
   void vider() noexcept;

   // parcoure un conteneur et applique une foncion unaire à chaque élément
   // Elle prend en paramètre une fonction unaire
   // Garantie no-throw
   template <typename unaryFunct>
   void parcourir(unaryFunct);

private:
   Conteneur<T> collection;
};



#include "collection_impl_g.h"

#endif /* COLLECTION_G_H */

