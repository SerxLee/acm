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

const int N = 250010;
const int INF=0x3f3f3f3f;
const int MOD=95041567,STA=8000010;
const double EPS=1e-8;
const double OO=1e15;
const int dx[8]={-1,1,-2,2,-2,2,-1,1};
const int dy[8]={-2,-2,-1,-1,1,1,2,2};
const int M = 12;

int myarr[202][202];

int main(){
	int n;
	cin >> n;
	for (int i = 1; i < n ;i++){
		for (int j = 1; j < i; j++){
			cin >> myarr[i][j];
		}
	}
	for (int i = n - 1; i >= 0; i--){
		for (int j = 1; j <= i; j++){
			myarr[i][j] += Max(myarr[i - 1][j], myarr[i][j + 1]);
		}
	}
	cout << myarr[1][1] << endl;
}