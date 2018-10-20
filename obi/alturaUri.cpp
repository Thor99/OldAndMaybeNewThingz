#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N;
    scanf("%d", &N);

    vector<int> nums(3000010);
    vector<int> freq(231);

    while(N--){
        int tam;
        int maxVal = 0;
        scanf("%d", &tam);

        for(int i = 0; i < tam; i++){
            int val;
            scanf("%d", &val);

            maxVal = max(maxVal, val);

            nums[i] = val;
        }

        fill(freq.begin(), freq.end(), 0);

        for(int i = 0; i < tam; i++){
            freq[nums[i]]++;
        }

        int iter = 0;
        for(int i = 0; i <= maxVal; i++){
            for(int j = 0; j < freq[i]; j++){
                nums[iter] = i;
                iter++;
            }
        }

        for(int i = 0; i < tam; i++){
            if(i == tam - 1){
                printf("%d", nums[i]);
            } else {
                printf("%d ", nums[i]);
            }
        }

        printf("\n");

        nums.clear();
    }
}