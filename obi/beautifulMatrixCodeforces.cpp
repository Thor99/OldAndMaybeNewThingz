#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int line, column;

    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= 5; j++){
            int valor;
            scanf("%d", &valor);

            if(valor == 1){
                line = i;
                column = j;
                break;
            }
        }
    }

    int movesLines = max(line, 3) - min(line, 3);
    int movesColumns = max(column, 3) - min(column, 3);

    printf("%d\n", movesLines + movesColumns);
}