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
        int* sentidos;
        
        // ostream buffer;

    public:
        Entidade(float x_inicial = 0, float y_inicial = 0);
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
        void posicionar(const float x, const float y);

        void exibirHitbox(FloatRect& lim);
        virtual void atualizarFigura() = 0;
        
        virtual FloatRect hitBox() const = 0; //entidade
        void verificarSentido(Entidade* pE);
        // virtual FloatRect getHitBoxAjustada(const float ajuste) const = 0;

        
    };

} using namespace Entidades;