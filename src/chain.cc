#include "../includes/chain.h"


Chain::Chain( const std::string kStr ){
  str_ = kStr;
}
  //Setter
void Chain::set(std::string str) {
  str_ = str;
}

 std::string Chain::get_chain() const {
  return str_;
}

std::ostream&operator<<(std::ostream& os , const Chain& kChain_){
  os << kChain_.str_;
  return os;
}

//Metodo size; retorna el tamaño de la cadena.
int Chain::size() const {
  return str_.size();
}

bool operator<(const Chain& chain1, const Chain& chain2){
  return chain1.str_ < chain2.str_;
}