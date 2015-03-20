/*
HDOJ 2433 最短路SPAF 
用sum[i]来存以i为起点的最短路之和，ans表示i从1到n的sum[i]的和，
然后摧毁道路之后，以u为起点，看能不能到达v，如果能到达，
同时也就说明了以v为起点也能到达u，因为路是双向的，
则以u，v为起点，保存它们的最短路之和，答案就是ans-sum[u]-sum[v]+num1+num2；
若不能到达，则直接输出INF。
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
#define maxn 105
#define INF 99999999
#define LL long long
using namespace std;
 
struct Edge
{
    int from,to,len;
    int next;
}edge[maxn*60];
int n,m,k;
int sum[maxn],vis[maxn],dis[maxn];
int head[maxn*30],u[maxn*30],v[maxn*30];
 
void AddEdge(int u,int v)
{
    edge[k].from=u;
    edge[k].to=v;
    edge[k].len=1;
    edge[k].next=head[u];
    head[u]=k++;
 
    edge[k].from=v;
    edge[k].to=u;
    edge[k].len=1;
    edge[k].next=head[v];
    head[v]=k++;
}
 
int SPFA(int s)
{
	queue<int> q;
    for(int i=0;i<=n;i++)
    {
        dis[i]=INF;
        vis[i]=0;
    }
    dis[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].to;
            if(dis[v]>dis[u]+edge[i].len)
            {
                dis[v]=dis[u]+edge[i].len;
                if(vis[v]==0)
                {
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    int Sum=0;
    for(int i=1;i<=n;i++)
        Sum+=dis[i];
    return Sum;
}
 
int main(){
	int ans; 
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(sum,0,sizeof(sum));
    	memset(head,-1,sizeof(head));
		k=1;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&u[i],&v[i]);
            AddEdge(u[i],v[i]);
        }
        ans=0;
        for(int i=1;i<=n;i++)
        {
            sum[i]=SPFA(i);
            ans+=sum[i];
        }
        for(int i=1;i<=m;i++)
        {
            edge[i*2-1].len=INF;
			edge[i*2].len=INF;//删除对应边 1 2
			 
            int num1=SPFA(u[i]);
            if(dis[v[i]]>=INF)
                printf("INF\n");
            else
            {
                int num2=SPFA(v[i]);
                printf("%d\n",ans + num1 + num2 - sum[u[i]]-sum[v[i]]);
            }
            //回溯 
            edge[i*2].len=1;
            edge[i*2-1].len=1;
        }
    }
    return 0;
}