//
// Created by Giuseppe Crescenzi on 09/06/25.
//

#include "Animation.h"

#include <cassert>

AssetManager* AssetManager::instance = nullptr;

AssetManager::AssetManager() {
    assert(instance == nullptr);
    instance = this;
}
sf::Texture &AssetManager::getTexture(std::string const &name) {
    auto& texMap = instance->textures;
    auto pair_found = texMap.find(name);
    if (pair_found == texMap.end()) {
        auto& texture = texMap[name];//inserisce automaticamente la texture
        texture.loadFromFile(name);
        return texture;
    } else {
        return pair_found->second;
    }
}

Animation::Animation() {
    sf::RenderWindow window(sf::VideoMode(400, 300), title, sf::Style::Default);
    window.setFramerateLimit(30);
    // time management
    sf::Clock clock;
    sf::Time elapsed;
    float elapsed_seconds;
    sf::Time dt;
    // initiate character
    auto anita = sf::Sprite(AssetManager::getTexture("../assets/anita.png"));
    anita.setPosition(sf::Vector2f(400./2 - 80.,300./2 - 46.));
    anita.setScale(2.5f, 2.5f);
    sf::Vector2i anita_size(64,64);
    anita.setTextureRect(sf::IntRect(0, 10*anita_size.y, anita_size.x, anita_size.y));
    //animation specs
    int anita_current_frame = 0;
    // gamecycle
    while (window.isOpen()) {
        int anita_frames = 9;
        float anita_animation_time = 1.f;
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        //UPDATE
        dt = clock.restart();
        elapsed += dt;
        elapsed_seconds = elapsed.asSeconds();
        anita_current_frame = static_cast<int>((elapsed_seconds / anita_animation_time) * static_cast<float>(anita_frames)) % anita_frames;
        anita.setTextureRect(sf::IntRect(anita_current_frame*anita_size.x, 10*anita_size.y, anita_size.x, anita_size.y));
        //RENDER
        //clear
        window.clear(sf::Color(96, 96, 96));
        //draw
        window.draw(anita);
        //display
        window.display();
    }
}

Animation::Animation(std::string  name) : title(std::move(name)) {
    sf::RenderWindow window(sf::VideoMode(400, 300), title, sf::Style::Default);
    window.setFramerateLimit(30);
    // time management
    sf::Clock clock;
    sf::Time elapsed;
    float elapsed_seconds;
    sf::Time dt;
    // initiate character
    auto sof = sf::Sprite(AssetManager::getTexture("../assets/sof.png"));
    sof.setPosition(sf::Vector2f(400./2 - 80.,300./2 - 46.));
    sof.setScale(1.8f, 1.8f);
    sf::Vector2i sof_size(64,64);
    sof.setTextureRect(sf::IntRect(0, 10*sof_size.y, sof_size.x, sof_size.y));
    //animation specs
    int sof_current_frame = 0;
    // gamecycle
    while (window.isOpen()) {
        int sof_frames = 9;
        float sof_animation_time = 1.f;
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        //UPDATE
        dt = clock.restart();
        elapsed += dt;
        elapsed_seconds = elapsed.asSeconds();
        sof_current_frame = static_cast<int>((elapsed_seconds / sof_animation_time) * static_cast<float>(sof_frames)) % sof_frames;
        sof.setTextureRect(sf::IntRect(sof_current_frame*sof_size.x, 10*sof_size.y, sof_size.x, sof_size.y));
        //RENDER
        //clear
        window.clear(sf::Color(96, 96, 96));
        //draw
        window.draw(sof);
        //display
        window.display();
    }
}

Animation::Animation(int inutile) {
    sf::RenderWindow window(sf::VideoMode(400, 300), "egro", sf::Style::Default);
    window.setFramerateLimit(30);
    // time management
    sf::Clock clock;
    sf::Time elapsed;
    float elapsed_seconds;
    sf::Time dt;
    // initiate character
    auto gab = sf::Sprite(AssetManager::getTexture("../assets/gab.png"));
    gab.setPosition(sf::Vector2f(400./2 - 128.,300./2 - 110.));
    gab.setScale(2.f, 2.f);
    sf::Vector2i gab_size(128,128);
    gab.setTextureRect(sf::IntRect(0, 54*64+gab_size.y, gab_size.x, gab_size.y));
    //animation specs
    int gab_current_frame = 0;
    // gamecycle
    while (window.isOpen()) {
        int gab_frames = 9;
        float gab_animation_time = 1.f;
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        //UPDATE
        dt = clock.restart();
        elapsed += dt;
        elapsed_seconds = elapsed.asSeconds();
        gab_current_frame = static_cast<int>((elapsed_seconds / gab_animation_time) * static_cast<float>(gab_frames)) % gab_frames;
        gab.setTextureRect(sf::IntRect(gab_current_frame*gab_size.x, 54*64+gab_size.y, gab_size.x, gab_size.y));
        //RENDER
        //clear
        window.clear(sf::Color(96, 96, 96));
        //draw
        window.draw(gab);
        //display
        window.display();
    }
}
