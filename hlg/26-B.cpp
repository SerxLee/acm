#include <iostream>
#include <cstring>
#include <algorithm>
typedef long long ll;
ll p[1 << 21];
ll a[50], n, s, k, cnt, MIN, MAX;
using namespace std;
void dfs1(ll now, int c) {
    if(c == k / 2) {
        p[cnt++] = now;
        return;
    }
    if(now - a[c] >= 0) dfs1(now - a[c], c + 1);
    if(now + a[c] <= n) dfs1(now + a[c], c + 1);
}
void dfs2(ll now, int c, ll l, ll r) {
    if(c == k) {
        if(r - l <= n) {
            int i = lower_bound(p, p + cnt, -l) - p;
            int j = lower_bound(p, p + cnt, n - r) - p;
            if(j == cnt) {
                if(p[j - 1] <= n - r) j--;
            } else {
                if(p[j] > n - r) j--;
            }
            if(j >= i) {
                MIN = min(MIN, p[i] + now);
                MAX = max(MAX, p[j] + now);
            }
        }
        return;
    }
    dfs2(now - a[c], c + 1, min(now - a[c], l), r);
    dfs2(now + a[c], c + 1, l, max(now + a[c], r));
}
int main() {
    cin >> n >> s >> k;
    for(int i = 0; i < k; i++) cin >> a[i];
    cnt = 0;
    dfs1(s, 0);
    sort(p, p + cnt);
    MAX = 0; MIN = n;
    dfs2(0, k / 2, 0, 0);
    cout << MIN << ' ' << MAX << endl;
    return 0;
}