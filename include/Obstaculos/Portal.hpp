#pragma once
#include "stdafx.h"
#include "Obstaculo.hpp"

class Portal : public Obstaculo {
private:
    float largura;
public:
    Portal();
    ~Portal();
    void obstacular(Jogador* pJ);
};