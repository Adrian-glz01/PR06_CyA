/**
 * @author: Adrián González Expósito
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Práctica 5: Autómatas finitos y reconocimiento de patrones
 */

#include "../includes/states.h"


States::States(){}
/**
 *
 *  @brief  States constructor -> initialize states objects-
 *  @param  int states.
 *
 */
States::States(int states, int type) { 
  states_ = states;
  type_= type;
}

/**
 *
 *  @brief  Operator overloading for minor operator
 *  @param  States_const& state.
 *  @return If the sent state is minor than other state.
 *
 */
bool States::operator<(States const& kState) const {
  return kState.states_ < states_;
}

/**
 *
 *  @brief Get the int value of a state.
 *  @return The value{number} of the state.
 *
 */
int States::get_state() const { return states_; }

int States::get_type() const { return type_; }
std::ostream&operator<<(std::ostream& os ,  const States& kState ){
  os << kState.get_state() << kState.get_type();
  return os;
}

bool States::aceptation_st(int aceptation){ return aceptation == 1; }