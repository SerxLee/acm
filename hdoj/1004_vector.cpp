
#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <cassert>
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
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int N = 10000005;
const int INF = 0x3f3f3f3f;
const int MOD = 95041567,STA = 8000010;
const double EPS = 1e-8;
const double OO = 1e15;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline T Min(T a,T b){return a < b ? a : b;}
template<class T> inline T Max(T a,T b){return a > b ? a : b;}

int n;
string a;

int main(){
    int i, j , k;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }

        //设置一个记录字符出现次数的vector，然后通过查找vector最大元素，找到相应的字符
        vector<int> times;
        vector<string> words;


        for (i = 0; i < n; i++) {
            cin >> a;
            words.push_back(a);
        }
        for (i = 0; i < words.size(); i++) {
            times.push_back(1);
        }
        for (i = 0; i < words.size(); i++) {
            for (j = i + 1; j < words.size(); j++) {
                if (words[i] == words[j]) {
                    times[i]++;
                    times[j]++;
                }
            }
        }
        string str;
        int max = 0;
        for (i = 0; i < times.size(); i++) {
            if (max < times[i]) {
                max = times[i];
                str = words[i];
            }
        }
        cout << str << endl;
    }
    return 0;
}