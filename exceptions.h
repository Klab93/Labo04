

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <exception>
#include <string>
class IndiceNonValide : public std::logic_error {
public:

   explicit IndiceNonValide(const std::string& s) : logic_error(s) {
   }

   explicit IndiceNonValide(const char* s) : logic_error(s) {
   }
};

class PrixNonValide : public std::logic_error {
public:

   explicit PrixNonValide(const std::string& s) : logic_error(s) {
   }

   explicit PrixNonValide(const char* s) : logic_error(s) {
   }
};
#endif /* EXCEPTIONS_H */

