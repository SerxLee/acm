#include <stdio.h>
#include <string.h>
#define N 3500
#define M 13000
int d[N],w[N],val[M],n,W;
 
void knapsack()
{
    int i,j;
    memset(val,0,sizeof(val));
    for(i=1;i<=n;i++)
        for(j=W;j>=1;j--)
        {
            if(j>=w[i]&&val[j-w[i]]+d[i]>val[j])
                val[j]=val[j-w[i]]+d[i];
        }
    return ;
}
 
int main()
{
    int i;
    while(scanf("%d%d",&n,&W)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%d%d",&w[i],&d[i]);
        knapsack();
        printf("%d\n",val[W]);
    }
    return 0;
}