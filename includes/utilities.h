/**
 * @author: Adrián González Expósito
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Práctica 6: Simulacion de DFAs
 */

#include <algorithm>
#include <cstring>
#include <functional>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "alphabet.h"
#include "chain.h"

void Usage(int, char* argv[]);

bool check_chain(std::string , std::vector<std::string>);

bool no_repeating_symbols(std::vector<std::string>);
