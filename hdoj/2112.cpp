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

const int N = 155;
const int INF=0x3f3f3f3f;
const int MOD=95041567,STA=8000010;
const double EPS=1e-8;
const double OO=1e15;
const int dx[8]={-1,0,1,0};
const int dy[8]={0,1,0,-1};
const int M = 12;

//end

map<string, int> mapp;
int n;
int w[N][N];
int vis[N];
int dis[N];
int flag;
char str_start[N], str_end[N];

void dijkstra(int s, int cnt){
    int i,j;
    memset(vis, 0, sizeof(vis));
    for(i = 0;i < cnt; i++){
        dis[i] = w[s][i];
    }
    dis[s] = 0;
    vis[s] = 1;
    for (i = 1;i < cnt; i++){
        int temp = INF;
        int u = s;
        for (j = 1;j < cnt; j++){
            if ((!vis[j]) && (dis[j] < temp)){
                u = j;
                temp = dis[j];
            }
        }
        vis[u] = 1;
        for (j = 1; j < cnt; j++){
            if ((!vis[j]) &&(dis[u] + w[u][j]) < dis[j]){
                dis[j] = dis[u] + w[u][j];
            }
        }
    }
}

void init(){
    mem(vis, 0);
    mem(dis, 0);
    mem(w, INF);
    flag = 0;
}

int main(){
    while (cin >> n && n != -1) {
        int cnt;
        init();
        mapp.clear();
        scanf("%s%s", str_start, str_end);
        if (!strcmp(str_start, str_end)) {
            flag = 1;
        }
        mapp[str_start] = 1;
        mapp[str_end] = 2;
        cnt = 3;
        int di;
        char str1[N], str2[N];
        for (int i = 0; i < n; i++) {
            scanf("%s%s%d", str1, str2, &di);
            if (!mapp[str1]) {
                mapp[str1] = cnt++;
            }
            if (!mapp[str2]) {
                mapp[str2] = cnt++;
            }
            if (w[mapp[str1]][mapp[str2]] > di) {
                w[mapp[str1]][mapp[str2]] = w[mapp[str2]][mapp[str1]] = di;
            }
        }
        if (flag) {
            printf("0\n");
            continue;
        }
        dijkstra(1, cnt);
        if (dis[2] == INF) {
            printf("-1\n");
        }else{
            printf("%d\n", dis[2]);
        }
    }
    return 0;
}