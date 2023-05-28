#ifndef ASCIISHEET_H_
#define ASCIISHEET_H_

#include <SFML/Graphics.hpp>
#include <array>

class AsciiSheet {
  public:
    sf::Texture ascii;
    std::array <sf::IntRect, 256> asciiList;

    void init();

};

#endif // ASCIISHEET_H_
