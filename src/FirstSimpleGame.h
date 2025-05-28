//
// Created by Giuseppe Crescenzi on 28/05/25.
//

#ifndef FIRSTSIMPLEGAME_H
#define FIRSTSIMPLEGAME_H

#include <SFML/Graphics.hpp>
#include <vector>


void InitShape (sf::RectangleShape& shape, const sf::Vector2f& position, const sf::Color& color);

inline sf::Vector2f right {5,0};
inline sf::Vector2f left {-5,0};
inline sf::Vector2f up {0,-5};
inline sf::Vector2f down {0,5};

class BlockSurvival {
public:
    BlockSurvival();
    void run() const;
private:
    std::unique_ptr<sf::RectangleShape> player;
    std::unique_ptr<sf::RectangleShape> checkpoint;
    std::vector<std::unique_ptr<sf::RectangleShape>> enemies;
    int numEnemies {1};
    sf::Vector2f startPos{0,0};
    sf::Vector2f endPos{500, 500};
    bool win {false};
    bool dead {false};
    int width{600};
    int height {600};
};


#endif //FIRSTSIMPLEGAME_H
