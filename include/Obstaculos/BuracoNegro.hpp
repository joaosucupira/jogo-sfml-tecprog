#pragma once
#include "stdafx.h"

#include "Obstaculo.hpp"

#define BURACO_NEGRO_PATH "./assets/Obstaculo/B_Negro_100x100px.png"
#define BURACO_NEGRO_LADO 100

class BuracoNegro : public Obstaculo {
    private:
        float forca;
    public:
        BuracoNegro(const float x_inicial, const float y_inicial);
        ~BuracoNegro();
        void carregarFigura();
        void atualizarFigura();
        void obstacular(Jogador* pJ);
        void executar();
        void salvaDataBuffer() {}
};