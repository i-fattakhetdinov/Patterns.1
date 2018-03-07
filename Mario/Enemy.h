#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Entity.h"

class Enemy : Entity {
private:

public:
    Enemy(Image &image, float xPos, float yPos, int width, int height) :
        Entity(image, xPos, yPos, width, height) {};    

    void checkCollision() {};

    void update(float time) {};
}