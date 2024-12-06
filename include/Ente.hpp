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
    RectangleShape* corpo;

public:
    Ente();
    virtual ~Ente();
    virtual void executar() = 0;

    void desenhar();
    void setGGrafico() { pGG = GerenciadorGrafico::getInstancia(); }
    void setId(const int i) { id = i; }
    void setCorpo(RectangleShape* pC);

    const int getId() const { return id; }
    RectangleShape* getCorpo() const { return corpo;}
    // void moverSprite(const sf::Vector2f vMove);
    // void setPos(const sf::Vector2f posicao);

};


