#include <stdio.h>
#include <string.h>
void kmp(char *tot, char *pth){
    int len_tot, len_pth, i, j;
    len_tot = strlen(tot);
    len_pth = strlen(pth);
    char pthd[len_pth];
    int biao[len_pth], k;
    k = len_pth - 1;
    for (i = 0; i < len_pth; i++) {
        pthd[k] = pth[i];
        k--;
    }
    for (i = 0; i < len_pth - 1; i++) {
        int yy = 0;
        for (j = 0; j <= i; j++) {
            if (pthd[j] == pth[j]) {
                yy++;
            }
        }
        if (yy == i + 1) {
            biao[i] = yy;
        }else{
            biao[i] = 0;
        }
    }
}