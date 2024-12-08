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

void Figura::setSprite(string path_sprite) {
    if (pSprite && pTextura) {
        if (!pTextura->loadFromFile(path_sprite)) {
            cerr << "Figura::setSprite(string &path_sprite) -> Erro ao carregar textura de " << path_sprite << endl;
            return;
        }
        pSprite->setTexture(*pTextura);
        pSprite->setTextureRect(IntRect(0, 0, 24, 24));
    } else { cout << "Figura::setSprite(string &path_sprite) -> ponteiro nulo." << endl; }
}
