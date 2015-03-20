#include <cstdio>
#include <string>
#include <iostream>
#define N 1000010
#define MaxInt 0x7fffffff


int w[505], p[505];
int n ,m;
int dp[505];

int main(){
	scanf("%d%d", &n, &m);
	memset(dp, MaxInt, sizeof(dp));
	for (int i = 0; i )
}
// struct node{
// 	vel;
// 	need;
// }aa[505];

// all[N];
// int n , m;

// int main(){
// 	scanf("%d%d", &n, &m);
// 	int ve;
// 	int ne;
// 	memset(all, MaxInt, sizeof(all));
// 	for (int i = 0; i < n; i++){
// 		scanf("%d%d", &ve, &ne);
// 		aa[i].vel = ve;
// 		aa[i].need = ne;
// 	}
// 	int temp = 0;
// 	for (int i = 0; i < n; i++){
// 		while (temp + aa[i].vel < m){
// 			all[temp + aa[i].need] = aa[i].vel + all[temp];
// 			temp += aa[i].need;
// 		}
// 	}
// 	for (int i = 0; i < n; i++){
// 		for (int j = aa[i].need; j < m; j++){
// 			if (all[j - aa[i].need != MaxInt){
// 				if (all[j] < all[j - aa[i].need] + aa[i].vel){
// 					all[j - aa[i].need];
// 				}
// 			}
// 		}
// 	}
// }