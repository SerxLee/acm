

// 类似最长递增子序列的想法，只不过这里求的是到第i个元素时，最长递增子序列，各个元素的和。求最大的那个值。

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
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}

vector<int> len;

int bisearch(int val){
    int left = 0;
    int right = len.size() - 1;
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (len[mid] < val) {
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return left;
}

int main(){
    int n;
    while (cin >> n) {
        while (!len.empty()) {
            len.pop_back();
        }
        if (n == 0) {
            break;
        }
        int val, ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> val;
            int k = bisearch(val);
            if (len.size() <= k) {
                len.push_back(val);
                ans += val;
            }else{
                len[k] = val;
            }
        }
        cout << ans << endl;
    }
    return 0;
}