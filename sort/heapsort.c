#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void maxheapify(int a[], int i, int size)
{
    int l, r;
    int large, temp;
    l = 2*i+1;
    r = 2*i+2;
    if (l < size-1 && a[l] > a[i]) {
        large = l;
    }else{
        large = i;
    }
    if (r <= size-1 &&a[r] > a[large]) {
        large = r;
    }
    if (large != i) {
        temp = a[i];
        a[i] = a[large];
        a[large] = temp;
    }
    maxheapify(a, large, size);
}
void buildmaxheap(int a[], int size)
{
    int i;
    for (i = size/2; i >= 0; i--) {
        maxheapify(a, i, size);
    }
}
void heapsort(int a[], int size)
{
    int length, i, temp;
    length = size;
    buildmaxheap(a, size);
    for (i = length; i >= 1; --) {
        temp = a[0];
        a[0] = a[i-1];
        a[i-1] = temp;
        length--;
        maxheapify(a, 0, length);
    }
}