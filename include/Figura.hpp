/* Classe figura pensada para agregar Sprite e Texture para desacopla-los
*  da classe Ente em um objeto reutilizável.
*/

#pragma once
#include "stdafx.h"

class Ente;

class Figura
{
private:

    Sprite sprite;
    Texture textura;
    IntRect secao;
    Vector2i qntdSecoes;
    Vector2i secaoFinal;
    Vector2i secaoInicial;
    int contAtualizacoes;

public:

    Figura(
        const int tamSecaoX = 1, const int tamSecaoY = 1,
        const int qntdSecaoX = 0, const int qntdSecaoY = 0,
        const int secaoFinalX = 0, const int secaoFinalY = 0,
        const int secaoInicialX = 0, const int secaoInicialY = 0
    );

    ~Figura();

    /*----------------------------------------------------------------------------*/
    void carregarTextura(string path_textura);
    void atualizarSecao();
    void setSecaoInicial();
    //void virar(const int sentido);
    //void mostrarDano();

    /*SET*/
    void setPosicao(const float x, const float y){ sprite.setPosition(x,y); }
    void setTamanho(const float tX, const float tY);
    void setCor(const Color &cor);
    
    /*GET*/
    FloatRect getLimites() const{ return sprite.getGlobalBounds();}
    Sprite getSprite() const {return sprite;}

};

