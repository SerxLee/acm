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

#define maxn 150005
#define pii pair<int, int>
#define psi pair<string, pii>

queue<psi> g;
int flag[maxn];

//bool operator <(const psi &x, const psi &y){
//    if (x.second.first == y.second.first){
//        return x.second.second > y.second.second;
//    }else{
//        return x.second.first < y.second.first;
//    }
//}

bool cmp(psi a,psi b){
    if (a.second.first == b.second.first){
        return a.second.second > b.second.second;
    }else{
        return a.second.first > b.second.first;
    }
}

bool cmp2(psi a, psi b){
    return a.second.second < b.second.second;
}



int main(){
    int T;
    int k, m , q;
    cin >> T;
    while (T--){
        memset(flag, 0, sizeof(flag));
        while (!g.empty()){
            g.pop();
        }
        psi a[maxn];
        cin >> k >> m >> q;
        for (int i = 1; i <= k; i++){
            cin >> a[i].first >> a[i].second.first;
            a[i].second.second = i;
        }
        int add = 0;
        while (m--){
            int r, l;
            cin >> r  >> l;
            sort(a + 1 + add, a + r + 1);
            add++;
            g.push(a[l]);
            flag[a[l].second.second] = 1;
        }
       sort(a + 1, a + k + 1, cmp2);
        for (int i = 1; i <= k; i++){
            if (!flag[a[i].second.second]){
                g.push(a[i]);
            }
        }
        
//        while (!g.empty()) {
//            cout << g.front().first <<" ";
//            g.pop();
//        }
//        for (int i = 1; i <= k; i++){
//            cout << a[i].first << endl;
//        }
        int qes[105];
        for (int i = 1; i <= q; i++){
            cin >> qes[i];
        }
        int mm = 0;
        psi last;
        int all = 0;
        while (!g.empty()){
            last = g.front();
            g.pop();
            mm++;
            
            for (int j = 1; j <= q; j++){
                int ff = 0;
                if (qes[j] == mm){
                    ff = 1;
                    all++;
                    cout << last.first;
                }
                if (ff){
                    if (all != q){
                        cout << " ";
                    }
                }
            }
        }
    }
    return 0;
}