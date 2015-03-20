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
#define PI 3.14159265359

template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline void CheckMin(T &a,T b){if(a>b) a=b;}
template<class T> inline void CheckMax(T &a,T b){if(a<b) a=b;}

const int N = 1000010;
const int INF=0x3f3f3f3f;
const int MOD=95041567,STA=8000010;
const double EPS=1e-8;
const double OO=1e15;
const int dx[8]={-1,0,1,0};
const int dy[8]={0,1,0,-1};

//end

char aa[N];
int next_[N];
int n, cas;

void get_next(){
    int j = -1;
    next_[0] = -1;
    for (int i = 1; i <= n; i++) {
        while (j > -1 && aa[j + 1] != aa[i]) {
            j = next_[j];
        }
        if (aa[j + 1] == aa[i]) {
            j++;
        }
        next_[i] = j;
    }
}

int main(){
    cas = 0;
    while (cin >> n && n != 0) {
        scanf("%s", aa);
        cas++;
        printf("Test case #%d\n", cas);
        get_next();
        for (int i = 2; i <= n; i++) {
            int j = (i - 1) - next_[i - 1];
            if (i % j == 0 && i != j)  {
                printf("%d %d\n", i, i / j);
            }
        }
        printf("\n");
    }
    return 0;
}