#include "Personagem.hpp"

Personagem::Personagem(ID::ids id, sf::Vector2f vPos, sf::Vector2f vCorpo, int vidas) :
    Entidade(id, vPos, vCorpo),
    num_vidas(vidas)
{
}

Personagem::~Personagem()
{
}
