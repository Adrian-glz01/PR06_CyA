/**
 * @author: Adrián González Expósito
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Práctica 6: Simulacion de DFAs
 */

#ifndef ALPHABET
#define ALPHABET

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <set>

#include "symbols.h"

class Alphabet {
 public:
  Alphabet();
  Alphabet(std::set<Symbols>);
  std::set<Symbols> get_alph(void);
  friend std::ostream&operator<<(std::ostream& ,  const Alphabet& );
  int size(void);
  
 private:
  std::set<Symbols> alph_;
};

#endif