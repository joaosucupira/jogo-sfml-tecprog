#include "Leaderboard.hpp"

Leaderboard::Leaderboard() :
pontuacoes()
{
    recuperar();
}

Leaderboard::~Leaderboard()
{
    salvar();
    
    while(!pontuacoes.empty())
        pontuacoes.pop();
}

void Leaderboard::executar()
{
    while (!pontuacoes.empty()) {
        auto top = pontuacoes.top();
        std::cout << "Prioridade: " << top.first << ", Valor: " << top.second << '\n';
        pontuacoes.pop();
    }
}

void Leaderboard::recuperar()
{

    int pontos;
    String nome;
    ifstream buffer(LEADER_BOARD_PATH);



}

void Leaderboard::salvar()
{
    int pontos;
    String nome;
    ofstream(LEADER_BOARD_PATH, std::ios::out);

}

void Leaderboard::adicionarJogador(Jogador *pJog)
{
    pontuacoes.emplace(pJog->getPontos(), pJog->getNome());
}
