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
        sf::Vector2f caixa;


    public:
        Entidade(sf::Vector2f vPos, sf::Vector2f vCai);
        Entidade();
        virtual ~Entidade();
        void setPosicao(sf::Vector2f vMudaP);
        void setVelocidade(sf::Vector2f vMudaV);
        void setCaixa(sf::Vector2f vMudaC);
        virtual void executar() = 0;
        virtual void salvar() = 0;
        sf::Vector2f getPosicao() const { return vPosicao; }
        sf::Vector2f getVelocidade() const { return velocidade; }
        sf::Vector2f getCaixa() const { return caixa; }
    };


}