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
#include <cctype>
#include <list>
#include <set>
#include <map>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1

const int N = 110;
const int M = 100000010;
const int INF=0x3f3f3f3f;
const int MOD=95041567,STA=8000010;
const double EPS=1e-8;
const double OO=1e15;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline void checkmin(T &a,T b){if(a>b) a=b;}
template<class T> inline void checkmax(T &a,T b){if(a<b) a=b;}
template<class T> inline void swap(T& a, T& b){T c(a); a = b; b = c;}

int n, m;
int aa[N];
int bb[110][110];

int Gcd(int a, int b){
    if(a == 0) return b;
    if(b == 0) return a;
    if(a % 2 == 0 && b % 2 == 0) return 2 * Gcd(a >> 1, b >> 1);
    else if(a % 2 == 0)  return Gcd(a >> 1, b);
    else if(b % 2 == 0) return Gcd(a, b >> 1);
    else return Gcd(abs(a - b), Min(a, b));
}

int main(){
    while(cin >> n >> m){
        int sum = 0;
        mem(bb, 0);
        for (int i = 1; i <= n; i++){
            cin >> aa[i];
        }
        int a, b;
        for (int i = 1; i <= m; i++){
            cin >> a >> b;
            bb[a][b] = 1;
            bb[b][a] = 1;
        }
        int c, d, gcd_;
        for (int i = 1; i < n; i++){
            for (int j = i + 1; j <= n; j++){
                gcd_ = Gcd(aa[i], aa[j]);
                c = aa[i] / gcd_;
                d = aa[j] / gcd_;
                
//                                   cout << c << "   " << d << endl;
                if ((c <= 110 && d <= 110) && bb[c][d]){
                    sum++;
                    cout << aa[i] << "  " << aa[j] << endl;

                    cout << c << "  " << d << endl;
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}