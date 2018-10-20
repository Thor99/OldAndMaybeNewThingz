#include "calculadora.hpp"
#include <cstdio>

int main(){
	float val1;
	char operacao;

	scanf("%f", &val1);
	Calculadora<float> calc1(val1);

	while(scanf(" %c", &operacao) == 1 && operacao != '=')
	{

		if(operacao == 'R')
		{
			calc1.Sqrt();
		}

		else
		{
			float val2;

			scanf("%f", &val2);

			Calculadora<float> calc2(val2);

			if(operacao == '+')
			{
				calc1 += calc2;
			}

			else if(operacao == '-')
			{
				calc1 -= calc2;
			}

			else if(operacao == '/')
			{
				calc1 /= calc2;
			}

			else
			{ // *
				calc1 *= calc2;
			}
		}
	}

	printf("%.2f\n", calc1.Resultado());
}
