#pragma once
#include "stdafx.h"
#include "Jogador.hpp"
#include "Obstaculo.hpp"
#include "Inimigo.hpp"

namespace Gerenciadores{
    class GerenciadorColisoes
    {
    private:
    
        Jogador* pJog1;
        Jogador* pJog2;

        vector<Obstaculo*> obstaculos;
        vector<Inimigo*> inimigos;
                
        //FloatRect limiteEtd1;
        //FloatRect limiteEtd2;
        
    public:
        GerenciadorColisoes();
        ~GerenciadorColisoes();
        
        void executar();

        const bool verificarColisao(Entidade* pEtd1, Entidade* pEtd2) const;
        
        //Janela vai se tornar uma plataforma
        void coliJogJanela();

        void coliJogObstaculo();
        void coliJogInimigo();

        void coliInimObstaculo();

        void setPJog1(Jogador *pJ1);
        // void setPJog2(Jogador *pJ2);

        void incluirObst(Obstaculo* pObst);
        void incluirInim(Inimigo* pInim);

    };
} using namespace Gerenciadores;

