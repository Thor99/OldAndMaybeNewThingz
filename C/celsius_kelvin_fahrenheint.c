#include <stdio.h>

int main()

{
	float temp;
	float tempNova1;
	float tempNova2;
	char t;
	
	printf("Digite a temperatura: ");
	scanf("%f %c", &temp, &t);
	
	if(t == 'c'){
		tempNova1 = (temp / 5) * 9 + 32; 
		tempNova2 = temp + 273;
		printf("Temperatura em fahrenheint = %f", tempNova1);
		printf("Em kelvin: %f", tempNova2);
	}
	
	else if(t == 'f'){
		tempNova1 = ((temp - 32) / 9) * 5;
		tempNova2 = ((temp - 32) / 9 * 5) + 273;
		printf("Temperatura em celsius: %f", tempNova1);
		printf("Em kelvin: %f", tempNova2);
	}
	
	else if(t == 'k'){
		tempNova1 = temp - 273;
		tempNova2 = (tempNova1/5)*9+32;
		printf("Em celsius: %f\n", tempNova1);
		printf("Em fahrenheint: %f", tempNova2);
	}
	
	else{
		printf("Digita namoral.");
	}

	return 0;
}