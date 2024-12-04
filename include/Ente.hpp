/* Classe abstrata PURA que deriva a maior parte dos objetos instanciados
* Derivam de Ente:
* - Entidade
* - Fase
* - Menu
*/

#pragma once
#include "stdafx.h"
#include "GerenciadorGrafico.hpp"

class Ente
{
protected:
    static int cont_id;
    int id;
    static GerenciadorGrafico* pGG;

    Vector2f posicao_inicial;
    RectangleShape* corpo;

public:
    Ente(
        const float x = 0.0f,
        const float y = 0.0f,
        const float largura = 100.0f,
        const float altura = 100.0f
    );
    virtual ~Ente();
    virtual void executar() = 0;

    void moverSprite(const sf::Vector2f vMove);
    void desenhar();

    void setId(const int i) { id = i; }
    void setPos(const sf::Vector2f posicao);
    void setGGrafico() { pGG = GerenciadorGrafico::getInstancia(); }

    const int getId() const { return id; }
    RectangleShape getCorpo() const { return *corpo;}

};


