#include "../includes/dfa.h"

//std::set<States>,int,  Alphabet, std::set<States>, set<transition> 
//chain

/*
4 <- numero de estados
0 <- initial state
0 0 2 a 1 b 3    0 0, 1 1, 2 1, 3 0 -> states 
1 1 2 a 1 b 2    a,b -> alphabet
2 1 2 a 1 b 3    0 a 1, 0 b 3, 1 a 1, 1 b 2, 2 a 1 .... -> transitions
3 0 2 a 3 b 3     
*/

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
  states_number = std::stoi(line);
  
  int initial_state_number;
  getline(file,line);
  initial_state_number = std::stoi(line);

  std::string mystr;

  std::vector<States> states_list;
  std::set<Transitions> transitions;
  Alphabet alphabet;

  for (int i =0; i < states_number; i++){
    std::vector<std::string> vec;
    getline(file,line);
    std::stringstream ssfile(line);
    while( ssfile >> mystr ){
      vec.emplace_back(mystr);
    }
    states_list.emplace_back(States(std::stoi(vec[0]),std::stoi(vec[1])));

    int begin = 3;
    int number_of_transitions = stoi(vec[2]);
    std::set<std::string> alphabet_set_vec; 
    for (int j= 0; j < number_of_transitions ; j++){
      alphabet_set_vec.insert(vec[begin]);
      Transitions tr_obj_aux(vec[begin],std::stoi(vec[0]),std::stoi(vec[begin+1]));
      transitions.insert(tr_obj_aux);
      begin += 2;
    }

    Alphabet alphabet_aux(alphabet_set_vec);
    alphabet = alphabet_aux;
  }
  std::cout << transitions.size() << "\n";
  for (auto element: transitions){
    std::cout << element << ",";
  }
  std::cout << "\n";
}