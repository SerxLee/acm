#include <stdio.h>
#include <string.h>


int main(){
    int s[103][103];
    int n, i, j;
    while (scanf("%d", &n) != EOF) {
        int com[103][103];
        memset(s, 0, sizeof(s));
        memset(com, 0, sizeof(com));
        for (i = 1 ; i <= n; i++) {
            for (j = 1; j <= i; j++) {
                scanf("%d", &s[i][j]);
            }
        }
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= i; j++) {
                if (com[i - 1][j - 1] + s[i][j] > com[i - 1][j] + s[i][j]) {
                    com[i][j] = com[i - 1][j - 1] + s[i][j];
                }else{
                    com[i][j] = com[i - 1][j] + s[i][j];
                }
            }
        }
        int max = com[n][1];
        for (i = 1; i <= n; i++) {
            if (com[n][i] > max) {
                max = com[n][i];
            }
        }
        printf("%d\n", max);
    }
    return 0;
}