/*
Memory 284K
Time   63MS
*/
#include <iostream>
#include <queue>
using namespace std;
#define MAXV 102
#define inf 1<<29

typedef struct{
	int x,y;
}Point;

Point point[MAXV];
char s[MAXV][MAXV];
int m,n,psum,map[MAXV][MAXV];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void findpoint(){
	int i,j;
	psum=1;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			if(s[i][j]=='A'){
				point[psum].x=i;
				point[psum++].y=j;
			}else if(s[i][j]=='S'){
				point[0].x=i;
				point[0].y=j;
			}
}

void bfs(int start){
	int discover[MAXV][MAXV],dis[MAXV][MAXV];
	queue <int> q;
	int i,a,b,tx,ty;

	for(i=0;i<m;i++)
		for(int j=0;j<n;j++){
			dis[i][j]=0;
			discover[i][j]=0;
		}

	a=point[start].x;
	b=point[start].y;
	q.push(a);
	q.push(b);
	discover[a][b]=true;

	while(!q.empty()){
		a=q.front();q.pop();
		b=q.front();q.pop();
		for(i=0;i<4;i++){
			tx=a+dx[i];
			ty=b+dy[i];
			if(!discover[tx][ty] && tx>=0 && tx<n && ty>=0 && ty<m && s[tx][ty]!='#'){
				dis[tx][ty]=dis[a][b]+1;
				discover[tx][ty]=true;
				q.push(tx);
				q.push(ty);
			}
		}
	}
	for(i=0;i<psum;i++){
		int t=dis[point[i].x][point[i].y];
		if(t) map[start][i]=t;
	}
}

void prim(){
	int i,j,v;
	int d[MAXV],vis[MAXV];
	for(i=0;i<psum;i++){
		d[i]=map[0][i];
		vis[i]=0;
	}
	
	for(i=0;i<psum;i++){
		int min=inf;
		for(j=0;j<psum;j++)
			if(!vis[j] && d[j]<min){
				min=d[j];
				v=j;
			}
			
			vis[v]=1;
			
			for(j=0;j<psum;j++){
				if(!vis[j] && map[v][j]<d[j])
					d[j]=map[v][j];
			}
	}
	int ans=0;
	for(i=0;i<psum;i++) ans+=d[i];
	printf("%d\n",ans);
}

int main(){
	int t,i;
	scanf("%d\n",&t);
	while(t--){
		gets(s[0]);
		sscanf(s[0],"%d%d",&n,&m);

		for(i=0;i<m;i++) gets(s[i]);
		findpoint();					//找到点的坐标
		for(i=0;i<psum;i++) bfs(i);				//计算距离
		prim();						//最小生成树
	}
	return 0;
}