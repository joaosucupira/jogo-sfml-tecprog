#pragma once

#include "stdafx.h"
#include "Jogador.hpp"

#define LEADER_BOARD_PATH "./data/leaderboard/leaderboard.txt"

class Leaderboard {
    private:
        priority_queue<pair<int, string>> pontuacoes;

    public:
        Leaderboard();
        ~Leaderboard();

        void executar();

        void recuperar();
        void salvar();

        void adicionarJogador(Jogador* pJog);

};