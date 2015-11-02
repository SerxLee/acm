//
//  main.cpp
//  shenyang
//
//  Created by Serx on 15/9/19.
//  Copyright (c) 2015年 serx. All rights reserved.
//

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
#define maxn  100005

const int INF=0x3f3f3f3f;

template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline void CheckMin(T &a,T b){if(a>b) a=b;}
template<class T> inline void CheckMax(T &a,T b){if(a<b) a=b;}

struct node{
    int a, b, c;
}g[maxn];

int father[maxn];
int link[maxn];

struct nod{
    int vv, ans;
}hh[5005];

bool cp(const node a,const node b){
    return a.c < b.c;
}

bool cp2(const nod a, const nod b){
    return a.vv < b.vv;
}

int getfather(int x){
    if (father[x] != x){
        father[x] = getfather(father[x]);
    }
    return father[x];
}

void uni(int x, int y){
    int xx, yy;
    xx = getfather(x);
    yy = getfather(y);
    if (link[xx] > link[yy]){
        father[yy] = xx;
        link[xx] += link[yy];
    }else{
        father[xx] = yy;
        link[yy] += link[xx];
    }
}

int main(){
    int T;
    cin >> T;
    int n, m , q;
    while (T--){
        cin >> n >> m >> q;

        for (int i = 1; i <= n; i++){
            father[i] = i;
            link[i] = 1;
        }
        for (int i = 1; i <= m; i++){
            cin >> g[i].a >> g[i].b >> g[i].c;
        }
        
        for (int i = 1; i <= q; i++){
            cin >> hh[i].vv;
        }
        
        sort(g + 1, g + m + 1, cp);
        sort(hh + 1, hh + q + 1, cp2);
        int ans = 0;
        for (int i = 1; i <= q; i++){
            for (int j = 1; j <= m; j++){
                if (g[j].c > hh[i].ans){
                    break;
                }
                if (getfather(g[j].a) != getfather(g[j].b)){
                    ans += link[getfather(g[j].a)] * link[getfather(g[j].b)] * 2;
                    uni(g[j].a, g[j].b);
                }
            }
            hh[i].ans = ans;
        }
        for (int i = 1; i <= q; i++){
            cout << hh[i].ans << endl;
        }
    }
    return 0;
}