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

const int N = 100010;
const int M = 100010;
const int INF=0x3f3f3f3f;
const int MOD=95041567,STA=8000010;

double EPS=1e-8;
const double OO=1e15;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline void checkmin(T &a,T b){if(a>b) a=b;}
template<class T> inline void checkmax(T &a,T b){if(a<b) a=b;}

int dp[10][2];
int dig[10];
int m , n;

int fs(int pos, bool six, bool all){
    printf("%d %d %d\n", pos, six, all);
    int ans = 0;
    if (pos == 0){
        return 1;
    }
    if (!all && dp[pos][six] != -1){
        return dp[pos][six];
    }
    int u = all? dig[pos]: 9;
//    printf("%d ", u);
    for (int i = 0; i <= u;i++){
        if ((six && i == 2) || i == 4)
            continue;
        int flag1 = 0;
        if (i == 6) flag1 = 1;
        ans += fs(pos - 1, flag1 , all && i == u);
    }
    return ans;
}

int f(int n){
    mem(dp, -1);
    int len = 0;
    while (n){
        dig[++len] = n % 10;
        n = n / 10;
    }
    return fs(len, 0, 0);
}

int main(){
    while (cin >> n >> m && n && m){
        cout << f(m) << endl;
    }
    return 0;
}