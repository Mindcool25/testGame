#include "board.hpp"


// TODO: Change from using same sprite to making unique ones per slot, and move to correct position.
Board::Board(sf::Sprite fill)
{
  for (int i = 0; i < 10; i++)
    {
      std::vector<Node> tempVec;
      for (int j = 0; j < 11; j++)
        {
          tempVec.push_back(Node{fill});
        }
      map.push_back(tempVec);
    }
}
