#include <stdio.h>

char s[4][5];
int lim[4][5];

void chang(int x, int y){
    if (lim[x][y] == 0) {
        lim[x][y] = 1;
    }else{
        lim[x][y] = 0;
    }
}

int main(){
    int i, j, k, sum;
    sum = 0;
    for (i = 0; i < 4; i++) {
        scanf("%s", s[i]);
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (s[i][j] == '+') {
                for (k = 0; k < 4; k++) {
                    chang(i, k);
                }
                for (k = 0; k < 4; k++) {
                    chang(k, j);
                }
                chang(i, j);
            }
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (lim[i][j] == 1) {
                sum++;
            }
        }
    }
    printf("%d\n", sum);
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (lim[i][j] == 1) {
                printf("%d %d\n", i + 1, j + 1);
            }
        }
    }
    return 0;
}