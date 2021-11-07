/**
 * @author: Adrián González Expósito
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Práctica 5: Autómatas finitos y reconocimiento de patrones
 */

#include <fstream>
#include <iostream>
#include <regex>
#include <set>
#include <string>
#include <vector>

#include "states.h"
#include "transitions.h"
#include "utilities.h"
#include "alphabet.h"
#include "chain.h"

class Dfa {
 public:
  Dfa(std::vector<States>, Alphabet, int, std::set<States>, std::vector<Transitions>);
  bool verificate_chain(const Chain&);
 private:
  std::vector<States> states_;
  Alphabet alphabet_;
  int initial_state_;
  std::set<States> acceptation_states_;
  std::vector<Transitions> transitions_;
};