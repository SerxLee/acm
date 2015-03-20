#include <stdio.h>
#include <string.h>
#define MAX(a,b) (a>b?a:b)

int main(){
    int t, n, i, j, sum;
    float p, v[110], f[10010];
    int w[110];
    scanf("%d", &t);
    while (t--) {
        memset(f, 0, sizeof(f));
        scanf("%f%d", &p, &n);
        sum = 0;
        for (i = 1; i <= n; i++) {
            scanf("%d%f", &w[i], &v[i]);
            v[i] = (1 - v[i]);
            sum += w[i];
        }
        f[0] = 1;
        for (i = 1; i <= n; i++) {
            for (j = sum; j >= w[i]; j--) {
                f[j] = MAX(f[j],f[j - w[i]] * v[i]);
            }
        }
        for (i = sum; i >= 0; i--) {
            if (f[i] >= 1 - p) {
                break;
            }
        }
        printf("%d\n", i);
    }
    return 0;
}