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


const int N = 20000;
const int INF=0x3f3f3f3f;
const int MOD=95041567,STA=8000010;
const double EPS=1e-8;
const double OO=1e15;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
const int M = 12;

int ans[250];

inline int tr(char a) {
    if (a <= 'z' && a >= 'a') {
        return a - 'a' + 10;
    }
    return a - '0';
}

inline char dtr(int a) {
    if (a >= 10) {
        return a + 'a' - 10;
    }
    return a + '0';
}

int main() {
    int n, b;
    char a[300];
    while (scanf("%d %d", &n, &b) != EOF) {
        memset(ans, 0, sizeof(ans));
        while (n--) {
            scanf("%s", a);
            int p = 0;
            int sl = strlen(a);
            for (int i = sl - 1; i >= 0; i--) {
                ans[p] += tr(a[i]);
                ans[p] %= b;
                p++;
            }
        }
        int i;
        for (i = 220; i >= 0 && ans[i] == 0; i--) {}
        if (i < 0) {
            cout << 0 << endl;
        } else {
            for (int j = i; j >= 0; j--) {
                putchar(dtr(ans[j]));
            }
            putchar('\n');
        }
    }
}
