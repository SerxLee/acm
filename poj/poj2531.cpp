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

const int M = 22;
const int INF=0x3f3f3f3f;
const int MOD=95041567,STA=8000010;
const double EPS=1e-8;
const double OO=1e15;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

int n = 0;
int max_, c, un_;
int choose[M], un_choose[M];
int net[M][M];
void dfs(int cur) {
    int temp_max;
    if (cur == n) {
        temp_max = 0;
        for (int i = 0;i < c;i++) {
            for (int j = 0;j < un_;j++) {
                temp_max += net[choose[i]][un_choose[j]];
            }
        }
        if (temp_max > max_) {
            max_ = temp_max;
            return ;
        }
    } else {
        choose[c++] = cur;
        dfs(cur+1);
        c--;
        un_choose[un_++] = cur;
        dfs(cur+1);
        un_--;
    }
}
int main(){
    cin >> n;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cin >> net[i][j];
        }
    }
    max_ = 0;
    dfs(0);
    cout << max_ << endl;
    return 0;
}