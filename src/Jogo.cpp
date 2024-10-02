#include "Jogo.hpp"


Jogo::Jogo()
{
    Jogador jogador1;
    jogador1+=7;
    jogador1+=7;
    cout << jogador1.getPontos() << endl;
    cout << "oi" << endl;
}

Jogo::~Jogo()
{
}