#include <iostream>
#include <cstdio>

using namespace std;

template<class T> inline T Max(T a,T b){return a>b?a:b;}

struct node{
    int v, w;
}myarr[505];

int dp[502][100010];

int main(){
    int n , m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> myarr[i].v >> myarr[i].w;
    }
    for (int i = 0; i <= m; i++){
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= m; j++){
            if (myarr[i].v > j){
                dp[i][j] = dp[i - 1][j];
            }else{
                dp[i][j] = Max(dp[i - 1][j], dp[i - 1][j - myarr[i].v] + myarr[i].w);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}