#include <stdio.h>
#include <string.h>
#define MAX 0x4f4f4f4f
int map[29][29], dis[29], mark[29];
int temp, n;
int prime(){
    int i, j, min, v;
    temp = 0;
    for(i = 1; i <= n; i++){
        dis[i] = map[1][i];
        mark[i] = 0;
    }
    mark[1] = 1;
    for(i = 1; i < n; i++){
        min = MAX;
        for(j = 1; j <= n; j++){
            if(dis[j] < min && !mark[j]){
                min = dis[j];
                v = j;
            }
        }
        mark[v] = 1;
        temp += min;
        for(j = 1; j <= n; j++){
            if(map[v][j] < dis[j])
                dis[j] = map[v][j];
        }
    }
    return 1;
}
int main(){
    char pl,plo;
    int b,i,j,x;
    while(scanf("%d" , &n) && n){
        memset(map, MAX, sizeof(map));
        for(j = 1;j <= n - 1; j++){
            getchar();
            scanf("%c%d", &pl, &b);
            for(i = 0; i < b; i++){
                getchar();
                scanf("%c%d", &plo, &x);
                map[pl-64][plo-64] = map[plo-64][pl-64]=x;
            }
        }
        prime();
        printf("%d\n", temp);
    }
    return 0;
}