#include "Jogador.hpp"
int Jogador::cont(0);

// Ideia para impedir criação de terceiro jogador: Verificar antes da chamada da cosntrutora
// (privar metodo construtor ou apenas nao utilizar sem a verificação)

Jogador::Jogador(const float x_inicial, const float y_inicial) :
Personagem(x_inicial, y_inicial),
pontos(0),
ehJog1(cont == 0),
pulando(false),
idFase(-1)
{

    if (cont < 2) {
        figura = new Figura(
            TAM_SECAO, TAM_SECAO, 
            QNTD_SECAO, QNTD_SECAO, 
            SEC_FINAL_X, SEC_FINAL_Y,
            SEC_INICIAL_X, SEC_INICIAL_Y
        );
        escolheCor();
        carregarFigura(JOGADOR_PATH);
        setTamanhoFigura(TAM_JOGADOR, TAM_JOGADOR);
        setPosicaoFigura(x, y);

        num_vidas = 30;
        cont++;
        
    } else {
        cout << endl << "Jogador::Jogador() -> Apenas dois jogadores permitidos." << endl;
    }
    
}

Jogador::~Jogador() {
    // cout << "estou sendo deletado" << endl;
    Jogador::cont--;
}

void Jogador::executar(){
    if(vivo){
        mover();
        aplicarGravidade();
        atualizarFigura();
        desenhar();
    }
}

void Jogador::salvar(){

    buffer.open(JOGADOR_SALVAR_PATH, std::ios::app);
    if(!buffer){
        cout << "Jogador()::salvar -> Erro ao abrir arquivo" << endl;
    }

    buffer << idFase << ' '
    << ehJog1 << ' '
    << pontos << ' '
    << x << ' '
    << y << ' '
    << num_vidas << ' '
    << andando << ' '
    << pulando << ' '
    << velocidade.y << endl;
    buffer.close();
}

void Personagens::Jogador::escolheCor() {
    Color cor = (ehJog1 ? Color::Yellow : Color::Cyan);
    setCorFigura(cor);
}

void Jogador::operator+=(int pts) { pontos += pts; }

void Jogador::operator--() {
    Personagem::operator--();
    notificarObservadores();
}

void Personagens::Jogador::operator--(const int dano) {
    Personagem::operator--();
    notificarObservadores();
}
