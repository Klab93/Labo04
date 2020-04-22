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
#ifndef COLLECTION_G_H
#define COLLECTION_G_H
#include <iostream>
#include <memory>
template <typename T, template <typename,typename = std::allocator<T>> class Conteneur>
class Collection;

template <typename T, template <typename,typename = std::allocator<T>> class Conteneur>
std::ostream& operator<< (std::ostream& lhs, 
                           const Collection<T,Conteneur>& rhs);

template <typename T, template <typename,typename = std::allocator<T>> class Conteneur>
class Collection {
   
   friend std::ostream& operator<< <T,Conteneur>(std::ostream& lhs, 
                           const Collection<T,Conteneur>& rhs);
   public :
      Collection();
      void ajouter(T element);
      T& get(size_t indice);
      size_t taille();
      bool contient(const T& element);
      void vider();

      template <typename unaryFunct>
		void parcourir(unaryFunct);

   private :
      Conteneur<T> collection;
};

    

#include "collection_impl_g.h"

#endif /* COLLECTION_G_H */

