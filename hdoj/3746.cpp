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

const int N = 100042;
const int INF=0x3f3f3f3f;
const int MOD=95041567,STA=8000010;
const double EPS=1e-8;
const double OO=1e15;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

int T, len, pd, p[N], j;
char str[N];

int main(){
    cin >> T;
    while (T--) {
        scanf("%s", str + 1);
        len = strlen(str + 1);
        p[1] = 0;
        j = 0;
        for (int i = 2; i <=  len ; i++) {
            while (j > 0 && str[j + 1] != str[i]) {
                j = p[j];
            }
            p[i]  = str[j + 1] == str[i] ? ++j: j;
        }
        pd = len - p[len];
        printf("%d\n", p[len]? (pd - p[len]%pd)%pd : pd);
    }
    return 0;
}