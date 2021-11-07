/**
 * @author: Adrián González Expósito
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Práctica 5: Autómatas finitos y reconocimiento de patrones
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
