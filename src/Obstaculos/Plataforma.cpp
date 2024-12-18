
#include "Plataforma.hpp"

Obstaculos::Plataforma::Plataforma(const int a, const int l) :
Obstaculo(false),
altura(a), largura(l)
{
    figura = new Figura(
        PLATAFORMA_LADO, PLATAFORMA_LADO,
        PLATAFORMA_LADO, PLATAFORMA_LADO,
        PLATAFORMA_LADO, PLATAFORMA_LADO,
        PLATAFORMA_LADO, PLATAFORMA_LADO
    );
    
}

Plataforma::~Plataforma()
{
}

void Obstaculos::Plataforma::executar() {
}
