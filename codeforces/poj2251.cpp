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
#include <cctype>
#include <list>
#include <set>
#include <map>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1

const int N = 105;
const int INF=0x3f3f3f3f;
const int MOD=95041567,STA=8000010;
const double EPS=1e-8;
const double OO=1e15;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline void checkmin(T &a,T b){if(a>b) a=b;}
template<class T> inline void checkmax(T &a,T b){if(a<b) a=b;}
template<class T> inline void swap1(T& a, T& b){T c(a); a = b; b = c;}

struct node{
    int z , x, y;
}s;

int l, r, c, flag;
int num, tim;
char map_[N][N][N];
int vis[N][N][N];

bool inmap(int x, int y){
    if (x > 0 && x <= r && y > 0 && y <= c) {
        return true;
    }
    return false;
}

void dd(int z, int x, int y){
    vis[z][x][y] = 1;
    if (map_[z][x][y] == 'E'){
        tim = Min(tim, num);
        flag = 1;
        num = 0;
        return;
    }
    if (z > l){
        return;
    }
    
    int xx, yy;
    for (int i = 0; i < 4 ; i++){
        xx = x + dx[i];
        yy = y + dy[i];
        if (map_[z][xx][yy] == 'E'){
            num++;
            tim = Min(tim, num);
            flag = 1;
            num = 0;
            return;
        }
        
//        if (map_[z + 1][xx][yy] == 'E') {
//            num += 2;
//            tim = Min(tim, num);
//            flag = 1;
//            return;
//        }
        if (inmap(xx, yy) && !vis[z][xx][yy] && map_[z][xx][yy] == '.'){
            num++;
            if (map_[z + 1][xx][yy] != '#'){
                num++;
                dd(z + 1, xx, yy);
                if (flag) {
                    return;
                }
            }
            dd(z, xx, yy);
        }
    }
}

int main(){
    while (cin >> l >> r >> c && l && r && c){
        num = flag = 0;
        tim = INF;
        mem(vis, 0);
        for (int il = 1; il <= l; il++){
            for (int ir = 1 ; ir <= r ; ir++){
                for (int ic = 1; ic <= c ; ic++){
                    cin >> map_[il][ir][ic];
                    if (map_[il][ir][ic] == 'S'){
                        s.z = il;
                        s.x = ir;
                        s.y = ic;
                    }
                }
            }
            getchar();
        }
        vis[s.z][s.x][s.y] = 1;
//        printf("%d %d %d\n", s.z, s.x, s.y);
        dd(s.z, s.x, s.y);
        if (tim == INF){
            printf("Trapped!\n");
        }else{
            printf("Escaped in %d minute(s).\n", tim);
        }
    }
    return 0;
}