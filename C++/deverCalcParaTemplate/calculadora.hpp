#ifndef CALCULADORA_H
#define CALCULADORA_H
#include <cmath>

template<typename T>
class Calculadora
{
    public:

        Calculadora()
        {
        	m_valor = T();
        }

        Calculadora(T valor)
        {
        	m_valor = valor;
        }

        Calculadora operator+(Calculadora c)
        {
        	return Calculadora(m_valor + c.Resultado());
        }

        void operator+=(Calculadora c)
        {
        	m_valor += c.Resultado();
        }

        Calculadora operator-()
        {
        	return Calculadora(-m_valor);
        }

        void operator-=(Calculadora c)
        {
        	m_valor -= c.Resultado();
        }

        Calculadora operator*(Calculadora c)
        {
        	return Calculadora(m_valor * c.Resultado());
        }

        void operator*=(Calculadora c)
        {
        	m_valor *= c.Resultado();
        }

        Calculadora operator/(Calculadora c)
        {
        	return Calculadora(m_valor / c.Resultado());
        }

        void operator/=(Calculadora c)
        {
        	m_valor /= c.Resultado();
        }

        Calculadora Sqrt()
        {
            return Calculadora(sqrt(m_valor));
        }

        T Resultado()
        {
        	return m_valor;
        }

        Calculadora Mais(T x)
        {
        	m_valor += x;
        	return Calculadora(m_valor);
        }

        Calculadora Menos(T x)
        {
        	m_valor -= x;
        	return Calculadora(m_valor);
        }

        Calculadora Vezes(T x)
        {
        	m_valor *= x;
        	return Calculadora(m_valor);
        }

        Calculadora Sobre(T x)
        {
        	m_valor /= x;
        	return Calculadora(m_valor);
        }

    private:
        T m_valor;
};
#endif
