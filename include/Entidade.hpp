/*
* Classe abstrata que deriva em:
* - Personagem;
* - Projetil;
* - Obstáculo;
* Entende-se o conceito de posição e velocidade a partir desta classe.
*/

#pragma once
#include "Ente.hpp"
#include "stdafx.h"

namespace Entidades 
{
    class Entidade : public Ente {

    protected:
        /* Coordenadas em que será desenhada a entidade inicialmente */
        int x;
        int y;
        Vector2f velocidade;
        // ostream buffer;

    public:
        Entidade(int dx = 0, int dy = 0);
        virtual ~Entidade();

        /* Métodos set e get*/

        virtual void executar() = 0;
        virtual void salvaDataBuffer() = 0;

        void setPosicao(const float x, const float y);
        void setTamanho(const float x, const float y);
        void setCor(const Color& cor);
        void setVelocidade(const float x, const float y);

        void setPosX(const float x) { corpo->setPosition(x, getPosY()); }
        void setPosY(const float y) { corpo->setPosition(getPosX(), y); }

        const int getX() const { return x; }
        const int getY() const { return y; }

        const float getPosX() const { return corpo->getPosition().x; }
        const float getPosY() const { return corpo->getPosition().y; }

        const float getTamX() const { return corpo->getSize().x; }
        const float getTamY() const { return corpo->getSize().y; }


        const Vector2f getVelocidade() const { return velocidade; }

    };


}