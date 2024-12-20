#include "Fase.hpp"

using namespace Fases;

Fase::Fase() :
GC()
{
}

Fase::~Fase()
{
}

void Fases::Fase::executar() {
    criarPlataformas();
}

void Fases::Fase::criarPlataformas()
{
    Plataforma* pP = NULL;
    const int n = 1;
    for (int i = 0; i < n; i++) {
        pP = new Plataforma(i, i);
        GC.incluirObst(pP);
        pP = NULL;
    }
    if (pP) delete pP;
    pP = NULL;
}
