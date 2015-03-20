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

//end
typedef pair<int , int> pii;
int map_[101][101];
int vis_[101][101];
int n, m;
int a[101];
int b[101];
vector<int > e[101];

int solve(int x, pii y){
    vis_[x] = 1;
    vector<pii> v;
    for (int i = 0; i < e[x]){
    	if (!vis_[i]){
    		pii g;
    		if (!solve)
    	}
    }
}

int main(){
    int tt;
    cin >> tt;
    while (tt--){
        for (int i = 0; i < 101; i++){
            e[i].clear();
        }
        mem(map_, 0);
        mem(vis_, 0);
        mem(a, 0);
        mem(b, 0);
        cin >> n;
        int aa, bb;
        for (int i = 1; i < n; i++){
            cin >> aa >> bb;
            e[aa].push_back(bb);
            e[bb].push_back(aa);
            map_[aa][bb] = 1;
            map_[bb][aa] = 1;
        }
        cin >> m;
        for (int i = 1; i <= m; i++){
            int t;
            cin >> t;
            a[t] = i;
        }
        for (int i = 2; i <= m; i++){
            solve(a[i - 1], a[i]);
        }
    }
}
