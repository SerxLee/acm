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
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}

int chang(char *a){
    int i, k = 0;
    for (i = 0; i < 20; i++) {
        if (a[i] != '\0') {
            k++;
        }
    }
    return k;
}

bool pan(char *a){
    int i, k;
    k = 0;
    int len;
    len = chang(a);
    if (len >= 6 && len <= 18) {
        if ((a[0] >= 'a' && a[0] <= 'z' )||( a[0] >= 'A' && a[0] <= 'Z')) {
            for (i = 0; i < len; i++) {
                if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z') || a[i] == '_' ||( a[i] >= '0' && a[i] <= '9')) {
                    k++;
                }
            }
        }
    }
    if (k == len) {
        return true;
    }else{
        return false;
    }
}

int main(){
    int t;
    int i, n, k, j = 0, b[105];
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        k = 0;
        for (i = 0; i < n; i++) {
            char a[20];
            getchar();
            gets(a);
            if (pan(a)) {
                k++;
            }
        }
        b[j++] = k;
        printf("%d", k);
    }
    return 0;
}