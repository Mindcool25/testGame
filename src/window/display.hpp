#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <SFML/Graphics.hpp>
#include <vector>

class Display {
    public:
        Display();

        int render();

        std::vector<sf::Sprite> sprites;
        sf::RenderWindow disp;
};



#endif // DISPLAY_H_
