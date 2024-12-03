#pragma once
#include "Ente.hpp"
#include "stdfax.h"

namespace Entidades 
{
    class Entidade : public Ente
    {
    private:
        /* data */
    protected:
        sf::Vector2f velocidade;
        sf::Vector2f corpo;


    public:
        Entidade();
        virtual ~Entidade();

        virtual void executar() = 0;
        virtual void salvar() = 0;

        void setPosicao(sf::Vector2f vMudaP);
        sf::Vector2f getPosicao() const { return vPosicao; }

        void setVelocidade(sf::Vector2f vMudaV);
        sf::Vector2f getVelocidade() const { return velocidade; }
        
        void setCorpo(sf::Vector2f vMudaC);
        sf::Vector2f getCorpo() const { return corpo; }
    };


}