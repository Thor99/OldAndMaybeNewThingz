#include "calculadora.h"
#include <math.h>

Calculadora::Calculadora(){
    m_valor = 0;
}

Calculadora::Calculadora(float x){
    m_valor = x;
}

Calculadora Calculadora::operator+(Calculadora c){
    return Calculadora(m_valor + c.Resultado());
}

void Calculadora::operator+=(Calculadora c){
    m_valor += c.Resultado();
}

Calculadora Calculadora::operator-(Calculadora c){
    return Calculadora(m_valor - c.Resultado());
}

void Calculadora::operator-=(Calculadora c){
    m_valor -= c.Resultado();
}

Calculadora Calculadora::operator-(){
    return Calculadora(-m_valor);
}

Calculadora Calculadora::operator*(Calculadora c){
    return Calculadora(m_valor * c.Resultado());
}

void Calculadora::operator*=(Calculadora c){
    m_valor *= c.Resultado();
}

Calculadora Calculadora::operator/(Calculadora c){
    return Calculadora(m_valor / c.Resultado());
}

void Calculadora::operator/=(Calculadora c){
    m_valor /= c.Resultado();
}

float Calculadora::Resultado(){
    return m_valor;
}

Calculadora Calculadora::Sqrt(){
    return Calculadora(sqrt(m_valor));
}

Calculadora Calculadora::Mais(float x){
    m_valor += x;
    return Calculadora(m_valor);
}

Calculadora Calculadora::Menos(float x){
    m_valor -= x;
    return Calculadora(m_valor);
}

Calculadora Calculadora::Vezes(float x){
    m_valor *= x;
    return Calculadora(m_valor);
}

Calculadora Calculadora::Sobre(float x){
    m_valor /= x;
    return Calculadora(m_valor);
}
