#ifndef BOARD_H_
#define BOARD_H_

#include <vector>
#include <SFML/Graphics.hpp>

struct Node {
  sf::Sprite actor;
};

class Board {
public:
  Board(sf::Sprite fill);
  std::vector<std::vector<Node>> map;

};

#endif // BOARD_H_
