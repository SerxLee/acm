#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#define N 201
using namespace std;

struct Persion{
    int x,y;
    int time;
    friend bool operator < (const Persion &a,const Persion &b){
        return a.time>b.time;
    }
    
};

int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char map[N][N];
int visited[N][N];
int m,n;

int BFS(int x,int y){
    priority_queue <Persion>q;
    Persion current,next;
    memset(visited,0,sizeof(visited));
    current.x=x;
    current.y=y;
    current.time=0;
    visited[current.x][current.y]=1;
    q.push(current);
    while(!q.empty()){
        current=q.top();
        q.pop();
        for(int i=0;i<4;i++){
            next.x=current.x+dir[i][0];
            next.y=current.y+dir[i][1];
            if(next.x>=0&&next.x<n&&next.y>=0&&next.y<m&&map[next.x][next.y]!='#'&&!visited[next.x][next.y]){
                if(map[next.x][next.y]=='r')
                    return current.time+1;
                if(map[next.x][next.y]=='x')
                    next.time=current.time+2;
                else
                    next.time=current.time+1;
                visited[next.x][next.y]=1;
                q.push(next);
            }
        }
    }
    return -1;
}
int main(){
    int i,j;
    Persion angle;
    while(cin>>n>>m&&(m||n)){
        for(i=0;i<n;i++)
            for(j=0;j<m;j++){
                cin>>map[i][j];
                if(map[i][j]=='a'){
                    angle.x=i;
                    angle.y=j;
                }
            }
        int time = BFS(angle.x,angle.y);
        if(time == -1)
            cout<<"Poor ANGEL has to stay in the prison all his life."<<endl;
        else
            cout<<time<<endl;
    }
    return 0;

}
