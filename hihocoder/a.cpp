#include <cstdio>
#include <cstring>
const int N = 13;
const int M = 1<<N;
const int mod = 100000000;
int st[M],map[M];  ///分别存每一行的状态和给出地的状态
int dp[N][M];  //表示在第i行状态为j时候可以放牛的种数
bool judge1(int x)  //判断二进制有没有相邻的1
{
    return (x&(x<<1));
}
bool judge2(int i,int x)
{
    return (map[i]&st[x]);
}
int main()
{
    int n,m,x;
    while(~scanf("%d%d",&n,&m))
    {
        memset(st,0,sizeof(st));
        memset(map,0,sizeof(map));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++){
                scanf("%d",&x);
                if(x==0)
                    map[i]+=(1<<(j-1));
            }

        }
        int k=0;
        for(int i=0;i<(1<<m);i++){
            if(!judge1(i))
                st[k++]=i;
        }
        for(int i=0;i<k;i++)
        {
            if(!judge2(1,i))
                dp[1][i]=1;
        }
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<k;j++)
            {
                if(judge2(i,j))  //判断第i行 假如按状态j放牛的话行不行。
                    continue;
                for(int f=0;f<k;f++)
                {
                    if(judge2(i-1,f))   //剪枝 判断上一行与其状态是否满足
                        continue;
                    if(!(st[j]&st[f]))
                        dp[i][j]+=dp[i-1][f];
                }
            }
        }
        int ans=0;
        for(int i=0;i<k;i++){
            ans+=dp[n][i];
            ans%=mod;
        }
        printf("%d\n",ans);
    }
    return 0;
}
