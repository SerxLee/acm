#include <stdio.h>
#include <string.h>

int n, i, j, n2, a, b, c, lim, bo, max, money[35],sum[35];
double q, mon;
char type;


int main(){
    while (scanf("%lf%d", &q, &n) != EOF) {
        if (n == 0) {
            break;
        }
        max = (int)(q * 100);
        memset(sum, 0, sizeof(sum));
        memset(money, 0, sizeof(money));
        for (i = 1; i <= n; i++) {
            scanf("%d", &n2);
            a = b = c = bo = 0;
            while (n2--) {
                scanf("%*c%c:%lf", &type, &mon);
                lim = (int)(mon * 100);
                if (type == 'A') {
                    a += lim;
                }else if (type == 'B'){
                    b += lim;
                }else if (type == 'C'){
                    c += lim;
                }else{
                    bo = 1;
                }
                if (bo != 1 && a + b + c <= 100000 && a <= 60000 && b <= 60000 && c <= 60000) {
                    money[i] = a + b + c;
                }else{
                    money[i] = 0;
                }
            }
        }
        for (i = 1; i <= n; i++) {
            sum[i] = money[i];
        }
        int temp;
        for (i = 2; i <= n; i++) {
            for (j = i - 1; j > 0; j--) {
                temp = sum[j] + money[i];
                if (temp <= max && temp > sum[i]) {
                    sum[i] = temp;
                }
            }
        }
        int max_sum;
        max_sum = sum[1];
        for (i = 2; i <= n; i++) {
            if (sum[i] > max_sum) {
                max_sum = sum[i];
            }
        }
        printf("%.2lf\n", max_sum / 100.0);
    }
    return 0;
}