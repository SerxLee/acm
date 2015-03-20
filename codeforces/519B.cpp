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

#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1

string po = string("polycarp");

template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline void checkmin(T &a,T b){if(a>b) a=b;}
template<class T> inline void checkmax(T &a,T b){if(a<b) a=b;}
template<class T> inline void swap1(T& a, T& b){T c(a); a = b; b = c;}

int n;

int main(){
    cin >> n;
    int aa, sum1 = 0, sum2 = 0, sum3 = 0;
    for (int i = 0; i < n; i++){
        scanf("%d", &aa);
        sum1 += aa;
    }
    for (int i = 1; i < n; i++) {
        scanf("%d", &aa);
        sum2 += aa;
    }
    for (int i = 2; i < n; i++) {
        scanf("%d", &aa);
        sum3 += aa;
    }
    printf("%d\n", sum1 - sum2);
    printf("%d\n", sum2 - sum3);
    return 0;
}