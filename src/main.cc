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
  initial_state_number = std::stoi(line); // initial state

  std::string mystr;

  std::vector<States> states_list;
  std::vector<Transitions> transitions;
  std::set<States> aceptation_states;
  Alphabet alphabet;

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
    std::set<std::string> alphabet_set_vec; 
    for (int j= 0; j < number_of_transitions ; j++){
      if(std::stoi(vec[1]) == 1){
        States aceptation_states_obj_aux(std::stoi(vec[0]), std::stoi(vec[1]));
        aceptation_states.insert(aceptation_states_obj_aux);
      }
      alphabet_set_vec.insert(vec[begin]);
      Transitions tr_obj_aux(vec[begin],std::stoi(vec[0]),std::stoi(vec[begin+1]));  // transitions 
      transitions.emplace_back(tr_obj_aux);
      begin += 2;
    }

    Alphabet alphabet_aux(alphabet_set_vec);
    alphabet = alphabet_aux; // alphabet
  }
  Dfa automatum(states_list,alphabet,initial_state_number,aceptation_states,transitions);
  std::ifstream chain_file;
  std::string line2;
  chain_file.open(chain_input);
  while(getline(chain_file,line2)){
    Chain mystr(line2);
    if(automatum.verificate_chain(mystr)){
      std::cout << line2 << " accepted\n";
    } else {
      std::cout << line2 << " rejected\n";
    }

  }
  //automatum.verificate_chain();
}