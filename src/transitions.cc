/**
 * @author: Adrián González Expósito
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Práctica 6: Simulacion de DFAs
 */

#include "../includes/transitions.h"

Transitions::Transitions(){}
/**
 *
 *  @brief  Transitions constructor -> initialize transitions objects-
 *  @param  char symbol.
 *  @param  int current_state.
 *
 */
Transitions::Transitions(std::string symbol, int current_state, int next_state) {
  symbol_ = symbol;
  current_state_ = current_state;
  next_state_ = next_state;
}

std::ostream&operator<<(std::ostream& os,  const Transitions& kTr){
  os << kTr.symbol_ << " " << kTr.current_state_ << " " << kTr.next_state_; 
  return os;
}

bool Transitions::operator<(Transitions const& kTr) const{
  return kTr.symbol_ < this->symbol_ || kTr.current_state_ < this->current_state_  ;
}

std::string Transitions::get_symbol() const { return symbol_; }

int Transitions::get_current_state() const { return current_state_; }

int Transitions::get_next_state() const { return next_state_; }

