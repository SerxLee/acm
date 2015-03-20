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
const int N = 101000;
const int INF=0x3f3f3f3f;
const int MOD=95041567,STA=8000010;
const double EPS=1e-8;
const double OO=1e15;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}

struct node{
    char a[15], b[15];
};

bool cmp(node a,node b){
    if (strcmp(a.b,b.b) < 0)
        return true;
    else
        return false;
}

int main(){
    char s[30];
//    int sum = 0;
    vector<node> s1;
    vector<node>::iterator low, up;
    while(gets(s)){
        node tmp;
        if(s[0] == '\0'){
            break;
        }
        sscanf(s, "%s %s", tmp.a, tmp.b);
        s1.push_back(tmp);
    }
    sort(s1.begin(),s1.end(),cmp);
//    for(vector <node> ::iterator iter=s1.begin();iter!=s1.end();iter++)
//        printf("%s %s\n",iter->a,iter->b);
//    cout << "\n";
    node dd;
    while (gets(dd.b)) {
        low = lower_bound(s1.begin(), s1.end(), dd, cmp);
//        cout << low->b << " ";
        if (strcmp(low->b, dd.b) == 0) {
            printf("%s\n",low->a);
        }else{
            puts("eh");
        }
//        int min = 0, mid, max = sum;
//        for(;;){
//            mid = (max - min) / 2 + min;
//            if (mid == min){
//                break;
//            }
//            if (strcmp(s1[mid].b, s) <= 0){
//                min = mid;
//            }
//            else {
//                max = mid;
//            }
//        }
//        if (strcmp(s,s1[mid].b) == 0)
//            printf("%s\n",s1[mid].a);
//        else
//            puts("eh");
        
    }
    return 0;
}