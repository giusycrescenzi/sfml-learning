//
// Created by Giuseppe Crescenzi on 25/05/25.
//
#include "RWindow.h"
using namespace sf;

void RWindow::RWindow_circle() {
    RenderWindow window(VideoMode(1000,600), "Wolf");
    Event event{};
    // create objects
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Key::Space) {
                    window.setTitle("Meow");
                }
            }
            if (event.type == Event::KeyReleased) {
                if (event.key.code == Keyboard::Key::Space) {
                    window.setTitle("Wolf");
                } else if (event.key.code == Keyboard::Key::Escape) {
                    window.close();
                } else if (event.key.code == Keyboard::Key::Right) {
                    window.clear(Color::Black);
                    window.draw(circle(1));
                } else if (event.key.code == Keyboard::Key::Left) {
                    window.clear(Color::Black);
                    window.draw(circle(-1));
                }else if (event.key.code == Keyboard::Key::Up) {
                    window.clear(Color::Black);
                    window.draw(circle(2));
                } else if (event.key.code == Keyboard::Key::Down) {
                    window.clear(Color::Black);
                    window.draw(circle(-2));
                }
            }
            window.display();
        }
    }
}

CircleShape RWindow::circle(const int dir) {
    CircleShape circle(25);
    circle.setFillColor(Color(210,0,210));
    if (dir == 1){
        x++;
        circle.setPosition(x*50,y*50);
    }if (dir == -1) {
        x--;
        circle.setPosition(x*50,y*50);
    }if (dir == 2){
        y--;
        circle.setPosition(x*50,y*50);
    }if (dir == -2) {
        y++;
        circle.setPosition(x*50,y*50);
    }return circle;
}
