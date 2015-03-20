#include <stdio.h>
#include <string.h>
#define MAX 0x4f4f4f4f
int n;
char str[2005][8];
int map[2005][2005], visited[2005], low[2005];
int prim(){
    int i,j,pos,min,result = 0;
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
                pos=j;
            }
        result += min;
        visited[pos] = 1;
        for(j = 2; j <= n; j++)
            if(visited[j] == 0 && low[j] > map[pos][j])
                low[j] = map[pos][j];
    }
    return result;
}
int main(){
    int i, j, sum, l;
    while (scanf("%d", &n) != EOF && n){
        memset(map, MAX, sizeof(map));
        for (i = 1; i <= n; i++) {
            scanf("%s", str[i]);
            for (j = i - 1; j > 0; j--) {
                sum = 0;
                for (l = 0; l < 7; l++)
                    if (str[i][l] != str[j][l])
                        sum++;
                map[i][j] = map[j][i] = sum;
            }
        }
        printf("The highest possible quality is 1/%d.\n", prim());
    }
    return 0;
}