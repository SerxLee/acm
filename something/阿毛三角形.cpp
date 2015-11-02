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
const int N = 111000;
const int INF=0x3f3f3f3f;
const int MOD=95041567,STA=8000010;
const double EPS=1e-8;
const double OO=1e15;
const int dx[4]={0, 1, -1};
const int dy[4]={1, -1, 0};
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}

int myarr[100][100];

int main(){
    int n;
    cin >> n;
    int m = n;
    mem(myarr, 0);
    int num = 0;
    int shu = 1;
    int ii = 0, jj = -1;
    int lim_jia = 0;
    while (m--){
        for (int i = 0; i <= m; i++){
            ii += dx[lim_jia];
            jj += dy[lim_jia];
            myarr[ii][jj] = shu;
            shu++;
        }
        lim_jia++;
        if (lim_jia >= 3){
            lim_jia %= 3;
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n ;j++){
            if (myarr[i][j]){
               printf("%d ", myarr[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}