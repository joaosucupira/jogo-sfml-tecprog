#include "Leaderboard.hpp"

Leaderboard::Leaderboard() :
pontuacoes()
{
    while(!pontuacoes.empty())
        pontuacoes.pop();

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
    std::priority_queue<std::pair<int, std::string>> temp = pontuacoes;
     pair<int,std::string> dado;
    
    std::cout << "\n=== Leaderboard ===\n";
    while (!temp.empty()) {
        dado = temp.top();
        std::cout << dado.second << " - " << dado.first << " pontos" << std::endl;
        temp.pop();
    }
    std::cout << "====================\n";
}

void Leaderboard::recuperar()
{

    int pontos;
    std::string nome;
    ifstream buffer(LEADER_BOARD_PATH);

    if(!buffer){
        cout << "Leaderboard::recuperar() -> Erro ao abrir arquivo" << endl;
        return;
    }

    while( leString(buffer, &nome) && buffer >> pontos){
        pontuacoes.emplace(pontos, nome);
    }

    buffer.close();
    

}

void Leaderboard::salvar()
{
    path dir("data/leaderBoard");

    if(!is_directory(dir)){
        create_directories(dir);
    }
    
    int pontos;
    std::string nome;
    pair<int,std::string> dado;

    priority_queue<pair<int,std::string>> copia = pontuacoes;
    ofstream arquivo(LEADER_BOARD_PATH, std::ios::out);

    if(!arquivo){
        cout << "Leaderboard::salvar() -> erro ao abrir arquivo" << endl;
        return;
    }

    while (!copia.empty())
    {
        dado = copia.top();

        pontos = dado.first;
        nome = dado.second;

        if(!gravaString(arquivo, nome))
            break;
        
        arquivo << ' ' << pontos << endl;

        if(!arquivo)
            break;
        

        copia.pop();
        pontos = -1;
        nome = "";
        dado.first = -1;
        dado.second = "";
    }
    
    arquivo.close();


}

void Leaderboard::adicionarJogador(Jogador *pJog)
{
    pontuacoes.emplace(pJog->getPontos(), pJog->getNome());
}

const bool Leaderboard::leString(ifstream &arquivo, string* str)
{
    size_t tam;
    string temp;

    arquivo >> tam;
    
    if(!arquivo)
        return false;

    temp.resize(tam);

    arquivo.read((char*)&temp[0], tam);

    if(!arquivo)
        return false;


    *str = temp;

    return true;
}

const bool Leaderboard::gravaString(ofstream &arquivo, string str)
{

    size_t tam;
    
    tam = str.size();

    arquivo << tam;
    arquivo.write((char*) &str[0], tam);

    if(!arquivo)
        return false;
    

    return true;
}
