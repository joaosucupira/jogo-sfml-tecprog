#include "Entidade.hpp"

namespace Entidades {
    class Projetil : public Entidade
    {
        private:
            /* data */
        public:
            Projetil();
            ~Projetil();
            void executar();
            void salvar();
    };

}
