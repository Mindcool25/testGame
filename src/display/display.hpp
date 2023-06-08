#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <SFML/Graphics.hpp>
#include "../entity/entity.hpp"
#include "../board/board.hpp"
#include <vector>

class Display {
public:
    Display();
    sf::RenderWindow disp;
    int draw(std::vector<Entity> actors, Board state);
    int render();

private:
    std::vector<std::vector<sf::Sprite>> buffer;

};



#endif // DISPLAY_H_
