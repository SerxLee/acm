#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble(int *a, int n)
{
    
    int i, j, temp;
    for (i = 0; i < n; i++) {
        for (j = n - 1 ; j > i; j--) {
            if (a[j] < a[j-1]) {
                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }
}
int main()
{
    int i;
    int a[10];
    srand((int)time(0));
    for (i = 0; i < 10; i++) {
        a[i] = rand()%(100-1)+1;
    }
    bubble(a);
    for (i = 0; i < 10; i++) {
        printf("%d ",a[i]);
    }
    getchar();
}
