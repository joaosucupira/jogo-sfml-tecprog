#pragma once
#include "Entidade.cpp"

class Inimigo : public Entidade {
    public:
        Inimigo() {
            // body.setFillColor(sf::Color::Magenta);
            body.setPosition(sf::Vector2f(200.f, 200.f));
        }

        ~Inimigo() {}

};