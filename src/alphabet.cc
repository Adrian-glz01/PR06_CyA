#include "../includes/alphabet.h"

Alphabet::Alphabet() {}

Alphabet::Alphabet( std::set<std::string> alph ){
  alph_ = alph;
}
std::set<std::string> Alphabet::get_alph(){
  return alph_;
}
std::ostream&operator<<(std::ostream& os ,  const Alphabet& Kalph_ ){
  for (auto symbol: Kalph_.alph_ ){
    os << symbol << " ";
  }
  return os;
}

int Alphabet::size(){ return alph_.size(); }