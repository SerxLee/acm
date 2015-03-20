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
#include <map>
using namespace std;
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define PI acos(-1.0)
const int N=1010;
const int INF=0x3f3f3f3f;
const int MOD=95041567,STA=8000010;
const double EPS=1e-8;
const double OO=1e15;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
const int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
inline int sign(double x){return (x>EPS)-(x<-EPS);}
template<class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T> T lcm(T a,T b){return a/gcd(a,b)*b;}
template<class T> inline T lcm(T a,T b,T d){return a/d*b;}
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline T Min(T a,T b,T c){return min(min(a, b),c);}
template<class T> inline T Max(T a,T b,T c){return max(max(a, b),c);}
template<class T> inline T Min(T a,T b,T c,T d){return min(min(a, b),min(c,d));}
template<class T> inline T Max(T a,T b,T c,T d){return max(max(a, b),max(c,d));}
//End

int mmap[N][N],link[N],vis[N],vlink[N];
char path[50][50];
int line[50][50];
int n,m,t,tmp1,tmp2;
bool dfs(int x){
    for(int i=1; i<tmp2; i++){
        if(mmap[x][i] == 1 && vis[i]==0)
        {
            vis[i]=1;
            if(link[i]==-1 || dfs(link[i]))
            {
                link[i]=x;
                return true;
            }
        }
    }
    return false;
}
void solve()
{
    int ans=0;
    mem(link,-1);
    for(int i=1; i<tmp1; i++){
        mem(vis,0);
        if(dfs(i))
            ans++;
    }
    printf("%d\n",tmp1+tmp2-ans-2);
}
int main(){
    int T, i, j, k;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        mem(path,0);
        for(i=1;i<=n;i++)
        {
            getchar();
            for(j=1;j<=m;j++)
                scanf("%c",&path[i][j]);
        }
        mem(line,-1);
        tmp1=1,tmp2=1;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(path[i][j]=='*')
                {
                    if((i+j)%2==0)
                        line[i][j]=tmp1++;
                    else
                        line[i][j]=tmp2++;
                }
            }
        }
        
        mem(mmap,0);
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                if(path[i][j]=='*' && (i+j)%2==1)
                {
                    for (k = 0; k < 4; k++) {
                        if (line[i + dx[k]][j + dy[k]] >= 1) {
                            mmap[line[i + dx[k]][j + dy[k]]][line[i][j]] = true;
                        }
                    }
                }
            }
        }
        solve();
    }
    return 0;
}
