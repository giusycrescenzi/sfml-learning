//
// Created by Giuseppe Crescenzi on 09/06/25.
//

#ifndef ANIMATION_H
#define ANIMATION_H

#include "SFML/Graphics.hpp"

class AssetManager {
public:
    AssetManager();
    static sf::Texture& getTexture(std::string const& name);
private:
    std::map<std::string, sf::Texture> textures;
    static AssetManager* instance;
};


class Animation {
public:
    Animation();
    explicit Animation(std::string name);
    explicit Animation(int inutile = 0);
    ~Animation() = default;
private:
    std::string title;
};



#endif //ANIMATION_H
