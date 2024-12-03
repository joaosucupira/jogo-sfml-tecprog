/* Classe abstrata PURA que deriva a maior parte dos objetos instanciados
* Derivam de Ente:
* - Entidade
* - Fase
* - Menu
* 
*/

#pragma once
#include "stdfax.h"
#include "GerenciadorGrafico.hpp"

class Ente
{
protected:

    static GerenciadorGrafico* pGG;
    sf::Vector2f vPosicao;
    // Animador* sprite;
    // static Gerenciador_Eventos* pGE;
    // Figura* sprite;

public:
    Ente();
    virtual ~Ente();

    virtual void executar() = 0;
    // virtual void atualizar(float dt) = 0;
    virtual void carregar();
    void moverSprite(const sf::Vector2f vMove);

    void setPos(const sf::Vector2f vPos);

    void setGGrafico() { pGG = GerenciadorGrafico::getInstancia(); }
    // void setGEventos() { pGE = Gerenciadores::Gerenciador_Eventos::getGerenciador_Eventos(); }



};


