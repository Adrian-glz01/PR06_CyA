/**
 * @author: Adrián González Expósito
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Práctica 6: Simulacion de DFAs
 */
#ifndef SYMBOLS
#define SYMBOLS

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

class Symbols {
 public:
  Symbols();
	Symbols(std::string Symbol);
	std::string get_symbols() const;
	friend std::ostream&operator<<(std::ostream& , const Symbols& );
	friend bool operator<(const Symbols& , const Symbols& );
	Symbols operator=(std::string c2);

 private:
 	std::string symbol_;
};

#endif