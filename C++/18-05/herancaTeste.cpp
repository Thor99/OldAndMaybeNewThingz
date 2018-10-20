#include <iostream>

using namespace std;

// Classe base e classe derivada.

// Métodos publicos: Pode ser acessado por todos
// Métodos protecteds: Pode ser acessado pela própria classe e classes filhas
// Métodos privates: Só pode ser acessado pela própria classe

/* Se escrevemos na classe derivada um método com o mesmo nome de um método da classe base, esse método sobrescreve
o método da classe base, e é executado. */

/* Se quisermos executar um método da classe base que tenha o mesmo nome que um método da classe derivada, chamamos
B::f(); OBS: Supondo que tenhamos um método f na classe derivada e na classe base. */

class B
{
    public:
        B();
        void f();
    protected:
        void g();
    private:
        void h();
};

// class [nome da classe derivada] : [escopo máximo] [nome da classe base]
// Public é o maior escopo permitido nesta classe derivada
class D : public B
{
    public:
        void f();
};

int main(){
    D d;
    d.f();
}
