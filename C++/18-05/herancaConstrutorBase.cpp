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
        B(int x);
        void f();
    protected:
        void g();
    private:
        void h();
        int m_valor;
};

B::B(int x){
    m_valor = x;
}

void B::f(){
    cout << "B::f() " << m_valor << endl;
}

void B::g(){
    cout << "B::g() " << m_valor << endl;
}

void B::h(){
    cout << "B::h() " << m_valor << endl;
}

// class [nome da classe derivada] : [escopo máximo] [nome da classe base]
// Public é o maior escopo permitido nesta classe derivada
class D : public B
{
    public:
        D(int x);
        void f();
};

D::D(int x)
: B(x)
{

}

void D::f()
{
    cout << "D::f()" << endl;
    B::f(), B::g();
}

int main(){
    D d(3);
    d.f();
}
