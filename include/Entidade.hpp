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
        float x; // tem que ser float por causa do sfml
        float y; 
        //Vector2f velocidade;
        // ostream buffer;

    public:
        Entidade(float dx = 0, float dy = 0);
        virtual ~Entidade();

    
        virtual void executar() = 0;
        virtual void salvaDataBuffer() = 0;

        /* Métodos set e get*/
        void setPosicaoCorpo(const float x, const float y);
        void setTamanho(const float x, const float y);
        void setCor(const Color& cor);
        void setXY(const float novoX, const float novoY);

        const float getX() const { return x; }
        const float getY() const { return y; }

        //Na Ente faz mais sentido
        const float getTamX() const { return corpo->getSize().x; }
        const float getTamY() const { return corpo->getSize().y; }

        // Usar apenas nas classes que já carregam as texturas das sprites por enquanto
        void ajustarSprite();
    };


}