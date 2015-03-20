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
const int N = 20100;
const int INF=0x3f3f3f3f;
const int MOD=95041567,STA=8000010;
const double EPS=1e-8;
const double OO=1e15;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}


void pan(char *ch){
    int i, j ,k, sum = 0;
    k = strlen(ch) - 1;
    for (i = k; k >= 0; k--) {
        if (ch[i] == '0') {
            k--;
        }else{
            break;
        }
    }
    if (ch[k] == '.') {
        k--;
    }
    ch[k + 1] = '\0';
}

int main(){
    int i , j, k, len;
    char a[100010];
    char b[100010];
    while (cin >> a >> b) {
        len = strlen(a);
        for (i = 0; i < len; i++){
            if (a[i] == '.') {
                pan(a);
                break;
            }
        }
        len = strlen(b);
        for (i = 0; i < len; i++) {
            if (b[i] == '.') {
                pan(b);
                break;
            }
        }

        if (!strcmp(a, b)) {
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}