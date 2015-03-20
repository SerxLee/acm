#include<stdio.h>
#include<string.h>
#define maxn 1005
char s[maxn],s1[maxn];
int a[maxn],b[maxn];
int main(){
    while(gets(s)){
        int m, t, i, j;
        int k;
        int fla;
        k = strlen(s);
        fla = 0;;
        for(i = 0; i < k; i++){
            if(s[i] == '{' || s[i] == '(' || s[i] == '['){
                s[i+1] += 32;
                break;
            }
        }
        for(i = 0; i < k; i++){
            if(s[i] == ','){
                fla = 1;
                m = i;
                break;
            }
        }
        if(!fla){
            for(i = 0; i < k; i++){
                switch (s[i]) {
                    case '{':
                        a[1] = i;
                        break;
                    case '}':
                        b[1] = i;
                        break;
                    case '(':
                        a[2] = i;
                        break;
                    case ')':
                        b[2] = i;
                        break;
                    case '[':
                        a[3] = i;
                        break;
                    case ']':
                        b[3] = i;
                        break;
                }
            }
            t = 1;
            while(t <= 3){
                for(j = a[t] + 1; j<b[t]; j++){
                    if(t == 1 && j == a[t] + 1)
                        printf("%c", s[j] - 32);
                    else
                        printf("%c",s[j]);
                }
                if(t != 3)
                    printf(" ");
                t++;
            }
            printf("\n");
        }
        else if(fla){
            for(i=0; i<m; i++){
                switch (s[i]) {
                    case '{':
                        a[1] = i;
                        break;
                    case '}':
                        b[1] = i;
                        break;
                    case '(':
                        a[2] = i;
                        break;
                    case ')':
                        b[2] = i;
                        break;
                    case '[':
                        a[3] = i;
                        break;
                    case ']':
                        b[3] = i;
                        break;
                }
            }
            t = 1;
            while(t <= 3){
                for(j = a[t] + 1; j < b[t]; j++){
                    if(t == 1 && (j == a[t] + 1))
                        printf("%c",s[j]-32);
                    else printf("%c",s[j]);
                }
                if(t != 3)
                    printf(" ");
                t++;
            }
            int cc;
            for(j = m; j < k; j++){
                if(s[j]=='{'||s[j]=='(' || s[j]=='['){
                    cc=j;
                    break;
                }
                else
                    printf("%c",s[j]);
            }
            for(i = cc; i < k; i++){
                switch (s[i]) {
                    case '{':
                        a[1] = i;
                        break;
                    case '}':
                        b[1] = i;
                        break;
                    case '(':
                        a[2] = i;
                        break;
                    case ')':
                        b[2] = i;
                        break;
                    case '[':
                        a[3] = i;
                        break;
                    case ']':
                        b[3] = i;
                        break;
                }
            }
            t = 1;
            while(t <= 3){
                for(j = a[t] + 1; j < b[t]; j++){
                    printf("%c",s[j]);
                }
                if(t != 3) printf(" ");
                t++;
            }
            printf("\n");
        }
    }
    return 0;
}