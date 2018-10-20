#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
	long long int N;
	long long int quant = 0;

	scanf("%lld", &N);


	for(long long int i = pow(10, N - 1); i < pow(10, N); i++){
		string sr = to_string(i);
		string s;
		s.assign(sr);
		reverse(sr.begin(), sr.end());


	    if(sr > s){
	    	quant += 1;
	    }
	}

	printf("%lld\n", quant);
	
}