#include "display.hpp"

Display::Display() {
    disp.create(sf::VideoMode(800, 600), "Test Game", sf::Style::Resize);
}


int Display::render(std::vector<Entity> sprites, ECSManager manager) {
    // Check if window is still open
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

        disp.clear(sf::Color::Blue);

        for(auto i = sprites.begin(); i != sprites.end(); i++)
        {
            sf::Sprite test = manager.getComponent<Actor>(*i) -> actor;
            disp.draw(test);
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
