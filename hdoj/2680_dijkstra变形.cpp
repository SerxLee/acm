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
#include <list>
#include <set>
#include <map>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define PI 3.14159265359

template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline void CheckMin(T &a,T b){if(a>b) a=b;}
template<class T> inline void CheckMax(T &a,T b){if(a<b) a=b;}

const int N = 1010;
const int INF=0x3f3f3f3f;
const int MOD=95041567,STA=8000010;
const double EPS=1e-8;
const double OO=1e15;
const int dx[8]={-1,0,1,0};
const int dy[8]={0,1,0,-1};

//end

int dis[N];
int n, m, s, w;
int bet[N][N];
int start[N];
int vis[N];
int ans;

void dijkstra(){
    int i,j, mark;
    memset(vis, 0, sizeof(vis));
    for(i = 0;i <= n; i++){
        dis[i] = INF;
    }
    dis[0] = 0;
    vis[0] = 1;
    for (i = 0;i <= n; i++){
        
        int temp = INF;
        mark = 0;
        
        for (j = 0;j <= n; j++){
            if ((!vis[j]) && (dis[j] < temp)){
                mark = j;
                temp = dis[j];
            }
        }
        vis[mark] = j;
        
        for (j = 0; j <= n; j++){
            if ((!vis[j]) &&(dis[mark] + bet[mark][j]) < dis[j]){
                dis[j] = dis[mark] + bet[mark][j];
            }
        }
    }
}

int main(){
    while (cin >> n >> m >> s) {
        mem(bet, INF);
        mem(start, 0);
        int ss, ee = 0, ww;
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &ss, &ee, &ww);
            if (bet[ss][ee] > ww) {
                bet[ss][ee] = ww;
            }
        }
        cin >> w;
        int lim;
        for (int i = 0; i < w; i++) {
            scanf("%d", &lim);
            bet[0][lim] = 0;
        }
        dijkstra();
        if (dis[s] == INF) {
            printf("-1\n");
        }else{
            printf("%d\n", dis[s]);
        }
    }
    return 0;
}