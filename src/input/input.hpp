#ifndef INPUT_H_
#define INPUT_H_

#include <SFML/Graphics.hpp>

class Input {
    public:
        Input(sf::Keyboard::Key);
        sf::Keyboard::Key key;
        bool isKeyPressed();
    private:
        bool released;
};


#endif // INPUT_H_
