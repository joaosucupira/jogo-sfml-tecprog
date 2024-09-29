#include <SFML/Graphics.hpp>
#include "Personagem.hpp"

class Principal
{
private:
    /* data */
    sf::RenderWindow* janela;
    Personagem amigo;


public:
    Principal();
    ~Principal();
    void executar();
};


