#include "Fase.hpp"

using namespace Fases;

Fase::Fase() :
GC(),
entidades()
{

}

Fase::~Fase()
{
}

void Fase::gerenciarColisoes()
{
}

void Fase::executar() 
{
    criarPlataformas();
}

void Fase::criarPlataformas() {
    Plataforma* pP = NULL;
    const int max = 1;

    for (int i = 0; i < max; i++) {
        pP = new Plataforma(0.0f, ALTURA - ALT_PLATAFORMA);
        entidades.adiciona(pP);
        pP = NULL;
    }
    if (pP) delete pP;
    pP = NULL;
}
