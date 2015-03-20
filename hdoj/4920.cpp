#include <cstdio>
#include <cstring>

unsigned char a[805][805];
unsigned char b[805][805];
unsigned char c[805][805];

int main(){
    int n, i, j, k, q, p;
    long temp;
    while (~scanf("%d", &n)) {
        memset(b, 0, sizeof(b));
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                scanf("%ld", &temp);
                a[i][j] = temp % 3;
            }
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                scanf("%ld", &temp);
                c[i][j] = temp % 3;
            }
        }
        for (k = 0; k < n; k++) {
            for (i = 0; i < n; i++) {
                if (!a[i][k]) continue;
                for (j = 0; j < n; j++) {
                    b[i][j] = (b[i][j] + c[k][j] * a[i][k]) % 3;
                }
            }
        }

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (j == n - 1) {
                    printf("%d", b[i][j]);
                }else{
                    printf("%d ", b[i][j]);
                }
            }
            printf("\n");
        }

    }
    return 0;
}