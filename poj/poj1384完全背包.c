#include <stdio.h>
#define max 10100

int f, e, dp[max], p[505], w[505];

int main() {
    int t, i, j, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &e, &f);
        f -= e;
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%d%d", &p[i], &w[i]);
        }
        for (i = 1; i <= f; i++) {
            dp[i] = max;
        }
        dp[0] = 0;
        int temp = 0;
        for (i = 0; i < n; i++) {
            while (temp + w[i] <= f) {
                dp[temp + w[i]] = dp[temp] + p[i];
                temp += w[i];
            }
        }
        for (i = 0; i < n; i++) {
            for (j = w[i]; j <= f; j++) {
                if (dp[j - w[i]] != max) {
                    if (dp[j] > dp[j - w[i]] + p[i]) {
                        dp[j] = dp[j - w[i]] + p[i];
                    }
                }
            }
        }
        if (dp[f] != max) {
            printf("The minimum amount of money in the piggy-bank is %d.\n", dp[f]);
        }else{
            printf("This is impossible.\n");
        }
    }
    return 0;
}