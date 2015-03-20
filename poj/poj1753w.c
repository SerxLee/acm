#include <stdio.h>
#include <string.h>

int b, w, chang, min;
int a[17];

void up(int i){
    if (i - 4 >= 0) {
        if (a[i - 4] == 0) {
            a[i - 4] = 1;
            b++;
            w--;
        }else{
            a[i - 4] = 0;
            w++;
            b--;
        }
    }
}

void down(int i){
    if (a[i + 4] <= 16) {
        if (a[i + 4] == 0) {
            a[i + 4] = 1;
            b++;
            w--;
        }else{
            a[i + 4] = 0;
            w++;
            b--;
        }
    }
}

void left(int i){
    if (i % 4 != 0) {
        if (a[i - 1] == 0) {
            a[i - 1] = 1;
            b++;
            w--;
        }else{
            a[i - 1] = 0;
            w++;
            b--;
        }
    }
}

void right(int i){
    if ((i + 1) % 4 != 0) {
        if (a[i + 1] == 0) {
            a[i + 1] = 1;
            b++;
            w--;
        }else{
            a[i + 1] = 0;
            w++;
            b--;
        }
    }
}

int main (){
    char s[5];
    int i, j, t;
    while (scanf("%s", s) != EOF) {
        memset(a, 0, sizeof(a));
        b = 0;
        w = 0;
        chang = 0;
        t = 0;
        for (i = 0; i < 4; i++) {
            if (s[i] == 'b') {
                b++;
                a[i] = 1;
            }else if (s[i] == 'w'){
                w++;
            }
        }
        for (i = 1; i < 4; i++) {
            scanf("%s", s);
            for (j = 0; j < 4; j++) {
                if (s[j] == 'b') {
                    b++;
                    a[4 * i + j] = 1;
                }else if (s[j] == 'w'){
                    w++;
                }
            }
        }
        while (t == 0) {
            if (chang == 0 && (b == 0 || w == 0)) {
                min = chang;
                t = 1;
            }else{
                for (i = 0; i < 16; i++) {
                    if (a[i] == 0) {
                        a[i] = 1;
                        b++;
                        w--;
                    }else{
                        w++;
                        b--;
                    }
                    up(i);
                    down(i);
                    left(i);
                    right(i);
                    chang++;
                    if (b == 0 || w == 0) {
                        min = chang;
                        break;
                    }
                }
            }
        }
        printf("%d\n", min);
    }
}