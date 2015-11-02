#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Point {
	double x;
	double y;
}p[105];

inline int min(int a, int b) {
	return a < b ? a : b;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int m, n;
		double r[105];
		cin >> m >> n;
		for (int i = 0; i < m; i++) {
			scanf ("%lf%lf", &p[i].x, &p[i].y);
		} 
		int ans = 0xffffff;
	
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				r[j] = sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x) + (p[i].y-p[j].y)*(p[i].y-p[j].y));
			}
			sort(r, r+m);
			if (m == n) {
				ans = min(ans,static_cast<int>(r[m-1]) + 1);
				break;
			}else if (m < n) {
				ans = 0xfffff;
				break;
			}else if (static_cast<int>(r[n-1])+1 < r[n]) {
				ans = min(static_cast<int>(r[n-1])+1, ans);	
			}else {
				ans = 0xfffff;
			}
			
		}
		cout << (ans == 0xfffff ? -1 : ans) << endl;
	}
	return 0;
}


//
//  main.cpp
//  beijing
//
//  Created by Serx on 15/9/20.
//  Copyright (c) 2015年 serx. All rights reserved.
//

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
#define maxn 100010
#define pff pair<float, float>
#define pffi pair<pff, int>

const int INF=0x3f3f3f3f;

template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline void CheckMin(T &a,T b){if(a>b) a=b;}
template<class T> inline void CheckMax(T &a,T b){if(a<b) a=b;}

struct node{
    double x, y;
}g[101];

double len[101][101];
int q[101][1001];

int ansm[101];

double leng(double x1, double y1, double x2, double y2){
    return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1) * (y2 - y1));

int main(){
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++){
            cin >> g[i].x >> g[i].y;
        }
        int all = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (i != j){
                    len[i][j] = leng(g[i].x, g[i].y, g[j].x, g[j].y);
                }else{
                    len[i][j] = INF;
                }
                //cout << len[i][j] << endl;
            }
        }
        
        int num = 0;
        int min = INF;
        int limj;
        for (int i = 0; i < n; i++){
            int lim = 1;
            sort(len[i], len[i] + n - i);
            for (int j = 0; j < n; j++){
                if (i != j){
                    lim++;
                    cout << lim << " ";
                    limj = j;
                    if (lim == m){
                        cout << i  << " " << j << " " << len[i][j] << endl;
                        num = ceil(len[i][limj]);
                        //cout << num << endl;
                        if (num < min){
                            min = num;
                        }
                    }
                }
            }
            cout << endl;
            

        }
        cout << min << endl;
    }
    return 0;
}