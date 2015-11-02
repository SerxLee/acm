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

#define maxn 150004

using namespace std;
struct node{
    int num;
    char name[201];
    int v;
}a[maxn];
struct node1{
    int t;
    int p;
}vv[maxn];

int  ans[maxn];

bool operator <(const node &a,const node &b){
    if(a.v == b.v){
        return a.num > b.num;
    }
    else
        return a.v < b.v;
}
bool cmp(node1 a,node1 b){
    return a.t < b.t;
}
int main(){
    int T;
    priority_queue<node>qu;
    scanf("%d", &T);
    while(T--) {
        int k, m, q;
        scanf("%d%d%d", &k, &m, &q);
        while(!qu.empty()) qu.pop();
        for(int i = 1;i <= k;i++)  {
            scanf("%s%d",a[i].name,&a[i].v);
            a[i].num = i;
        }
        for(int i = 1;i <= m;i++) {
            scanf("%d%d", &vv[i].t, &vv[i].p);
        }
        sort(vv + 1,vv + m + 1,cmp);
        for(int i = 1;i < m;i++){
            if(vv[i].t == vv[i+1].t){
                vv[i].p += vv[i+1].p;
                for(int j = i+1;j < m;j++){
                    vv[j] = vv[j+1];
                }
                i--;
                m--;
            }
        }

        vv[0].t = 0;
        int now = 0;
        for(int i = 1;i <= m;i++){
            for(int j =vv[i-1].t+1;j <= vv[i].t;j++)
                qu.push(a[j]);
            for(int l = 1;l <= vv[i].p;l++){
                if(qu.empty()) break;
                ans[now+1] = qu.top().num;
                qu.pop();
                now++;
            }
        }
        for(int j = vv[m].t+1;j <= k;j++)
            qu.push(a[j]);
        while(!qu.empty()){
            ans[now+1] = qu.top().num;
            qu.pop();
            now++;
        }
        
        int ques[102];
        for(int i = 1;i <= q;i++){
            scanf("%d", &ques[i]);
        }
        for(int j = 1;j <= q;j++){
            if(j == 1)
                printf("%s",a[ans[ques[j]]].name);
            else
                printf(" %s",a[ans[ques[j]]].name);
        }
        printf("\n");
    }
}