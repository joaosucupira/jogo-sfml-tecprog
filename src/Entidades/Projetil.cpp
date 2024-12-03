#include "Projetil.hpp"
#include "Id.h"
using namespace Entidades;

Projetil::Projetil() :
Entidade(ID::ids::projetil, sf::Vector2f(1.0f, 1.0f), sf::Vector2f(1.0f,1.0f))
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