//最长公共子序列代码模板

#include <iostream>

using namespace std;

 

#define N 105

int dp[N+1][N+1];

char str1[N],str2[N];

 

//比较两个数的大小

int maxx(int a,int b){

      if(a>b){

           return a;

      }

      return b;

}

 

//函数功能：获取两个字符串的最长公共子序列的数目

//len1:字符串1的长度

//len2:字符串2的长度

int LCSL(int len1,int len2){

 

      int i,j;

      int len=maxx(len1,len2);

 

      for(i=0;i<=len;i++){

           dp[i][0]=0;//y为空字符串

           dp[0][i]=0;//x为空字符串

      }

 

      for(i=1;i<=len1;i++){

           for(j=1;j<=len2;j++){

                 if(str1[i-1]==str2[j-1]){

                      dp[i][j]=dp[i-1][j-1]+1;

                 }

                 else{

                      dp[i][j] = maxx(dp[i - 1][ j ] , dp[i][j - 1]) ; 

                 }

           }

 

      }

      return dp[len1][len2];

} 

 

int main(){

 

      while(cin>>str1>>str2){

 

           int len1=strlen(str1);//获取字符串1的长度

           int len2=strlen(str2);//获取字符串2的长度

 

           cout<<LCSL(len1,len2)<<endl;

 

      }

      return 0;

 

}

