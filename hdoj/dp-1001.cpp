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


int pri[N], wei[N], num[N], dp[N];

int main(){
    int t, n, m;
    scanf("%d", &t);
    while (t--) {
        mem(dp, 0);
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &pri[i], &wei[i], &num[i]);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < num[i]; j++) {
                for (int l = 1; l <= n; l++) {
                    dp[l] = Max(dp[l], dp[l - pri[i]] + wei[i]);
                }
            }
        }
        printf("%d\n", dp[n]);
    }
    return 0;



// ===========================================================

    
struct node{
    int pri;
    int wei;
    int num;
} a[N] ;

int dp[N];

int main(){
    int t, n, m;
    scanf("%d", &t);
    while (t--) {
        mem(dp, 0);
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &a[i].pri, &a[i].wei, &a[i].num);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < a[i].num; j++) {
                for (int l = 1; l <= n; l++) {
                    dp[l] = Max(dp[l], dp[l - a[i].pri] + a[i].wei);
                }
            }
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}