#include<stdio.h>
#define MAX 100010

int f[MAX];
int c[MAX];
int t;

void chu()
{
    int i;
    for(i = 1;i < MAX; i++)
    {
        f[i] = i;
        c[i] = 0;
    }
}

//查找
int find1(int a)
{
    int r = a;
    while(f[r] != r)
        r = f[r];
    return r;
}

//压缩
void find2(int a)
{
    int i,j,r;
    r = a;
    while(f[r]!=r)
        r=f[r];
    i=a;
    while(i!=r)
    {
        j = f[i];
        f[i] = r;
        i = j;
    }
}

void merge(int a,int b){
    int A, B;
    A = find1(a);
    B = find1(b);
    if(A == B)
        t = 0;
    else
        f[A] = B;
}
int main(){
    int i,a,b,p;
    while(scanf("%d%d", &a, &b) && a != -1){
        chu();
        p = 0;
        t = 1;
        if(a == 0 && b == 0){
            printf("Yes\n");
            continue;
        }
        while(a != 0){
            if(t){
                merge(a,b);
                c[a] = c[b] = 1;
            }
            scanf("%d%d",&a,&b);
        }
        for(i = 0; i < MAX; i++)
            if(c[i])
                find2(i);
        for(i = 0;i < MAX; i++)
            if(c[i])
                if( find1(i) == i)
                    p++;
        if(p == 1 && t)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}