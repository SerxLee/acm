#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <cassert>
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
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define PI acos(-1.0)
const int N=10100;
const int INF=0x3f3f3f3f;
const int MOD=95041567,STA=8000010;
const double EPS=1e-8;
const double OO=1e15;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
const int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
inline int sign(double x){return (x>EPS)-(x<-EPS);}
template<class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T> T lcm(T a,T b){return a/gcd(a,b)*b;}
template<class T> inline T lcm(T a,T b,T d){return a/d*b;}
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline T Min(T a,T b,T c){return min(min(a, b),c);}
template<class T> inline T Max(T a,T b,T c){return max(max(a, b),c);}
template<class T> inline T Min(T a,T b,T c,T d){return min(min(a, b),min(c,d));}
template<class T> inline T Max(T a,T b,T c,T d){return max(max(a, b),max(c,d));}


char str1[N][20];
int sum_1, sum_2;
int len2,len1;

void getdic(){
    sum_1 = 0;
    while (scanf("%s%*c", str1[sum_1])) {
        if (str1[sum_1][0]== '#') {
            break;
        }else sum_1++;
    }
}

bool Cor(char *str){
    int i;
    for(i = 0;i < sum_1; i++)
        if(strcmp(str1[i],str) == 0)
            return true;
    return false;
}

void duoyi(char *str2, char *str1){
    int arr[20], j, k, isSort;
    mem(arr, -1);
    for(j = 0; j < len1; j++){
        for(k = j == 0 ? 0 : arr[j - 1] + 1; k < len2; k++){
            if(str2[k] == str1[j]){
                arr[j] = k;
                break;
            }
        }
    }
    isSort = 1;
    for(j = 0;j < len1 - 1; j++){
        if(arr[j+1] < arr[j] || arr[j] == -1){
            isSort = 0;
            break;
        }
    }
    if(arr[len1 - 1] == -1)
        isSort = 0;
    if(isSort)
        printf(" %s",str1);
}
void shaoyi(char *str2, char *str1){
    int arr[20], j, k, isSort;
    mem(arr,-1);
    for(j = 0; j < len2; j++){
        for(k = j == 0 ? 0 : arr[j - 1] + 1; k < len1; k++){
            if(str2[j] == str1[k]){
                arr[j] = k;
                break;
            }
        }
    }
    isSort = 1;
    for(j = 0; j < len2 - 1; j++){
        if(arr[j + 1] < arr[j] || arr[j] == -1){
            isSort = 0;
            break;
        }
    }
    if(arr[len2 - 1] == -1)
        isSort = 0;
    if(isSort)
        printf(" %s",str1);
}

void chongfu(char *str){
    printf("%s:",str);
    int i, j, k, diff;
    len2 = strlen(str);
    for(i = 0; i < sum_1; i++){
        len1 = strlen(str1[i]);
        if(len2 == len1){
            diff = 0;
            for(j = 0;j < len1; j++){
                if(str[j] != str1[i][j])
                    diff++;
            }
            if(diff == 1)
                printf(" %s",str1[i]);
        }
        else if(len2 == len1 + 1){
            duoyi(str, str1[i]);
        }
        else if(len2 + 1 == len1){
            shaoyi(str, str1[i]);
        }
    }
}
int main(){
    int i, j;
    getdic();
    char str2[50][20];
    sum_2 = 0;
    for (j = 0; j < 50; j++) {
        scanf("%s%*c",str2[sum_2]);
        if (str2[sum_2][0] == '#') {
            break;
        }else{
            sum_2++;
        }
    }
    for (i = 0; i < sum_2; i++) {
        if(Cor(str2[i]))
            printf("%s is correct\n",str2[i]);
        else{
            chongfu(str2[i]);
            printf("\n");
        }
    }
    return 0;
}