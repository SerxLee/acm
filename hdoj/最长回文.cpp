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
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}

char a[N];



int longll(char *a){
    int maxlen = 1;
    int start = 0;
    int len = strlen(a);
    int low, high;
    for (int i = 1; i < len; i++) {
        low = i - 1;
        high = i;
        while (low >= 0 && high < len && a[low] == a[high]) {
            if (high - low + 1 > maxlen) {
                start = low;
                maxlen = high - low + 1;
            }
            low--;
            high ++;
        }
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len && a[low] == a[high]) {
            if (high - low  + 1 > maxlen) {
                start = low;
                maxlen = high - low + 1;
            }
            low--;
            high++;
        }
    }
    return maxlen;
}

int main(){
    while (cin >> a) {
        int n = longll(a);
        cout << n << endl;
    }
}