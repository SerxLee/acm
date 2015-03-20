#include <stdio.h>

long int po(long int x, int n)
{
    if (n == 0 ) {
        return 1;
    }
    if (n == 1) {
        return x;
    }
    if (n % 2 ==0) {
        return po(x * x, n/2);
    }else{
        return po(x * x, n/2) * x;
    }
}
int main()
{
    printf("%ld",po(22, 6));
}