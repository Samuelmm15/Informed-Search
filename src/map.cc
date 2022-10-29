/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Inteligencia Artificial
 * Curso: 3º
 * Práctica 2: Búsqueda Informada
 * @file map.h
 * @authors Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es) 
 *          Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-10-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../include/map.h"

Map::Map(size_t rows, size_t cols, size_t start_row, size_t start_col, size_t goal_row, size_t goal_col) {
  setM(rows);
  setN(cols);
  setStart(start_row, start_col);
  setGoal(goal_row, goal_col);
  map_ = new Square *[rows, cols];
  for(size_t i = 0; i < rows; i++)
    for(size_t j = 0; j < cols;j++)
      map_[i * cols + j] = new Square(i, j);
};

Map::~Map() {};
  
void Map::setM(size_t rows) {
  M_ = rows;
};

void Map::setN(size_t cols) {
  N_ = cols;
};

void Map::setStart(size_t start_row, size_t start_col) { 
  start_row_ = start_row;
  start_col_ = start_col;
};

void Map::setGoal(size_t goal_row, size_t goal_col) {
  goal_row_ = goal_row;
  goal_col_ = goal_col;
};

size_t Map::getM() const {
  return M_;
};

size_t Map::getN() const {
  return N_;
};

std::ostream& Map::WhiteLine(std::ostream &os) {
  size_t count = 0;
  os << "\n" << "    " << WHITE_GRND << " ";
  while(count<getN()){
    os << "      ";
    count++;
  }
  os << " " << RESET << "\n";

  return os;
}

void Map::writeMap(std::ostream &os) {
  os << "   "; 
  for (size_t a = 0; a < getN(); a++){
    os << "    " << std::setfill('0') << std::setw(2) << a;
  }
  for (size_t i = 0; i < getM(); i++) {
    WhiteLine(os);
    os << std::setfill('0') << std::setw(3) << i << " " << WHITE_GRND << " " << RESET;
    // for (size_t j = 0; j < getN(); j++) {
    //   map_[i * getN() + j]->WriteSquare(os);
    // }
    os << WHITE_GRND << " " << RESET;
  }
  WhiteLine(os);
};

