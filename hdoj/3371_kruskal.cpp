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
const int maxn=250010;
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}

int n,m,k;
int noconnected = 0;
int father[510];

struct node{
    int u, v, w;
}mapp[maxn];

void quicksort(node *a, int l, int k){
    if (l < k) {
        int i = l , j = k;
        node tmp = a[l];
        while (i < j) {
            while (i < j && a[j].w >= tmp.w) {
                j--;
            }
            if (i<j) {
                a[i++]= a[j];
            }
            
            while (i<j && a[i].w <= tmp.w) {
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

int getfather(int x){            //非递归。。。。。找father
    int k, j, r;
    r = x;
    while (r != father[r]) {
        r = father[r];
    }
    k = x;
    while (k != r) {
        j = father[k];
        father[k] = r;
        k = j;
    }
    return r;
}

int kruskal(){
    int ans = 0;
    quicksort(mapp, 0, m - 1);
    for (int i = 0; noconnected > 1 && i < m; i++){
        int x = getfather(mapp[i].u);
        int y = getfather(mapp[i].v);
        if(x != y){
            ans += mapp[i].w;
            father[x] = y;
            noconnected--;
        }
    }
    if (noconnected == 1)
        return ans;
    return -1;
}

void chu(){
    int i;
    for (i = 0; i < n; i++) {
        father[i] = i;
    }
}

int main(){
    int T;
    scanf("%d", &T);
    while (T--){
        scanf("%d%d%d", &n, &m, &k);
        chu();
        for (int i = 0; i < m; i++){
            scanf("%d%d%d",&mapp[i].u, &mapp[i].v, &mapp[i].w);
            mapp[i].u--;
            mapp[i].v--;
        }
        for (int i = 0;i < k; i++){
            int t;
            scanf("%d",&t);
            int fathe, son;
            scanf("%d",&fathe);
            fathe--;
            for (int i = 1; i < t; i++){
                scanf("%d",&son);
                son--;
                father[getfather(son)] = father[getfather(fathe)];
                fathe = son;
            }
        }
        for (int i = 0; i < n; i++){
            if (father[i] == i)
                noconnected++;
        }
        printf("%d\n", kruskal());
    }
    return 0;
}
