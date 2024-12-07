#include "Projetil.hpp"


Projetil::Projetil(float dx, float dy):
Entidade(dx, dy)
{
}

Projetil::~Projetil()
{
}

void Projetil::executar()
{
    cout << "Projetil executado!" << endl;
}

void Projetil::salvar()
{
    cout << "Projetil salvo!" << endl;
}