/**
 * @author: Adrián González Expósito
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Práctica 6: Simulacion de DFAs
 */

#include "../includes/dfa.h"

int main(int argc, char* argv[]){
  Usage(argc, argv);
  std::string dfa_input= argv[1];
  std::string chain_input = argv[2];
  std::string file_output = argv[3];

  std::ifstream file;
  std::string line;
  file.open(dfa_input);

  int states_number;
  getline(file,line);
  states_number = std::stoi(line);  //states number 
  
  int initial_state_number;
  getline(file,line);
  if (line.size() > 1) {
    std::cout << "Exist more than one aceptation state in the DFA\n\
                    Aborted program\n";
    std::cout << line << "\n";
    exit(EXIT_SUCCESS);
  }
  initial_state_number = std::stoi(line); // initial state

  std::string mystr;

  std::vector<States> states_list;
  std::vector<Transitions> transitions;
  std::set<States> aceptation_states;
  Alphabet alphabet;

  std::vector<std::string> alph_aux_vec;

  for (int i =0; i < states_number; i++){
    std::vector<std::string> vec;
    getline(file,line);
    std::stringstream ssfile(line);
    while( ssfile >> mystr ){
      vec.emplace_back(mystr);
    }
    states_list.emplace_back(States(std::stoi(vec[0]),std::stoi(vec[1]))); // state number and type

    int begin = 3;
    int number_of_transitions = stoi(vec[2]);
    std::set<Symbols> alphabet_set_vec; 

    std::vector<std::string> check_symbol_repetition_vec = {};

    for (int j= 0; j < number_of_transitions ; j++) {
      if (std::stoi(vec[1]) == 1) {
        States aceptation_states_obj_aux(std::stoi(vec[0]), std::stoi(vec[1]));
        aceptation_states.insert(aceptation_states_obj_aux);
      }
      alphabet_set_vec.insert(vec[begin]);
      alph_aux_vec.emplace_back((vec[begin]));
      Transitions tr_obj_aux(vec[begin],std::stoi(vec[0]),std::stoi(vec[begin+1]));  // transitions 
      transitions.emplace_back(tr_obj_aux);

      check_symbol_repetition_vec.emplace_back(vec[begin]);
      begin += 2;
    }

    if (!no_repeating_symbols(check_symbol_repetition_vec)) {
      std::cout << "In this automatum does not exist one transitions for each symbol of the DFA's alphabet.\n";
      exit(EXIT_SUCCESS);
    }
    Alphabet alphabet_aux(alphabet_set_vec);
    alphabet = alphabet_aux; // alphabet
  }

  std::ofstream output(file_output);

  Dfa automatum(states_list,alphabet,initial_state_number,aceptation_states,transitions);
  std::ifstream chain_file;
  std::string line2;
  chain_file.open(chain_input);
  while (getline(chain_file,line2)) {
    if (check_chain(line2,alph_aux_vec)) {
      Chain mystr(line2);
      if (automatum.verificate_chain(mystr)) {
        output << line2 << " -- Accepted\n";
      } else {
        output << line2 << " -- Rejected\n";
      }
    } else {
      output << line2 << " -- Rejected\n";
    }
  }
}
