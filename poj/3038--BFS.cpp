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

const int N = 42;
const int INF=0x3f3f3f3f;
const int MOD=95041567,STA=8000010;
const double EPS=1e-8;
const double OO=1e15;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
const int M = 12;

int mapp[N][N];
int w, h, flag, ansl, ansr, lu;
int vis[N][N];

struct persion{
    int x, y;
    int lu;
    friend bool operator < (const persion &a, const persion &b){
        return a.lu > b.lu;
    }
};

persion en, stt;

//bool inmap(int x, int y){
//    if (x > 0 && x <= h && y > 0 && y <= w) {
//        return true;
//    }
//    return false;
//}

int bfs_shortest(int x, int y){
    priority_queue<persion> q;
    persion next, now;
    mem(vis, 0);
    now.x = x;
    now.y = y;
    now.lu = 1;
    vis[now.x][now.y] = 1;
    q.push(now);
    while (!q.empty()) {
        now = q.top();
        q.pop();
        for (int i = 0; i < 4; i++) {
            next.x = now.x + dx[i];
            next.y = now.y + dy[i];
            next.lu = now.lu + 1;
            if (!vis[next.x][next.y] && mapp[next.x][next.y]) {
                if (next.x == en.x && next.y == en.y) {
                    return next.lu;
                }
                vis[next.x][next.y] = 1;
                q.push(next);
            }
        }
    }
    return 0;
}

void Dfsl(int x, int y, int step, int face){
    if (flag == 1) {
        return;
    }
    if (x == en.x && y == en.y){
        flag = 1;
        ansl = step;
        return;
    }
    if (face == 1){
        if (mapp[x+1][y])    Dfsl(x+1,y,step+1,4);
        if (mapp[x][y-1])    Dfsl(x,y-1,step+1,1);
        if (mapp[x-1][y])    Dfsl(x-1,y,step+1,2);
        if (mapp[x][y+1])    Dfsl(x,y+1,step+1,3);
    }else if (face == 2){
        if (mapp[x][y-1])    Dfsl(x,y-1,step+1,1);
        if (mapp[x-1][y])    Dfsl(x-1,y,step+1,2);
        if (mapp[x][y+1])    Dfsl(x,y+1,step+1,3);
        if (mapp[x+1][y])    Dfsl(x+1,y,step+1,4);
    }else if (face == 3){
        if (mapp[x-1][y])    Dfsl(x-1,y,step+1,2);
        if (mapp[x][y+1])    Dfsl(x,y+1,step+1,3);
        if (mapp[x+1][y])    Dfsl(x+1,y,step+1,4);
        if (mapp[x][y-1])    Dfsl(x,y-1,step+1,1);
    }else{
        if (mapp[x][y+1])    Dfsl(x,y+1,step+1,3);
        if (mapp[x+1][y])    Dfsl(x+1,y,step+1,4);
        if (mapp[x][y-1])    Dfsl(x,y-1,step+1,1);
        if (mapp[x-1][y])    Dfsl(x-1,y,step+1,2);
    }
}

void Dfsr(int x,int y,int step,int face){
    if(flag == 1)
        return;
    if(x == en.x && y == en.y){
        flag = 1;
        ansr = step;
        return;
    }
    if(face == 1){
        if (mapp[x - 1][y])     Dfsr(x - 1, y, step + 1, 2);
        if (mapp[x][y - 1])     Dfsr(x, y - 1, step + 1, 1);
        if (mapp[x + 1][y])     Dfsr(x + 1, y, step + 1, 4);
        if (mapp[x][y + 1])     Dfsr(x, y + 1, step + 1, 3);
    }
    else if (face == 2){
        if (mapp[x][y + 1])     Dfsr(x, y + 1, step + 1, 3);
        if (mapp[x-1][y])     Dfsr(x-1,y,step+1,2);
        if (mapp[x][y-1])     Dfsr(x,y-1,step+1,1);
        if (mapp[x+1][y])     Dfsr(x+1,y,step+1,4);
    }
    else if (face == 3){
        if (mapp[x+1][y])     Dfsr(x+1,y,step+1,4);
        if (mapp[x][y+1])     Dfsr(x,y+1,step+1,3);
        if (mapp[x-1][y])     Dfsr(x-1,y,step+1,2);
        if (mapp[x][y-1])     Dfsr(x,y-1,step+1,1);
    }
    else{
        if (mapp[x][y-1])     Dfsr(x,y-1,step+1,1);
        if (mapp[x+1][y])     Dfsr(x+1,y,step+1,4);
        if (mapp[x][y+1])     Dfsr(x,y+1,step+1,3);
        if (mapp[x-1][y])     Dfsr(x-1,y,step+1,2);
    }
}

int main(){
    int T;
    cin >> T;
    char lim[50];
    while (T--) {
        scanf("%d%d",&w,&h);
        getchar();
        mem(mapp, 0);
        for (int i = 1; i <= h; i++) {
            gets(lim);
            for (int j = 0; j < w; j++) {
                if (lim[j] == '.') {
                    mapp[i][j + 1] = 1;
                }
                if (lim[j] == 'S') {
                    mapp[i][j + 1] = 1;
                    stt.y = j + 1;
                    stt.x = i;
                }
                if (lim[j] == 'E') {
                    mapp[i][j + 1] = 1;
                    en.x = i;
                    en.y = j + 1;
                }
            }
        }
//        for (int i = 1; i <= h; i++) {
//            for (int j = 1; j <= w; j++) {
//                cout << mapp[i][j];
//            }
//            cout << endl;
//        }
        lu = bfs_shortest(stt.x, stt.y);
        flag = 0;
        Dfsl(stt.x, stt.y, 1, 1);
        flag = 0;
        Dfsr(stt.x, stt.y, 1, 1);
        printf("%d %d %d\n", ansl, ansr, lu);
    }
    return 0;
}
