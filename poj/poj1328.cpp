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
const int N = 1010;
const int INF=0x3f3f3f3f;
const int MOD=95041567,STA=8000010;
const double EPS=1e-8;
const double OO=1e15;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}

struct point{
    double left, right;
} ;

point a[N], temp;

void quicksort(point a[], int l, int k){
    if (l < k) {
        int i = l , j = k;
        point tmp = a[l];
        while (i < j) {
            while (i < j && a[j].left >= tmp.left) {
                j--;
            }
            if (i<j) {
                a[i++] = a[j];
            }
            
            while (i<j && a[i].left <= tmp.left) {
                i++;
            }
            if (i<j) {
                a[j--] = a[i];
            }
        }
        a[i] = tmp;
        quicksort(a, l, i-1);
        quicksort(a, i+1, k);
    }
}
int main(){
    int count, i, num, t;
    double x, y, d;
    int flat;
    num = 1;
    while(~scanf("%d %lf",&t, &d) && (t || d)){
        count = 1;
        flat = 0;
        for(i = 0; i < t; i++){
            scanf("%lf %lf",&x, &y);
            if(abs(y) > d)
                flat = 1;
            else{
                a[i].left = x*1.0 - sqrt(d*d-y*y);
                a[i].right = x*1.0 + sqrt(d*d-y*y);
            }
        }
        printf("Case %d: ",num++);
        if(flat == 1)
            printf("-1\n");
        else{
            quicksort(a , 0, t - 1);
            temp = a[0];
            for(i = 1; i < t; i++){
                if(a[i].left > temp.right){
                    count++;
                    temp = a[i];
                }
                else if(a[i].right < temp.right){
                    temp = a[i];
                }
            }
            printf("%d\n",count);
        }
    }
}
