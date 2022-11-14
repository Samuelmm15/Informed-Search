/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Inteligencia Artificial
 * currentso: 3º
 * Práctica 2: Búsqueda Informada
 * @file map.h
 * @authors Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 *          Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief This file contains the implementation of the different methods of the `Map` class.
 * @version 0.1
 * @date 2022-10-29
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/map.h"

/// Overloading input and output flow operators to display colors per screen.
std::ostream& White_  (std::ostream& os) {return os << "\033[0;37m";}
std::ostream& Cyan_   (std::ostream& os) {return os << "\033[0;36m";}
std::ostream& Green_  (std::ostream& os) {return os << "\033[0;32m";}
std::ostream& Red_    (std::ostream& os) {return os << "\033[0;31m";}
std::ostream& Purple_ (std::ostream& os) {return os << "\033[0;35m";}

/**
 * @brief This is the constructor of the `Map` class.
 * 
 * @param rows The number of rows of the map.
 * @param cols The number of the columns of the map.
 * @param start_row The row of the starting position.
 * @param start_col The column of the starting position.
 * @param goal_row The row of the goal position.
 * @param goal_col The column of the goal position.
 */
Map::Map(size_t rows, size_t cols, size_t start_row, size_t start_col, size_t goal_row, size_t goal_col) {
  setM(rows);
  setN(cols);
  setStart(start_row, start_col);
  setGoal(goal_row, goal_col);
  map_ = new Square *[rows * cols];
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      map_[i * cols + j] = new Square(i, j);
    }
  }
};

/**
 * @brief This is the destructor of the `Map` class.
 * 
 */
Map::~Map(){};

/**
 * @brief This method sets the number of rows of the map.
 * 
 * @param rows The number of rows of the map.
 */
void Map::setM(size_t rows) { M_ = rows; };

/**
 * @brief This method sets the number of columns of the map.
 * 
 * @param cols The number of columns of the map.
 */
void Map::setN(size_t cols) { N_ = cols; };
/**
 * @brief This method sets the starting position of the map.
 * 
 * @param start_row The row of the starting position.
 * @param start_col The column of the starting position.
 */
void Map::setStart(size_t start_row, size_t start_col) {
  start_row_ = start_row;
  start_col_ = start_col;
};

/**
 * @brief This method sets the goal position of the map.
 * 
 * @param goal_row This is the row of the goal position.
 * @param goal_col This is column of the goal position.
 */
void Map::setGoal(size_t goal_row, size_t goal_col) {
  goal_row_ = goal_row;
  goal_col_ = goal_col;
};

/**
 * @brief This method stablishes the value of the heuristic option.
 * 
 * @param heuristic_option The heuristic option selected.
 */
void Map::setHeuristicFlag(int heuristic_option) { 
  heuristic_option_ = heuristic_option;
};

/**
 * @brief This method returns the number of rows of the map.
 * 
 * @return size_t 
 */
size_t Map::getM() const { return M_; };

/**
 * @brief This method returns the number of columns of the map.
 * 
 * @return size_t 
 */
size_t Map::getN() const { return N_; };

/**
 * @brief This method sets the initial state of the map.
 * 
 * @param i The row of the initial state.
 * @param j The column of the initial state.
 */
void Map::setInitialState(size_t i, size_t j) {
  initial_ = i * getN() + j;
  map_[i * getN() + j]->setState(1);
  setStart(i, j);
};

/**
 * @brief This method sets the goal state of the map.
 * 
 * @param i The row of the goal state.
 * @param j The column of the goal state.
 */
void Map::setGoalState(size_t i, size_t j) {
  goal_ = i * getN() + j;
  map_[i * getN() + j]->setState(2);
  setGoal(i, j);
};

/**
 * @brief This method prints the map correctly.
 * 
 * @param os 
 * @return std::ostream& 
 */
std::ostream &Map::WhiteLine(std::ostream &os) {
  size_t count = 0;
  os << "\n" << "    " << WHITE_GRND << " ";
  while (count < getN()) {
    os << "      ";
    count++;
  }
  os << " " << RESET << "\n";

  return os;
}

/**
 * @brief This method prints the map. It was a beta test to check if the route was being created correctly.
 * 
 */

void Map::RouteSearch() {
  if (start_row_ <= goal_row_) {
    if (start_row_ ==
        goal_row_) {
      if (start_col_ < goal_col_) {  /// Advance to the same row and to the right
        for (size_t i = start_col_ + 1; i <= goal_col_ - 1; i++) {
          map_[start_row_ * getN() + i]->setState(3);
        }
      } else {  /// Retreat to the same row and to the left
        for (size_t i = start_col_ + 1; i >= goal_col_ - 1; i--) {
          map_[start_row_ * getN() + i]->setState(3);
        }
      }
    } else {
      for (size_t i = start_row_ + 1; i <= goal_row_; i++) {
        map_[i * getN() + start_col_]->setState(3);
      }
      for (size_t i = start_col_ + 1; i <= goal_col_ - 1; i++) {
        map_[goal_row_ * getN() + i]->setState(3);
      }
    }
  } else {  /// Retreat case
    for (size_t i = start_row_ - 1; i >= goal_row_; i--) {
      map_[i * getN() + start_col_]->setState(3);
    }
    if (start_col_ < goal_col_) {  /// Ad
      for (size_t i = start_col_ + 1; i <= goal_col_ - 1; i++) {
        map_[goal_row_ * getN() + i]->setState(3);
      }
    } else {  /// Retreat to the same row and to the left
      for (size_t i = start_col_ + 1; i >= goal_col_ - 1; i--) {
        map_[goal_row_ * getN() + i]->setState(3);
      }
    }
  }
};

