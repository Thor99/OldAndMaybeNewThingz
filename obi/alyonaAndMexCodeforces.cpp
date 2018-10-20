#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    vector<int> nums;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int val;
        scanf("%d", &val);

        nums.push_back(val);
    }

    sort(nums.begin(), nums.end());

    int mex = 1;
    for(int i = 0; i < n; i++){
        if(nums[i] >= mex){
            mex++;
        }
    }

    printf("%d\n", mex);
}