#pragma once
#include "Entidade.cpp"

class Jogador : public Entidade {
private:
public:
    Jogador() {

    }
    ~Jogador() {}

    void move() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            body.move(sf::Vector2f(2.0f, 0.0f));
        } 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            body.move(sf::Vector2f(-2.0f, 0.0f));
        } 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            body.move(sf::Vector2f(0.0f,-2.0f));
        } 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            body.move(sf::Vector2f(0.0f, 2.0f));
        } 
    }

    void move2() {
        // body.setFillColor(sf::Color::Red);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            body.move(sf::Vector2f(2.0f, 0.0f));
        } 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            body.move(sf::Vector2f(-2.0f, 0.0f));
        } 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            body.move(sf::Vector2f(0.0f,-2.0f));
        } 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            body.move(sf::Vector2f(0.0f, 2.0f));
        } 
    }
};