#pragma once
#include "Ente.hpp"
#include "stdafx.h"

namespace Entidades 
{
    class Entidade : public Ente {

    protected:
        int x;
        int y;
        // Vector2f velocidade;
        // ostream buffer;

    public:
        Entidade(int dx = 0, int dy = 0);
        virtual ~Entidade();

        virtual void executar() = 0;
        virtual void salvaDataBuffer() = 0;

        const int getX() const { return x; }
        const int getY() const { return y; }

        // void setPosicao(sf::Vector2f vMudaP);
        // sf::Vector2f getPosicao() const { return posicao_inicial; }

        // void setVelocidade(sf::Vector2f vMudaV);
        // sf::Vector2f getVelocidade() const { return velocidade; }
        
        // void setCorpo(sf::Vector2f vMudaC);
        // sf::Vector2f getCorpo() const { return corpo; }
    };


}