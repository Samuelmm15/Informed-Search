/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Inteligencia Artificial
 * Curso: 3º
 * Práctica 2: Búsqueda Informada
 * @file square.h
 * @authors Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 *          Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2022-10-29
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cfloat>
#include <algorithm>
#include <cmath>
#include <iomanip>

/// Definición de los distintos colores necesarios para colorear las distintas casillas.
#define BLACK_GRND "\033[1;40m"
#define WHITE_GRND "\033[1;47m"
#define RED_GRND "\033[41m"
#define BLUE_GRND "\033[1;44m"
#define GREEN_GRND "\033[1;42m"
#define MAGENT_GRND "\033[1;45m"
#define RESET "\033[0m"

/// Coloreación de las distintas casillas dependiendo de su constante.
std::ostream& kBoldOff(std::ostream& os) {return os << "\e[0m";}
std::ostream& kBoldOn (std::ostream& os) {return os << "\e[1m";}
std::ostream& kWhite  (std::ostream& os) {return os << "\033[0;37m";}
std::ostream& kCyan   (std::ostream& os) {return os << "\033[0;36m";}
std::ostream& kGreen  (std::ostream& os) {return os << "\033[0;32m";}
std::ostream& kRed    (std::ostream& os) {return os << "\033[0;31m";}
std::ostream& kYellow (std::ostream& os) {return os << "\033[0;33m";}
std::ostream& kPurple (std::ostream& os) {return os << "\033[0;35m";}

/**
 * @brief This class contains the implementation of the different squares of the map simulation.
 * 
 * 
 * 
 */
class Square {
  public:
    Square();
  private:
};