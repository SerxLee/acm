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
#define maxn  1005

const int INF=0x3f3f3f3f;

template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline void CheckMin(T &a,T b){if(a>b) a=b;}
template<class T> inline void CheckMax(T &a,T b){if(a<b) a=b;}

#define ll long long
#define pll pair<ll, ll>

vector<pll > pp;
map<tuple<pll, pll >, int> aa;
map<tuple<pll, pll >, int>::iterator it;

double len(double x1, double y1, double x2, double y2){
    return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1) * (y2 - y1));
}

bool is_sample(int i, int j, int k){
    if ((pp[j].first - pp[i].first) * (pp[k].second - pp[i].second) - (pp[k].first - pp[i].first) * (pp[j].second - pp[i].second) != 0){
        return false;
    }else{
        return true;
    }
}

pair<ll, ll> jj(ll x1, ll y1, ll x2, ll y2){
    ll len1, a1, b1, cosr;
    len1 = x1*x2 + y1*y2;
    len1 = len1*len1;
    a1 = x1*x1 + y1*y1;
    b1 = x2*x2 + y2*y2;
    ll g = __gcd(len1, a1*b1);
    return make_pair(len1/g, a1*b1/g);
}

int main (){
    int n;
    while (cin >> n){
        if (n == 0){
            break;
        }
        pp.clear();
        aa.clear();
        int x, y;
        for (int i = 0; i < n; i++){
            cin >> x >> y;
            pp.push_back(make_pair(x, y));
        }
        
        sort(pp.begin(), pp.end());
        pp.erase(unique(pp.begin(), pp.end()), pp.end());
        n = pp.size();
        
        pair<ll, ll> lim[3];
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                for (int k = j + 1; k < n; k++){
#define pif pp[i].first
#define pis pp[i].second
#define pjf pp[j].first
#define pjs pp[j].second
#define pkf pp[k].first
#define pks pp[k].second
                    if (is_sample(i, j, k)){
                        continue;
                    }
                    lim[0] = jj(pif - pjf, pis - pjs, pif - pkf, pis - pks);
                    lim[1] = jj(pjf - pkf, pjs - pks, pjf - pif, pjs - pis);
                    lim[2] = jj(pkf - pif, pks - pis, pkf - pjf, pks - pjs);
                    sort(lim, lim + 3);
                    aa[make_tuple(lim[0], lim[1])]++;

//                    for (int ii = 0; ii < 3; ii++){
//                        cout << lim[ii] << " ";
//                    }
//                    cout << endl;
                    
                }
            }
        }
        int ans = 0;
        for (it = aa.begin(); it != aa.end(); it++){
            if (it->second > ans){
                ans = it->second;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
/*
3 1 1
6 5 12 10 4 0 0 1 1 2 0 1 -1 0
*/