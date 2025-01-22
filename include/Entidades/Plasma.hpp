#pragma once
#include "Entidade.hpp"

#define PLASMA_PATH "./assets/Obstaculo/plataforma.24x24.png"
#define PLASMA_TAM_SEC 24
#define PLASMA_ALTURA 24

#define LARG_PLASMA 1.5
#define ALT_PLASMA 4

namespace Entidades {

    class Plasma : public Entidade
    {
        
        bool ativo;

    public:
        Plasma(float dx, float dy);
        ~Plasma();
        void executar();
        // void atualizar(float dt);
        void salvar();
        
    };

} using namespace Entidades;
