#include <cstdio>

int main(){
    int h1, m1, h2, m2;

    while(scanf("%d %d %d %d", &h1, &m1, &h2, &m2) == 4 && (h1 + m1 + h2 + m2) != 0){
        int resp;

        if(h1 > h2){
            resp= 60 * (24 - (h1 - h2)) + (m2 - m1);
        } else if(h1 == h2){
            if(m1 > m2){
                resp = 60 * 24 + (m2 - m1);
            } else {
                resp = m2 - m1;
            }
        } else { // h1 < h2
            resp = (60 * (h2 - h1)) + (m2 - m1);
        }

        printf("%d\n", resp);
    }
}