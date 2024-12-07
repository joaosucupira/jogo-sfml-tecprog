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
    RectangleShape* corpo;
    float *pDeltaTime;

    static GerenciadorGrafico* pGG;
public:
    Ente();
    virtual ~Ente();
    virtual void executar() = 0;

    void desenhar();
    void setGGrafico() { pGG = GerenciadorGrafico::getInstancia(); }
    void setId(const int i) { id = i; }
    void setCorpo(RectangleShape* pC);
    void setDeltaTime(float* pDt){ if(pDt) pDeltaTime = pDt;}


    const int getId() const { return id; }
    RectangleShape* getCorpo() const { return corpo;}
    

    void moverSprite(Vector2f vMove);


    // void setPos(const sf::Vector2f posicao);

};


