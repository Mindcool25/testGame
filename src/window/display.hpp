#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <SFML/Graphics.hpp>
#include <vector>
#include "../component/component.hpp"
#include "../manager/manager.hpp"

class Display {
    public:
        Display();

        int render(std::vector<Entity> sprites, ECSManager manager);

        sf::RenderWindow disp;
};



#endif // DISPLAY_H_
