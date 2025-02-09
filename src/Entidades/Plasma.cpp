#include "Plasma.hpp"

Plasma::Plasma(float x_inicial, float y_inicial):
Entidade(x_inicial, y_inicial),
ativo(false),
antiGrav(7.8),
dano(0)
{
    figura = new Figura(10,10,2,1,10, 0, 0, 0);
    carregarFigura(PLASMA_PATH);
    setTamanhoFigura(LARG_PLASMA, ALT_PLASMA);
    setPosicaoFigura(x_inicial, y_inicial);
    
}

Plasma::Plasma(const int dano):
Entidade(-1, -1),
ativo(false),
antiGrav(7.8),
dano(dano)
{
    figura = new Figura(10,10,2,1,10, 0, 0, 0);
    carregarFigura(PLASMA_PATH);
    setTamanhoFigura(LARG_PLASMA, ALT_PLASMA);
    setPosicaoFigura(-1, -1);
}

Plasma::~Plasma(){
}

void Plasma::executar(){
    if (ativo) {
        aplicarGravidade();
        deslocar();
        desenhar();
    }
}

void Plasma::salvar(){

    buffer.open(PLASMA_SALVAR_PATH, std::ios::app);

    if(!buffer){
        cout << "Plasma::salvar() -> erro ao abrir arquivo" << endl;
        return;
    }

    buffer << ativo << ' ' 
    << x << ' ' 
    << y << ' ' 
    << velocidade.x << ' '
    << velocidade.y << ' '
    << dano << endl;

    buffer.close();
}

void Plasma::queimar(Jogador* pJ){

    pJ->operator--(dano);
    velocidade = Vector2f(0,0);
    
    //colocando fora da tela
    x = -LARG_PLASMA;
    y = -ALTURA;
}

void Plasma::deslocar(){

    float aux;

    if(!pGG){
        cout<< "Personagem::mover() -> ponteiro gGrafico nulo" << endl;
        return;
    }

    planar();

    aux = pGG->getDeltaTime();
    aux *= PIXEL_METRO;

    x += velocidade.x *  aux;
    y += velocidade.y *  aux;

    setPosicaoFigura(x,y);
}

void Plasma::planar(){
    
    float aux;

    if(!pGG){
        cout << "AberracaoEspacial::planar() -> ponteiro gGrafico nulo" << endl;
        return;
    }

    aux = antiGrav * pGG->getDeltaTime();

    velocidade.y -= aux;
}
