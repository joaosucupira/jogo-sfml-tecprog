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
        void criarObstaculos();
        void criarSuportes();
        void criarPortais();
        void criarAlienigenas();
        void criarViajantesMaus();
        void carregarFigura();

    };


}using namespace Fases;
