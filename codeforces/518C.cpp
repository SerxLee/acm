#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline T Min(T a,T b){return a<b?a:b;}


struct node{
    int x, y;
};

map<int, node> mp1;
map<node, int> mp2;
int v, t, aa[100001], bb[100001];
long long ans;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    ans = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &aa[i]);
        bb[aa[i]] = i;
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &v);
        t = bb[v];
        ans += (t - 1) / k + 1;
        if (t > 1) {
            swap(aa[t], aa[t - 1]);
            bb[aa[t]] = t;
            bb[aa[t - 1]] = t - 1;
  
        }
    }
    printf("%lld\n",ans);
    return 0;
}