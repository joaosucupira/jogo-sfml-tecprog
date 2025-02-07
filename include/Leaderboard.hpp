#pragma once

#include "stdafx.h"
#include "Jogador.hpp"

#define LEADER_BOARD_PATH "./data/leaderBoard/leaderboard.txt"

class Leaderboard {
    private:
        priority_queue<pair<int, std::string>> pontuacoes;

    public:
        Leaderboard();
        ~Leaderboard();

        void executar();

        void recuperar();
        void salvar();

        void adicionarJogador(Jogador* pJog);

    private:

        const bool leString(ifstream& arquivo, string* str);
        const bool gravaString(ofstream& arquivo, string str);

};