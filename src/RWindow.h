//
// Created by Giuseppe Crescenzi on 25/05/25.
//

#ifndef RWINDOW_H
#define RWINDOW_H
#include <SFML/Graphics.hpp>

class RWindow {
public:
    explicit RWindow(const int w = 500, const int h = 350) :
        width(w), height(h) {}
    void RWindow_circle();
    sf::CircleShape move_circle(int dir);
    void RotatingTriangles() const;
    void Triangle() const;
    void SixtySeconds() const;
    [[nodiscard]] sf::ConvexShape triangle(const sf::Vector2f& p1,
        const sf::Vector2f& p2,
        const sf::Vector2f& p3,
        const sf::Vector2f& position,
        const sf::Vector2f& origin) const;
private:
    float x{0};
    float y{0};
    int width;
    int height;
};

#endif //RWINDOW_H
