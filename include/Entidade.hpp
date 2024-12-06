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
        int x;
        int y;
        Vector2f velocidade;
        // ostream buffer;

    public:
        Entidade(int dx = 0, int dy = 0);
        virtual ~Entidade();

        void setPosicao(const float x, const float y);
        void setTamanho(const float x, const float y);
        void setCor(const Color& cor);
        void setVelocidade(const float x, const float y);


        virtual void executar() = 0;
        virtual void salvaDataBuffer() = 0;

        const int getX() const { return x; }
        const int getY() const { return y; }    
        const Vector2f getVelocidade() const { return velocidade; }

    };


}