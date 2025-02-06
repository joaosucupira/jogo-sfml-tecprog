#pragma once

#include "stdafx.h"

class Leaderboard {
    private:
        priority_queue<pair<int, string>> pontuacoes;
    public:
        Leaderboard();
        ~Leaderboard();

        void executar();
};