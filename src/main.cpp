//#define SOL_ALL_SAFETIES_ON 1
//#include <sol/sol.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>


#include "window/display.hpp"

#include "ascii/asciisheet.hpp"

#include "component/component.hpp"

#include "manager/manager.hpp"

int main(int argc, char* argv[]) {

    AsciiSheet test;
    test.init();

    ECSManager manager;

    Entity e1 = manager.createEntity();

    manager.addComp(e1, Pos{1, 3});

    Pos* pos1 = manager.getComponent<Pos>(e1);
    std::cout << "x: " << pos1->x << " y: " << pos1->y << std::endl;

    // Creating lua object to hold a script
	// Maybe create a different obj per thing?
	//sol::state lua;

	// Opening a library from sol
	//lua.open_libraries(sol::lib::base);

	// Registering a C++ function
	//lua.set_function("testfunc", test_func);

	// Loading the script
	//lua.script_file("test.lua");


	// SFML stuff
    // create the window
    Display disp;

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
    sprite.setTextureRect(test.asciiList.at(2));

    sf::Sprite s2;
    s2.setTexture(texture);
    s2.setTextureRect(test.asciiList.at(5));

    disp.sprites.push_back(sprite);
    disp.sprites.push_back(s2);


    // run the program as long as the window is open
    while (disp.render() == 0)
    {

    }
	return 0;
}
