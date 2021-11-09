/**
 * @author: Adrián González Expósito
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Práctica 6: Simulacion de DFAs
 */

#include "../includes/dfa.h"

/**
 *
 *  @brief  Dfa constructor -> initialize dfa objects-
 *  @param  std::set<States> set states of the DFA.
 *  @param  Alphabet Buiild the alphabet of the DFA
 *  @param  int build initial state.
 *  @param  std::set<States> set of aceptation states.
 *  @param  std::vector<Transitions> set of transitions that make up the DFA.
 *
 */
Dfa::Dfa(std::vector<States> states, Alphabet alphabet, int initial_state,
         std::set<States> acceptation_states, std::vector<Transitions> transitions): alphabet_{alphabet} {
  states_ = states;
  initial_state_ = initial_state;
  acceptation_states_ = acceptation_states;
  transitions_ = transitions;
}


/**
 *
 *  @brief  Algorithim that verificate if a chain is accepted or not by the DFA.
 *  @param  const_Chain& the chain that going to get examinated.
 *  @return True if the chain is accepted or False if it is rejected.
 *
 */
bool Dfa::verificate_chain(const Chain& mystr) {
  int c_state = initial_state_;
  for (int j = 0; j < mystr.size(); j++) {
    for (int i = 0; i < (alphabet_.size() * states_.size()); i++) {
      if (transitions_[i].get_current_state() == c_state) {
        if (transitions_[i].get_symbol() == std::string(1, mystr.get_chain()[i])) {
          c_state = transitions_[i].get_next_state();
        }
      }
    }
  }
  for (auto acceptation_state: acceptation_states_ ) {
    if (acceptation_state.get_state() == c_state) {
      return true;
    }
  }
  return false;
}
