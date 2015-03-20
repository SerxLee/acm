#include <stdio.h>
#include <string.h>

char school[12][100];

struct pop{
    char s[100][100];
    char pain[100][100];
    int sum;
}join[101];

int main(){
    int i, j, k, n, l;
    for (i = 0; i < 12; i++) {
        scanf("%s", school[i]);
    }
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        join[i].sum = 0;
    }
    for (i = 0; i < n; i++) {
        scanf("%d", &k);
        for (j = 0; j < k; j++) {
            scanf("%s : %s", join[i].s[j], join[i].pain[j]);
            if (join[i].pain[j][0] == 'g') {
                for (l = 0; l < 4; l++) {
                    if (strcmp(join[i].s[j], school[l]) == 0) {
                        join[i].sum++;
                    }
                }
            }
            if (join[i].pain[j][0] == 's') {
                for (l = 4; l < 8; l++) {
                    if (strcmp(join[i].s[j], school[l]) == 0) {
                        join[i].sum++;
                    }
                }
            }
            if (join[i].pain[j][0] == 'b') {
                for (l = 8; l < 12; l++) {

                    if (strcmp(join[i].s[j], school[l]) == 0) {
                        join[i].sum++;
                    }
                }
            }
        }
    }
    int max;
    max = 0;
    for (i = 0; i < n; i++) {
        if (join[i].sum > max) {
            max = join[i].sum;
        }
    }
    printf("%d", max * 5);
    return 0;
}