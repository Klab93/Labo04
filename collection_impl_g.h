/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : collection_impl_g.h
 Auteur(s)   : Kylian Bourcoud, Anne Sophie Ganguillet, Carl Penalva
 Date        : 22.04.2020

 But         : Implémenter les fonctionalités de la classe Collection
 
 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/
#ifndef COLLECTION_IMPL_G_H
#define COLLECTION_IMPL_G_H
#include "collection_g.h"
#include "exceptions.h"
#include <string>
#include <iterator>

const std::string MSG_ERREUR = "Erreur dans Collection::get :\n"
       "n doit etre strictement plus petit que collection.size()";

template <typename T, template <typename,typename> class Conteneur>
void Collection<T, Conteneur>::ajouter(T element){
   collection.push_back(element);
}

template <typename T, template <typename,typename> class Conteneur>
T& Collection<T,Conteneur>::get(size_t indice){
   if(indice >= collection.size()){
      
      throw IndiceNonValide(MSG_ERREUR);
   }
   if( indice == collection.size() - 1 ){
   	return collection.back();
   }
   auto it = collection.begin();
   //advance fonction de la librairie iterator
   std::advance(it, indice);
   
   return *it;
}

template <typename T, template <typename,typename> class Conteneur>
size_t Collection<T, Conteneur>::taille() const noexcept{
   return collection.size();
}

template <typename T, template <typename,typename> class Conteneur>
bool Collection<T, Conteneur>::contient(const T& element) const {
   for(auto i = collection.begin(); i != collection.end(); ++i){
      if(*i == element){
         return true;
      }
   }
   return false;  
}

template <typename T, template <typename,typename> class Conteneur>
void Collection<T, Conteneur>::vider() noexcept {
   collection.clear();
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
	if( collection.empty() ) return;
	for(auto it = collection.begin(); it != collection.end(); ++it){
		fn(*it);
	}
}

#endif /* COLLECTION_IMPL_G_H */

