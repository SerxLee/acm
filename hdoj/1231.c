#include <stdio.h>
#include <string.h>

int a[10010];
int sum[10010];
int start[10010];
int t, i, j, k, m;

int main(){
    while (scanf("%d", &k) != EOF) {
        if (k == 0) {
            break;
        }
        memset(start, 0, sizeof(start));
        for (i = 0; i < k; i++) {
            scanf("%d", &a[i]);
        }
        sum[0] = a[0];
        start[0] = a[0];
        m = 0;
        if (a[0] < 0) {
            m = 1;
        }
        for (i = 1; i < k; i++) {
            if (a[i] < 0) {
                m++;
            }
            if (sum[i - 1] >= 0) {
                sum[i] = sum[i - 1] + a[i];
                start[i] = start[i - 1];
            }else{
                sum[i] = a[i];
                start[i] = a[i];
            }
        }
        int max_sum, max_end, max_start;
        if (m == k) {
            max_sum = 0;
            max_start = a[0];
            max_end = a[k - 1];
        }else{
            max_sum = sum[0];
            max_end = a[0];
            max_start = start[0];
            for (i = 1; i < k; i++) {
                if (sum[i] > max_sum) {
                    max_sum = sum[i];
                    max_end = a[i];
                    max_start = start[i];
                }
            }
        }
        printf("%d %d %d\n", max_sum, max_start, max_end);
    }
    return 0;
}