#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include <stdlib.h>
#include <string>
using namespace std;


class Entidade {
protected:
    sf::Texture textura;
    sf::RenderWindow* window;

public:
    sf::RectangleShape body;
    Entidade() : body(sf::Vector2f(100.f, 100.f)) {
        // body.setFillColor(sf::Color::Blue);
    }
    // Entidade(sf::Texture tex) : body(sf::Vector2f(100.f, 100.f)) {
    //     body.setTexture(&tex);
    // }
    ~Entidade() {}

    void setWindow(sf::RenderWindow* window) { this->window = window; }
    void draw() { window->draw(body); }
};