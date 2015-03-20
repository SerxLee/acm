#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <cassert>
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
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int N = 102;
const int INF = 0x3f3f3f3f;
const int MOD = 95041567,STA = 8000010;
const double EPS = 1e-8;
const double OO = 1e15;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline T Min(T a,T b){return a < b ? a : b;}
template<class T> inline T Max(T a,T b){return a > b ? a : b;}


//

struct node{
    int k_d;
    int p_d;
    int v_d;
} a[15][104];

int pa[15];
int k, n, m;
int dp[21][10010];

int main(){
    while (~scanf("%d%d%d", &n, &m ,&k)) {
        memset(dp, -1, sizeof(dp));
        memset(pa, 0, sizeof(pa));
        int t;
        for (int i = 0; i < n; i++) {
            scanf("%d", &t);
            scanf("%d%d", &a[t][pa[t]].p_d, &a[t][pa[t]].v_d);
            pa[t]++;
        }
        memset(dp[0], 0, sizeof(dp[0]));
        for(int i = 1; i <= k; i++){
            for(int j = 0; j < pa[i]; j++){
                for(int l = m; l >= a[i][j].p_d; l--){
                    if(dp[i][l - a[i][j].p_d] != -1){
                        dp[i][l] = Max(dp[i][l], dp[i][l - a[i][j].p_d] + a[i][j].v_d);
                    }
                    if(dp[i - 1][l - a[i][j].p_d] != -1){
                        dp[i][l] = Max(dp[i][l], dp[i - 1][l - a[i][j].p_d] + a[i][j].v_d);
                    }
                }
            }
        }
        if(dp[k][m] < 0){
            printf("Impossible\n");
        }else{
            printf("%d\n",dp[k][m]);
        }
    }
    return 0;
}