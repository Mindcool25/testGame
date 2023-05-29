//#define SOL_ALL_SAFETIES_ON 1
//#include <sol/sol.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>


#include "window/display.hpp"

#include "ascii/asciisheet.hpp"

#include "component/component.hpp"

#include "manager/manager.hpp"

void input(ECSManager manager);
void updateActor(ECSManager manager);
void updateMovement(ECSManager manager);

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

    manager.addComp(e1, Pos{16, 16});
    manager.addComp(e1, Actor{sprite});
    manager.addComp(e1, Controllable{true});
    manager.addComp(e1, Velocity{0, 0});

    if (manager.hasBothComponents<Pos, Actor>(e1))
    {
        std::cout << "yes" << std::endl;
    }
    Pos* pos1 = manager.getComponent<Pos>(e1);


	// SFML stuff
    // create the window
    Display disp;

    // run the program as long as the window is open
    std::vector<Entity> actors = manager.getEntitiesWithComponent<Actor>();
    while (disp.render(actors, manager) == 0)
    {
        // Systems
        input(manager);
        updateMovement(manager);
        updateActor(manager);
        Pos* pos1 = manager.getComponent<Pos>(e1);
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


void input(ECSManager manager)
{
    std::vector<Entity> movers = manager.getEntitiesWithComponent<Controllable>();

    for (auto i = movers.begin(); i != movers.end(); i++)
    {
        if(manager.getComponent<Controllable>(*i) -> current == true)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                std::cout << "almost to crash" << std::endl;
                std::cout << "WOOO" << std::endl;
                if(manager.getComponent<Pos>(*i) == nullptr)
                {
                    std::cout << "Oh no bois" << std::endl;
                }
                manager.getComponent<Pos>(*i)->x += 1;
                std::cout << "Whoops" << std::endl;
            }
        }
    }
}

void updateMovement(ECSManager manager)
{
    std::vector<Entity> toUpdate = manager.getEntitiesWithComponent<Velocity>();

    for (auto i = toUpdate.begin(); i != toUpdate.end(); i++)
    {
        Velocity* vel = manager.getComponent<Velocity>(*i);
        Pos* pos = manager.getComponent<Pos>(*i);

        pos->x += vel->x;
        pos->y += vel->y;
    }
}

void updateActor(ECSManager manager)
{
    std::vector<Entity> toUpdate = manager.getEntitiesWithComponent<Actor>();

    for (auto i = toUpdate.begin(); i != toUpdate.end(); i++)
    {
        Actor* actor = manager.getComponent<Actor>(*i);
        Pos* pos = manager.getComponent<Pos>(*i);

        actor->actor.setPosition(pos->x, pos->y);
    }
}
