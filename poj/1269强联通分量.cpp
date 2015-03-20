#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
#define N 10005

vector<int> g[N];
stack<int>s;
int Bcnt;
int n, m;
int Stop;
int Dindex;
int dfn[N];
bool vis[N];
int belong[N];
int low[N];

void tarjan(int i){
    int j;
    dfn[i] = low[i] = ++Dindex;
    vis[i] = true;
    s.push(i);
    for (j = 0; j < g[i].size(); j++){
        int v = g[i][j];
        if (!dfn[v]){
            tarjan(v);
            if (low[v] < low[i])
                low[i] = low[v];
        }
        else if (vis[v] && dfn[v] < low[i])
            low[i] = dfn[v];
    }
    if (dfn[i] == low[i]){
        Bcnt++;
        int p;
        while(1){
            p = s.top();
            vis[j] = false;
            belong[j] = Bcnt;
            s.pop();
            if (p == i) {
                break;
            }
        }
    }
    return;
}

void solve(){
    int i;
    Stop = Bcnt = Dindex = 0;
    memset(dfn,0,sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(belong, 0, sizeof(belong));
    memset(vis, false, sizeof(vis));
    for (i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
}

int main(){
    int i, x, y;
    while (~scanf("%d%d", &n, &m)) {
        if (n == 0 && m == 0) {
            break;
        }
        for (i = 0; i < N; i++) {
            g[i].clear();
        }
        while (!s.empty()) {
            s.pop();
        }
        for (i = 0; i < m; i++) {
            scanf("%d%d", &x, &y);
            g[x].push_back(y);
        }
        solve();
        puts(Bcnt == 1? "Yes": "No");
    }
}