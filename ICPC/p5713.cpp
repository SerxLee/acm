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
#define maxn  1005
const int INF=0x3f3f3f3f;

template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline void CheckMin(T &a,T b){if(a>b) a=b;}
template<class T> inline void CheckMax(T &a,T b){if(a<b) a=b;}

struct note{
    int x,y,z;
}p[maxn];

double a[maxn][maxn], lu[maxn];
int lim[maxn], n, vis[maxn];
double mlu[maxn][maxn];
int flag[maxn][maxn];

double prim(){
    int u = 1;
    double sum = 0;
    memset(vis,0,sizeof(vis));
    memset(mlu,0,sizeof(mlu));
    memset(flag, 0, sizeof(flag));
    for (int i = 1; i <= n; i++){
        lu[i] = a[u][i];
        lim[i] = u;
    }
    vis[u]=1;
    for (int i = 1; i < n; i++) {
        double minn = INF;
        int v =- 1;
        for (int j=1; j <= n; j++){
            if (!vis[j] && lu[j] < minn){
                v = j;
                minn = lu[j];
            }
        }
        sum += lu[v];
        vis[v] = 1;
        flag[v][lim[v]] = flag[lim[v]][v] = 1;
        for (int k = 1; k <= n; k++){
            if (vis[k] && k != v){
                mlu[v][k] = mlu[k][v] = Max(mlu[k][lim[v]], lu[v]);
            }
            if (!vis[k] && a[v][k] < lu[k]){
                lu[k] = a[v][k];
                lim[k] = v;
            }
        }
    }
    return sum;
}

double ce(int x,int y,int u,int v){
    return sqrt((x - u) * (x - u) + (y - v) * (y - v));
}

int main(){
    int T;
    cin >> T;
    while (T--){
        double sum, ans;
        cin >> n;
        for ( int i = 1; i <= n; i++){
            cin >> p[i].x >> p[i].y >> p[i].z;
        }
        for (int i = 1; i <= n; i++){
            a[i][i] = 0;
            for (int j = i + 1; j <= n; j++){
                a[i][j] = a[j][i] = ce(p[i].x, p[i].y, p[j].x, p[j].y);
            }
        }
        sum = prim();
        ans = -1;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++){
                if (flag[i][j]){
                    ans = Max(ans, (p[i].z + p[j].z) / (sum - a[i][j]));
                }else{
                    ans = Max(ans,(p[i].z + p[j].z) / (sum - mlu[i][j]));
                }
            }
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}