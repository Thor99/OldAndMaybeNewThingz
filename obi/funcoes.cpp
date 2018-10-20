#include <stdio.h>
#include <string>
#include <math.h>
#include <iostream>

using namespace std;

string returnWinner(int n1, int n2, int n3){
    int max = 0;
    string winner;
    int arr[3] = {n1, n2, n3};

    for(int i = 0; i < 3; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    if(max == arr[0]){
        winner = "Rafael ganhou";
    }

    else if(max == arr[1]){
        winner = "Beto ganhou";
    }

    else {
        winner = "Carlos ganhou";
    }

    return winner;
}

int main(){
    int times, n1, n2, numRafael, numBeto, numCarlos;

    scanf("%d", &times);

    for(int i = 0; i < times; i++){
        scanf("%d %d", &n1, &n2);

        numRafael = pow(3 * n1, 2) + pow(n2, 2);
        numBeto = (2 * pow(n1, 2)) + pow(5 * n2, 2);
        numCarlos = (-100 * n1) + pow(n2, 3);

        string winner = returnWinner(numRafael, numBeto, numCarlos);

        cout << winner << endl;
    }

    return 0;
}
