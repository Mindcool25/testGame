//#define SOL_ALL_SAFETIES_ON 1
//#include <sol/sol.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>


#include "display/display.hpp"

#include "ascii/asciisheet.hpp"

#include "entity/entity.hpp"

#include "input/input.hpp"


int main(int argc, char* argv[]) {

    AsciiSheet test;
    test.init();

    // Sprite stuff
    sf::Texture texture;
    if (!texture.loadFromFile("assets/font/Tileset.png"))
    {
        std::cout << "Failed to load image" << std::endl;
    }

    texture.setSmooth(false);
    std::cout << "Loaded image" << std::endl;

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setColor(sf::Color::Green);
    sprite.setTextureRect(test.asciiList.at(2));

    // Creating the map
    Board map(texture, test);
    std::cout << map.map.size() << std::endl;
    std::cout << map.map.at(0).size() << std::endl;

    Entity woo;

    woo.brain = player;
    woo.actor = sprite;
    woo.x = 3;
    woo.y = 2;

    std::vector<Entity> actors;
    actors.push_back(woo);

    // Creating input variables
    Input up(sf::Keyboard::K);
    Input down(sf::Keyboard::J);
    Input left(sf::Keyboard::H);
    Input right(sf::Keyboard::L);

    // SFML stuff
    // create the window
    Display disp;
    disp.draw(actors, map);

    // main game loop
    while (disp.render() != 1) {
        disp.draw(actors, map);
        for (auto i = actors.begin(); i < actors.end(); i++)
        {
            // Loop over actors and control them according to brain.
            if (i->brain == player)
            {
                if (left.isKeyPressed())
                {
                    i->x -= 1;
                }
                else if (right.isKeyPressed())
                {
                    i->x += 1;
                }
                else if (up.isKeyPressed())
                {
                    i->y -= 1;
                }
                else if (down.isKeyPressed())
                {
                    i->y += 1;
                }
            }
        }
    }


    // Creating lua object to hold a script
	// Maybe create a different obj per thing?
	//sol::state lua;

	// Opening a library from sol
	//lua.open_libraries(sol::lib::base);

	// Registering a C++ function
	//lua.set_function("testfunc", test_func);

	// Loading the script
	//lua.script_file("test.lua");

	return 0;
}
