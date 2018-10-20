#include <stdio.h>

int isPalindrome(int n){ // Se numero é palindromo, retorna 1, senão, 0.
    int reverse = 0;
    int k = n;

    while(k != 0) {
        int rem = k % 10;
        reverse = reverse * 10 + rem;
        k/=10;
    }

    if(n == reverse){
        return 1;
    } else {
        return 0;
    }
}

int getCloserPalindrome(int n){ // Função recursiva pra ir testando se os numero seguintes a n, e o primeiro a ser palindromo é retornado.
    if(isPalindrome(n + 1) == 1){
        return (n + 1);
    } else {
        return getCloserPalindrome(n + 1);
    }
}

int main(){
    int cases, number;

    scanf("%d", &cases);

    for(int i = 0; i < cases; i++){
        scanf("%d", &number);
        printf("%d\n", getCloserPalindrome(number));
    }

    return 0;
}
