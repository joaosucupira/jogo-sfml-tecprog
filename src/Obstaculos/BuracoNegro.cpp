#include "BuracoNegro.hpp"

BuracoNegro::BuracoNegro(const float x_inicial, const float y_inicial) :
Obstaculo(x_inicial, y_inicial),
forca(200.0f)
{
    figura = new Figura(
        BURACO_NEGRO_LADO, BURACO_NEGRO_LADO,
        7, 6,
        500, 500,
        0, 0
    );

    carregarFigura(BURACO_NEGRO_PATH);
    setTamanhoFigura(TAM_BURACO_NEGRO, TAM_BURACO_NEGRO);
    setPosicaoFigura(x_inicial, y_inicial);
    figura->setCor(Color::Magenta);
    figura->setAjuste(ALT_PLATAFORMA / 10.0f);
    
}

BuracoNegro::~BuracoNegro() 
{
}

void BuracoNegro::executar() {
    desenhar();
    atualizarFigura();
    gravitar();
}

void BuracoNegro::salvar(){

    buffer.open(BURACO_NEGRO_SALVAR_PATH,std::ios::app);
    
    if(!buffer){
        cout << "BuracoNegro::salvar() -> Erro ao abrir arquivo" << endl;
        return;
    }

    buffer << x << ' '
    << y << endl;

    buffer.close();
}

void BuracoNegro::obstacular(Jogador *pJ) {
    if (!pJ) {
        cout << "void BuracoNegro::obstacular(Jogador *pJ) -> ponteiro nulo" << endl;
        return;
    }
    float dt = pGG->getDeltaTime();
    float resultante = dt * forca;


    int fX = 0, fY = 0;
    if (pJ->getLimites().getPosition().x < getLimites().getPosition().x + TAM_BURACO_NEGRO / 3.0f) {
        fX += resultante;
    } else {
        fX -= resultante;
    }
    if (pJ->getLimites().getPosition().y < getLimites().getPosition().y) {
        fY -= resultante;
    } else {
        fY += resultante;
    }

    pJ->setXY(pJ->getX() + fX, pJ->getY() + fY);
    
    puxar(pJ, dt);

    
}

void BuracoNegro::puxar(Jogador *pJ, float dt) {

    // Temporizador acumulado para controlar o dano
    static float tempoAcumulado = 0.0f; // Mantém o tempo entre chamadas
    float cadencia = 0.3f;              // Tempo entre danos (em segundos)
    tempoAcumulado += dt;

    // Reduzir a vida do jogador apenas se o tempo acumulado ultrapassar a cadência
    if (tempoAcumulado >= cadencia) {
        pJ->operator--();
        tempoAcumulado = 0.0f; // Reiniciar o temporizador
        // cout << "Vida jogador: " << pJ->getVidas() << endl;
    }
}
