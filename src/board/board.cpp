#include "board.hpp"



// TODO: Change from using same sprite to making unique ones per slot, and move to correct position.
Board::Board(sf::Texture texture, AsciiSheet sheet)
{
  for (int i = 0; i < 10; i++)
    {
      std::vector<Node> tempVec;
      for (int j = 0; j < 11; j++)
        {
          sf::Sprite fill;
          fill.setTexture(texture);
          fill.setTextureRect(sheet.asciiList.at(0));
          fill.setPosition(sf::Vector2f(j*16, i*16));
          //fill.setColor(sf::Color(255, 255, 255, 100));
          tempVec.push_back(Node{fill});
        }
      map.push_back(tempVec);
    }
}
