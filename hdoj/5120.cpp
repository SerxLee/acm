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
#define PI 3.14159265359

template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline void CheckMin(T &a,T b){if(a>b) a=b;}
template<class T> inline void CheckMax(T &a,T b){if(a<b) a=b;}

const int N = 3010;
const int INF=0x3f3f3f3f;
const int MOD=95041567,STA=8000010;
const double EPS=1e-8;
const double OO=1e15;
const int dx[8]={-1,1,-2,2,-2,2,-1,1};
//{-1,0,1,0};
const int dy[8]={-2,-2,-1,-1,1,1,2,2};
//{0,1,0,-1};
const int M = 12;

//end

struct node{
    int x, y;
};

double AREA(node a, double r1, node b, double r2){
    double d = sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
    if (d >= r1 + r2)
        return 0;
    if (r1 > r2){
        double tmp = r1;
        r1 = r2;
        r2 = tmp;
    }
    if (r2 - r1 >= d)
        return PI * r1 * r1;
    double ang1 = acos((r1*r1 + d*d - r2*r2) / (2*r1*d));
    double ang2 = acos((r2*r2 + d*d - r1*r1) / (2*r2*d));
    return ang1*r1*r1 + ang2*r2*r2 - r1*d*sin(ang1);
}

int main(){
    int T;
    cin >> T;
    for (int ii = 1; ii <= T; ii++) {
        node a, b;
        double r1, r2;
        scanf("%lf%lf", &r1, &r2);
        scanf("%d%d%d%d", &a.x, &a.y, &b.x, &b.y);
        double result;
        result = AREA(a, r2, b, r2) - AREA(a, r1, b, r2) - AREA(a, r2, b, r1) + AREA(a, r1, b, r1);
        printf("Case #%d: %8lf\n", ii, result);
    }
    return 0;
}