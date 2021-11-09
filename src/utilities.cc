/**
 * @author: Adrián González Expósito
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Práctica 6: Simulacion de DFAs
 */

#include "../includes/utilities.h"

const std::string KError_message{
    "Fatal error! The execution of this programm is not correct.\n\
  Try './{exe_file_name}  --help' to get more information.\n"};

const std::string Khelp_message{
    "The execution of this program must be done with 3 parameters.\n\
  Correct use example: ./{exe_file_name} [dna_info.dfa] [chain_input_file] [output_file]\n\n"};

/**
 *
 *  @brief Send a error message if the arguments on the execution are not
 * corrects.
 *
 */
void Usage(int argc, char* argv[]) {
  if (argc == 1) {
    std::cout << KError_message << std::endl;
    exit(EXIT_SUCCESS);
  }else if (strcmp(argv[1], "--help") == 0) {
    std::cout << Khelp_message << std::endl;
    exit(EXIT_SUCCESS);
  }
}

/**
 *
 *  @brief Check if the chain belong to the dfa's alphabet.
 *  @param std::string Chain.
 *  @param std::vector<std::string> alphabet.
 *  @return true if the chain belong to the alphabet, and false in the opposite case.
 *
 */
bool check_chain(std::string Chain_, std::vector<std::string> alph) {
  for (auto element : Chain_) {
    std::string symbol;
    symbol.push_back(element);
    std::vector<std::string>::iterator belong = std::find(alph.begin(),alph.end(),symbol);

    if (belong == alph.end()) { 
      return false; 
    }
  }
  return true;
}

/**
 *
 *  @brief Check if the there is one transition per symbol on the alphabet inside the dfa.
 *  @param std::vector<std::string> symbols vector.
 *  @return true if there is no repeating symbols on the transitions, and false in the opposite case.
 *
 */
bool no_repeating_symbols(std::vector<std::string> symbols_vec) {
  bool returned_value = true;
  for (int i = 1; i < symbols_vec.size(); i++) {
    if (symbols_vec[i-1] == symbols_vec[i]){
      returned_value = false;
    }
  }
  return returned_value;
}