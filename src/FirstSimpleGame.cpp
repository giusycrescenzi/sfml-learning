//
// Created by Giuseppe Crescenzi on 28/05/25.
//

#include "FirstSimpleGame.h"
#include <random>

void InitShape(sf::RectangleShape &shape, const sf::Vector2f &position, const sf::Color &color) {
    shape.setPosition(position);
    shape.setFillColor(color);
    shape.setOrigin(shape.getSize().x / 2, shape.getSize().y / 2);
}
BlockSurvival::BlockSurvival() {
    // instantiate the two main elements
    player = std::make_unique<sf::RectangleShape>(sf::Vector2f(30,30));
    InitShape(*player, startPos, sf::Color::Green);
    checkpoint = std::make_unique<sf::RectangleShape>(sf::Vector2f(20,20));
    InitShape(*checkpoint, endPos, sf::Color::Blue);
    // then create and store enemies in the vector
    std::random_device rd;
    float rand_x = 0;
    float rand_y = 0;
    for (int i = 0; i < numEnemies; i++) {
        std::mt19937 gen(rd());
        std::uniform_int_distribution distrib_x(1, width);
        rand_x = static_cast<float>(distrib_x(gen));
        std::uniform_int_distribution distrib_y(1, height);
        rand_y= static_cast<float>(distrib_y(gen));
        auto enemy = std::make_unique<sf::RectangleShape>(sf::Vector2f(50,50));
        InitShape(*enemy, sf::Vector2f(rand_x, rand_y), sf::Color::Red);
        enemies.emplace_back(std::move(enemy));
    }
}
void BlockSurvival::run() const{
    sf::RenderWindow win(sf::VideoMode(width,height), "Red equals Bad");
    win.setFramerateLimit(60);
    sf::Event event {};

    while (win.isOpen()) {
        // HANDLE INPUT
        while (win.pollEvent(event)) {
            // closing the game
            if (event.type == sf::Event::Closed) {
                win.close();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player->move(left);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player->move(right);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            player->move(up);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            player->move(down);
        }
        // Winning \ Losing condition
        if (player->getGlobalBounds().intersects(checkpoint->getGlobalBounds())) {
            // HANDLE WINNING CASE
            sf::RenderWindow winning(sf::VideoMode(235,0),"YOU WON, GOOD BOYY");
            sf::Event ev{};
            while (winning.isOpen()) {
                while (winning.pollEvent(ev)) {
                    if (ev.type == sf::Event::EventType::Closed)
                        winning.close();
                }
            }
            win.close();
        }
        for (auto& it : enemies) {
            if (player->getGlobalBounds().intersects(it->getGlobalBounds())) {
                // HANDLE LOSING CASE
                player->setPosition(startPos);
            }
        }
        // UPDATE
        win.clear(sf::Color::White);
        win.draw(*player);
        win.draw(*checkpoint);
        for (auto& it : enemies) {
            win.draw(*it);
        }
        // DISPLAY
        win.display();
    }
}