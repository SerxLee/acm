
#include <cstdio>
#include <cstring>
#include <cstdlib>
const int MAXN = 1 << 5;
double r[MAXN][MAXN];
int n, m;
char s[MAXN][MAXN];

int findbuf( char *buf)
{
    int i;
    for( i = 0; i < m; i ++)
        if( !strcmp( buf, s[i]))
            return i;
}

void Read_Gragh()
{
    char buf1[MAXN], buf2[MAXN];
    double rate;
    for( int i = 0; i < n; i ++)
        scanf( "%s", s[i]);
    memset( r, 0, sizeof (r));
    for( int i = 0; i < n; i ++) r[i][i] = 1;
    scanf( "%d", &m);
    for( int i = 0; i < m; i ++)
    {
        scanf( "%s%lf%s", buf1, &rate, buf2);
        r[ findbuf( buf1)][ findbuf(buf2)] = rate;
    }
}

bool floyd()
{
    for( int k = 0; k < n; k ++)
        for( int i = 0; i < n; i ++)
            for( int j = 0; j < n; j ++)
                if( r[i][j] < r[i][k] * r[k][j])
                    r[i][j] = r[i][k] * r[k][j];
    for( int i = 0; i < n; i ++)
        if( r[i][i] > 1) return true;
    return false;
}

int main()
{
    int cas = 0;
    while( scanf( "%d", &n), n)
    {
        Read_Gragh();
        printf( "Case %d: ", ++ cas);
        bool ok = floyd();
        if( ok) printf( "Yes\n");
        else printf( "No\n");
    }
    return 0;
}