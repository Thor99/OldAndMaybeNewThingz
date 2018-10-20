#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(){
	string n;
	double salarioFixo, totalVendas;

	cin >> n;

	scanf("%lf", &salarioFixo);
	scanf("%lf", &totalVendas);

	printf("TOTAL = R$ %.2f\n", (salarioFixo + (0.15 * totalVendas)));
}