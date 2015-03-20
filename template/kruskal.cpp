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
const int N = 2010;
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}

struct node{
    int x, y;
    int v;
};

int father[N];
int son[N];
node mapp[N];
int n, m;
int bian, all_v;

//快排。。。不说了，从小到大排
void qsort(node *a, int l, int k){   
    if (l < k) {
        int i = l , j = k;
        node tmp = a[l];
        while (i < j) {
            while (i < j && a[j].v >= tmp.v) {
                j--;
            }
            if (i < j) {
                a[i++] = a[j];
            }
            
            while (i < j && a[i].v <= tmp.v) {
                i++;
            }
            if (i < j) {
                a[j--] = a[i];
            }
        }
        a[i] = tmp;
        qsort(a, l, i-1);
        qsort(a, i+1, k);
    }
}

//并查集get上一级
int getfather(int x){
    int v;
    v = x;
    if (v == father[x]) {
        return v;
    }else{
        return getfather(father[x]);
    }
}

//并查集判断是否成环
bool marge(int x, int y){
    int xx, yy;
    xx = getfather(x);
    yy = getfather(y);
    if (xx != yy) {
        if (son[x] > son[y]) {
            father[y] = x;
            son[x] += son[y];
        }else{
            father[x] = y;
            son[y] += son[x];
        }
        return  true;
    }
    return false;
}

int main(){
    int i, k = 0;
//    k标记：是否构成树
    while (scanf("%d%d", &n, &m) != EOF) {
        bian = 0;
//        标记变的数量
        all_v = 0;
//        边的总价值
        for (i = 1; i <= n; i++) {
            father[i] = i;
            son[i] = 1;
        }
        for (i = 0; i < m; i++) {
            scanf("%d%d%d", &mapp[i].x, &mapp[i].y, &mapp[i].v);
        }
        qsort(mapp, 0, m - 1);
        for (i = 0; i < m; i++) {
            printf("%d ", mapp[i].v);
        }
        for (i = 0; i < m ; i++) {
            if (marge(mapp[i].x, mapp[i].y)) {
                bian++;
                all_v += mapp[i].v;
                cout<<mapp[i].x << "->" << mapp[i].y << endl;
            }
            if (bian == n - 1) {
                k = 1;
                break;
            }
        }
        if (k == 1) {
            printf("%d\n", all_v);
        }else{
            printf("date error\n");
        }
    }
    return 0;
}