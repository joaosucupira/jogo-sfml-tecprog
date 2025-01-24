
#include "Plataforma.hpp"

Obstaculos::Plataforma::Plataforma(const int x_inicial, const int y_inicial) :
Obstaculo(x_inicial, y_inicial),
altura(0)
{
    figura = new Figura(
        PLATAFORMA_LARGURA, PLATAFORMA_ALTURA,
        1, 1,
        0, 0,
        0, 0
    );
    carregarFigura();
    setTamanhoFigura(LARG_PLATAFORMA, ALT_PLATAFORMA);
    setPosicaoFigura(x_inicial, y_inicial);

}


Plataforma::~Plataforma()
{
}


// obstacular não consideram o ajuste pois ele nao se aplica ao deslocamento pós colisão

void Obstaculos::Plataforma::obstacular(Jogador *pJ)
{
    if (!pJ) {
        cout << "void Obstaculos::Plataforma::obstacular(Jogador *pJ) -> ponteiro nulo " << endl;
        return;
    }

    const float ajusteColisao = 0.25f;

    FloatRect lim1 = pJ->getLimites();
    FloatRect lim2 = this->getLimites();


    //Colisao a esquerda do Personagem
    if (sentidos[0]) {
        pJ->setXY(lim1.left + (lim2.width * ajusteColisao), lim1.top);
        pJ->setVelocidadeX(0);
        // cout << "ESQUERDA" << endl;
  
    }
    //Colisao a direita do Personagem
    else if (sentidos[1]) {
        pJ->setXY(lim1.left - (lim2.width * ajusteColisao), lim1.top);
        pJ->setVelocidadeX(0);
        // cout << "DIREITA" << endl;
    }
    
        
    //Colisao a baixo do Personagem
    if(sentidos[2]) {
        pJ->setXY(lim1.left, lim2.top - (lim1.height));
        pJ->setVelocidadeY(0);
        pJ->setEstaPulando(false);
    }
    //Colisao a cima do Personagem
    else if(sentidos[3]) {
        pJ->setXY(lim1.left, lim2.top + (lim2.height + COLISAO));
        pJ->setVelocidadeY(0);
        // cout << "CIMA" << endl;
        
        
    }
}

void Obstaculos::Plataforma::obstacular(Inimigo *pI) {

    if (!pI) {
        cout << "void Obstaculos::Plataforma::obstacular(Inimigo *pI) -> ponteiro nulo " << endl;
        return;
    }


    FloatRect lim1 = pI->getLimites();
    FloatRect lim2 = this->getLimites();

    if(sentidos[0]) {
        pI->setXY(lim1.left + (lim2.width + COLISAO), lim1.top);
        pI->atualizaVelocidade(Vector2f(-1.0, 1.0));
    } 
    
    //Colisao a direita do Personagem
    else if(sentidos[1]) {
        pI->setXY(lim1.left - (lim2.width + COLISAO), lim1.top);
        pI->atualizaVelocidade(Vector2f(-1.0, 1));
    }
    
    //Colisao a baixo do Personagem
    if(sentidos[2]){
        pI->setXY(lim1.left, lim2.top - (lim1.height));
        pI->setVelocidadeY(0);
        pI->setEstaPulando(false);
    }
    //Colisao a cima do Personagem
    if(sentidos[3])
        pI->setXY(lim1.left, lim2.top + (lim2.height));
}

void Obstaculos::Plataforma::salvaDataBuffer() {
}

void Obstaculos::Plataforma::carregarFigura()
{
    if (figura) {
        figura->carregarTextura(PLATAFORMA_PATH);
    } else { cout << "void Obstaculos::Plataforma::carregarFigura() -> ponteiro nulo" << endl; }
}

void Obstaculos::Plataforma::executar() {
    desenhar();  
}
