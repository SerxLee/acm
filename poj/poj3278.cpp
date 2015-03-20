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

const int N = 100001;
const int INF=0x3f3f3f3f;
const int MOD=95041567,STA=8000010;
const double EPS=1e-8;
const double OO=1e15;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
const int dd[3]={1,-1,2};

//end

int k ,n, les;
queue<int> q;
int vis[N];
int step[N];

void dfs(int n){
    q.push(n);
    vis[n] = 1;
    int head, nn = 0;
    while(!q.empty()){
        head = q.front();
        q.pop();
        for (int i = 0; i < 3; i++){
            if (i == 0 && head < k){
                nn = head + dd[i];
            }else if (i == 1 && head > 0){
                nn = head + dd[i];
            }else if (head * dd[i] < N){
                nn = head * dd[i];
            }
            if (nn > N || nn < 0){
                continue;
            }
            if (!vis[nn]){
                q.push(nn);
                step[nn] = step[head] + 1;
                vis[nn] = 1;
            }
            if (nn == k){
                les = step[nn];
                return;
            }
        }
    }
}

int main(){
    while (cin >> n >> k){
        if (n > k){
            cout << n - k << endl;
        }else{
            mem(vis, 0);
            mem(step, 0);
            dfs(n);
            cout << les << endl;
        }
    }
    return 0;
}