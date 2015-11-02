#include <iostream>
#include <cstdio>

using namespace std;

template<class T> inline T Max(T a,T b){return a>b?a:b;}

struct node{
    int v, w;
}myarr[110];

int dp[110][100010];

int main(){
    int n , m;

    int lim_n;
    cin >> lim_n;

    for (int i = 1; i <= lim_n; i++){
        cin >> myarr[i].v;
    }
    for (int i = 0; i <= lim_n; i++){
        dp[0][i] = 0;
    }
    for (int i = 1; i <= lim_n; i++){
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