// 最长回文

// Time Limit : 4000/2000ms (Java/Other)   Memory Limit : 32768/32768K (Java/Other)
// Total Submission(s) : 5   Accepted Submission(s) : 3
// Problem Description
// 给出一个只由小写英文字符a,b,c...y,z组成的字符串S,求S中最长回文串的长度.
// 回文就是正反读都是一样的字符串,如aba, abba等
 

// Input
// 输入有多组case,不超过120组,每组输入为一行小写英文字符a,b,c...y,z组成的字符串S 两组case之间由空行隔开(该空行不用处理) 字符串长度len <= 110000
 

// Output
// 每一行一个整数x,对应一组case,表示该组case的字符串中所包含的最长回文长度.
 

// Sample Input
// aaaa

// abab
 

// Sample Output
// 4
// 3
 

// Source
// 2009 Multi-University Training Contest 16 - Host by NIT
//  

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

const int N = 101000 * 2;
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

char s[N];
char str[N];
int n, p[N];

void pre(){
    n = strlen(s);
    str[0] = '.';
    str[1] = '#';
    for (int i = 0; i < n; i++) {
        str[i * 2 + 2] = s[i];
        str[i * 2 + 3] = '#';
    }
    n = n * 2 + 2;
    str[n] = 0;
}

void kp(){
    int mx = 0;
    int id;
    for (int i = 1; i < n; i++){
        if( mx > i )
            p[i] = Min( p[2 * id - i], p[id]+ id - i );
        else
            p[i] = 1;
        for(; str[i+p[i]] == str[i-p[i]]; p[i]++)
            ;
        if( p[i] + i > mx ){
            mx = p[i] + i;
            id = i;
        }
    }
}

void pt(){
    int ans = 0;
    for (int i = 0; i < n; i++) {
        
        checkmax(ans, p[i]);
    }
    printf("%d\n", ans-1);
}

int main(){
    while (scanf("%s", s) != EOF) {
        pre();
        kp();
        pt();
    }
    return 0;
}