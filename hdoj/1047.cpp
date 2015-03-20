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

const int N = 42;
const int INF=0x3f3f3f3f;
const int MOD=95041567,STA=8000010;
const double EPS=1e-8;
const double OO=1e15;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
const int M = 12;

int res[110], a[110], b[110];

string jiafa(string str2, string str1){
    int len_sum, len_add;
    len_add = str1.length();
    len_sum = str2.length();
    if (len_sum > len_add) {
        for (int i = 1; i <= len_sum - len_add; i++) {
            str1 = "0" + str1;
        }
    }else{
        for (int i = 1; i <= len_add - len_sum; i++) {
            str2 = "0" + str2;
        }
    }
    int jinshu = 0;
    int yushu;
    len_sum = str2.length();
    string str;
    for(int i = len_sum - 1; i >= 0; i--){
        yushu = str1[i] - '0' + str2[i] - '0' + jinshu;
        jinshu = yushu/10;
        yushu %= 10;
        str = char(yushu + '0') + str;
    }
    if(jinshu != 0)
        str = char(jinshu + '0') + str;
    return str;
}

int main(){
    int T;
    cin >> T;
    while (T--) {
        string sum = "0", add;
        while (cin >> add) {
            if (add == "0") {
                break;
            }
            sum = jiafa(sum, add);
        }
        cout << sum << endl;
        if (T != 0) {
            cout << endl;
        }
    }
    return 0;
}