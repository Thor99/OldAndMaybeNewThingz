#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<int> vec;

	vec.push_back(10);
	vec.push_back(9);
	vec.push_back(65);
	vec.push_back(1);
	vec.push_back(190);
	vec.push_back(13);
	vec.push_back(-5);

	// Sort crescente
	sort(vec.begin(), vec.end());

	for(int i = 0; i < vec.size(); i++){
		printf("%d ", vec[i]);
	}

	printf("\n");

	// Sort decrescente
	sort(vec.rbegin(), vec.rend());

	for(int i = 0; i < vec.size(); i++){
		printf("%d ", vec[i]);
	}
}