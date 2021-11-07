#ifndef ALPHABET
#define ALPHABET

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <set>

class Alphabet {
 public:
  Alphabet();
  Alphabet( std::set<std::string> alph );
  std::set<std::string> get_alph(void);
  friend std::ostream&operator<<(std::ostream& ,  const Alphabet& );
  int size(void);
 private:
  std::set<std::string> alph_;
};

#endif