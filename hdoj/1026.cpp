//杭电1026   优先队列 + bfs宽搜 + 栈stack

#include <stack>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int n , m;
char map[100][100];
int mov[4][2] = {1,0,0,1,-1,0,0,-1};
int flag[100][100];


struct node{
    int x, y, time;
    friend bool operator < (node a , node b){
        return a.time > b.time;
    }
};

struct node1{
    int xx;
    int yy;
};

node1 road[100][100];

bool inmap(int x,int y){
    if (x >= 0 && x <= 9 && y >= 0 && y <= 9) {
        return true;
    }else{
        return false;
    }
}

int bfs(){
    int i;
    priority_queue<node>q;
    node first;
    node next;
    first.x = 0;
    first.y = 0;
    first.time = 0;
    flag[0][0] = 0;
    q.push(first);
    while (!q.empty()) {
        first = q.top();
        q.pop();
        for (i = 0; i < 4; i++) {
            next.x = first.x + mov[i][0];
            next.y = first.y + mov[i][1];
            next.time = first.time + 1;
            if (inmap(next.x, next.y) && !flag[next.x][next.y]) {
                if (map[next.x][next.y] > '0' && map[next.x][next.y]  <= '9') {
                    next.time += map[next.x][next.y] - '0';
                }
                if (map[next.x][next.y] != 'X') {
                    flag[next.x][next.y] = 1;
                    q.push(next);
                    road[next.x][next.y].xx = first.x;
                    road[next.x][next.y].yy = first.y;
                }
            }
            if (next.x == n - 1 && next.y == m - 1) {
                return next.time;
            }
        }
    }
    return -1;
}

int main(){
    int i, t, j, k;
    while (~scanf("%d%d", &n, &m)) {
        memset(flag, 0, sizeof(flag));
        for (i = 0; i < n; i++) {
            scanf("%s", map[i]);
        }
        t = bfs();
        if (t != -1) {
            stack<node>s;
            printf("It takes %d seconds to reach the target position, let me show you the way.\n", t);
            node moving;
            moving.x = n - 1;
            moving.y = m - 1;
            int x, y;
            while (moving.x != 0 || moving.y != 0) {
                s.push(moving);
                x = road[moving.x][moving.y].xx;
                y = road[moving.x][moving.y].yy;
                moving.x = x;
                moving.y = y;
            }
            int tt = 1;
            printf("%ds:(0, 0)", tt++);
            while (!s.empty()) {
                moving = s.top();
                s.pop();
                printf("->(%d,%d)\n", moving.x, moving.y);
                if (map[moving.x][moving.y] > '0' && map[moving.x][moving.y] < '9') {
                    j = map[moving.x][moving.y] - '0';
                    for (k = 0; k < j; k++) {
                        printf("%ds:FIGHT AT (%d,%d)\n", tt++, moving.x, moving.y);
                    }
                }
                if (moving.x == n - 1 && moving.y == m - 1) {
                    continue;
                }
                printf("%ds:(%d,%d)", tt++, moving.x, moving.y);
            }
        }else{
            printf("God please help our poor hero.\n");
        }
        printf("FINISH\n");
    }
    return 0;
}