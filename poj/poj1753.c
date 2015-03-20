#include <stdio.h>
int a[17],b,w,min,cut;
void up(int i)
{
    if(i-4>=0)
    {
        if(a[i-4]==0)
        {
            a[i-4]=1;
            w--;
            b++;
        }
        else
        {
            a[i-4]=0;
            w++;
            b--;
        }
    }
}
void down(int i)
{
    if(i+4<16)
    {
        if(a[i+4]==0)
        {
            a[i+4]=1;
            w--;
            b++;
        }
        else
        {
            a[i+4]=0;
            w++;
            b--;
        }
    }
}
void left(int i)
{
    if(i-1>=0&&i/4==(i-1)/4)
    {
        if(a[i-1]==0)
        {
            a[i-1]=1;
            w--;
            b++;
        }
        else
        {
            a[i-1]=0;
            w++;
            b--;
        }
    }
}
void right(int i)
{
    if(i+1<16&&i/4==(i+1)/4)
    {
        if(a[i+1]==0)
        {
            a[i+1]=1;
            w--;
            b++;
        }
        else
        {
            a[i+1]=0;
            w++;
            b--;
        }
    }
}
void fib(int i)
{
    int j;
    if(i==-1)
    {
        for(j=i+1; j<16; j++)
        {
            fib(j);
        }
    }
    else
    {
        if(cut==0&&(b==0||w==0))
        {
            min=cut;
            return ;
        }
		if(i>=0&&i<16)
		{
		if(a[i]==0)
        {
            a[i]=1;
            w--;
            b++;
        }
        else
        {
            a[i]=0;
            w++;
            b--;
        }
	}
        up(i);
        down(i);
        left(i);
        right(i);
        cut++;
        if((b==0||w==0)&&min>cut)
        {
            min=cut;
        }
        else
        {
            for(j=i+1; j<16; j++)
            {
                fib(j);
            }

        }
		if(i>=0&&i<16)
	{
		if(a[i]==0)
        {
            a[i]=1;
            w--;
            b++;
        }
        else
        {
            a[i]=0;
            w++;
            b--;
        }
	}
        up(i);
        down(i);
        left(i);
        right(i);
        cut--;
    }
}
int main()
{
    int i,j;
    char s[6];
    while(scanf("%s",s)!=EOF)
    {
        b=0;
        w=0;
        min=1<<30;
        cut=0;
        for(i=0; i<4; i++)
        {
            if(s[i]=='b')
            {
                a[i]=1;
                b++;
            }
            else if(s[i]=='w')
            {
                a[i]=0;
                w++;
            }
        }
        for(i=1; i<4; i++)
        {
            scanf("%s",s);
            for(j=0; j<4; j++)
            {
                if(s[j]=='b')
                {
                    a[i*4+j]=1;
                    b++;
                }
                else if(s[j]=='w')
                {
                    a[i*4+j]=0;
                    w++;
                }
            }
        }
        fib(-1);
        if(min!=1<<30)
        {
            printf("%d\n",min);
        }
        else
        {
            printf("Impossible\n");
        }

    }
    return 0;
}