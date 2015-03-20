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

const int N = 33;
const int INF=0x3f3f3f3f;
const int MOD=95041567,STA=8000010;
const double EPS=1e-8;
const double OO=1e15;
const int dx[] = {-1,1,0,0,0,0};
const int dy[] = {0,0,-1,1,0,0};
const int dz[] = {0, 1};

template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline void checkmin(T &a,T b){if(a>b) a=b;}
template<class T> inline void checkmax(T &a,T b){if(a<b) a=b;}
template<class T> inline void swap1(T& a, T& b){T c(a); a = b; b = c;}

int a;

void bfs(){
    __int64_t x = 1, pos;
    queue< __int64_t> qq;
    qq.push(x);
    while (!qq.empty()) {
        pos = qq.front();
        qq.pop();
        for (int i = 0; i < 2; i ++){
            x = pos * 10 + i;
            if (x % a == 0) {
                cout << x << endl;
                return;
            }
            qq.push(x);
        }
    }
}

int main(){
    while (cin >> a && a) {
        if(a==1)
        {
            cout<<"1"<<endl;
            continue;
        }
        bfs();

    }
    return 0;
}