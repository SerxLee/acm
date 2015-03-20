#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void charu(double a[],int n)
{
    int i, j;
    double tmp;
    for (j=1; j<n; j++) {
        tmp = a[j];
        for (i=j; i>0 && a[i-1] > tmp; i--) {
            a[i] = a[i-1];
        }
        a[i] = tmp;
    }
}
int main()
{
    int x;
    int a[33];
    srand((int)time(0));
    for (x=0; x<33; x++) {
        a[x] = rand()%(100-1)+1;
    }
    charu(a, 33);
    for (x=1; x<33; x++) {
        printf("%d ",a[x]);
    }
}
