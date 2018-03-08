#pragma once
#include "SFML/Graphics.hpp"
#include "Constants.h"
#include "Entity.h"

class Player: public Entity {
private:
    enum{ left, right, up, down, jump, stay} state;
    //TODO : связать анимацию с состоянием
    int score;
    int ground;
    int life;

    void control() {
        if (Keyboard::isKeyPressed) {
            if (Keyboard::isKeyPressed(Keyboard::Left)) {
                state = left;
            }
            if (Keyboard::isKeyPressed(Keyboard::Right)) {
                state = right;
            }

            if (Keyboard::isKeyPressed(Keyboard::Up) && isOnGround) {
                state = jump; isOnGround = false;
            }

            if (Keyboard::isKeyPressed(Keyboard::Down)) {
                state = down;
            }
        }
    }

    void checkCollision() {};
public:
    Player(Image &image, float xPos, float yPos, int width, int height) :
        Entity(image, xPos, yPos, width, height), score(0), ground(0), life(START_PLAYER_LIFE) {};

    void update(float time) {
        control();
        switch (state){
            case left: break;
            case right: break;
            case up: break;
            case down: break;
            case stay: break;
        }
    }
};