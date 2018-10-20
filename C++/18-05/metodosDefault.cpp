#include <iostream>

using namespace std;

/* Se quisermos que um metodo tenha uma definição padrão ({}), igualamos o método a default */

class B
{
    public:
        B() = default; // mesma coisa que B(){};
        void f();
    protected:
        void g();
    private:
        void h();
        int m_valor;
};