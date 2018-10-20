#include <cstdio>

int main(){
    int n;
    while(scanf("%d", &n) == 1 && n != 0){
        int arr[100000];
        bool ambiguo = true;

        for(int i = 1; i <= n; i++){
            scanf("%d", &arr[i]);
        }

        for(int i = 1; i <= n; i++){
            if(arr[arr[i]] != i){
                ambiguo = false;
                break;
            }
        }

        if(ambiguo){
            printf("ambiguous\n");
        } else {
            printf("not ambiguous\n");
        }
    }
}