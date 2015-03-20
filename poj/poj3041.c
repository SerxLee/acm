#include <stdio.h>

#define maxn 501

struct Edge
{
    int v;
};

int n, k, map[maxn][maxn];
int vis[maxn], connect[maxn];

void input()
{
    int i;
    for (i =0; i < k; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        map[a][b] =1;
    }
}

int work(int a)
{
    int i;
    for (i =0; i < n; i++)
        if (map[a][i] &&!vis[i])
        {
            vis[i] =1;
            if (connect[i] ==-1|| work(connect[i]))
            {
                connect[i] = a;
                return1;
            }
        }
    return0;
}

int main()
{
    scanf("%d%d", &n, &k);
    input();
    int i;
    memset(connect, -1, sizeof(connect));
    for (i =0; i < n; i++)
    {
        memset(vis, 0, sizeof(vis));
        work(i);
    }
    int ans =0;
    for (i =0; i < n; i++)
        if (connect[i] !=-1)
            ans++;
    printf("%d", ans);
    return0;
}