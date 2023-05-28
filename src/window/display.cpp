#include "display.hpp"

Display::Display() {
    disp.create(sf::VideoMode(800, 600), "Test Game");
}


int Display::render() {
    // Check if window is still open
    if(disp.isOpen()) {
        sf::Event event;
        while(disp.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                disp.close();
        }

        disp.clear(sf::Color::Blue);

        for(auto i = sprites.begin(); i != sprites.end(); i++)
        {
            disp.draw(*i);
        }

        disp.display();

        return 0;
    }
    else
    {
        return 1;
    }
    return 1;
}
