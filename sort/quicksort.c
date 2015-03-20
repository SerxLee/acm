#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int a[], int l, int k)
{
    if (l < k) {
        int i = l , j = k, tmp = a[l];
        while (i < j) {
            while (i < j && a[j] >= tmp) {
                j--;
            }
            if (i<j) {
                a[i++]= a[j];
            }
            
            while (i<j && a[i] <= tmp) {
                i++;
            }
            if (i<j) {
                a[j--] = a[i];
            }
        }
        a[i] = tmp;
        quicksort(a, l, i-1);
        quicksort(a, i+1, k);
    }
}

int main()
{
    int i;
    int a[1000000];
    srand((int)time(0));
    for (i=0; i< 1000000; i++) {
        a[i] =rand()%1000000;
    }
    quicksort(a, 0, 1000000);
    for (i=0; i<1000000;i++ ) {
        printf("%d\n",a[i]);
    }
}
