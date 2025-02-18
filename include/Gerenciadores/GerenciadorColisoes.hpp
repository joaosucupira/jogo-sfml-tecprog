/**CREDITOS: Os calculos de verificação dos sentidos das colisões inspirado no conteúdo 
 * do youtube do antigo monitor de Técnicas de Programaçao Matheus Burda **/


#pragma once
#include "stdafx.h"
#include "Jogador.hpp"
#include "Obstaculo.hpp"
#include "Inimigo.hpp"
#include "Plasma.hpp"
#include "Sujeito.hpp"

namespace Gerenciadores{
    class GerenciadorColisoes : public Sujeito
    {
    private:
    
        Jogador* pJog1;
        Jogador* pJog2;

        vector<Obstaculo*> obstaculos;
        list<Inimigo*> inimigos;
        set<Plasma*> plasmas;
                
        int sentidos[4] = {0};

        
    public:
        GerenciadorColisoes();
        ~GerenciadorColisoes();

        /*----------------------------------------------------------------------------*/
        void executar();

        void incluirObst(Obstaculo* pObst);
        void incluirInim(Inimigo* pInim);
        void incluirPlas(Plasma* pPlas);

        const int getInimigosVivos();

        /*SET*/
        void setPJog1(Jogador *pJ1);
        void setPJog2(Jogador *pJ2);

    private:

        const bool verificarColisao(Entidade* pE1, Entidade* pE2) const;
        void verificarSentido(Entidade* pE1, Entidade* pE2);
        void separarEntidades(Entidade* pE1, Entidade* pE2);

        void coliJogObstaculo();
        void coliJogInimigo();
        void coliJogPlasma();
        void coliInimObstaculo();


    };
} using namespace Gerenciadores;

