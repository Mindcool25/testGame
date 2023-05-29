#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <SFML/Graphics.hpp>

// Positioning
struct Pos {
    int x;
    int y;
};

struct Velocity {
    int x;
    int y;
};

// Graphics
struct SpriteSheet {
    sf::Texture& texture;
};

struct Actor {
    sf::Sprite actor;
};

struct Controllable {
    bool current;
};
#endif // COMPONENT_H_
