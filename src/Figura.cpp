#include "Figura.hpp"

Figura::Figura() :
pTextura(new Texture()),
pSprite(new Sprite())
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
        pSprite->setTextureRect(IntRect(24, 0, 24, 24));
        pSprite->setOrigin(12.0f, 12.0f);
        pSprite->setScale(Vector2f(7.0f, 7.0f));

        /* Ajuste de origem */
        // IntRect tex = pSprite->getTextureRect();
        // pSprite->setOrigin(tex.width / 2.0f, tex.height / 2.0f);

    } else { cout << "Figura::setSprite(string &path_sprite) -> ponteiro nulo." << endl; }
}
