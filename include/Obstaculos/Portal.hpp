#pragma once
#include "stdafx.h"
#include "Obstaculo.hpp"

#define PORTAL_PATH "./assets/Obstaculo/Ship_portal_32x32.png"
#define PORTAL_LADO 32

class Portal : public Obstaculo {
private:
    float raio;
public:
    Portal(const float x_inicial = 0.0f, const float y_inicial = 0.0f);
    ~Portal();
    void obstacular(Jogador* pJ);
 
    void executar();
    void salvaDataBuffer() {}
};