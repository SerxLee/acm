#include <stdio.h>

void bubblesort( int *a);

int main(){
    int i, a[10];
    for (i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }
    bubblesort(a);
    for (i = 0; i < 10; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}

void bubblesort(int *a){
    int i, j, temp;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10 - i - 1; j++) {
            if (a[j]> a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}