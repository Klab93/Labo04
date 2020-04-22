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
#ifndef COLLECTION_IMPL_G_H
#define COLLECTION_IMPL_G_H
#include "collection_g.h"
#include "exceptions.h"
#include <string>
template <typename T, template <typename,typename> class Conteneur>
Collection<T, Conteneur>::Collection() {}


template <typename T, template <typename,typename> class Conteneur>
void Collection<T, Conteneur>::ajouter(T element){
   collection.push_back(element);
}

template <typename T, template <typename,typename> class Conteneur>
T& Collection<T,Conteneur>::get(size_t indice){
   if(indice >= collection.size()){
      std::string erreur = "Erreur dans Collection::get :\n"
       "n doit etre strictement plus petit que collection.size()";
      throw IndiceNonValide(erreur);
   }
   if( indice == collection.size() - 1 ){
   	return collection.back();
   }
   auto it = collection.begin();
   for( size_t i = 0; i < indice; ++i){
   	++it;
   }
   return *it;
}

template <typename T, template <typename,typename> class Conteneur>
size_t Collection<T, Conteneur>::taille(){
   return collection.size();
}

template <typename T, template <typename,typename> class Conteneur>
bool Collection<T, Conteneur>::contient(const T& element){
   for(auto i = collection.begin(); i != collection.end(); ++i){
      if(*i == element){
         return true;
      }
   }
   return false;  
}

template <typename T, template <typename,typename> class Conteneur>
void Collection<T, Conteneur>::vider(){
   collection.erase(collection.begin(),collection.end());
}
template <typename T, template <typename,typename> class Conteneur>
std::ostream& operator<< (std::ostream& lhs, 
                           const Collection<T,Conteneur>& rhs){
   lhs << "[";
   for(auto i = rhs.collection.begin(); i != rhs.collection.end(); ++i){
      if(i != rhs.collection.begin()){
         lhs << ", ";
      }
      lhs << *i;
   }
   
   lhs << "]";
   return lhs;
}

template <typename T, template <typename,typename> class Conteneur>
template <typename UnaryFunct>
void Collection<T, Conteneur>::parcourir(UnaryFunct fn){
	for(auto it = collection.begin(); it != collection.end(); ++it){
		fn(*it);
	}
}

#endif /* COLLECTION_IMPL_G_H */

