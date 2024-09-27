#include <SFML/Graphics.hpp>
#include "Jogador.cpp"
#include "Inimigo.cpp"

class Jogo
{
private:
    sf::Texture textura;
    sf::Texture textura2;
    sf::Texture textura3;
    sf::RenderWindow window;
    Jogador jogador1;
    Jogador jogador2;
    Inimigo inimigo1;

public:
    Jogo() : 
    window(sf::VideoMode(400, 400), "Jogo") 
    {
        textura.loadFromFile("./assets/img/jogadorsprite.png");
        textura2.loadFromFile("./assets/img/jogador2sprite.png");
        textura3.loadFromFile("./assets/img/inimigosprite.png");
        inimigo1.setWindow(&window);
        jogador1.setWindow(&window);
        jogador2.setWindow(&window);
        jogador1.body.setTexture(&textura);
        jogador2.body.setTexture(&textura2);
        inimigo1.body.setTexture(&textura3);
        Executar();
    }
    ~Jogo() {}
    
    void Executar() {
        while (window.isOpen()) {
            sf::Event event;
            while(window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
                
                // if (event.type == sf::Event::KeyPressed) {
                //     switch (event.key.code) {
                //         case sf::Keyboard::W:
                //             shape.move(sf::Vector2f(0.f,-1.5f));
                //             break;
                //         case sf::Keyboard::A:
                //             shape.move(sf::Vector2f(-1.5f,0.f));
                //             break;
                //         case sf::Keyboard::S:
                //             shape.move(sf::Vector2f(0.f,1.5f));
                //             break;
                //         case sf::Keyboard::D:
                //             shape.move(sf::Vector2f(1.5f,0.f));
                //             break;
                //         default:
                //             break;
                //     }
                // }
            }

            jogador1.move();
            jogador2.move2();
            window.clear();
            inimigo1.draw();
            jogador1.draw();
            jogador2.draw();
            window.display();
        }
    }
};

int main() {
    Jogo jogo1;
    return 0;
}