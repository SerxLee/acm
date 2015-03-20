/*
ID: sdj22251
PROG: subset
LANG: C++
*/
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#define MAXN 222222
#define MAXM 104444
#define INF 100000000
#define PI acos(-1.0)
#define eps 1e-12
#define L(X) X<<1
#define R(X) X<<1|1
using namespace std;
struct node
{
    int v, next;
}edge[2 * MAXN];
int head[MAXN], e, cnt, n, m;
int low[MAXN], high[MAXN], vis[MAXN], a[MAXN];
void insert(int x, int y)
{
    edge[e].v = y;
    edge[e].next = head[x];
    head[x] = e++;
    edge[e].v = x;
    edge[e].next = head[y];
    head[y] = e++;
}
void init()
{
    e = cnt = 0;
    memset(head, -1, sizeof(head));
}
void dfs(int u)
{
    low[u] = ++cnt;
    vis[u] = 1;
    for(int i = head[u]; i != -1; i = edge[i].next)
    if(!vis[edge[i].v]) dfs(edge[i].v);
    high[u] = cnt;
}
int lowbit(int x)
{
    return x & -x;
}
void modify(int x, int v)
{
    for(int i = x; i <= n; i += lowbit(i))
        a[i] += v;
}
int get_sum(int x)
{
    int sum = 0;
    for(int i = x; i >= 1; i -= lowbit(i))
        sum += a[i];
    return sum;
}
int main()
{
    init();
    scanf("%d", &n);
    int x, y;
    char op[5];
    for(int i = 0; i < n - 1; i++)
    {
        scanf("%d%d", &x, &y);
        insert(x, y);
    }
    dfs(1);
    scanf("%d", &m);
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i++)
        modify(i, 1);
    for(int i = 0; i < m; i++)
    {
        scanf("%s%d", op, &x);
        if(op[0] == 'C')
        {
            if(vis[x]) modify(low[x], 1);
            else modify(low[x], -1);
            vis[x] = (!vis[x]);
        }
        else
        {
            int ans = get_sum(high[x]) - get_sum(low[x] - 1);
            printf("%d\n", ans);
        }
    }
    return 0;
}
