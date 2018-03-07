#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
class Entity {
protected:
    bool isLife, isOnGround;
    Texture texture;
    Sprite sprite;
    FloatRect rect;
    float xPos, yPos;
    float gravityAcceleration, speed;
    float width, height;
public:
    Entity(Image &image, float xPos, float yPos, int width, int height): 
        xPos(xPos), yPos(yPos), width(width), height(height), speed(0), gravityAcceleration(GRAVITY_ACCELERATION), 
        isLife(true), isOnGround(false) {
        texture.loadFromImage(image);
    }

    virtual void checkCollision() {};

    virtual void update(float time) {};
};