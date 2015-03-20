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
const int dx[8]={-1,0,1,0, -1, -1, 1, 1};
const int dy[8]={0,1,0,-1, 1, -1, 1, -1};
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}

char mapp[105][105];
int n, m;

bool inmap(int x, int y){
    if (x >= 0 && x < n && y >= 0 && y < m) {
        return true;
    }
    return false;
}
void bfs(int x, int y){
    int xx, yy;
    for (int i = 0; i < 8; i++) {
        xx = x + dx[i];
        yy = y + dy[i];
        if (inmap(xx, yy) && mapp[xx][yy] == '@') {
            mapp[xx][yy] = '*';
            bfs(xx, yy);
        }
    }
}

int main(){
    while (cin >> n >> m) {
        int num = 0;
        if (n == 0 && m == 0) {
            break;
        }
        for (int i = 0; i < n; i++) {
            scanf("%s", mapp[i]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mapp[i][j] == '@') {
                    bfs(i, j);
                    num++;
                }
            }
        }
        cout << num << endl;
    }
    return 0;
}