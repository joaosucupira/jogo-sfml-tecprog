#pragma once
#include "stdfax.h"

class Animado;

class Ente
{
protected:
    static int cont_Ente;
    const int id;
    sf::Vector2f vPosicao;
    // static Gerenciador_Grafico* pGG;
    // static Gerenciador_Eventos* pGE;
    // Figura* pFig;
    //...

public:
    Ente(sf::Vector2f vP);
    Ente();
    virtual ~Ente();
    virtual void executar() = 0;
    void desenhar();
    void mover(const sf::Vector2f vMove);
    void setPos(const sf::Vector2f vPos);
    

    // void setGGrafico() { pGG = Gerenciadores::Gerenciador_Grafico::getGerenciador_Grafico(); }
    // void setGEventos() { pGG = Gerenciadores::Gerenciador_Eventos::getGerenciador_Eventos(); }

    const int getId() const { return id; }

};


