#include <stdio.h>
#include <string.h>
#define maxl (1<<63)-1

int main(){
    long long n, len, i, j;
    char a[maxl] = {'^','_','_','^'}, b[maxl] = {'T','.','T'}, c[maxl], ans;
    while (scanf("%lld", &n) != EOF) {
        ans = ' ';
        while (ans == ' ') {
            for (i = 0; i < strlen(a); i++) {
                c[i] = a[i];
            }
            if (strlen(c) >= n) {
                ans = a[n - 1];
            }else{
                strcat(c, b);
                for (i = 0; i < strlen(c); i++) {
                    b[i] = c[i];
                }
            }
        }
        printf("%c\n", ans);
    }
    return 0;
}