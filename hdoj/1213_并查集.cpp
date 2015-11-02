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
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int N = 20100;
const int INF = 0x3f3f3f3f;
const int MOD = 95041567,STA = 8000010;
const double EPS = 1e-8;
const double OO = 1e15;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline T Min(T a,T b){return a < b ? a : b;}
template<class T> inline T Max(T a,T b){return a > b ? a : b;}

//用  递归  搜寻父亲

int n, m;
int father[1005];

int getfather(int v){    //路径压缩（采用递归的方式压缩路径， 但是，递归压缩路径可能会造成溢出栈）
    if (father[v] == v)
        return v;
    return father[v] = getfather(father[v]);
}

int getfather(int v){   //路径压缩，非递归方式
    int k, j ,r;
    r = v;
    while (r != father[r]) {
        r = father[r];
    }
    k = v;
    while (k != r) {
        j = father[k];
        father[k] = r;
        k = j;
    }
    return r;
}


void judge(int x,int y){                        //合并
    int fx,fy;
    fx = getfather(x);
    fy = getfather(y);
    if (fx == fy)
        return;
    father[fx] = fy;
}

int main(){
    int t, i ,k , a, b;
    scanf("%d", &t);
    while (t--) {
        k = 0;
        for (i = 1; i <= 1005; i++) father[i] = i;
        scanf("%d%d", &n, &m);
        for (i = 1; i <= m; i++) {
            scanf("%d%d", &a, &b);
            judge(a, b);
        }
        for (i = 1; i <= n; i++) {
            if(father[i] == i)
                k++;
        }
        printf("%d\n", k);
    }
    return 0;
}