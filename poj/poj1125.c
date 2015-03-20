#include <stdio.h>
#include <string.h>
#define INF 9999
int edge[110][110];
int n;
void floyd()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(k==i||k==j)
                continue;
                if(edge[i][j]>edge[i][k]+edge[k][j])
                edge[i][j]=edge[i][k]+edge[k][j];
            }
        }
    }
}
int main()
{
    int m,x,y;
    while(scanf("%d", &n) != EOF && n)
    {
        memset(edge,INF,sizeof(edge));
 
        for(int i=1;i<=n;i++)
        {
            scanf("%d", &m);
            for(int j=1;j<=m;j++)
            {
                scanf("%d%d", &x, &y);
                edge[i][x]=y;
            }
        }
        floyd();
        int min =INF;
        int flag=0;//
        for(int i=1;i<=n;i++)
        {
            int max=0;
            for(int j=1;j<=n;j++)
            {
                if(i == j)
                    continue;
                if(edge[i][j]>max)
                    max=edge[i][j];
            }
            if(max<min)
            {
                min=max;
                flag=i;
            }
        }
        if(min==INF)
            printf("disjoint\n");
        else
            printf("%d %d\n\n", flag, min);
    }