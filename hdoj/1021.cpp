//大水体

#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    int n;
    while (scanf("%d", &n) != EOF) {
        if ((n - 2) % 4 == 0) {
            printf("yes\n");
        }else{
            printf("no\n");
        }
    }
    return 0;
