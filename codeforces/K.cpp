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

double p, a, b, c, d, n;

int main(){
	while (cin  >> p >> a >> b >> c >> d >> n){
		double bb = 0;
		int si, co;
		for (int i = 1; i <= n; i++){
			si = sin(a * i + b);
			co = cos(c * k + d);
			double lim = p * ( si + co + 2);
			bb = Max(bb, lim);
		}
		cout << bb << endl;	
	}
	return 0;
}