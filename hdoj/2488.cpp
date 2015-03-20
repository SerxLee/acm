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

template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline void CheckMin(T &a,T b){if(a>b) a=b;}
template<class T> inline void CheckMax(T &a,T b){if(a<b) a=b;}

const int N = 250010;
const int INF=0x3f3f3f3f;
const int MOD=95041567,STA=8000010;
const double EPS=1e-8;
const double OO=1e15;
const int dx[8]={-1,1,-2,2,-2,2,-1,1};
//{-1,0,1,0};
const int dy[8]={-2,-2,-1,-1,1,1,2,2};
//{0,1,0,-1};
const int M = 12;


int p,q;
int way[M * M][3];
int vis[M][M];

bool inmap(int x, int y){
    if (x >= 0 && x < p && y >= 0 && y < q) {
        return true;
    }
    return false;
}

int dfs(int tot, int now, int x, int y){
    int xx, yy;
    if (now == tot) {
        return 1;
    }else{
        for (int i = 0; i < 8; i++) {
            xx = x + dx[i];
            yy = y + dy[i];
            if (inmap(xx, yy) && !vis[xx][yy]) {
                vis[xx][yy] = 1;
                if (dfs(tot, now + 1, xx, yy)) {
                    way[now][0]=xx;
                    way[now][1]=yy;
                    return 1;
                }
                vis[xx][yy] = 0;
            }
        }
    }
    return 0;
}

int main(){
    int n;
    cin >> n;
    for (int ii = 1; ii <= n; ii++) {
        mem(vis, 0);
        vis[0][0] = 1;
        cin >> q >> p;
        int tot = p * q;
        printf("Scenario #%d:\n", ii);
        if(dfs(tot, 1, 0, 0)){
            for (int i = 0; i < tot; i++) {
                printf("%c%d",way[i][0] + 'A', way[i][1] + 1);
            }
            printf("\n");
        }else{
            printf("impossible\n");
        }
        if (ii != n) {
            printf("\n");
        }
    }
    return 0;
}
