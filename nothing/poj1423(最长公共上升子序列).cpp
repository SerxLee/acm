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
const int N = 101000;
const int INF=0x3f3f3f3f;
const int MOD=95041567,STA=8000010;
const double EPS=1e-8;
const double OO=1e15;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}

int a[N], b[N];
int f[N];
int main(){
    int T, n, m;
    cin >> T;
    while (T--) {
        mem(f, 0);
        cin >> n;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        cin >> m;
        for (int i = 1; i <= m; i++) {
            scanf("%d", &b[i]);
        }
        for (int i = 1; i <= n; i++) {
            int max = 0;
            for (int j = 1; j <= m; j++) {
                if (a[i] > b[j] && f[j] > max) {
                    max = f[j];
                }else if(a[i] == b[j] && f[j] < max + 1){
                    f[j] = max + 1;
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = Max(ans, f[i]);
        }
        cout << ans << endl;
        if (T != 0) {
            printf("\n");
        }
    }
    return 0;
}