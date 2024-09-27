#include <SFML/Graphics.hpp>

class Personagem
{
private:
    /* data */
    float x, y;
    sf::Texture* tex;
    sf::RectangleShape corpo;

public:
    Personagem(float x0 = 0.f, float y0 = 0.f, const char* pathTextura = "");
    ~Personagem();
    void atualizar();
    void desenhar(sf::RenderWindow* janela);
};

