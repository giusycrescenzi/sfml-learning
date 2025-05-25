//
// Created by Giuseppe Crescenzi on 25/05/25.
//

#ifndef RWINDOW_H
#define RWINDOW_H
#include <SFML/Graphics.hpp>

class RWindow {
public:
    void RWindow_circle();
    sf::CircleShape circle(int dir);
private:
    float x{0};
    float y{0};
};

#endif //RWINDOW_H
