#include<cstdio>

using namespace std;

int b, s, n[30000];

int main() {
    scanf("%d", &b);
    for(int i = 1; i <= b; i++) {
        scanf("%d", &s);
        n[0] = 0;
        for(int j = 1; j < s; j++)
            scanf("%d", &n[j]);
        int a = 0, b = 0, c = 0, sum = 0, max = 0;
        for(int j = 1; j < s; j++) {
            sum += n[j];
            if(sum > max || (sum == max && j - a > b - c)) {
                max = sum;
                b = j;
                c = a;
            }
            if(sum < 0) {
                a = j;
                sum = 0;
            }
        }
        if(max > 0)
            printf("The nicest part of route %d is between stops %d and %d\n", i, c + 1, b + 1);
        else
            printf("Route %d has no nice parts\n", i);
    }
}