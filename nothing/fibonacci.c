迭代
#include <stdio.h>
void sj(int n){
    int i, a = 1, b = 1, c = 1;
    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    printf("%d\n", c);
}
int main(){
    int n;
    while (scanf("%d", &n) != EOF) {
        sj(n);
    }
    return 0;
}