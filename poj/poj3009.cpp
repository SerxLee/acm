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

int w, h, ans;
int board[25][25];
typedef struct point{
    int x, y;
}Point;
Point start, end_;
bool flag = false;
int min_;
bool IsOver(Point now){
    if (now.x == end_.x){
        int s = now.y < end_.y ? now.y : end_.y;
        int e = now.y > end_.y ? now.y : end_.y;
        for (int i = s + 1; i < e; ++ i){
            if (board[now.x][i] != 0){
                return false;
            }
        }
        return true;
    }else if(now.y == end_.y){
        int s = now.x < end_.x ? now.x : end_.x;
        int e = now.x > end_.x ? now.x : end_.x;
        for (int i = s + 1; i < e; ++ i){
            if (board[i][now.y] != 0){
                return false;
            }
        }
        return true;
    }else{
        return false;
    }
    
}
void dfs(Point now){
    if (ans > 9){
        return;
    }
    if (IsOver(now)){
        if (min_ > ans){
            min_ = ans;
        }
        flag = true;
        return;
    }
    
    Point tmp;
    //down
    if (now.x + 1 <= h && ! board[now.x + 1][now.y]){
        for (int i = now.x + 2; i <= h; ++ i){
            if (board[i][now.y]){
                ans ++;
                tmp.x = i - 1;
                tmp.y = now.y;
                board[i][now.y] = 0;
                dfs(tmp);
                board[i][now.y] = 1;
                ans --;
                break;
            }
        }
    }
    //right
    if (now.y + 1 <= w && ! board[now.x][now.y + 1]){
        for (int j = now.y + 2; j <= w; ++ j){
            if (board[now.x][j]){
                ans ++;
                tmp.x = now.x;
                tmp.y = j - 1;
                board[now.x][j] = 0;
                dfs(tmp);
                board[now.x][j] = 1;
                ans --;
                break;
            }
        }
    }
    //up
    if (now.x - 1 >= 1 && ! board[now.x - 1][now.y]){
        for (int i = now.x - 2; i >= 1; -- i){
            if (board[i][now.y]){
                ans ++;
                tmp.x = i + 1;
                tmp.y = now.y;
                board[i][now.y] = 0;
                dfs(tmp);
                board[i][now.y] = 1;
                ans --;
                break;
            }
        }
    }
    //left
    if (now.y - 1 >= 1 && ! board[now.x][now.y - 1]){
        for (int j = now.y - 2; j >= 1; -- j){
            if (board[now.x][j]){
                ans ++;
                tmp.x = now.x;
                tmp.y = j + 1;
                board[now.x][j] = 0;
                dfs(tmp);
                board[now.x][j] = 1;
                ans --;
                break;
            }
        }
    }
    return;
}
int main(){
    while (cin >> w >> h && w && h){
        ans = 0;
        flag = false;
        min_ = INF;
        mem(board, 0);
        for (int i = 1; i <= h; ++ i){
            for (int j = 1; j <= w; ++ j){
                scanf("%d", &board[i][j]);
                if (board[i][j] == 2){
                    start.x = i;
                    start.y = j;
                    board[i][j] = 0;
                }else if (board[i][j] == 3){
                    end_.x = i;
                    end_.y = j;
                }
            }
        }
        dfs(start);
        if (!flag || min_ > 9){
            printf("-1\n");
        }else
            printf("%d\n", min_ + 1);
    }
    return 0;
}
