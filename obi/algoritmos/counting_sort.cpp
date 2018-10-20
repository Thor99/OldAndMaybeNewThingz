#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// Counting sort é bom quando o maior valor de um array for baixo

int main(){
    vector<int> arr;
    vector<int> freq;
    int tamArr;
    int maxVal = 0;

    arr.push_back(8);
    arr.push_back(7);
    arr.push_back(8);
    arr.push_back(8);
    arr.push_back(7);
    arr.push_back(1);

    tamArr = arr.size();
    for(int i = 0; i < tamArr; i++){
        maxVal = max(maxVal, arr[i]);
    }

    freq.reserve(maxVal + 1);
    fill(freq.begin(), freq.end(), 0);

    // Counting sort
    for(int i = 0; i < tamArr; i++){
        freq[arr[i]]++;
    }

    int iter = 0;
    for(int i = 0; i <= maxVal; i++){
        for(int j = 0; j < freq[i]; j++){
            arr[iter] = i;
            iter++;
        }
    }

    // Print
    for(int i = 0; i < tamArr; i++){
        printf("%d ", arr[i]);
    }
}