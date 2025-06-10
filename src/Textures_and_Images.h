//
// Created by Giuseppe Crescenzi on 30/05/25.
//

#ifndef TEXTURES_AND_IMAGES_H
#define TEXTURES_AND_IMAGES_H

#include <SFML/Graphics.hpp>

class TWindow {
public:
    TWindow();
    ~TWindow() = default;
    void LegaBasket() const;
    void LegaBasketRepeated();
private:
    std::unique_ptr<sf::RectangleShape> rect;
    sf::Texture texture;
};



#endif //TEXTURES_AND_IMAGES_H