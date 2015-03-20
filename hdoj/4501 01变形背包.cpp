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
#include <map>
using namespace std;
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define PI acos(-1.0)
const int N=110;
const int INF=0x3f3f3f3f;
const int MOD=95041567,STA=8000010;
const double EPS=1e-8;
const double OO=1e15;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
const int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
inline int sign(double x){return (x>EPS)-(x<-EPS);}
template<class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T> T lcm(T a,T b){return a/gcd(a,b)*b;}
template<class T> inline T lcm(T a,T b,T d){return a/d*b;}
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline T Min(T a,T b,T c){return min(min(a, b),c);}
template<class T> inline T Max(T a,T b,T c){return max(max(a, b),c);}
template<class T> inline T Min(T a,T b,T c,T d){return min(min(a, b),min(c,d));}
template<class T> inline T Max(T a,T b,T c,T d){return max(max(a, b),max(c,d));}
//End

struct node{
    int a;
    int b;
    int val;
} aaa[110];

int dp[55][110][110];

int main(){
    int n, v1, v2, k;

    node lim;
    while (cin >> n >> v1 >> v2 >> k) {
        mem(dp, 0);
        for (int i = 1; i <= n; i++) {
            cin >> lim.a >> lim.b >> lim.val;
            aaa[i] = lim;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = k; j >= 0; j--) {
                for (int l = v1; l >= 0; l--) {
                    for (int t = v2; t >= 0; t--) {
                        int max = 0;
                        if (j >= 1) {
                            max = Max(max, dp[j - 1][l][t] + aaa[i].val);
                            
                        }
//                        cout << dp[j][l][t]  << "aa" << endl;
                        if (l >= aaa[i].a) {
                            max = Max(max, dp[j][l - aaa[i].a][t] + aaa[i].val);
                            
                        }
                        

//                        cout << dp[j][l][t]  << "bb" << endl;

                        if (t >= aaa[i].b) {
                            max = Max(max, dp[j][l][t - aaa[i].b] + aaa[i].val);
                            

                        }
                        dp[j][l][t] = Max(dp[j][l][t], max);
//                        cout << dp[j][l][t]  << "cc" << endl;
                        
                    }
                }
            }
        }
        printf("%d\n", dp[k][v1][v2]);
    }
    return 0;
}
