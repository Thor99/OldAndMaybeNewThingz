#ifndef CALCULADORA_H
#define CALCULADORA_H

class Calculadora
{
    public:
        Calculadora();
        Calculadora(float x);

        Calculadora operator+(Calculadora c); // a + c
        void operator+=(Calculadora c);// a = a + c

        Calculadora operator-(Calculadora c); // a - c
        void operator-=(Calculadora c);// a = a - c

        Calculadora operator-(); // -a

        Calculadora operator*(Calculadora c); // a * c
        void operator*=(Calculadora c);// a = a * c

        Calculadora operator/(Calculadora c); // a / c
        void operator/=(Calculadora c);// a = a / c

        Calculadora Sqrt();

        float Resultado();

        Calculadora Mais(float x);
        Calculadora Menos(float x);
        Calculadora Vezes(float x);
        Calculadora Sobre(float x);

    private:
        float m_valor;
};


#endif
