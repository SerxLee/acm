#include <stdio.h>
#include <string.h>
void lj(int *hight, int n){
    int maxlong;
    int i, j;
    int longest[n];
    longest[1] = 1;
    for (i = 2; i <= n; i++) {
        maxlong = 1;
        for (j = 1; j <= i - 1; j++) {
            if (hight[i] <= hight[j]) {
                if (longest[j] + 1 > maxlong) {
                    maxlong = longest[j] + 1;
                    longest[i] = maxlong;
                }
            }
        }
    }
    maxlong = longest[1];
    for (i = 2; i <= n; i++) {
        if (longest[i] > maxlong) {
            maxlong = longest[i];
        }
    }
    printf("%d\n", maxlong);
}

int main(){
    
}