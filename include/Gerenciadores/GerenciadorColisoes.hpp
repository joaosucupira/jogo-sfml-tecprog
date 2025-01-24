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
                
        FloatRect lim1;
        FloatRect lim2;
        int sentidos[4] = {0};
        const float ajustePerso;
        const float ajusteObst;
        
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

        const bool verificarColisao(FloatRect lim1, FloatRect lim2) const;
        void verificarSentido(Vector2f pos1, Vector2f pos2);
        FloatRect ajusteHitBoxPerso(FloatRect lim);
        void restauraHitBoxPerso(FloatRect &lim);

        FloatRect ajusteHitBoxObst(FloatRect lim);
        void restauraHitBoxObst(FloatRect &lim);

        void jogadorPlataforma(Jogador* pJog);
        void inimigoPlataforma(Inimigo* pInim);
        void inimigoJanela(Inimigo* pInim);
        void jogadorInimigo(Jogador* pJog, Inimigo* pInim);

        //Janela vai se tornar uma plataforma
        
        void coliJogJanela();
        void coliJogObstaculo();
        void coliJogInimigo();
        void coliJogPlasma();

        void coliInimObstaculo();
        void coliInimJanela();

    };
} using namespace Gerenciadores;

