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
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
template<class T> inline T Min(T a,T b){return a < b ? a : b;}
template<class T> inline T Max(T a,T b){return a > b ? a : b;}

char a[1005], b[1010], c[1010];

int main(){
    int t, i, j,len_a, len_b, sum, lim, la, lb, k;
    scanf("%d", &t);
    for (i = 1; i <= t; i++) {
        stack<int> s;
        while (!s.empty()) {
            s.pop();
        }
        scanf("%s%s", a, b);
        len_a = la = strlen(a);
        len_b = lb = strlen(b);
        sum = 0;
        len_a--;
        len_b--;
        while (len_a >= 0 && len_b >= 0) {
            lim = 0;
            lim = a[len_a] - '0' +  b[len_b] - '0' + sum;
            sum = 0;
            if (lim >= 10) {
                lim -= 10;
                sum++;
            }
            s.push(lim);
            len_b--;
            len_a--;
        }
        while (len_b >= 0) {
            s.push(b[len_b] - '0' + sum);
            len_b--;
            sum = 0;
        }
        while (len_a >= 0) {
            s.push(a[len_a] - '0' + sum);
            len_a--;
            sum = 0;
        }
        if (sum != 0) {
            s.push(sum);
            sum = 0;
        }
        k = 0;
        while (!s.empty()) {
            c[k++] = s.top() + '0';
            s.pop();
        }
        printf("Case %d:\n", i);
        printf("%s + %s = ", a, b);
        printf("%s\n", c);
    }
    return 0;
}