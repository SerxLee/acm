#include <iostream>
#include <vector>
#define __maxNodes 1005
using namespace std;

vector<int> G[__maxNodes];
typedef vector<int>::iterator iterator_t;

int num_left;
int num_right;

int matching[__maxNodes];
int check[__maxNodes];

bool dfs(int u) {
    for (iterator_t i = G[u].begin(); i != G[u].end(); i++) {
        int v = *i;
        if (!check[v]) {
            check[v] = true;
            if (matching[v] < 0 || dfs(matching[v])) {
                matching[v] = u;
                matching[u] = v;
                return true;
            }
        }
    }
    return false;
}

int xyl_dfs() {
    int ans = 0;
    memset(matching, -1, sizeof(matching));
    for (int u = 0; u < num_left; u++) {
        if (matching[u] == -1) {
            memset(check, 0, sizeof(check));
            if (dfs(u)) {
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    int k, m, n;
    int t1, t2;
    while (true) {
    cin >> k;
    if (k == 0) {
        return 0;
    }
    cin >> m >> n;
    num_left = m;
    num_right = n;
    for (int i = 0; i < __maxNodes; i++) {
        G[i].clear();
    }
    for (int i = 0; i < k; i++) {
        cin >> t1 >> t2;
        G[t1-1].push_back(t2+500);
        G[t2+500].push_back(t1-1);
    }
    cout << xyl_dfs() << endl;
    }
}