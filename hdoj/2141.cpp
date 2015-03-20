#include <iostream>
using namespace std;

int a[505], b[505], c[505];
int ab[250005];

int main() {
    int l, n, m;
    int ff = 0;
    while (cin >> l >> n >> m) {
        cout << "Case " << ++ff << ":" << endl;
        for (int i = 0; i < l; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++){
            cin >> b[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> c[i];
        }
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < n; j++) {
                ab[i * n + j] = a[i] + b[j];
            }
        }
        sort(ab, ab + l * n);
        int x, t;
        cin >> x;
        for (int i = 0; i < x; i++) {
            cin >> t;
            bool flag = false;
            for (int j = 0; j < m; j++) {
                if (*lower_bound(ab, ab + l * n, t - c[j]) ==  t - c[j]) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
}