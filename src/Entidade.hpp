#include "Ente.hpp"

namespace Entidades 
{
    class Entidade : public Ente
    {
    protected:
        int x;
        int y;
    private:
        /* data */
    public:
        Entidade(/* args */);
        ~Entidade();
        virtual void executar() = 0;
        virtual void salvar() = 0;
    };


}