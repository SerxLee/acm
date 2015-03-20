
#include <string.h>
#include <stdio.h>
#define INF 0xfffffff
#define N 30020

int map[N][N],vis[N],dis[N];
int n,s,e;

void dijkstra(int s){
    int i,j;
    memset(vis, 0, sizeof(vis));
    for(i = 0;i < n; i++){
        dis[i] = map[s][i];
    }
    
    dis[s] = 0;
    vis[s] = 1;
    for (i = 1;i < n; i++){
        int temp = INF;
        int u = s;
        for (j = 0;j < n; j++){
            if ((!vis[j]) && (dis[j] < temp)){
                u = j;
                temp = dis[j];
            }
        }
        vis[u]=1;
        for (j = 0; j < n; j++){
            if ((!vis[j]) &&(dis[u]+map[u][j]) < dis[j]){
                dis[j] = dis[u]+map[u][j];
            }
        }
    }
}
int main()
{
    int i, j, m;
    char str[N][20], b_str[20], a_str[20];
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                map[i][j]=INF;
            }
        }
        for (i = 0; i < n; i++) {
            scanf("%s", str[i]);
        }
        int a,b,time;
        for(i = 1; i <= m; i++)
        {
            scanf("%s%s%d", a_str, b_str, &time);

            for (i = 0; i < n; i++) {
                if (a_str[0] == str[i][0]) {
                    a = i;
                }
            }
            for (i = 0; i < n; i++) {
                if (b_str[0] == str[i][0]) {
                    b = i;
                }
            }
            if(time < map[a][b])
                map[a][b]=map[b][a] = time;
        }
        scanf("%s%s", a_str, b_str);
        for (i = 0; i < n; i++) {
            if (a_str[0] == str[i][0]) {
                s = i;
            }
        }
        for (i = 0; i < n; i++) {
            if (b_str[0] == str[i][0]) {
                e = i;
            }
        }
        dijkstra(s);
        printf("%d\n", dis[e]);
    }
    return 0;
}