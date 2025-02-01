#pragma once
#include "stdafx.h"

#include "Fase.hpp"
#define LUA_PATH "./assets/Fase/cenario_fase_lua.png"

namespace Fases {

    class Lua : public Fase {
        
        const int maxViajantesMaus;

    public:
        Lua();
        ~Lua();

        /*----------------------------------------------------------------------------*/
        void executar();
        void criar();
        void recuperar();

    private:
        
        void criarInimigos();
        void criarObstaculos();

        void criarPlataformas();
        void criarPortais();

        void criarAlienigenas();
        void criarViajantesMaus();

        void definirGravidade();
        void configurarPerseguido();
        
        void atualizaPerseguido();

    };


}using namespace Fases;
