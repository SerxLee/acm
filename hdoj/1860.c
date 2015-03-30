#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define maxm 105
#define maxn 105

struct Edge{
    int v;
    int next;
    double rate;
    double commission;
}edge[maxm * 2];

int n, m;
int s;
int head[maxn];
double v;
double dist[maxn];
int in_queue[maxn];//bool  判断是否入栈
int push_cnt[maxn];
int q[maxn];
int edge_cnt;

void addedge(int a, int b, double r, double c)
{
    edge[edge_cnt].v = b;
    edge[edge_cnt].next = head[a];
    edge[edge_cnt].rate = r;
    edge[edge_cnt].commission = c;
    head[a] = edge_cnt++;
}


int spfa(int s)
{
    for (int i = 0; i < n; i++)
        dist[i] = -1;
    dist[s] = v;
    memset(in_queue, 0, sizeof(in_queue));
    memset(push_cnt, 0, sizeof(push_cnt));
    int front, rear;
    front = 0;
    rear = 0;
    q[rear++] = s;
    in_queue[s] = 1;
    push_cnt[s] = 1;
    
    while (front != rear)
    {
        int u = q[front++];
        if (front == maxn)
            front = 0;
        in_queue[u] = 0;
        double cur = dist[u];
        for (int i = head[u]; ~i; i = edge[i].next)
        {
            int v = edge[i].v;
            double r = edge[i].rate;
            double c = edge[i].commission;
            double temp = (cur - c) * r;
            if (temp > dist[v])
            {
                dist[v] = temp;
                if (in_queue[v])
                    continue;
                q[rear++] = v;
                if (rear == maxn)
                    rear = 0;
                in_queue[v] = 1;
                push_cnt[v]++;
                if (push_cnt[v] > n)
                    return 1;
            }
        }
        if (dist[s] > v)
            return 1;
    }
    return 0;
}

int main(){
    edge_cnt = 0;
    memset(head, -1, sizeof(head));
    scanf("%d%d%d%lf", &n, &m, &s, &v);
    s--;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        double r, c;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        scanf("%lf%lf", &r, &c);
        addedge(a, b, r, c);
        scanf("%lf%lf", &r, &c);
        addedge(b, a, r, c);
    }

    if (spfa(s) == 1)
        puts("YES");
    else
        puts("NO");
    return 0;
}