/**
 * @brief This method prints the map.
 * 
 * @param os 
 */
void Map::WriteMap(std::ostream &os) {
  os << "   ";
  for (size_t a = 0; a < getN(); a++) {
    os << "    " << std::setfill('0') << std::setw(2) << a;
  }
  for (size_t i = 0; i < getM(); i++) {
    WhiteLine(os);
    os << std::setfill('0') << std::setw(3) << i << " " << WHITE_GRND << " " << RESET;
    for (size_t j = 0; j < getN(); j++) {
      map_[i * getN() + j]->WriteSquare(os);
    }
    os << WHITE_GRND << " " << RESET;
  }
  WhiteLine(os);
};

/**
 * @brief This method prepare the initial map to search trough it.
 * 
 */
void Map::StartPreparation() {
  map_[initial_]->setgScore(0);
  map_[initial_]->setfScore(Heuristic(initial_, goal_));
  _path.push_back(initial_);
  _openSet.push_back(initial_);
  flag_ = false;
}

/**
 * @brief This method calculates the heuristic value of a given state.
 * 
 * @param i The row position.
 * @param j The column position.
 * @return double 
 */
double Map::Heuristic(size_t i, size_t j) {
  double cost;
  if (heuristic_option_ == 1) {
    int aux1 = map_[i]->getI() - map_[j]->getI(),
    aux2 = map_[i]->getJ() - map_[j]->getJ();
    cost = std::abs(aux1) + std::abs(aux2);
  }
  if (heuristic_option_ == 2) {
    cost = sqrt(((map_[i]->getI() - map_[j]->getI()) * (map_[i]->getI() - map_[j]->getI())) + ((map_[i]->getJ() - map_[j]->getJ())*(map_[i]->getJ() - map_[j]->getJ())));
  }
  return cost;
}

/**
 * @brief This method calculates the neighbors of a given state.
 * 
 * @param nodeId The identification of the square.
 * @return std::vector<size_t> 
 */
std::vector<size_t> Map::getNeighbors(size_t nodeId) {
  std::vector<size_t> neighbors;
  /// West comprobation
  if (map_[nodeId]->getJ() > 0) 
    neighbors.push_back(nodeId - 1); 
  /// East comprobation
  if (map_[nodeId]->getJ() < (getN() - 1)) 
    neighbors.push_back(nodeId + 1); 
  /// North comprobation
  if (map_[nodeId]->getI() > 0) 
    neighbors.push_back(nodeId - getN()); 
  /// South comprobation
  if (map_[nodeId]->getI() < (getM() - 1)) 
    neighbors.push_back(nodeId + getN());

  return neighbors;
}

/**
 * @brief This method calculates de A* algorithm.
 * 
 */
void Map::AStarAlgorithm() {
  int length_path = 0;
  int expanded_nodes = 0;
  StartPreparation();
  flag_ = false;

  while (!_openSet.empty()) {
    double lowestF = DBL_MAX;
    size_t current;

    for (auto it = _openSet.begin(); it != _openSet.end(); it++) {
      if (map_[*it]->getfScore() < lowestF) {
        lowestF = map_[*it]->getfScore();
        current = *it;
      }
    }

    if (current == goal_) {
      flag_ = true;
      break;
    } else {
      auto it = std::find(_openSet.begin(), _openSet.end(), current);
      _openSet.erase(it);
      _closedSet.push_back(current);
      std::vector<size_t> neighbors = getNeighbors(current);
      for (size_t i = 0; i < neighbors.size(); i++) {
        auto it = std::find(_closedSet.begin(), _closedSet.end(), neighbors[i]);
        if (it == _closedSet.end()) {
          double tentativeGScore = map_[current]->getgScore() + Heuristic(current, neighbors[i]);
          auto it = std::find(_openSet.begin(), _openSet.end(), neighbors[i]);
          if (it == _openSet.end()) {
            expanded_nodes++;
            _openSet.push_back(neighbors[i]);
          } else if (tentativeGScore >= map_[neighbors[i]]->getgScore()) {
            continue;
          }
          map_[neighbors[i]]->setCamefrom(current);
          map_[neighbors[i]]->setgScore(tentativeGScore);
          map_[neighbors[i]]->setfScore(tentativeGScore + Heuristic(neighbors[i], goal_));
        }
      }
    }
  }
  if (flag_) {
    _path.push_back(goal_);
    size_t current = map_[goal_]->getCamefrom();
    while (current != initial_) {
      length_path++;
      _path.push_back(current);
      size_t previous = map_[current]->getCamefrom();
      map_[current]->setState(3);
      current = previous;
    }
    std::cout << Green_	<< "\n\n¡Hay una camino al destino!" << std::endl;
    std::cout << Cyan_ << "\nLongitud del camino mínimo: " << length_path;
    std::cout << Cyan_ << "\nNodos expandidos: " << expanded_nodes << RESET << std::endl << std::endl;;
  } else {
    std::cout << Red_ << "¡No hay camino hacia el destino!" << RESET << std::endl;
  }
  return;
}