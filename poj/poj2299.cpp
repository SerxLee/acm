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
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define PI acos(-1.0)
const int N = 500100;
const int INF=0x3f3f3f3f;
const int MOD=95041567,STA=8000010;
const double EPS=1e-8;
const double OO=1e15;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
const int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
inline int sign(double x){return (x>EPS)-(x<-EPS);}
template<class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T> T lcm(T a,T b){return a/gcd(a,b)*b;}
template<class T> inline T lcm(T a,T b,T d){return a/d*b;}
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline T Min(T a,T b,T c){return min(min(a, b),c);}
template<class T> inline T Max(T a,T b,T c){return max(max(a, b),c);}
template<class T> inline T Min(T a,T b,T c,T d){return min(min(a, b),min(c,d));}
template<class T> inline T Max(T a,T b,T c,T d){return max(max(a, b),max(c,d));}
//End

//归并排序 求逆序数 逆序数定义：
//    一个数列中 若I < J,但是A[I]>A[J] ,  则A[I]与A[J]就互为逆序数。
long long a[N], sum, b[N];
void guibin(int start, int end) {
    int i, j, k, mid;
    if (start == end) {
        return;
    }
    mid = (start + end) / 2;
    guibin(start, mid);
    guibin(mid + 1, end);
    i = start;
    j = mid + 1;
    k = 0;
    while (i <= mid && j <= end) {
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        }else{
            sum += mid - i + 1;
            b[k++] = a[j++];
        }
    }
    while (i <= mid) {
        b[k++] = a[i++];
    }
    while (j <= end) {
        b[k++] = a[j++];
    }
    for (i = 0; i <= end - start; i++) {
        a[start + i] = b[i];
    }
    return;
}
int main(){
    int n, i;
    while(scanf("%d", &n) != EOF && n){
        sum = 0;
        for (i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        guibin(0, n - 1);
        printf("%lld\n", sum);
    }
    return 0;
}