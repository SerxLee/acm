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

struct node{
    int x;
    int bs;
};

int vis[N+5]={0};
int n, m;
queue<node > q;

void bfs(){
    q.push({n,0});
    vis[n] = 1;
    while (!q.empty()) {
        node nex = q.front();
        q.pop();
        if (nex.x == m) {
            cout << nex.bs << endl;
            return;
        }
        for (int i = 0; i < 2; i++){
            int x;
            if (i == 0){
                x = nex.x * 2;
            }else{
                x = nex.x - 1;
            }
            if (x <= max(n, m) * 2 && x >= 0 && !vis[x]) {
                vis[x] = 1;
                q.push({x, nex.bs+1});
            }
        }
    }
    
}

int main(){
    cin >> n >> m;
    bfs();
    return 0;
}