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
        /* Coordenadas em que será desenhada a entidade */
        float x;
        float y; 
        
        // ostream buffer;

    public:
        Entidade(float dx = 0, float dy = 0);
        virtual ~Entidade();

    
        virtual void executar() = 0;
        virtual void salvaDataBuffer() = 0;

        /* Métodos set e get*/

        void setPosicaoFigura(const float x, const float y);
        void setTamanhoFigura(const float x, const float y);
        void setCorFigura(const Color& cor);

        void setXY(const float novoX, const float novoY);
        const float getX() const { return x; }
        const float getY() const { return y; }
        
    };

} using namespace Entidades;