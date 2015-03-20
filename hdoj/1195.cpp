#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int visit[4]={0},ss,a[4],b[4];int cmp(int s)  {
    int i,sum,aa[4]={s/1000,s/100%10,s/10%10,s%10};
    for(i=sum=0;i<4;i++){
        if(abs(aa[i]-b[i])<5)
            sum+=abs(aa[i]-b[i]);
        else
            sum+=9-abs(aa[i]-b[i]);
    }return sum;
}
void dfs(int sum,int s) {
    int i;
    if(sum>999)  
    {
        i=cmp(sum)+s;
        if(i<ss)
            ss=i;
        return;
    }pp
    for(i=0;i<4;i++){
        if(!visit[i]){
            visit[i]=1;
            dfs(sum*10+a[i],s++);
            visit[i]=0;
        }
    }
}
int main (void)
{
    int i,j,n,m,t;
    cin>>t;
    while(t--&&cin>>n>>m){
        for(i=3,j=1;i>=0;i--,j*=10){
            a[i]=n/j%10;
            b[i]=m/j%10;
        }
        ss=99999;
        dfs(0,0);
        cout<<ss<<endl;
        
    }
    return 0;
}