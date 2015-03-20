#include <stdio.h>
#include <string.h>
int index_KMP(char *s,char *t,int pos);
void get_next(char *t,int *);

char s[20002];
char t[50][22];
int next[22];
int pos=0;

int main(){
    int n, m, i, mm, tt;
    scanf("%d", &tt);
    while (tt--) {
        
    mm = 1;
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%s", t[i]);
    }
    scanf("%s", s);
    for (i = 0; i < m; i++) {
        get_next(t[i], next);
        n = index_KMP(s,t[i],pos);
        if (n != 0) {
            mm = 0;
        }
    }
    if (mm == 1) {
        printf("not infected\n");
    }else{
        printf("infected\n");
    }
    }
    return 0;
}

int index_KMP(char *s,char *t,int pos)
{
    int i=pos,j=1;
    while (i <= (int)strlen(s) && j<=(int)strlen(t))
    {
        if (j==0||s[i]==t[j-1])
        {
            i++;
            j++;
        }
        else j=next[j];
    }
    if (j>(int)strlen(t))
        return i-strlen(t) + 1;
    else
        return 0;
}

void get_next(char *t,int *next)
{
    
    int i=1,j=0;
    next[0]=next[1]=0;
    while (i<(int)strlen(t))
    {
        if (j==0||t[i]==t[j])
        {
            i++;
            j++;
            next[i]=j;
        }
        else j=next[j];
    }
    
}