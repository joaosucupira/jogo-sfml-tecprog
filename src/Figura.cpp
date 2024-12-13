#include "Figura.hpp"

Figura::Figura(const int spriteX, const int spriteY) :
pTextura(new Texture()),
pSprite(new Sprite()),
secao_atual(IntRect(0, 0, 0, 0)),
contAtualizacoes(0),
secaoX(spriteX), secaoY(spriteY)
{
    secao_atual = IntRect(0, 0, secaoX, secaoY);
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
        pSprite->setTextureRect(secao_atual);
        ajustarTamanho();
    } else { cout << "Figura::setSprite(string path_sprite) -> ponteiro nulo." << endl; }
}

void Figura::ajustarTamanho() {
    if (pronta()) {
        pSprite->setOrigin(12.0f, 12.0f);
        pSprite->setScale(Vector2f(7.0f, 7.0f));
    } else
        cout << "Figura::ajustarTamanho() -> ponteiro nulo / textura nao carregada ainda" << endl;
}

void Figura::setProximaSecaoSprite() {


    //O ideial é fazer esse contAtualizacoes antes de chamar essa funcao -> Coesao


    contAtualizacoes++;

    if(!pSprite){
        cout << "void Figura::setProximaSecaoSprite() -> ponteiro nulo." << endl;
        return;
    }

    if (contAtualizacoes == 10) {

        contAtualizacoes = 0;

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
    }
}

void Figura::setSpriteInicial() {
    secao_atual.left = 24;
    secao_atual.top = 0;
    pSprite->setTextureRect(secao_atual);     
    
}
