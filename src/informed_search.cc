/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Inteligencia Artificial
 * Curso: 3º
 * Práctica 2: Búsqueda Informada
 * @file informed_search.cc
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

#include "../include/map.h"
#include "../include/square.h"

int main() {
  size_t rows, cols;
  size_t start_x, start_y;
  size_t goal_x, goal_y;

  std::cout << "Bienvenido al programa de búsqueda informada" << std::endl;
  std::cout << "Introduzca el tamaño del mapa (MxN): " << std::endl;
  std::cout << "Numero de filas (M): " << std::endl;
  std::cin >> rows;
  std::cout << "Numero de columnas (N): " << std::endl;
  std::cin >> cols;
  std::cout << std::endl;
  std::cout << "Introduzca la posición inicial (X,Y): " << std::endl;
  std::cout << "Posicion inicial en X: " << std::endl;
  std::cin >> start_x;
  std::cout << "Posicion inicial en Y: " << std::endl;
  std::cin >> start_y;
  std::cout << std::endl;
  std::cout << "Introduzca la posición final (X,Y): " << std::endl;
  std::cout << "Posicion final en X: " << std::endl;
  std::cin >> goal_x;
  std::cout << "Posicion final en Y: " << std::endl;
  std::cin >> goal_y;

  Map map(rows, cols, start_x, start_y, goal_x, goal_y);
  map.setInitialState(start_x, start_y);
  // map.setGoalState(goal_x, goal_y);
  map.writeMap(std::cout);
}

