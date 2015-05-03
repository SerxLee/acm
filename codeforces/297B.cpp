#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string.h>

using namespace std;

char aa[200020];


int main(){
    while (scanf("%s", aa){
        int len = strlen(aa);
        int n;
        scanf("%d", &n);
        int lim;
        for (int i = 0; i < n; i++){
            scnaf("%d", &lim);
            while (lim <= len / 2){
                char lim_a;
                lim_a = aa[lim - 1];
                aa[lim - 1] = aa[len - lim];
                aa[len - lim] = lim_a;
                lim++;
//                cout << "a" << endl;
            }
                    }
        printf("%s", aa);

    }
    return 0;
}