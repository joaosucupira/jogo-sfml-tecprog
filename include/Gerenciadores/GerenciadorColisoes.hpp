#pragma once
#include "stdafx.h"
#include "Jogador.hpp"
#include "Obstaculo.hpp"
#include "Inimigo.hpp"
#include "Plasma.hpp"

namespace Gerenciadores{
    class GerenciadorColisoes
    {
    private:
    
        Jogador* pJog1;
        Jogador* pJog2;

        vector<Obstaculo*> obstaculos;
        vector<Inimigo*> inimigos;
        vector<Plasma*> plasmas;
                
        int sentidos[4] = {0};

        
    public:
        GerenciadorColisoes();
        ~GerenciadorColisoes();
        
        void executar();

        void setPJog1(Jogador *pJ1);
        // void setPJog2(Jogador *pJ2);

        void incluirObst(Obstaculo* pObst);
        void incluirInim(Inimigo* pInim);
        void incluirPlas(Plasma* pPlas);

    private:

        const bool verificarColisao(Entidade* pE1, Entidade* pE2) const;
        void verificarSentido(Entidade* pE1, Entidade* pE2);

        void coliJogObstaculo();
        void coliJogInimigo();
        void coliInimObstaculo();




    };
} using namespace Gerenciadores;

