#include<cstdio>
#include<iostream>
#include<cstring>
#define INF 0x3f3f3f3f
using namespace std;

double edge[1010][1010];
double dis[1010];
bool vis[1010];
int n;

void dij(int x)
{
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));   //每次标记数组都要清零。

    for(int i=1;i<=n;i++)
    {
        dis[i]=edge[x][i];
    }

    vis[x]=true;
    int u=x;
    for(int i=1;i<n;i++)
    {
        double mm=0;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j] && dis[j] > mm)
            {
                mm=dis[j];
                u=j;
            }
        }

        vis[u]=true;

        for(int j=1;j<=n;j++)
        {
            if(!vis[j] && edge[u][j]*dis[u] > dis[j])
                dis[j] = edge[u][j]*dis[u];
        }
    }
}

int main()
{
    int m,x,y;
    while(scanf("%d",&n)!=EOF)
    {
        memset(edge,0,sizeof(edge));

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%lf",&edge[i][j]);
            }
        }

        scanf("%d",&m);
        for(int k=0;k<m;k++)
        {
            scanf("%d%d",&x,&y);
            dij(x);
            if(dis[y]==0)
                printf("What a pity!\n");
            else
                printf("%.3lf\n",dis[y]);
        }
    }
    return 0;
}