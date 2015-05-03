#include <stdio.h>
#include <string.h>
#define MINUSINF 0x80000000
#define MAXN 100
#define MAXV 1000
int max(int a,int b)
{
    return a>b?a:b;
} 
//n件物品和一个容量为v的背包。第i件物品的费用是c[i]，价值是w[i]，装满与否要求为full
//算法1：经典DP二维数组解法，时间复杂度及空间复杂度均为O(nv) 
int ZeroOnePack1(int n,int v,int c[],int w[],int full)
{
    int i,j;
    int f[MAXN][MAXV];
    if(full)
    {
        for(i=0;i<=n;i++)
            for(j=0;j<=v;j++) 
                f[i][j]=MINUSINF;
        f[0][0]=0;
    } 
    else memset(f,0,sizeof(f));
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=v;j++)
        {
            if(j>=c[i])
                f[i][j]=max(f[i-1][j],f[i-1][j-c[i]]+w[i]);
            else f[i][j]=f[i-1][j];
        }
    }
    if(f[n][v]<0) return -1;
    else return f[n][v];
}