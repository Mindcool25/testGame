//#define SOL_ALL_SAFETIES_ON 1
//#include <sol/sol.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>


#include "window/display.hpp"

#include "ascii/asciisheet.hpp"

#include "component/component.hpp"

#include "manager/manager.hpp"

int input(ECSManager manager);

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

    ECSManager manager;


    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setTextureRect(test.asciiList.at(2));

    Entity e1 = manager.createEntity();
    Entity e2 = manager.createEntity();

    manager.addComp(e1, Pos{1, 3});
    manager.addComp(e1, Actor{sprite});
    manager.addComp(e1, Controllable{true});

    manager.addComp(e2, Pos{4, 3});
    manager.addComp(e2, Actor{sprite});

    Pos* pos1 = manager.getComponent<Pos>(e1);
    std::cout << "x: " << pos1->x << " y: " << pos1->y << std::endl;


	// SFML stuff
    // create the window
    Display disp;

    // run the program as long as the window is open
    std::vector<Entity> actors = manager.getEntitiesWithComponent<Actor>();
    while (disp.render(actors, manager) == 0)
    {
        // Systems
        input(manager);
        Pos* pos1 = manager.getComponent<Pos>(e1);
        std::cout << "x: " << pos1->x << " y: " << pos1->y << std::endl;
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


int input(ECSManager manager)
{
    std::vector<Entity> movers = manager.getEntitiesWithComponent<Controllable>();

    for (auto i = movers.begin(); i != movers.end(); i++)
    {
        if(manager.getComponent<Controllable>(*i) -> current == true)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                manager.getComponent<Pos>(*i)->x += 1;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            std::cout << "Left" << std::endl;
        }
    }
    return 0;
}
