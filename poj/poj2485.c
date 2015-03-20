#include <stdio.h>
#include <string.h>
#define MAX 0x4f4f4f4f
#define N 505
int n;
int str[N][N];
int map[N][N], visited[N], low[N];
int prim(){
    int i, j, pos, min, max;
    memset(visited,0,sizeof(visited));
    visited[1] = 1;
    pos = 1;
    for(i = 2; i <= n; i++)
        low[i] = map[pos][i];
    for(i = 1; i < n; i++){
        min = MAX;
        for(j = 2; j <= n; j++)
            if(visited[j] == 0 && min > low[j]){
                min = low[j];
                pos = j;
            }
        visited[pos] = 1;
        for(j = 2; j <= n; j++)
            if(visited[j] == 0 && low[j] > map[pos][j])
                low[j] = map[pos][j];
        max = low[j];
        for (j = 2; j <= n; j++)
            if (low[j] > max)
                max = low[j];
    }
    return max;
}
int main(){
    int t, i, j;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++) {
                scanf("%d", &str[i][j]);
                map[i][j] = str[i][j];
            }
        printf("%d\n", prim());
    }
    return 0;
}