#include "Figura.hpp"

Figura::Figura() :
pTextura(new Texture()),
pSprite(new Sprite()),
secao_atual(IntRect(0, 0, 24, 24))
{
}

Figura::~Figura() {
    if (pTextura != NULL) delete pTextura;
    if (pSprite != NULL) delete pSprite;

    pTextura = NULL;
    pSprite = NULL;
}

void Figura::carregarTextura(string path_sprite) {
    if (!pTextura->loadFromFile(path_sprite)) {
        cerr << "Figura::carregarTextura(string path_sprite) -> Erro ao carregar textura de " << path_sprite << endl;
        return;
    }
}

void Figura::setSprite(string path_sprite)
{
    if (pSprite && pTextura) {
        /* Carregamento de textura */
        carregarTextura(path_sprite);
        pSprite->setTexture(*pTextura);

        // Escolhendo a seção da sprite
        pSprite->setTextureRect(secao_atual);
        pSprite->setOrigin(12.0f, 12.0f);
        pSprite->setScale(Vector2f(7.0f, 7.0f));


    } else { cout << "Figura::setSprite(string &path_sprite) -> ponteiro nulo." << endl; }
}

void Figura::setProximaSecaoSprite() {
    if (pSprite) {
        if (secao_atual.left < 48) {
            secao_atual.left += 24;

        } else if (secao_atual.top < 48) {
            secao_atual.left = 0;
            secao_atual.top += 24;
        } 

        if (secao_atual.left == 24 && secao_atual.top == 48) {
            secao_atual.left = 0;
            secao_atual.top = 0;

        }
        pSprite->setTextureRect(secao_atual);        
    } else { cout << "void Figura::setProximaSecaoSprite() -> ponteiro nulo." << endl; }
}

void Figura::setSpriteInicial() {
    secao_atual.left = 0;
    secao_atual.top = 0;
}
