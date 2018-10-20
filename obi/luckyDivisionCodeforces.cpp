#include <cstdio>

using namespace std;

int main(){
    int n;
    bool almostLucky = false;

    scanf("%d", &n);

    if(n % 4 == 0 || n % 7 == 0){
        almostLucky = true;
    }

    else if(n % 47 == 0 || n % 74 == 0 || n % 44 == 0 || n % 77 == 0){
        almostLucky = true;
    }

    else if(n % 444 == 0 || n % 447 == 0 || n % 474 == 0 || n % 477 == 0 || n % 744 == 0 || n % 747 == 0 || n % 777 == 0){
        almostLucky = true;
    }

    if(almostLucky){
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}