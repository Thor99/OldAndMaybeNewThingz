#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int length, sumOfDigits;
	vector<long long int> numbersThatFit;

	scanf("%d %d", &length, &sumOfDigits);

	/* Este for pegara cada número da sequencia e aplicará um for no mesmo, pra ver a soma dos seus digitos. */

	for(long long int i = pow(10, length - 1); i < pow(10, length); ++i){
		printf("%lld\n", i);
		string number = to_string(i);
		int sum = 0;

		for(int k = 0; k < length; ++k){
			int digit = number[k] - 48; // Pegar o real valor inteiro do digito, a partir do char

			sum += digit;
		}

		if(sum == sumOfDigits){
			numbersThatFit.push_back(i);
		}
	}

	sort(numbersThatFit.begin(), numbersThatFit.end()); // Sort crescente

	if(numbersThatFit.size() >= 1){
		printf("%lld %lld", numbersThatFit[0], numbersThatFit[numbersThatFit.size() - 1]);
	} else {
		printf("-1 -1");
	}
}