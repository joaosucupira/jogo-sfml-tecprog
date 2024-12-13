/* Classe figura pensada para agregar Sprite e Texture para desacopla-los
*  da classe Ente em um objeto reutilizável.
*/

#pragma once
#include "stdafx.h"

class Ente;

class Figura
{
private:
    Texture* pTextura;
    Sprite* pSprite;
    IntRect secao_atual;
    int contAtualizacoes;
    int secaoX;
    int secaoY;

    Ente* pEnte;

public:
    Figura(const int spriteX, const int spriteY);
    ~Figura();

    void setEnte(Ente* pE);
    void carregarTextura(string path_sprite);
    void setSprite(string path_sprite);
    void ajustarTamanho();
    void setProximaSecaoSprite();
    void setSpriteInicial();
    void virar(const int sentido);

    const bool pronta() const { return pTextura && pSprite; }
    Sprite* getSprite() const { return pSprite; }
};

