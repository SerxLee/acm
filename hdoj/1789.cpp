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

struct node{
    int a, b;
    friend bool operator < (node x, node y){
        return y.b < x.b;
    }
};

void quicksort(node a[], int l, int k)
{
    if (l < k) {
        int i = l , j = k;
        node tmp = a[l];
        while (i < j) {
            while (i < j && a[j].a >= tmp.a) {
                j--;
            }
            if (i<j) {
                a[i++]= a[j];
            }
            
            while (i<j && a[i].a <= tmp.a) {
                i++;
            }
            if (i<j) {
                a[j--] = a[i];
            }
        }
        a[i] = tmp;
        quicksort(a, l, i-1);
        quicksort(a, i+1, k);
    }
}

node lim[1005];

int main(){
    int T, n, sc, day, all;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        all = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &lim[i].a);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &lim[i].b);
            all += lim[i].b;
        }
        quicksort(lim, 0, n - 1);
        sc = 0;
        day = 0;
        node lim_;
        priority_queue<node> q;
        for (int i = 0; i < n; i++) {
            if (lim[i].a > day) {
                day++;
                q.push(lim[i]);
            }else{
                lim_ = q.top();
                if (lim[i].b > lim_.b) {
                    q.push(lim[i]);
                    q.pop();
                }
            }
        }
        while (!q.empty()) {
            sc += q.top().b;
//            printf("%d ", q.top().b);
            q.pop();
        }
        printf("%d\n",all -  sc);
    }
    return 0;
}