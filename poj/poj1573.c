#include <stdio.h>
#include <string.h>
int com[15][15];
int map[15][15];
char str[15][15];
char stri[15][15];
int n, m, s, sum, bol, t;
int  a ,b;
char fx[4] = {'N', 'E', 'W', 'S'};
int stepi[4] = {-1, 0, 0, 1};
int stepj[4] = {0, 1, -1, 0};
void system(){
    int i, j, ii;
    i = 1;
    j = s;
    map[i][j] = 1;
    com[i][j] = 1;
    while (i > 0 && i <= n && j > 0 && j <= m) {
        a = i;
        b = j;
        for (ii = 0; ii < 4; ii++) {
            if (stri[i][j] == fx[ii]) {
                i += stepi[ii];
                j += stepj[ii];
                if (com[i][j] == 0) {
                    com[i][j] = com[a][b] + 1;
                }else{
                    sum = com[i][j] - 1;
                    t = com[a][b] - com[i][j] + 1;
                    bol = 0;
                    return;
                }
                break;
            }

        }
    }
    sum = com[a][b];
}
int main() {
    int i, j;
    while (scanf("%d%d%d", &n, &m ,&s) != EOF) {
        if (n == 0 && m == 0 && s == 0) {
            break;
        }
        sum = 0;
        bol = 1;
        for (i = 1; i <= n; i++) {
            scanf("%s", str[i]);
        }
        for (i = 1; i <= n; i++) {
            for (j = 0; j < m; j++) {
                stri[i][j + 1] = str[i][j];
            }
        }
        memset(com, 0, sizeof(com));
        system();
        if (bol == 1) {
            printf("%d step(s) to exit\n", sum);
        }else{
            printf("%d step(s) before a loop of %d step(s)\n", sum, t);
        }
    }
    return 0;
}