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
const int INF=0x3f3f3f3f;
const int MOD=95041567,STA=8000010;
const double EPS = 1e-8;
const double OO=1e15;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}

int n, m;
char mapp[205][205];
int all[100001];
int one_time, sum;
int flag[205][205];

bool inmap(int x, int y){
    if (x >= 0 && x < n && y >= 0 && y < m) {
        return true;
    }
    return false;
}

void dfs(int x, int y){
    int i, xx, yy;
    if (mapp[x][y] == 'r') {
        all[sum++] = one_time;
    }
    else if(mapp[x][y] != '#'){
        for (i = 0; i < 4; i++) {
            xx = x + dx[i];
            yy = y + dy[i];
            if (inmap(xx, yy) && !flag[xx][yy] && mapp[xx][yy] != '#') {
                if (mapp[x][y] == 'x') {
                    one_time++;
                }
                flag[xx][yy] = 1;
                one_time++;
                dfs(xx, yy);
                
                flag[xx][yy] = 0;
                one_time--;
                if (mapp[x][y] == 'x') {
                    one_time--;
                }
            }
        }
    }
}

int main(){
    int i, j, k, x, y;
    while(scanf("%d%d", &n,&m) != EOF){
        mem(flag, 0);
        sum = one_time = 0;
        for (i = 0; i < n; i++) {
            scanf("%s", mapp[i]);
        }
        x = y = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (mapp[i][j] == 'a') {
                    x = i;
                    y = j;
                }
            }
        }
        dfs(x, y);
        
        if (sum == 0) {
            printf("Poor ANGEL has to stay in the prison all his life.\n");
        }else{
            k = INF;
            for (i = 0; i < sum; i++) {
                if (all[i] < k) {
                    k = all[i];
                }
            }
            printf("%d\n", k);
        }
    }
    return 0;
}