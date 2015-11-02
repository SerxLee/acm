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
#define maxn  500005

const int INF=0x3f3f3f3f;

template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline void CheckMin(T &a,T b){if(a>b) a=b;}
template<class T> inline void CheckMax(T &a,T b){if(a<b) a=b;}

int n;

map<int, int> mymap;
int link[maxn][maxn];
int dp[maxn][maxn];
int line1[maxn];
int line2[maxn];



int main(){
	while (cin >> n){
		mem(link, 0, sizeof(link));
		mem(dp, 0, sizeof(dp));
		int x, y;
		int sum1 = n;
		int sum2 = n;
		for (int i = 0 ;i < n; i++){
			cin >> x >> y;
			line1[i] = x - 1;
			line2[i] = y - 1;
		}
		for (int i = 0; i < n; i++){
			link[line1][line2] = 1;
		}
		int max = 0;
		for (int i = sum1; i >= 0; i--){
			for (int j = sum2; j >= 0; j--){
				for (int k = 0; k < n; k++){
					if (line1[k] >= (n - sum1) && line2[k] >= (n - sum2)){
						max = Max(max, dp[i - line1[k]][j - line2[k]] + link[line1[k]][line2[k]]);
					}
				}
			}
		}
		cout << max << endl;
	}
}