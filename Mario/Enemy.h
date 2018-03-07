#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Entity.h"

class Enemy : public Entity {
private:
    void checkCollision() {};
public:
    Enemy(Image &image, float xPos, float yPos, int width, int height) :
        Entity(image, xPos, yPos, width, height) {};    

    void update(float time) {};
};