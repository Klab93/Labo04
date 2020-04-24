/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : main.cpp
 Auteur(s)   : Anne Sophie Ganguillet, Kylian Bourcoud, Carl Penalva
 Date        : 22.04.2020

 But         : Mettre à disposition une classe Collection générique modélisant une 
               collection et permettant de d'effectuer diverses manipulation sur
               celle-ci.
               La classe fourni les outils suivants :
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

 Remarque(s) : La classe ne peut être utilisées qu'avec des conteneurs 
               mettant à disposition les méthodes push_back(), size(), back(), 
               clear(), empty(), begin() et end().
               La méthode get() lève une exception du type IndiceNonValide si
               l'indice passé en paramètre et supérieur ou égal à la taille 
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

template <typename T, template <typename, typename = std::allocator<T>> 
          class Conteneur>
std::ostream& operator<<(std::ostream& lhs,
        const Collection<T, Conteneur>& rhs);

template <typename T, template <typename, typename = std::allocator<T>> 
         class Conteneur>
class Collection {
   friend std::ostream& operator<< <T, Conteneur>(std::ostream& lhs,
           const Collection<T, Conteneur>& rhs);
public:
   Collection() = default;
   void ajouter(T element);
   T& get(size_t indice);
   size_t taille() const noexcept;
   bool contient(const T& element) const;
   void vider() noexcept;

   template <typename unaryFunct>
   void parcourir(unaryFunct);

private:
   Conteneur<T> collection;
};



#include "collection_impl_g.h"

#endif /* COLLECTION_G_H */

