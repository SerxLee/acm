// popular cow 

#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const int N = 10105;

vector<int> g[N];
stack<int> s;

int Bcnt;
int n, m;
int stop;
int Dindex;
int dfn[N], low[N], belong[N];
bool vis[N];
int num[N];

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
            vis[p] = false;
            belong[p] = Bcnt;
            s.pop();
            num[Bcnt]++;
            if (p == i) {
                break;
            }
        }
    }
}
int out[N];
int pan, sum;
void solve(){
    int i, j, a, b;
    sum = 0;
    stop = Bcnt = Dindex = 0;
    mem(dfn, 0);
    mem(belong, 0);
    mem(low, 0);
    mem(vis, false);
    mem(out, 0);
    mem(num, 0);
    for (i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for (i = 1; i <= n;i++) {
        for (j = 0; j < g[i].size(); j++) {
            a = belong[i];
            b = belong[g[i][j]];
            if (a != b) {
                out[a] = 1;
            }
        }
    }
    pan = 0;
    for (i = 1; i <= Bcnt; i++) {
        if (!out[i]) {
            sum++;
            pan = i;
        }
    }
}

int main(){
    int i, x, y;
    while(scanf("%d%d", &n,&m) != EOF){
        for (i = 0; i < N; i++) {   //初始化多次错误。。。。。。。。。。。。。。。。。。。
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
        
        if (sum == 1) {
            printf("%d\n", num[pan]);
        }else{
            printf("0\n");
        }
    }
    return 0;
}