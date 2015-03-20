#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <cctype>
#include <list>
#include <set>
#include <map>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))

const int N = 1010;
const int INF=0x3f3f3f3f;


//end

int map_[N][N], dis[N], vis[N];
int n, m ,start, end, ans;

void dijkstra(int s){
    int i,j;
    memset(vis, 0, sizeof(vis));
    for(i = 0;i < n; i++){
        dis[i] = map_[s][i];
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
            if ((!vis[j]) && (dis[u] + map_[u][j]) < dis[j]){
                dis[j] = dis[u] + map_[u][j];
            }
        }
    }
}

int main(){
    int a, b, c;
    while (cin >> n >> m >> start >> end){
        mem(map_, INF);
        for (int i = 0; i < m; i++){
            cin >> a >> b >> c;
            if (map_[a - 1][b - 1] != INF) {
                if (map_[a - 1][b - 1] > c) {
                    map_[a - 1][b - 1] = c;
                    map_[b - 1][a - 1] = c;
                }else{
                    continue;
                }
            }else{
                map_[a - 1][b - 1] = c;
                map_[b - 1][a - 1] = c;
            }
        }
        dijkstra(start - 1);
        cout << dis[end - 1] << endl;
    }
    return 0;
}
