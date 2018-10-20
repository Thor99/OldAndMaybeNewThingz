#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(){
	int inicio, acoes;

	scanf("%d %d", &inicio, &acoes);

	for(int i = 0; i < acoes; i++){
		string s;
		cin >> s;

		if(s == "fechou"){
			inicio += 1;
		} else {
			inicio -= 1;
		}
	}

	printf("%d\n", inicio);
}