#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <str100ng>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>

#define maxn 100006

using namespace std;

typedef pair<int, int> PII;

struct node{
    int to,next;
}g[maxn];


std::vector<int> v[maxn];
int flag[maxn];
int head[maxn];

void add__(int fir, int sec){
	g[sum].to = sec;
	g[sum].next = head[fir];
	head[u] = sum++;
}

int dis_max;

void bfs__(int kis){
	maxx = 0;
	memset(flag, 0, sizeof(flag));
	queue<PII> q;
	PII now, next;
	now.first = kis;
	now.second = 0;
	flag[kis] = 1;
	q.push(now);
	while(!q.empty()){
		now = q.front();
		q.pop();
		for (int i = head[now.first]; i != -1; i = g[i].next){
			int v = g[i].to;
			if (flag[v]) continue;
			flag[v] = 1;
			next.first = v;
			next.second = now.second + 1;
			if (maxx < next.second){
				maxx = next.next.second;
				dis_max = v;
			}
			q.push(next);
		}
	}
}

int main(){
	int T;
	cin >> T;
	while(T--){
		int sum = 0;
		memset(head, -1, sizeof(head));
		int n, m, k;
		cin >> n >> m;
		for (int i = 0; i < n - 1; i++){
			v[i].clear();
		}
		for (int i = 0; i < n - 1; i++){
			int fir, sec;
			cin >> fir >> sec;
			add__(sec, fir);
			add__(fir, sec);
		}
		bfs__(1);
		bfs__(dis_max);
		while (m--){
			cin >> k;
			if (k - 1 <= maxx){
				cout << k - 1 << endl;
			}else{
				cout << maxx + (k - maxx - 1) * 2 << endl;
			}
		}
	}
	return 0;
}