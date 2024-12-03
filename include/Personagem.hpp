#pragma once

#include "stdfax.h"
#include "Entidade.hpp"
using namespace Entidades;

/* Falta: GERENCIADOR GRAFICO; ANIMAÇÃO (OPCIONAL)*/

namespace Personagens {
    class Personagem : public Entidade
    {
        private:
            /* data */

        protected:
            int num_vidas;
        public:
            Personagem(ID::ids id, sf::Vector2f vPos, sf::Vector2f vCorpo, int vidas);
            ~Personagem();

            int getVidas() const { return num_vidas; }
            virtual void executar() = 0;
    };
} using namespace Personagens;