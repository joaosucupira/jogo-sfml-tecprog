#include "Leaderboard.hpp"

Leaderboard::Leaderboard() :
pontuacoes()
{
    pontuacoes.emplace(10, "joao");
    pontuacoes.emplace(25, "klug");
    pontuacoes.emplace(30, "fulano");
    pontuacoes.emplace(20, "sucupira");

}

Leaderboard::~Leaderboard()
{
}

void Leaderboard::executar()
{
    while (!pontuacoes.empty()) {
        auto top = pontuacoes.top();
        std::cout << "Prioridade: " << top.first << ", Valor: " << top.second << '\n';
        pontuacoes.pop();
    }
}
