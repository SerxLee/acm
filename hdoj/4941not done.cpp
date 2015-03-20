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
#include <map>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int N = 100005;
const int INF = 0x3f3f3f3f;
const int MOD = 95041567,STA = 8000010;
const double EPS = 1e-8;
const double OO = 1e15;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline T Min(T a,T b){return a < b ? a : b;}
template<class T> inline T Max(T a,T b){return a > b ? a : b;}

int T, n, m, k, x, y, c, q, Case;

map<int, int> hang, lie;
map<pair<int, int>, int> all;    //用     pair<int， int>  做 Key；

int main(){
    scanf("%d", &T);
    Case = 1;
    while (T--) {
        scanf("%d%d%d", &n, &m, &k);
        hang.clear(), lie.clear(), all.clear();
        while (k--) {
            scanf("%d%d%d", &x, &y, &c);
            hang[x] = x;
            lie[y] = y;
            all[pair<int, int>(x, y)] = c;
        }
        printf("Case #%d:\n", Case++);
        scanf("%d", &q);
        while (q--) {
            scanf("%d%d%d", &c, &x, &y);
            if (c == 1) {
                swap(hang[x], hang[y]);
            }else if(c == 2){
                swap(lie[x], lie[y]);
            }else{
                x = hang[x];
                y = lie[y];
                printf("%d\n", all[pair<int , int>(x, y)]);
            }
        }
    }
    return 0;
}