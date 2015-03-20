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

map<string , int > ma;
int ans;

int main(){
    string a, t, b;
    int n ;
    ans = 1;
    cin >> n;
    ma["polycarp"] = 1;
    while (n--) {
        cin >> a >> t >> b;
        transform(a.begin(), a.end(), a.begin(), ::tolower);
        transform(b.begin(), b.end(), b.begin(), ::tolower);
        if (ma[b] != 0) {
            ma[a] = ma[b] + 1;
        }
        if (ma[a] > ans){
            ans = ma[a];
        }
    }
    cout << ans << endl;
    return 0;
}