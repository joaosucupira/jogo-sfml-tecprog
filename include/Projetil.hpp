#pragma once
#include "Entidade.hpp"

namespace Entidades {
class Projetil : public Entidade
{
public:
    Projetil(float dx, float dy);
    ~Projetil();
    void executar();
    // void atualizar(float dt);
    void salvar();
};

} using namespace Entidades;
