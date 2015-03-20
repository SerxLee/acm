#include <stdio.h>
#include <string.h>
int main(){
    int ju[505][505];
    int m, n, t, i, j, k, c1, c2, r1, r2, sum[100005], a;
    scanf("%d", &t);
    int ca = 1;
    while (ca <= t) {
        memset(sum, 0, sizeof(sum));
        scanf("%d%d", &n, &m);
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                scanf("%d", &a);
                ju[i][j] = a * a;
            }
        }
        scanf("%d", &k);
        int cak = 1;
        while (cak <= k) {
            scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
            for (i = r2 - r1; i >= 0; i--) {
                for (j = c2; j >= c1; j--) {
                    sum[cak] += ju[i + 1][j];
                }
            }
            cak++;
        }
        printf("Case %d:\n", ca);
        for (i = 1; i <= k ; i++) {
            printf("%d\n", sum[i]);
        }
        ca++;
    }
    return 0;
}