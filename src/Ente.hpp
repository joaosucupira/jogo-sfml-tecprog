#include <SFML/Graphics.hpp>

class Ente
{
protected:
    int id;
    // Gerenciador_Grafico* pGG;
    // Figura* pFig;
    //...

private:
    /* data */
public:
    Ente(/* args */);
    ~Ente();
    virtual void executar() = 0;
    void desenhar();
};

