/* Classe abstrata PURA que deriva a maior parte dos objetos instanciados
* Derivam de Ente:
* - Entidade
* - Fase
* - Menu
* O atributo id é um namespace reservado que enumera um numero inteiro
* para cada tipo de ente.
*/

#pragma once
#include "Id.h"
#include "stdfax.h"

class Animador;

class Ente
{
protected:

    Animador* sprite;
    ID::ids id;
    sf::Vector2f vPosicao;
    // static Gerenciador_Grafico* pGG;
    // static Gerenciador_Eventos* pGE;
    // Figura* sprite;

public:
    Ente(ID::ids idEnte, sf::Vector2f vP);
    Ente();
    virtual ~Ente();

    virtual void executar() = 0;
    // virtual void atualizar(float dt) = 0;
    virtual void carregar();
    void moverSprite(const sf::Vector2f vMove);

    void setPos(const sf::Vector2f vPos);
    ID::ids getID() const { return id; }

    // void setGGrafico() { pGG = Gerenciadores::Gerenciador_Grafico::getGerenciador_Grafico(); }
    // void setGEventos() { pGG = Gerenciadores::Gerenciador_Eventos::getGerenciador_Eventos(); }



};


