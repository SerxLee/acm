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

const int N = 10000010;
const int M = 100010;
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


//end

int map_[20][20];
int start, end;
int un_net_x[20][4][4];
int un_net_y[20][4][4];
int n , m;
int sx = 0, sy = 0, ex = 0, ey = 0;
int flag = 0, min_;


bool in_map(int x, int y){
    if (x > 0 && x <= n && y > 0 && y <= m)
        return true;
    return false;
}
int nn = 1;
int ans = 0;

bool over(int x, int y){
    int ss = 0, ee = 0;
    cout << "aa" <<endl;
    if (x == ex && y == ey) {
        return true;
    }
    if (x == ex){
        cout << "xx" << endl;
        ss = y;
        ee = ey;
        if (y > ey) {
            swap1(ss, ee);
        }
//        printf("%d %d\n", ss, ee);
        for (int i = ss; i < ee; i++) {
//            printf("%d ", map_[x][i]);
            if (map_[x][i] != 0) {
                return false;
            }
        }
//        printf("\n");
        return true;
    }
    if (y == ey){
        cout << "yy" <<endl;
        ss = x;
        ee = ex;
        if (x > ex) {
            swap1(ss, ee);
        }
        for (int i = ss; i < ee; i++) {
            if (map_[i][y] != 0) {
                return false;
            }
        }
        return true;
    }
    return false;
}

void dfs(int x,int y){
    cout << ans << "  " << x << " " << y;
    if (ans > 9) {
        ans = -1;
        return;
    }
    
    if (over(x, y)){
        if (min_ > ans) {
            min_ = ans;
        }
        flag = 1;
        printf("%d\n", min_);
        return;
    }
    int xx, yy;
        for (int i = 0; i < 4; i++) {
            printf("%d\n", i);
            flag = 0;
            if (in_map(x + dx[i], y + dy[i]) && !map_[x + dx[i]][y + dy[i]]) {
                if (i == 0 && !flag) { //up
                    for (int j = x - 2; j >= 1; j--) {
                        if (map_[j][y]) {
                            xx = j + 1;
                            ans++;
                            map_[j][y] = 0;
                            cout << "up  ";
                            dfs(xx, y);
                            if (flag) {
                                printf("bb\n");
                                break;
                            }
                            map_[j][y] = 1;
                            ans--;
                            break;
                        }
                    }
                }
                if (i == 1 && !flag) { //right
                    for (int j = y + 2; j <= m; j++) {
                        if (map_[x][j]) {
                            yy = j - 1;
                            ans++;
                            map_[x][j] = 0;
                            cout << "right  ";
                            dfs(x, yy);
                            if (flag) {
                                printf("bb\n");
                                break;
                            }
                            map_[x][j] = 1;
                            ans--;
                            break;
                        }
                    }

                }
                if (i == 2 && !flag) { //down
                    for (int j = x + 2; j <= n; j++) {
                        if (map_[j][y]) {
                            xx = j - 1;
                            ans++;
                            map_[j][y] = 0;
                            cout << "down  ";
                            dfs(xx, y);
                            if (flag) {
                                printf("bb\n");
                                break;
                            }
                            map_[j][y] = 1;
                            ans--;
                            break;
                        }
                    }

                }
                if (i == 3 && !flag) { //left
                    for (int j = y - 1; j >= 1; j--) {
                        if (map_[x][j]) {
                            yy = j + 1;
                            ans++;
                            map_[x][j] = 0;
                            cout << "left  ";
                            dfs(x, yy);
                            if (flag) {
                                printf("bb\n");
                                break;
                            }
                            map_[x][j] = 1;
                            ans--;
                            break;
                        }
                    }
                }
            }
        }
}


//int dfs(int x, int y){
//    num++;
////    printf("%d %d %d\n", nn++, x , y);
//    int xx, yy;
//    for (int i = 0; i < 4; i++){
//        if (dx[i] == 0 && !un_net_y[y][dx[i] + 1][dy[i] + 1]){
//            continue;
//        }else if (!un_net_x[x][dx[i] + 1][dy[i] + 1]){
//            continue;
//        }
//        xx = x + dx[i];
//        yy = y + dy[i];
//        if (map_[xx][yy] == 3){
//            return 1;
//        }
//        if (map_[xx][yy] == 1) {
//            continue;
//        }
//        int flag = 1;
//        while(map_[xx][yy] == 0 && flag){
////            printf("come in\n");
//            xx += dx[i];
//            yy += dy[i];
////            cout <<"xunhuan:" << xx << " " << yy << " " << i << endl;
//            if (!in_map(xx , yy)){
////                cout << "a" << endl;
//                flag = 0;
//                if (xx != x){
//                    un_net_y[y][dx[i] + 1][dy[i] + 1] = 0;
//                }else{
//                    un_net_x[x][dx[i] + 1][dy[i] + 1] = 0;
//                }
//            }
//            if (map_[xx][yy] == 3){
////                cout << "b" << endl;
//                return 1;
//            }
//            if (map_[xx + dx[i]][yy + dy[i]] == 1){
////                cout << "c" << endl;
//                flag = 0;
//                map_[xx + dx[i]][yy + dy[i]] = 0;
//                if (dfs(xx, yy)) {
//                    return 1;
//                }
//            }
//        }
//    }
//    return 0;
//}

int main(){
    while (cin >> n >> m && n && m){
        min_ = INF;
        ans = 0;
        mem(map_, -1);
        mem(un_net_y, 1);
        mem(un_net_x, 1);
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cin >> map_[i][j];
                if (map_[i][j] == 2){
                    sx = i;
                    sy = j;
                    map_[i][j] = 0;
                }
                if (map_[i][j] == 3){
                    ex = i;
                    ey = j;
                    map_[i][j] = 0;
                }
            }
        }
//        int link = dfs(sx, sy);
//        cout << link << endl;
        dfs(sx, sy);
        cout << min_ << endl;
    }
    return 0;
}w