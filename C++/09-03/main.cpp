#include "calculadora.h"
#include <stdio.h>
#include <math.h>
#include <iostream>

int main()
{
    //float val;

    //scanf("%f", &val);
    //Calculadora calc1(val);
    //calc1.Mais(3);
    //calc1.Menos(6);
    //calc1.Vezes(10);
    //calc1.Sobre(34);
    //printf("%f\n", calc1.Resultado());

    // -----------------------

    // printf("%f\n", calc1.Mais(3).Menos(6).Vezes(10).Sobre(34).Resultado());

    // -----------------------

    //Calculadora c1(3);
    //Calculadora c2(5);
    //Calculadora c3 = c1 + 3.0f; isso é aceito pois nossa classe usa seu metodo construtor e utiliza o valor como parametro.
    //Calculadora c3 = c1 + c2;
    //printf("%f\n", -c3.Resultado());

    // -----------------------

    // Calculadora c1(3);
    // Calculadora c2(4);
    // c1 += c2;
    // printf("%f\n", c1.Resultado());

    // -----------------------

    float a, b, c, result1, result2;

    std::cin >> a >> b >> c;

    Calculadora ca(a);
    Calculadora cb(b);
    Calculadora cc(c);

    if(ca.Resultado() == 0){
        std::cout << "Nao e uma equação quadratica";
    } else {
        if(((cb * cb) - (ca * cc) * 4).Resultado() > 0){
            Calculadora result1calc((-cb + ((cb * cb) - (ca * cc) * 4).Sqrt()) / 2 * ca);
            Calculadora result2calc((-cb + ((cb * cb) - (ca * cc) * 4).Sqrt()) / 2 * ca);

            std::cout << result1calc.Resultado() << " " << result2calc.Resultado() << std::endl;
        } else if(((cb * cb) - (ca * cc) * 4).Resultado() < 0){
            std::cout << "Nao tem raizes reais";
        } else {
            Calculadora result1calc(-cb / (ca * 2));

            std::cout << result1calc.Resultado() << std::endl;
        }
    }
}
