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

    Ente* pEnte; //talvez nao precise ser bidirecional (até agora dá pra fazer sem)

public:

    /*Klug: Se todas as sprites que tem animacao tiverem um padrao na 
    secao final , inicial e qntd de secoes dá para usar macro em vez de 
    colocar parametro na construtora. Se for assim dá pra criar um booleano animacao
    na construtora para colocar os valores default, caso seja falso
    Sucupira: Genial
    */
    Figura(
        const int tamSecaoX = 1, const int tamSecaoY = 1,
        const int qntdSecaoX = 0, const int qntdSecaoY = 0,
        const int secaoFinalX = 0, const int secaoFinalY = 0,
        const int secaoInicialX = 0, const int secaoInicialY = 0
    );

    ~Figura();

    void setEnte(Ente* pE);
 
    void carregarTextura(string path_textura);

    void setPosicao(const float x, const float y){ sprite.setPosition(x,y); }
    void setProximaSecao();
    void setSecaoInicial();
    void virar(const int sentido);

    void setTamanho(const float tX, const float tY);
    void setCor(const Color &cor);

    FloatRect getLimites() const{ return sprite.getGlobalBounds();}
    Sprite getSprite() const {return sprite;}
};

