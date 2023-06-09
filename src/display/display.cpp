#include "display.hpp"
#include <iostream>

Display::Display() {
    disp.create(sf::VideoMode(800, 600), "Test Game", sf::Style::Resize);
}

int Display::render() {
    if(disp.isOpen()) {
        sf::Event event;
        while(disp.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                disp.close();
            if(event.type == sf::Event::Resized)
            {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                disp.setView(sf::View(visibleArea));
            }
        }

        disp.clear(sf::Color::Black);

        for(auto i = buffer.begin(); i < buffer.end(); i++)
        {
            for(auto j = i->begin(); j < i->end(); j++)
            {

                disp.draw(*j);
            }
        }

        disp.display();
        return 0;
    }
    return 1;
}

// TODO: Apply position to all nodes before actually drawing them. Maybe have an update func?
// TODO: Be able to zoom in and out of screen. UI also needs to be worked on.
int Display::draw(std::vector<Entity> sprites, Board state) {
    buffer.clear();
    // Add map to buffer
    for(auto i = state.map.begin(); i < state.map.end(); i++)
    {
        std::vector<sf::Sprite> tempVec;
        for(auto j = i->begin(); j < i->end(); j++)
        {
            tempVec.push_back(j->actor);
        }
        buffer.push_back(tempVec);
    }

    // Add entites to buffer
    for(auto i = sprites.begin(); i < sprites.end(); i++) {
        i->actor.setPosition(sf::Vector2f(i->x*16, i->y*16));
        buffer.at(i->y).at(i->x) = i->actor;
    }
    return 0;
}
