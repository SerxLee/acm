#include <stdio.h>
#include <stdlib.h>
#define max 1000000000;
intd[1000][1000];
int main()
{
inti,j,k,m,n;
intx,y,z;
scanf("%d%d",&n,&m);
 
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
d[i][j]=max;
 
for(i=1;i<=m;i++)
{
scanf("%d%d%d",&x,&y,&z);
d[x][y]=z;
d[y][x]=z;
}
 
for(k=1;k<=n;k++)
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
{
if(d[i][k]+d[k][j]<d[i][j])
d[i][j]=d[i][k]+d[k][j];
}
 
for(i=1;i<=m;i++)
printf("%d",d[1][i]);
return0;
}