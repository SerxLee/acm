
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
typedef __int64 LL;
typedef unsigned __int64 ULL;
const int N=1010;
const int INF=0x3f3f3f3f;
const int MOD=95041567,STA=8000010;
const LL LNF=1LL<<60;
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

int vis[N],y[N],w[N][N],t[N][2],id[N],l[N],r[N];
int n,a,b,cnt1,cnt2;

int dfs(int u)
{
    int v;
    for(v=0;v<cnt1;v++){
        if(vis[v] || !w[u][v])continue;
        vis[v]=1;
        if(y[v]==-1 || dfs(y[v])){
            y[v]=u;
            return 1;
        }
    }
    return 0;
}

int main()
{
    int i,j,L,R,ok;
    while(~scanf("%d%d",&a,&b))
    {
        L=b+1,R=a-1;
        scanf("%d",&n);
        cnt1=cnt2=0;
        for(i=0;i<n;i++){
            scanf("%d%d",&t[i][0],&t[i][1]);
            if(t[i][1]){
                l[cnt1]=i;
                id[i]=cnt1++;
            }
            else {
                r[cnt2]=i;
                id[i]=cnt2++;
            }
        }
        mem(w,0);
        for(i=0;i<n;i++){
            if(t[i][1]==0)continue;
            for(j=i-1;j>=0;j--){
                if(t[j][1]==1)continue;
                if(t[i][0]-t[j][0]>=L && t[i][0]-t[j][0]<=R)continue;
                w[id[i]][id[j]]=1;
            }
        }
        mem(y,-1);ok=1;
        for(i=0;i<cnt1;i++){
            mem(vis,0);
            if(dfs(i)==0){
                ok=0;
                break;
            }
        }

        if(ok){
            printf("No reason\n");
            for(i=0;i<cnt1;i++){
                printf("%d %d\n",t[r[i]][0],t[ l[ y[i] ] ][0]);
            }
        }
        else printf("Liar\n");

    }
    return 0;
}