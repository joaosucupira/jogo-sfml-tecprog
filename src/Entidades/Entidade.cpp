#include "Entidade.hpp"
using namespace Entidades;

Entidade::Entidade(sf::Vector2f vPos, sf::Vector2f vCai) :
Ente(vPos)
{
    caixa = vCai;
    velocidade = sf::Vector2f(0.0f, 0.0f);
}

Entidade::Entidade()
{
    caixa = sf::Vector2f(0.0f, 0.0f);
    velocidade = sf::Vector2f(0.0f, 0.0f);
}

Entidade::~Entidade()
{
}

void Entidade::setPosicao(sf::Vector2f vMudaP) {
    Ente::setPos(vMudaP);
}

void Entidades::Entidade::setCaixa(sf::Vector2f vMudaC)
{
    caixa = vMudaC;
}

void Entidade::setVelocidade(sf::Vector2f vMudaV) {
    velocidade = vMudaV;
}