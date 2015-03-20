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
const int N = 10100;
const int INF=0x3f3f3f3f;
const int MOD=95041567,STA=8000010;
const double EPS=1e-8;
const double OO=1e15;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}

struct node{
    int x;
    friend bool operator< (node a, node b){
        return b.x < a.x;
    }
};

void quicksortt(node a[], int l, int k){
    if (l < k) {
        int i = l , j = k;
         node tmp = a[l];
        while (i < j) {
            while (i < j && a[j].x <= tmp.x) {
                j--;
            }
            if (i<j) {
                a[i++]= a[j];
            }
            
            while (i<j && a[i].x >= tmp.x) {
                i++;
            }
            if (i<j) {
                a[j--] = a[i];
            }
        }
        a[i] = tmp;
        quicksortt(a, l, i-1);
        quicksortt(a, i+1, k);
    }
}

int main(){
    int n;
    node a[N];
    while (scanf("%d", &n) != EOF) {
        priority_queue<node> q;
        deque<node> deq;
        int time = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i].x);
        }
        quicksortt(a, 0, n - 1);
        for (int i = 0; i < n; i++) {
            deq.push_back(a[i]);
        }
        node f1, f2, b1, b2, hui;
        while (deq.size() >= 2) {
            f1 = deq.back();
            deq.pop_back();
            f2 = deq.back();
            deq.pop_back();
            printf("%d %d ", f1.x, f2.x);
            time += f2.x;
            printf("%d ", time);
            q.push(f1);
            q.push(f2);
            if (deq.size() < 2) {
                break;
            }else{
                hui = q.top();
                q.pop();
                time += hui.x;
                printf("%d ", time);
                deq.push_back(hui);
                b1 = deq.front();
                deq.pop_front();
                b2 = deq.front();
                deq.pop_front();
                time += b1.x;
                printf("%d ", time);
                q.push(b1);
                q.push(b2);
                if (deq.size() < 2) {
                    printf("%d ", q.top().x);
                    break;
                }else{
                    hui = q.top();
                    time += hui.x;
                    printf("%d ", time);
                    q.pop();
                    deq.push_back(hui);
                }
            }
        }
        if (deq.size() == 1) {
            hui = q.top();
            time += hui.x;
            printf("%d ", time);
            if (deq.front().x > hui.x) {
                hui = deq.front();
            }
            time += hui.x;
            printf("%d ", time);
            deq.pop_back();
        }else{
            printf("%d\n", time);
        }
    }
    return 0;
}