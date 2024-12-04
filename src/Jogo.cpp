#include "Jogo.hpp"
GerenciadorGrafico* Jogo::pGG = GerenciadorGrafico::getInstancia();

Jogo::Jogo() :
GE(),
J1(true)
{
        RectangleShape R1(Vector2f(100.0f, 100.0f));
        Clock relogio;

        while ((pGG->getJanela()).isOpen()) {
            float dt = relogio.restart().asSeconds();
            Vector2f gravidade(0.0f, dt * 600.0f);
            if (R1.getPosition().y < ALTURA - R1.getSize().x) {
                R1.move(gravidade);
            }

            Event e;
            while ((pGG->getJanela()).pollEvent(e)) {
                if (e.type == Event::Closed) {
                    (pGG->getJanela()).close();

                }
                if (e.type == Event::KeyPressed) {
                    Vector2f movimento(0.0f, 0.0f);

                    if (e.key.code == Keyboard::Right) {
                        movimento.x += 30.0f ;
                    } 
                    if (e.key.code == Keyboard::Left) {
                        movimento.x -= 30.0f ;
                    } 
                    if (e.key.code == Keyboard::Up) {
                        movimento.y -= 100.0f;
                    }
                    if (e.key.code == Keyboard::Up && e.key.code == Keyboard::Right) {
                        movimento.x += 100.0f;
                        movimento.y -= 100.0f;
                    }
                    R1.move(movimento);
                }
            }
            (pGG->getJanela()).clear();
            (pGG->getJanela()).draw(R1);
            (pGG->getJanela()).display(); 

        }
    }

Jogo::~Jogo()
{
}