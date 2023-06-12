#include "input.hpp"

// Creates Input object with key to check
Input::Input(sf::Keyboard::Key in)
{
    key = in;
}

// Checks if the key was previously down
bool Input::isKeyPressed()
{
    if(released)
    {
        if(sf::Keyboard::isKeyPressed(key))
        {
            released = false;
            return true;
        }
    }
    else if (!sf::Keyboard::isKeyPressed(key)) {
        released = true;
        return false;
    }
    return false;
}
