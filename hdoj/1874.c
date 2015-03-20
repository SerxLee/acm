#include <string.h>
#include <stdio.h>
#define INF 0xfffffff
#define N 201
int map[N][N],vis[N],dis[N];
int n,s,e;

void Dijkstra(){
    int i,j;
    for(i = 0; i < n; i++)
    {
        dis[i] = map[s][i];   //将各地到起始位置的距离存至dis数组
        vis[i] = 0;
    }
    dis[s] = 0;
    for(i = 0; i < n; i++){
        int tmp = INF;
        int k;
        for(j = 0; j < n; j++){
            if(!vis[j] && dis[j] < tmp){ //找出到起始位置最短的一条路径
                tmp = dis[j];
                k = j;
            }
        }
        vis[k] = 1; //标记
        for(j = 0; j < n; j++)
        {
            if(!vis[j] && dis[j] > dis[k] + map[k][j])
                dis[j] = dis[k] + map[k][j];
        }
    }
    if(dis[e] != INF)
        printf("%d\n", dis[e]);
    else
        printf("-1\n");
}
int main()
{
    int i,j,m;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                map[i][j]=INF;
            }
        }
        int a,b,time;
        for(i = 1; i <= m; i++)
        {
            scanf("%d%d%d", &a, &b, &time);
            if(time < map[a][b])
                map[a][b]=map[b][a]=time;    //判断并给出a，b两地所花最短时间
        }
        scanf("%d%d", &s, &e);
        Dijkstra();
    }
    return 0;
}