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

class States {
 public:
  States();
  States(int, int);
  int get_state(void) const;
  int get_type(void) const;
  bool operator<(States const& ) const;
  friend std::ostream&operator<<(std::ostream& ,  const States& );
  bool aceptation_st(int);

 private:
  int states_;
  int type_;
};


