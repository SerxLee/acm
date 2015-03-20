#include <stdio.h>
typedef struct point{
	int x,y,step;
}target;
target que[100000];
char map[305][305];
int ax,ay,bx,by;
int num[305][305],m,n,min,flag[4][2]={0,1,0,-1,1,0,-1,0};
void BFS(target start)
{
	int end,top,i;
	target in,next;
	end=top=0;
	que[top]=start;
	while(top>=end)
	{
		in=que[end];
		end=(end+1);
		for(i=0;i<4;i++)
		{
			next.x=in.x+flag[i][0];
			next.y=in.y+flag[i][1];
			if(next.x==bx&&next.y==by&&min>in.step+1)
				min=in.step+1;
			if(next.x>=0&&next.x<m&&next.y>=0&&next.y<n&&map[next.x][next.y]!='S'&&map[next.x][next.y]!='R')
			{
				if(num[next.x][next.y]>in.step+1)
				{
					next.step=in.step+1;
					if(map[next.x][next.y]=='B')
						next.step++;
					num[next.x][next.y]=in.step+1;
					top=(top+1);
					que[top]=next;
				}
			}
		}
	}
}
int main()
{
	int i,j;
	target start;
	while(scanf("%d%d",&m,&n),m||n)
	{
		for(i=0;i<m;i++)
		{
			scanf("%s",map[i]);
			for(j=0;j<n;j++)
			{
				if(map[i][j]=='T')
				{
					ax=i;ay=j;
				}
				if(map[i][j]=='Y')
				{
					bx=i;by=j;
				}
				num[i][j]=100000;
			}
		}
		min=100000;
		start.x=ax;start.y=ay;start.step=0;
		BFS(start);
		if(min==100000)
			printf("-1\n");
		else printf("%d\n",min);
	}
	return 0;
}