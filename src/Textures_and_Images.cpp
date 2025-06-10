//
// Created by Giuseppe Crescenzi on 30/05/25.
//

#include "Textures_and_Images.h"
#include <iostream>

TWindow::TWindow() {
    rect = std::make_unique<sf::RectangleShape>(sf::Vector2f(200,200));
    texture.loadFromFile("../assets/basket_logo.png");
    rect->setOutlineColor(sf::Color::Green);
    rect->setOutlineThickness(2);
}
void TWindow::LegaBasket() const {
    sf::RenderWindow window(sf::VideoMode(600, 400),"legabasket");
    rect->setTexture(&texture);
    sf::Event event{};
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            window.clear(sf::Color::White);
            window.draw(*rect);
            window.display();
        }
    }
}

void TWindow::LegaBasketRepeated() {
    sf::RenderWindow window(sf::VideoMode(600,400),"legabasket");
    rect->setSize(sf::Vector2f(600,400));
    texture.setRepeated(true);
    texture.setSmooth(true);
    rect->setTextureRect(sf::IntRect(0,0,static_cast<int>(texture.getSize().x*3),static_cast<int>(texture.getSize().y*2)));
    rect->setTexture(&texture);
    sf::Event event{};
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::White);
        window.draw(*rect);
        window.display();
    }
}