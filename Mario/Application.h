#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Entity.h"
#include <vector>
using std::vector;

class Application {
protected:
    RenderWindow *window;
    bool isFullscreen;
    Player *player;
    Clock clock;
public:
    Application();
    Application(bool isFullscreen);
    ~Application();

    void run();
};

Application::Application() {
    window = new RenderWindow(VideoMode(HEIGHT, WIDTH), NAME, Style::Fullscreen);
}


Application::Application(bool isFullscreen) {
    this->isFullscreen = isFullscreen;
    if (isFullscreen) {
        window = new RenderWindow(VideoMode(HEIGHT, WIDTH), NAME, Style::Fullscreen);
    }
    else {
        window = new RenderWindow(VideoMode(HEIGHT, WIDTH), NAME, Style::Default);
    }
}

Application::~Application() {
    delete window;
}

void Application::run() {
    vector<Entity*> entities;

    Image playerImage;
    playerImage.loadFromFile(PLAYER_IMAGE_FILE);
    entities.push_back(new Player(playerImage, 0, 0, 0, 0));

    Image enemyImage;
    enemyImage.loadFromFile(ENEMY_IMAGE_FILE);
    entities.push_back(new Enemy(enemyImage, 0, 0, 0, 0));

    while (window->isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
        }

        window->clear();
        for (auto i : entities) {
            i->update(time);
            window->draw(i->getSprite());
        }
        window->display();
    }
}
