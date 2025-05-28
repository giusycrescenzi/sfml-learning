//
// Created by Giuseppe Crescenzi on 28/05/25.
//

#include "FirstSimpleGame.h"

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
    for (int i = 0; i < numEnemies; i++) {
        auto enemy = std::make_unique<sf::RectangleShape>(sf::Vector2f(50,50));
        InitShape(*enemy, sf::Vector2f(300,300), sf::Color::Red);
        enemies.emplace_back(std::move(enemy));
    }
}

void BlockSurvival::run() const{
    sf::RenderWindow win(sf::VideoMode(width,height), "Red equals Bad");
    win.setFramerateLimit(60);
    sf::Event event {};
    // since isKeyPressed doesn't work on macOS M1 and M2
    bool RightPressed = false;
    bool LeftPressed = false;
    bool UpPressed = false;
    bool DownPressed = false;

    while (win.isOpen()) {
        // HANDLE INPUT
        while (win.pollEvent(event)) {
            // closing the game
            if (event.type == sf::Event::Closed) {
                win.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::Key::Right:
                        RightPressed = true;
                        break;
                    case sf::Keyboard::Key::Left:
                        LeftPressed = true;
                        break;
                    case sf::Keyboard::Key::Up:
                        UpPressed = true;
                        break;
                    case sf::Keyboard::Key::Down:
                        DownPressed = true;
                        break;
                    default:
                        break;
                }
            }
            if (event.type == sf::Event::KeyReleased) {
                switch (event.key.code) {
                    case sf::Keyboard::Key::Right:
                        RightPressed = false;
                    break;
                    case sf::Keyboard::Key::Left:
                        LeftPressed = false;
                    break;
                    case sf::Keyboard::Key::Up:
                        UpPressed = false;
                    break;
                    case sf::Keyboard::Key::Down:
                        DownPressed = false;
                    break;
                    case sf::Keyboard::Key::Escape:
                        win.close();
                    break;
                    default:
                        break;
                }
            }
        }
        // implement movement for the player square
        if (RightPressed) {
            player->move(right);
        }
        if (LeftPressed) {
            player->move(left);
        }
        if (UpPressed) {
            player->move(up);
        }
        if (DownPressed) {
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
