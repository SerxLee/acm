#include <stdio.h>
#include <string.h>

void charu(int a[],int n);

int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, tt, j;
        int a[202];
        memset(a, 0, sizeof(a));
        scanf("%d", &tt);
        while (tt--){
            scanf("%d%d", &n, &m);
            if (n > m) {
                j = m;
                m = n;
                n = j;
            }
            for (j = (n + 1) / 2; j <= (m + 1) / 2; j++) {
                a[j]++;
            }
        }
        charu(a, 202);
        printf("%d\n", a[0] * 10);
    }
}

void charu(int a[],int n){
    int i, j;
    int tmp;
    for (j = 1; j < n; j++) {
        tmp = a[j];
        for (i = j; i > 0 && a[i-1] < tmp; i--) {
            a[i] = a[i-1];
        }
        a[i] = tmp;
    }
}