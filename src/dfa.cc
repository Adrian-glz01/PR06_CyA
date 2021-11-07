/**
 * @author: Adrián González Expósito
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Práctica 5: Autómatas finitos y reconocimiento de patrones
 */

#include "../includes/dfa.h"

/**
 *
 *  @brief  Dfa constructor -> initialize dfa objects-
 *  @param  std::set<States> build states.
 *  @param  std::set<char> build alphabet.
 *  @param  int initial_state build initial state.
 *  @param  std::set<States> aceptation states.
 *
 */
Dfa::Dfa(std::vector<States> states, Alphabet alphabet, int initial_state,
         std::set<States> acceptation_states, std::vector<Transitions> transitions): alphabet_{alphabet} {
  states_ = states;
  initial_state_ = initial_state;
  acceptation_states_ = acceptation_states;
  transitions_ = transitions;
}

bool Dfa::verificate_chain(const Chain& mystr){
  int c_state = initial_state_;
  for (int j = 0; j < mystr.size(); j++){
    for (int i = 0; i < (alphabet_.size() * states_.size()); i++)
      if(transitions_[i].get_current_state() == c_state )
        if(transitions_[i].get_symbol() == std::string(1, mystr.get_chain()[i]) )
          c_state = transitions_[i].get_next_state();
  }
  for(auto acceptation_state: acceptation_states_ ){
    if (acceptation_state.get_state() == c_state)
      return true;
  }
  return false;
}
