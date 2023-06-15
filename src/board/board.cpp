#include "board.hpp"

#include <iostream>



// TODO: Change from using same sprite to making unique ones per slot, and move to correct position.
Board::Board(sf::Texture* texture, AsciiSheet sheet)
{
  for (int i = 0; i < 10; i++)
  {
    std::vector<Node> temp;
    for (int j = 0; j < 10; j++)
    {
      sf::Sprite e(*texture, sheet.asciiList.at(i+j));
      e.setPosition(j*16, i*16);
      temp.push_back(Node{e});
    }
    map.push_back(temp);
  }
}
