#ifndef BOARD_H_
#define BOARD_H_

#include <vector>
#include <SFML/Graphics.hpp>
#include "../ascii/asciisheet.hpp"

struct Node {
  sf::Sprite actor;
};

class Board {
public:
  Board(sf::Texture* texture, AsciiSheet sheet);
  std::vector<std::vector<Node>> map;

};

#endif // BOARD_H_
