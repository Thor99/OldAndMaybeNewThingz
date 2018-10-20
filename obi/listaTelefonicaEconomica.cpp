#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        vector<string> nums;
        for(int i = 0; i < n; i++){
            string num;
            cin >> num;
            nums.push_back(num);
        }

        sort(nums.begin(), nums.end());

        int tam = nums[0].size();

        long int counter = 0, i = 0, next = 1;
        while(next != n){
            for(int j = 0; j < tam; j++){
                if(nums[i][j] == nums[next][j]){
                    counter++;
                } else { // Passa para o próximo indice de nums
                    i = next;
                    next++;
                    break;
                }
            }
       }

        printf("%ld\n", counter);
    }

}