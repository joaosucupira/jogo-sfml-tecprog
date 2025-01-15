#include "Figura.hpp"
#include "Ente.hpp"

Figura::Figura(
const int tamSecaoX, const int tamSecaoY,
const int qntdSecaoX, const int qntdSecaoY,
const int secaoFinalX, const int secaoFinalY,
const int secaoInicialX, const int secaoInicialY
):
sprite(),
textura(),
secao(0, 0, tamSecaoX, tamSecaoY),
qntdSecoes(qntdSecaoX,qntdSecaoY),
secaoFinal(secaoFinalX, secaoFinalY),
secaoInicial(secaoInicialX, secaoInicialY),
contAtualizacoes(0)
// pEnte(NULL)
{
}

Figura::~Figura() {
}

void Figura::carregarTextura(string path_textura)
{
    if (!textura.loadFromFile(path_textura))
        cout << "Figura::carregarTextura(string path_textura) -> Erro ao carregar textura de " << path_textura << endl;
    else{
        sprite.setTexture(textura);
        sprite.setTextureRect(secao);
    }
        
}


void Figura::setTamanho(const float tX, const float tY)
{
    //sprite.setOrigin(secaoX / 2.0f, secaoY / 2.0f); //Acho q isso só complica as coisas !!!
    sprite.setScale(tX / secao.width , tY / secao.height);
    
}

void Figura::setCor(const Color &cor){
    sprite.setColor(cor);
}


//Quebrar essa funcao em AtualizarSecaoX e AtualizarSecaoY
void Figura::atualizarSecao() {

    // alterei porque ficou lerdo depois de acrescentar entidades
    if (contAtualizacoes < 5){
        contAtualizacoes++;
        return;
    }

    contAtualizacoes = 0;

    if(secao.left == secaoFinal.x && secao.top == secaoFinal.y) {
        secao.left = 0;
        secao.top = 0;
    } 
    else if (secao.left < (qntdSecoes.x - 1) * secao.width) {
        secao.left += secao.width;
    }
    else if (secao.top < (qntdSecoes.y - 1) * secao.height) {
        secao.left = 0;
        secao.top += secao.height;
    }
    
    sprite.setTextureRect(secao);
}

void Figura::setSecaoInicial() {

    secao.left = secaoInicial.x;
    secao.top = secaoInicial.y;

    sprite.setTextureRect(secao);
}

void Figura::virar(const int sentido) {
    sprite.scale(sentido, 1);
}
