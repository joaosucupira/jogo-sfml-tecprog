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
    
        float x;
        float y; 
        int sentidos[4] = {0};
        Vector2f velocidade;
        static float gravidade;
        ofstream buffer;

    public:

        Entidade(float x_inicial = 0, float y_inicial = 0);
        virtual ~Entidade();

        /*----------------------------------------------------------------------------*/
        virtual void executar() = 0;
        virtual void salvar() = 0;
        virtual FloatRect hitBox() const = 0;

        /*SET*/
        void setXY(const float novoX, const float novoY);
        void setX(const float novoX){x = novoX;}
        void setY(const float novoY){y = novoY;}

        void setSentidos(int s[4]);

        void setVelocidade (Vector2f v) { velocidade = v;}
        void setVelocidadeX(float x){ velocidade.x = x;}
        void setVelocidadeY(float y){ velocidade.y = y;}
        void atualizaVelocidade(Vector2f num) {velocidade.x *= num.x; velocidade.y *= num.y;}

        static void setGravidade(float g){gravidade = g;}
        
        /*GET*/
        const float getX() const { return x; }
        const float getY() const { return y; }

        Vector2f getVelocidade() const { return velocidade;}

        const float getGravidade() const { return gravidade;}

    protected:

        void aplicarGravidade();
        
    };

} using namespace Entidades;