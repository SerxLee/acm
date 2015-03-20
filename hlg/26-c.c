#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long double n,arr[107],sum=0,cnt=0,mark[107]={0},sum2=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
       cin>>arr[i];
       sum+=arr[i];
    }
    long double self=sum/(n+1);
    for(int i=0;i<n;i++)
    {
       if(arr[i]-self>0)
       {
          mark[i]=arr[i]-self;
       }
    }
    for(int i=0;i<n;i++)
    {
          sum2+=mark[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<floor(100*mark[i]/sum2+0.0001)<<endl;      
    }
    cin>>n;
}
    
    