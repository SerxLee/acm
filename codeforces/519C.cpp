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
#include <cctype>
#include <list>
#include <set>
#include <map>

using namespace std;

const int dx[2]={2, 1};
const int dy[2]={1, 2};

#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1

template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline void checkmin(T &a,T b){if(a>b) a=b;}
template<class T> inline void checkmax(T &a,T b){if(a<b) a=b;}
template<class T> inline void swap1(T& a, T& b){T c(a); a = b; b = c;}

int ans;

int main(){
    int n , m;
    cin >> n >> m;
    ans = 0;
    while (n > 0 && m > 0) {
        if (n >= m && n >= 2 && m >= 1){
            n -= dx[0];
            m -= dy[0];
            ans++;
        }else if(m >= n && n >= 1 && m >= 2){
            n -= dx[1];
            m -= dy[1];
            ans++;
            
        }else{
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}