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
const int N = 10000005;
const int INF = 0x3f3f3f3f;
const int MOD = 95041567,STA = 8000010;
const double EPS = 1e-8;
const double OO = 1e15;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline T Min(T a,T b){return a < b ? a : b;}
template<class T> inline T Max(T a,T b){return a > b ? a : b;}

int father[N];
int sum[N];

int getfather(int v){   //路径压缩，非递归方式
    int k, j ,r;        //Accepted    1213    0MS 296K    1818 B  G++ Serx......Lee
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

void mager(int a, int b){
    int x, y;
    x = getfather(a);
    y = getfather(b);
    if(x != y)
    {
        father[x] = y;
        sum[y] += sum[x];   //重点地方，WR 了 N 次
    }
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF) {
        for(int i = 1;i <= N; i++){
            sum[i] = 1;
            father[i] = i;
        }
        while(n--)
        {
            int a,b;
            scanf("%d%d", &a, &b);
            mager(a, b);
        }
        int ans=1;
        for(int i=1; i <= N; i++){
            if(father[i] == i && sum[i] > ans) //在此WR无数次。。。。。
                ans = sum[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}