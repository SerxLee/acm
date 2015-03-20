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

template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline void CheckMin(T &a,T b){if(a>b) a=b;}
template<class T> inline void CheckMax(T &a,T b){if(a<b) a=b;}

string s;
int w[30];
long long sum[100005];
map<long long, int> ma[30];
int main() {
    for (int i = 0; i < 26; i++) {
        cin >> w[i];
    }
    long long aa = 0;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        sum[i] = sum[i - 1] + w[s[i] - 'a'];
    }
    ma[s[0] - 'a'][sum[0]]++;
    for (int i = 1; i < s.size(); i++) {
        int bb = s[i] - 'a';
        if (ma[bb].count(sum[i - 1])) {
            aa += ma[bb][sum[i - 1]];
        }
        ma[bb][sum[i]]++;
    }
    cout << aa << endl;
    return 0;
}