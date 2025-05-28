//
// Created by Giuseppe Crescenzi on 25/05/25.
//
#include "RWindow.h"
#include <iostream>
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
                    window.draw(move_circle(1));
                } else if (event.key.code == Keyboard::Key::Left) {
                    window.clear(Color::Black);
                    window.draw(move_circle(-1));
                }else if (event.key.code == Keyboard::Key::Up) {
                    window.clear(Color::Black);
                    window.draw(move_circle(2));
                } else if (event.key.code == Keyboard::Key::Down) {
                    window.clear(Color::Black);
                    window.draw(move_circle(-2));
                }
            }
            window.display();
        }
    }
}
CircleShape RWindow::move_circle(const int dir) {
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
void RWindow::RotatingTriangles() const {
    RenderWindow window(VideoMode(width,height), "not symbols or it will crash");
    window.setFramerateLimit(30);
    // init shapes
    ConvexShape t1; // upper triangle
    t1.setPointCount(3);
    t1.setPoint(0,Vector2f(-25,0));
    t1.setPoint(1,Vector2f(25,0));
    t1.setPoint(2,Vector2f(0,-100));
    t1.setOrigin(Vector2f(0,0));
    t1.setPosition(Vector2f(width/2,height/2));
    t1.setFillColor(Color(65,90,119));
    ConvexShape t2; // lower triangle
    t2.setPointCount(3);
    t2.setPoint(0,Vector2f(-25,0));
    t2.setPoint(1,Vector2f(25,0));
    t2.setPoint(2,Vector2f(0,100));
    t2.setOrigin(Vector2f(0,0));
    t2.setPosition(Vector2f(width/2,height/2));
    t2.setFillColor(Color(119,141,169));
    CircleShape c1;
    c1.setRadius(100);
    c1.setOrigin(Vector2f(100,100));
    c1.setPosition(Vector2f(width/2,height/2));
    c1.setFillColor(Color::Transparent);
    c1.setOutlineThickness(2);
    c1.setOutlineColor(Color(224,225,221));
    // event
    Event event{};
    while (window.isOpen()) {
        if (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        // UPDATE FRAME
        t1.rotate(1.0f);
        t2.rotate(1.0f);
        // RENDER FRAME
        window.clear(Color(13,27,42));
        window.draw(t1);
        window.draw(t2);
        window.draw(c1); // static
        window.display();
    }
}
void RWindow::Triangle() const {
    RenderWindow window(VideoMode(width,height),"triangolo");
    ConvexShape t1;
    t1.setPointCount(3);
    t1.setPoint(0,Vector2f(width/2-25,height/2));
    t1.setPoint(1,Vector2f(width/2+25,height/2));
    t1.setPoint(2,Vector2f(width/2,height/2-100));
    t1.setOrigin(Vector2f(width/2,height/2));
    t1.setPosition(Vector2f(width/2,height/2));
    t1.setFillColor(Color(65,90,119));
    Event event;
    while (window.isOpen()) {
        if (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear(Color(13,27,42));
        window.draw(t1);
        window.display();
    }
}

void RWindow::SixtySeconds() const {
    RenderWindow window(VideoMode(width,height),"useless ahh spinning thingy");
    window.setFramerateLimit(30);
    // draw the stopwatch
    float l_width = 10;
    float l_height = 100;
    ConvexShape l1 = triangle(Vector2f(l_width/2,0),Vector2f(-l_width/2,0),
        Vector2f(0,l_height),Vector2f(width/2, height/2),Vector2f(0,0));
    l1.setFillColor(Color(255,51,51));
    ConvexShape l2 = triangle(Vector2f(l_width/2,0),Vector2f(-l_width/2,0),
        Vector2f(0,l_height),Vector2f(width/2, height/2),Vector2f(0,0));
    l2.setRotation(90);
    l2.setFillColor(Color(102,178,255));
    ConvexShape l3 = triangle(Vector2f(l_width/2,0),Vector2f(-l_width/2,0),
        Vector2f(0,l_height),Vector2f(width/2, height/2),Vector2f(0,0));
    l3.setRotation(180);
    l3.setFillColor(Color(102,255,178));
    ConvexShape l4 = triangle(Vector2f(l_width/2,0),Vector2f(-l_width/2,0),
        Vector2f(0,l_height),Vector2f(width/2, height/2),Vector2f(0,0));
    l4.setRotation(270);
    l4.setFillColor(Color(255,102,178));
    CircleShape c(100);
    c.setRadius(100);
    c.setOrigin(Vector2f(100,100));
    c.setPosition(Vector2f(width/2,height/2));
    c.setFillColor(Color::Transparent);
    c.setOutlineThickness(2);
    c.setOutlineColor(Color(224,225,221));
    Event event;
    bool rotating = false;
    while (window.isOpen()) {
        if (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Key::Space) {
                    rotating = !rotating; // inverting the boolean state
                }
                if (event.key.code == Keyboard::Key::R) {
                    l1.setRotation(0);
                    l2.setRotation(90);
                    l3.setRotation(180);
                    l4.setRotation(270);
                    if (rotating) {rotating = false;}
                }
            }
        }

        // UPDATE FRAME
        // set to 0.2f to have one rotation every 60 seconds
        if (rotating) {
            l1.rotate(5.0f);
            l2.rotate(5.0f);
            l3.rotate(5.0f);
            l4.rotate(5.0f);
        }// RENDER FRAME
        window.clear(Color::Black);
        window.draw(c);
        window.draw(l1);
        window.draw(l2);
        window.draw(l3);
        window.draw(l4);
        window.display();
    }
}

ConvexShape RWindow::triangle(
    const Vector2f& p1,
    const Vector2f& p2,
    const Vector2f& p3,
    const Vector2f &position,
    const Vector2f& origin) const {
    ConvexShape t;
    t.setPointCount(3);
    Vector2f temp(p1.x,-p1.y);
    t.setPoint(0,temp);
    temp.x = p2.x;
    temp.y = -p2.y;
    t.setPoint(1,temp);
    temp.x = p3.x;
    temp.y = -p3.y;
    t.setPoint(2,temp);
    t.setOrigin(origin);
    temp.x = position.x;
    temp.y = position.y;
    t.setPosition(temp);
    return t;
}












