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
#include <cctype>
#include <list>
#include <set>
#include <map>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1

const int N = 10000010;
const int M = 100010;
const int INF=0x3f3f3f3f;
const int MOD=95041567,STA=8000010;
const double EPS=1e-8;
const double OO=1e15;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline void checkmin(T &a,T b){if(a>b) a=b;}
template<class T> inline void checkmax(T &a,T b){if(a<b) a=b;}
template<class T> inline void swap1(T& a, T& b){T c(a); a = b; b = c;}

int n, k;
char map_[10][10];
int num;
int lock_x[10];
int lock_y[10];

void dd(int ans, int x){
    if (ans >= k){
        num++;
        return;
    }
    if (x >= n){
        return;
    }
    for (int i = 0; i < n; i ++){
        if (map_[x][i] == '#' && !lock_x[x] && !lock_y[i]){
            lock_y[i] = 1;
            lock_x[x] = 1;
            dd(ans + 1, x + 1);
            lock_y[i] = 0;
            lock_x[x] = 0;
        }
    }
    dd(ans, x + 1);
}

int main(){
    while (cin >> n >> k){
        if (n == -1 && k == -1){
            break;
        }
        num = 0;
        mem(lock_y, 0);
        mem(lock_x, 0);
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < n; j++){
                cin >> map_[i][j];
            }
        }
        dd(0, 0);
        printf("%d\n", num);
    }
    return 0;
}