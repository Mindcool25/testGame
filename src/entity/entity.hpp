#ifndef ENTITY_H_
#define ENTITY_H_

#include <SFML/Graphics.hpp>

enum Controller {
  player, ai, projectile, immobile
};

class Entity {
public:
  // Funky stuff
  Controller brain;
  sf::Sprite actor;

  // Position and Velocity
  int x;
  int y;
  int dx;
  int dy;

  // Doing a turn
  void turn();

  // Controlling movement
  void move(int x, int y); // Called from lua to make movement changes


private:
};

#endif // ENTITY_H_
