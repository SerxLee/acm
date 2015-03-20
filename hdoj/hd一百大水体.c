
2000
#include <stdio.h>

int main ()
{
    char a, b, c, d, t;
    while(scanf("%c%c%c%c", &a, &b, &c, &d) != EOF)
    {
        if(a > b)
        {
            t = a, a = b, b = t;
        }
        if(a > c)
        {
            t = a, a = c, c = t;
        }
        if(b > c)
        {
            t = b, b = c, c = t;
        }
        printf("%c %c %c\n", a, b, c);
    }
    return 0;
}

2001
#include <stdio.h>
#include <math.h>

int main()
{
	double x1, y1, x2, y2;
    double s, j;
    while (scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2) != EOF) {
        s = pow(x1 - x2, 2) + pow(y1 - y2, 2);
        j = sqrt(s);
        printf("%0.2lf\n",j);
    }
    return 0;
}

2002
#include <stdio.h>
#define PI 3.1415927

int main ()
{
    double r, v;
    while (scanf("%lf",&r)!=EOF) {
        v = PI * r * r * r * 4 / 3;
        printf("%0.3lf\n", v);
    }
    return 0;
}



2003
#include <stdio.h>

int main()
{
    double b;
    while (scanf("%lf", &b) != EOF) {
        if (b < 0) {
            printf("%0.2lf\n", -b);
        }else{
            printf("%0.2lf\n", b);
        }
    }
    return 0;
}

2004
#include <stdio.h>
int main ()
{
    int a;
    while(scanf("%d", &a) != EOF)
    {
        if(a > -1 && a < 60)
            printf("E\n");
        else
            if(a > 59 && a < 70)
                printf("D\n");
            else
                if(a > 69 && a < 80)
                    printf("C\n");
                else
                    if(a > 79 && a < 90)
                        printf("B\n");
                    else
                        if(a > 80 && a < 101)
                            printf("A\n");
                        else
                            printf("Score is error!\n");
    }
    return 0;
}

2005
#include <stdio.h>
int main()
{
    int year, month, day;
    int m, days;
    int a[12];
    while (scanf("%d/%d/%d", &year, &month, &day) != EOF) {
        days = 0;
        for (m = 1; m <= month - 1; m++) {
            switch (m) {
            case 1:case 3:case 5:case 7:case 8:case 10:case 12:
                a[m] = 31;
                    break;
            case 4:case 6:case 9:case 11:
                a[m] = 30;
                    break;
            case 2:
                if ((year % 4 !=0 && year % 100 == 0 )|| year % 400 != 0) {
                    a[m] = 28;
                }else{
                    a[m] = 29;
                }
            }
            days += a[m];
        }
        printf("%d\n", days+day);
    }
    return 0;
}

2006
#include <stdio.h>
int main()
{
    int n, i;
    int a[1000];
    while (scanf("%d", &n) != EOF) {
        int s = 1;
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (i = 0; i < n; i++) {
            if (a[i] % 2 != 0) {
                s *= a[i];
            }
        }
        printf("%d\n", s);
    }
}

2007
#include <stdio.h>

int main(){
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF) {
        long i, sum = 0,sum2 = 0;
        if (a > b) {
            i = a;
            a = b;
            b = i;
        }
        for (i = a; i <= b; i++) {
            if (i % 2 == 0) {
                sum += i * i;
            }else{
                sum2 += i * i * i;
            }
        }
        printf("%ld %ld\n", sum, sum2);
    }
    return 0;
}

2008
#include <stdio.h>

int main()
{
    int n, i;
    int k, z, l;
    double a[1000];
    while (scanf("%d", &n) != EOF) {
        k = 0; z = 0; l = 0;
        for (i = 0; i < n; i++) {
            scanf("%lf", &a[i]);
        }
        for (i = 0; i < n; i++) {
            if (a[i] < 0) {
                k++;
            }else{
                if (a[i] == 0) {
                    z++;
                }else{
                    l++;
                }
            }
        }
        if (n == 0) {
            break;
        }
        printf("%d %d %d\n", k, z, l);
    }
    return 0;
}

2009
#include <stdio.h>
#include <math.h>
int main()
{
    int i, m;
    double a[1000];
    while (scanf("%lf", &a[0]) != EOF) {
        double s = 0;
        scanf("%d", &m);
        for (i = 1; i < 1000; i++) {
            a[i] = sqrt(a[i - 1]);
        }
        for (i = 0; i < m; i++) {
            s += a[i];
        }
        printf("%.2lf\n", s);
    }
    return 0;
}

2010
#include <stdio.h>
int main()
{
    int n, m, i, j, k, l, s, x;
    while (scanf("%d%d", &m, &n) != EOF) {
        x = 0;
        for (i = m; i <= n; i++) {
            j = 0;
            k = 0;
            l = 0;
            s = i;
            while (i >= 100) {
                i -= 100;
                j++;
            }
            while(i >= 10 && i < 100) {
                i -= 10;
                k++;
            }
            while(i >= 1 && i < 10) {
                i -= 1;
                l++;
            }
            if (((j*j*j) + (k*k*k) + (l*l*l)) == s) {
                printf("%d ", s);
                x++;
            }
            i = s;
        }
        if (x == 0) {
            printf("no");
        }
        printf("\n");
    }
    return 0;
}

2011
#include <stdio.h>
int main()
{
    int m, i, x, j;
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        float s = 0;
        int k = 1;
        scanf("%d", &x);
        for (j = 1; j <= x; j++) {
            s += k * 1.0 / j;
            k = -k;
        }
        printf("%.2f\n", s);
    }
    return 0;
}

2012

#include <stdio.h>
#include <math.h>
int main(){
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF) {
        int i, j, l, ii;
        if (a == 0 && b == 0) {
            break;
        }
        
        l = 0;
        for (i = a; a <= b; i++) {
            j = i * i + i + 41;
            for (ii = 2; ii <= sqrt(j); ii++) {
                if (j % ii == 0) {
                    l++;
                    break;
                }
            }
        }
        if (l == 0) {
            printf("OK\n");
        }else{
            printf("Sorry\n");
        }
    }
    return 0;
}

2013
#include <stdio.h>
int main()
{
    int n, s, i, a;
    while (scanf("%d", &n) != EOF)
    {
        a = 1;
        for (i = 1; i < n; i++)
        {
            s = (a + 1) * 2;
            a = s;
        }
        printf("%d\n", s);
    }
    return 0;
}

2014
#include <stdio.h>

void charu(int *a,int n)
{
    int i,j, tmp ;
    for (j=1; j<n; j++) {
        tmp = a[j];
        for (i=j; i>0 && a[i-1] > tmp; i--) {
            a[i] = a[i-1];
        }
        a[i] = tmp;
    }
}
int main()
{
    int n, i;
    while (scanf("%d", &n) != EOF) {
        double s = 0;
        int a[n];
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        charu(a, n);
        for (i = 1; i < n - 1; i++) {
            s += a[i];
        }
        printf("%.2lf\n", s/(n-2));
    }
    return 0;
}

2015
#include <stdio.h>
int main ()
{
    int n, m, i, x, j, k;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        x = 0;
        j = 0;
        k = 0;
        for (i = 1; i <= n; i++)
        {
            j++;
            x += 2 * i;
            if (m == j){
                if (k){
                    printf(" ");
                }
                k = 1;
                printf("%d", x / m);
                j = 0;
                x = 0;
            }
        }
        if (x){
            printf(" %d",x/j);
        }
        printf("\n");
    }
    return 0;
}

2016
//////1
#include <stdio.h>
int main(){
    int n, i, a[100], min, j;
    while (scanf ("%d", &n) != EOF)
    {
        if(!n) {
            break;
        }
        scanf ("%d", &a[0]);
        min = 0, j = a[0];
        for (i = 1;i < n; i++) {
            scanf ("%d", &a[i]);
            if (a[i] < j) {
                j = a[i];
                min = i;
            }
        }
        j = a[0], a[0] = a[min], a[min] = j, j = 0;
        for (i = 0; i < n; i++) {
            if (j) {
                printf(" ");
            }
            printf("%d", a[i]);
            j = 1;
        }
        printf("\n");
    }
    return 0;
}
//////2
#include <stdio.h>

int main()
{
    int n, i;
    while (scanf("%d", &n) != EOF) {
	if (n == 0) {
		break;
	}
        int a[n], min, tmp, k;
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        min = a[0];
        for (i = 1; i < n; i++) {
            if (a[i] < min) {
                min = a[i];
                tmp = i;
            }
        }
        k = a[0];
        a[0] = min;
        a[tmp] = k;
        for (i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
        if (n == 0) {
            break;
        }
    }
    return 0;
}

2017
#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int i, sum;
    char a[1000];
    getchar();
    while (n--) {
        gets(a);
        for (i = 0, sum = 0; a[i] != '\0'; i++) {
            if (a[i] >= '0' && a[i] <= '9') {
                sum++;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}

2018
#include <stdio.h>
int main ()
{
    int a[55] = {0, 1, 2, 3, 4};
    int n ;
    for (n = 4; n < 55; n++) {
        a[n] = a[n - 1] + a[n - 3];
    }
    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }
        printf("%d\n", a[n]);
    }
    return 0;
}

2019
#include <stdio.h>
int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        if (n == 0 && m == 0) {
            break;
        }
        int a[100];
        int i, j;
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (i = 0; i < n; i++) {
            if (a[i] > m) {
                for (j = n; j >= i; j--) {
                    a[j + 1] = a[j];
                }
                a[i] = m;
                break;
            }
        }
        if (a[n - 1] < m) {
            a[n] = m;
        }
        for (i = 0; i < n + 1; i++) {
            printf("%d ", a[i]);
        }
    }
    return 0;
}

2020
#include<stdio.h>
#include<math.h>
int main(){
	int n,a[101], q, b[101], i, t, j;
	while(scanf("%d",&n) != EOF){
        if (n == 0) {
            break;
        }
		for(i = 0; i < n; i++){
			scanf("%d", &a[i]);
			b[i] = abs(a[i]);
		}
        for (i = 0; i < n; i++) {
            t = b[i];
            q = a[i];
            for (j = i; j > 0 && b[j - 1] < t; j--) {
                b[j] = b[j - 1];
                a[j] = a[j - 1];
            }
            b[j] = t;
            a[j] = q;
        }
        for (i = 0; i < n; i++) {
            if (i != n - 1) {
                printf("%d ", a[i]);
            }else{
                printf("%d\n", a[i]);
            }
        }
	}
	return 0;
}


2021
#include<stdio.h>
int main(){
    int n;
    while(scanf("%d", &n) != EOF && n != 0) {
        int i, sum=0, all;
        for (i = 1; i <= n; i++) {
            scanf ("%d", &all);
            sum += all / 100;
            all = all % 100;
            sum += all / 50;
            all = all % 50;
            sum += all / 10;
            all = all % 10;
            sum += all / 5;
            all = all % 5;
            sum += all / 2;
            all = all % 2;
            sum += all / 1;
        }
        printf("%d\n", sum);
    }
    return 0;
}

2022
#include <stdio.h>
int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        int a[n + 1][m + 1];
        int i, j;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        int sum_i, sum_j, sum, lim;
        sum = 0;
        sum_i = 1;
        sum_j = 1;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                if (a[i][j] < 0) {
                    lim = -a[i][j];
                }else{
                    lim = a[i][j];
                }
                if (lim > sum) {
                    sum = lim;
                    sum_i = i;
                    sum_j = j;
                }
            }
        }
        printf("%d %d %d\n", sum_i, sum_j, a[sum_i][sum_j]);
    }
    return 0;
}

2023
#include <stdio.h>
int main(){
    int n, m, j;
    while (scanf("%d%d", &n, &m) != EOF) {
        int i, x = 0;
        double d[6], a[51], c[] = {0, 0, 0, 0, 0, 0}, b[51][6];
        for (i = 0; i < n; i++) {
            double l = 0;
            for (j = 0; j < m; j++) {
                scanf("%lf", &b[i][j]);
            }
            for (j = 0; j < m; j++) {
                l += b[i][j];
                c[j] += b[i][j];
            }
            a[i] = l/m;
        }
        for (i = 0; i < m; i++) {
            d[i] = c[i]/m;
        }
        for (i = 0; i < n; i++) {
            int z = 0;
            for (j = 0; j < m; j++) {
                if (b[i][j] >= d[j]) {
                    z++;
                }
            }
            if (z == m) {
                x++;
            }
        }
        for (i = 0; i < n; i++) {
            if(i != n - 1){
                printf("%.2lf ", a[i]);
            }else{
                printf("%.2lf\n", a[i]);
            }
        }
        for (i = 0; i < m; i++) {
            if(i != m - 1){
                printf("%.2lf ", d[i]);
            }else{
                printf("%.2lf\n", d[i]);
            }
        }
        printf("%d\n\n", x);
    }
    return 0;
}

2024
#include<stdio.h>
#include<string.h>
int main(){
    int n, b, j;
    char a[1000];
    while(scanf("%d\n", &n) != EOF){
        while(n--){
            int s = 0, s1 = 0;
            gets(a);
            b = strlen(a);
            for(j = 0; j < b; j++){
                if(a[j]=='_') s++;
                if(a[j]>='0'&&a[j]<='9'&&j!=0||a[j]>='a'&&a[j]<='z'||a[j]>='A'&&a[j]<='Z')
                    s1++;
            }
            if(s + s1 == b){
                printf("yes\n");
            }else{
                printf("no\n");
            }
        }
    }
    return 0;
}

2025
#include<stdio.h>
#include<string.h>
int main() {
    char a[100];
    while(scanf("%s", a) != EOF) {
        char max = 'a';
        int i, n;
        n = strlen(a);
        for (i = 0; i < n; i++) {
            if (a[i] > max) {
                max = a[i];
            }
        }
        for (i = 0; i < n; i++) {
            printf("%c", a[i]);
            if (a[i] >= max) {
                printf("(max)");
            }
        }
        printf("\n");
    }
    return 0;
}

2026
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(){
    char a[101] = { };
    while (gets(a)) {
        int i, len;
        len = strlen(a);
        a[0] = toupper(a[0]);
        for (i = 0; i < len; i++) {
            if (a[i] == ' ') {
                a[i + 1] = toupper(a[i + 1]);
            }
        }
        for (i = 0; i < len; i++) {
            printf("%c", a[i]);
        }
        printf("\n");
    }
    return 0;
}

2027
#include <stdio.h>
#include <string.h>
int main(){
    int n, k;
    char al[101];
    scanf("%d", &n);
    for (k = n; k > 0; k--) {
        gets(al);
        int len, j, a, e, i, o, u;
        a = e = i = o = u = 0;
        len = strlen(al);
        for (j = 0; j < len; j++) {
            if (al[j] == 'a') {
                a++;
            }
            if (al[j] == 'e') {
                e++;
            }
            if (al[j] == 'i') {
                i++;
            }
            if (al[j] == 'o') {
                o++;
            }
            if (al[j] == 'u') {
                u++;
            }
        }
        printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",a , e, i, o, u);
        if (k > 1) {
            printf("\n");
        }
    }
    return 0;
}

2029
#include <stdio.h>
#include <string.h>
int main(){
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        char a[100], b[100];
        scanf("%s", a);
        int len, k;
        len = strlen(a);
        for (k = 0; k < len; k++) {
            b[len - k - 1] = a[k];
        }
        int q = 0;
        for ( k = 0; k < len; k++) {
            if (a[k] == b[k]) {
                q++;
            }
        }
        if (q >= len) {
            printf("yes\n");
        }else{
            printf("no\n");
        }
    }
    return 0;
}

2030
#include <stdio.h>
#include <string.h>

int main(){
    int i, sum, n;
    char a[1000];
    scanf("%d", &n);
    getchar();
    while (n--) {
        sum = 0;
        gets(a);
        for (i = 0; i < strlen(a); i++) {
            if (a[i] < 0) {
                sum++;
            }
        }
        printf("%d\n", sum / 2);
    }
    return 0;
}

2031
////////2
#include <stdio.h>
int main() {
    int n, m, r, a[100], i;
    while (scanf("%d%d",&n,&r) != EOF) {
        i = 0;
        m = n;
        if (n < 0) {
            n = -n;
        }
        while (n != 0) {
            a[i++] = n % r;
            n = n / r;
        }
        if (m < 0 ) {
            printf("-");
        }
        for (i = i - 1; i >= 0; i--) {
            if (a[i] > 9) {
                switch(a[i]) {
                    case 10: printf("A");
                        break;
                    case 11: printf("B");
                        break;
                    case 12: printf("C");
                        break;
                    case 13: printf("D");
                        break;
                    case 14: printf("E");
                        break;
                    case 15: printf("F");
                        break;
                }
            }else{
                printf("%d",a[i]);
            }
        }
        printf("\n");
    }
    return 0;
}

2032 杨辉三角
#include <stdio.h>
int main() {
    int n, i, j;
    while (scanf("%d", &n) != EOF) {
        if (n == 1) {
            printf("1");
        }
        int a[30][30] = {0};
        a[0][1] = 1;
        for (i = 1; i < n; i++) {
            for (j = 1; j <= i + 1; j++) {
                a[i][j] = a[i - 1][j - 1] + a[i-1][j];
            }
        }
        for (i = 0; i < n; i++) {
            for (j = 1; j <= i + 1; j++) {
                printf("%d", a[i][j]);
                if (j != i + 1) {
                    printf(" ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}

2034 人见人爱A-­B
#include <stdio.h>
int main()
{
int n,m;
    while(scanf("%d%d",&n,&m)!=EOF&&!(n==0&&m==0))
    {
        int i,j,t;
        int flag=0;
        int a[101],b[101];
        int c[101]={0};
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        for(i=0;i<m;i++)
        scanf("%d",&b[i]);
        for(i=1;i<n;i++)
            {
                t=a[i];
            for(j=i;j>0;j--)
                {
                        if(t<a[j-1])
                a[j]=a[j-1];
                else
                break;
                }
            a[j]=t;
            }
    
            for(i=0;i<n;i++){
                for(j=0;j<m;j++)
                if(a[i]==b[j])
                    break;
                if(j>=m)
    c[flag++]=a[i];
            }
        if(flag==0)
                printf("NULL");
            else
{
                    for(i=0;i<flag;i++)
                            printf("%d ",c[i]);}
        printf("\n");
    }
return 0;
}

2035
#include <stdio.h>
int main() {
    int a, b, i, sum;
    while (scanf("%d%d", &a, &b) != EOF) {
        if (a == 0 && b == 0) {
            break;
        }
        sum = 1;
        for (i = 0; i < b; i++) {
            sum *= a;
            sum %= 1000;
            }
        printf("%d\n", sum);
    }
    return 0;
}

2037 (WA……)
#include <stdio.h>

struct pro{
    int start;
    int end;
} a[50];

void quicksort(int l, int k)
{
    if (l < k) {
        int i = l , j = k, tmp = a[l].end;
        while (i < j) {
            while (i < j && a[j].end >= tmp) {
                j--;
            }
            if (i<j) {
                a[i++].end= a[j].end;
            }
            
            while (i<j && a[i].end <= tmp) {
                i++;
            }
            if (i<j) {
                a[j--].end = a[i].end;
            }
            
        }
        a[i].end = tmp;
        quicksort(l, i-1);
        quicksort(i+1, k);
    }
}

int main(){
    int n, i, j, m;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }
        for (i = 0; i < n; i++) {
            scanf("%d%d", &a[i].start, &a[i].end);
        }
        quicksort(0, n-1);
        for (i = 0; i < n; i++) {
            printf("%d ", a[i].end);
        }
        printf("\n");
        for (i = m = j = 0; i < n; i++) {
            if (j <= a[i].start) {
                j = a[i].end;
                m++;
            }

        }
        printf("%d\n", m);
    }
    return 0;
}

2037 (AC)

#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct{
    int s,e;
}time;
time a[MAX];
int comp(const void *a,const void *b){
    time t1=*(time*)a;
    time t2=*(time*)b;
    if(t1.e==t2.e)
        return t1.s-t2.s;
    else
        return t1.e-t2.e;
}
int main(){
    int n,i,t,c;
    while(scanf("%d",&n)&&n){
        for(i=0;i<n;i++)
            scanf("%d%d",&a[i].s,&a[i].e);
        qsort(a,n,sizeof(time),comp);
        for(i=t=c=0;i<n;i++){
            if(a[i].s>=t){
                t=a[i].e;
                c++;
            }
        }
        printf("%d\n",c);
    }
}

2039 三角形
#include <stdio.h>
int main(){
    double a,b,c,t;
    scanf("%lf", &t);
    while(t--){
        scanf("%lf%lf%lf",&a,&b,&c);
        if((a+b>c)&&(a+c>b)&&(b+c>a))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
2040 亲和数
#include <stdio.h>
int main(){
    int n, i, a, b, sum1, sum2, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        a = b = 0;
        sum1 = sum2 = 0;
        scanf("%d%d", &a, &b);
        for (j = 1; j < a / 2 + 1; j++) {
            if (a % j == 0) {
                sum1 += j;
            }
        }
        for ( j = 1; j < b / 2 + 1; j++) {
            if (b % j == 0) {
                sum2 += j;
            }
        }
        if (sum1 == b && sum2 == a) {
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}

2041 楼梯
#include <stdio.h>
int main(){
    int n, i, m, k, l, a;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        m = a = 0;
        scanf("%d", &m);
        for (k = 0; k < m; k++) {
            for (l = 0; l < m; l++) {
                if (2 * k + l == m-1) {
                    a++;
                }
            }
        }
        printf("%d\n", a);
    }
    return 0;
}

2042 不容易2
#include <stdio.h>
int main(){
    int n, m, i, sum;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        m = 0;
        sum = 3;
        scanf("%d", &m);
        while (m--) {
            sum -= 1;
            sum *= 2;
        }
        printf("%d\n", sum);
    }
    return 0;
}


2048 神、上帝以及老天爷

#include <stdio.h>
int main(){
    int i , t, n;
    scanf("%d", &t);
    double b[21], a[21];
    b[1] = 0;
    b[2] = 1;
    b[3] = 2;
    a[0] = 1;
    for (i = 1; i <21; i++) {
        a[i] = a[i - 1] * i;
    }
    for (i = 3; i < 21; i++) {
        b[i] = (i - 1) * (b[i - 1] + b[i - 2]);
    }
    while (t--) {
        scanf("%d", &n);
        printf("%.2lf%%\n", b[n] * 100 / a[n]);
    }
    return 0;
}

2049
#include <stdio.h>

int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        int m, n, i;
        scanf("%d%d", &m, &n);
        long long int a[22], s, n1, tm;
        s = 1;
        n1 = n;
        tm = 1;
        a[0] = 1;
        a[1] = 0;
        a[2] = 1;
        a[3] = 2;
        for (i = 4; i <= 20; i++) {
            a[i] = ((i - 1) * (a[i - 2] + a[i - 1]));
        }
        if (m == n) {
            printf("%lld\n", a[n]);
        }else{
            while (tm <= n) {
                s *= m;
                m--;
                tm++;
            }
            while (n1 > 1) {
                s /= n1;
                n1--;
            }
            printf("%lld\n", s * a[n]);
        }
    }
    return 0;
}
2047
#include <stdio.h>
int main(){
    int n, i;
    while (scanf("%d", &n) != EOF) {
        long long int a[44];
        a[1] = 3;
        a[2] = 8;
        for (i = 3; i <= n; i++) {
            a[i] = (2 * a[i - 1]) + (2 * a[i - 2]);
        }
        printf("%lld\n", a[n]);
    }
    return 0;
}


2051 bitset

#include <stdio.h>
int main(){
    int i;
    while (scanf("%d", &i) != EOF) {
        int j, n = 0,a[11];
        while (i != 0) {
            n++;
            j = i % 2;
            a[n] = j;
            i = i / 2;
        }
        for (i = n; i >= 1; i--) {
            printf("%d", a[i]);
        }
        printf("\n");
    }
    return 0;
}

2052

#include <stdio.h>
int main() {
    int n, m;
    while (scanf ("%d%d", &n, &m) != EOF) {
        printf("+");
        int i, j;
        for (i = 0; i < n; i++) {
            printf("-");
        }
        printf("+\n");
        for(i = 0; i < m;i++) {
            for (j = 0; j < n + 2; j++) {
                if (j == 0)
                    printf("|");
                if (j == n + 1)
                    printf("|\n");
                else if (j < n + 1 && j > 0) {
                    printf(" ");
                }
            }
        }
        printf("+");
        for (i = 0; i < n; i++) {
            printf("-");
        }
        printf("+\n");
        printf("\n");
    }
    return 0;
}

2053

#include <stdio.h>
int main(){
    int n;
    while (scanf("%d", &n) != 0) {
        int i, k;
        k = 0;
        for (i = 1; i <= n; i++) {
            if (n % i == 0) {
                k++;
            }
        }
        if (k % 2 == 0) {
            printf("0\n");
        }else{
            printf("1\n");
        }
    }
    return 0;
}

2054

#include <stdio.h>
int main(){
    int a, b;
    while (scanf("%d%d", &a,&b) != EOF) {
        if (a == b) {
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}

2055
#include <stdio.h>
int main() {
    char x;
    int y, n;
    scanf("%d", &n);
    while (n--) {
        scanf("%s%d", &x, &y);
        if (x >= 'a' && x <= 'z') {
            printf("%d\n", - x + 96 + y);
        }
        if (x >= 'A' && x <= 'Z') {
            printf("%d\n", x - 64 + y);
        }
    }
    return 0;
}


2056
#include<stdio.h>
#include<math.h>
int max(int a,int b)
{
    return (a>b?a:b);
}
int min(int a,int b)
{
    return (a<b?a:b);
}
int main()
{
    float x[4],y[4];
    int i,j,a,b,c,d,e,f,g,h;
    float temp;
    while(scanf("%f%f%f%f%f%f%f%f",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2],&x[3],&y[3])!=EOF){
        a=max(x[0],x[1]);
        b=min(x[0],x[1]);
        c=max(y[0],y[1]);
        d=min(y[0],y[1]);
        e=max(x[2],x[3]);
        f=min(x[2],x[3]);
        g=max(y[2],y[3]);
        h=min(y[2],y[3]);
        if(a<f||b>e||c<h||d>g){
            printf("0.00\n");
            continue;
        }
        for(i=0;i<3;i++)
            for(j=0;j<3-i;j++){
                if(x[j]>x[j+1]){
                    temp=x[j];
                    x[j]=x[j+1];
                    x[j+1]=temp;
                }
                if(y[j]>y[j+1])
                {
                    temp=y[j];
                    y[j]=y[j+1];
                    y[j+1]=temp;
                }
            }
        
        printf("%.2f\n",(x[2]-x[1])*(y[2]-y[1]));
    }
    return 0;
}

2057
#include <stdio.h>
int main()
{
    __int64 a,b;
    while(scanf("%I64X%I64X",&a,&b)!=EOF)
    {
        if(a+b<0)
            printf("-%I64X\n",-a-b);
        else
            printf("%I64X\n",a+b);
    }
    return 0;
}

2059
#include <stdio.h>
int main() {
    int l;
    while (scanf("%d", &l) != EOF) {
        int n, c, t, vr, vt1, vt2;
        int i, j, p[102];
        double min, len, dp[102], e, tu;
        scanf("%d%d%d%d%d%d", &n, &c, & t, &vr, &vt1, &vt2);
        for (i = 1; i <= n; i++) {
            scanf("%d", &p[i]);
        }
        p[i] = l;
        dp[0] = 0;
        for (i = 1;  i < n + 2; i++) {
            min = 10000000;
            for (j = 0; j < i; j++) {
                len = p[i] - p[j];
                if ((1.0 * c / vt1 + (len - c + 0.0) / vt2 ) > len / vt2) {
                    e = len / vt2;
                }else{
                    e = 1.0 * c / vt1 + (len - c + 0.0) / vt2 + t;
                }
                e += dp[j];
                if (e < min) {
                    min = e;
                }
            }
            dp[i] = min;
        }
        tu = l / vr;
        if (dp[n + 1] < tu) {
            printf("What a pity rabbit!\n");
        }else{
            printf("Good job,rabbit!\n");
        }
    }
    return 0;
}

2059
#include <stdio.h>
int main() {
    int l;
    while (scanf("%d", &l) != EOF) {
        int n, c, t, vr, vt1, vt2;
        int i, j, p[102];
        double min, len, dp[102], e, tu;
        scanf("%d%d%d%d%d%d", &n, &c, &t, &vr, &vt1, &vt2);
        for (i = 1; i <= n; i++) {
            scanf("%d", &p[i]);
        }
        p[0] = 0;
        p[n+1] = l;
        dp[0] = 0;
        for (i = 1;  i <= n + 1; i++) {
            min = 10000000;
            for (j = 0; j < i; j++) {
                len = p[i] - p[j];
                if (len <= c) {
                    e = len * 1.0 / vt1;
                }else{
                    e = (c * 1.0 / vt1) + (len - c) * 1.0 / vt2;
                }
                e += dp[j];
                if (j) {
                    e += t;
                }
                if (e < min) {
                    min = e;
                }
            }
            dp[i] = min;
        }
        tu =1.0 * l / vr;
        if (dp[n + 1] < tu) {
            printf("What a pity rabbit!\n");
        }else{
            printf("Good job,rabbit!\n");
        }
    }
    return 0;
}

2060 snooker
#include<stdio.h>
int a[6]={7,6,5,4,3,2};
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int s,m,n,i;
        scanf("%d%d%d",&n,&s,&m);
        if(n>6)
        {
            s+=(n-6)+(n-6)*7;
            n=6;
        }
        for(i=0;i<n;i++) s+=a[i];
        if(s>=m) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

2064

#include <stdio.h>
int main(){
    int n, i;
    long m;
    while (scanf("%d", &n) != EOF) {
        m = 1;
        for (i = 0; i < n; i++) {
            m *= 3;
        }
        printf("%ld\n", m - 1);
    }
    return 0;
}

2069 

#include <stdio.h>
int main(){
    int n;
    while (scanf("%d", &n) != EOF) {
        int a, b , c, d, e, t = 0;
        for (a = 0; a * 50 <= n; a++) {
            for (b = 0; a * 50 + b * 25 <= n; b++) {
                for (c = 0; a * 50 + b * 25 + c * 10 <= 250; c++) {
                    for (d = 0; a * 50 + b * 25 + c * 10 + d * 5 <= n; d++) {
                        e = n - (a * 50 + b * 25 + c * 10 + d * 5);
                        if (a + b + c + d + e <= 100) {
                            t++;
                        }
                    }
                }
            }
        }
        printf("%d\n", t);
    }
    return 0;
}

2071 (gcc)
#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    double a[101];
    while (n--) {
        int m;
        scanf("%d", &m);
        int i;
        for (i = 0; i < m; i++) {
            scanf("%lf", &a[i]);
        }
        double k;
        k = a[0];
        for (i = 1; i < m; i++) {
            if (a[i] > k) {
                k = a[i];
            }
        }
        printf("%0.2lf\n", k);
    }
    return 0;
}

2080 (用到数学函数库math.h   函数有sqrt() 反三角函数acos()   )

#include <stdio.h>
#include <math.h>
#define pi 3.141592653
int main(){
    int n;
    scanf("%d", &n);
    while (n--) {
        double x1, y1, x2, y2;
        scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
        double z, a;
        z = x1 * x2 + y1 * y2;
        a = sqrt(x1 * x1 + y1 * y1) * sqrt(x2 * x2 + y2 * y2);
        printf("%0.2lf\n", acos(z / a) / pi * 180);
    }
    return 0;
}

2074 叠筐

#include <stdio.h>
int main(){
    int n;
    int k = 0;
    while (scanf("%d ", &n) != EOF) {
        if (k++ > 0) {
            printf("\n");
        }
        char a, b, c;
        scanf("%c %c", &a, &b);
        if ((n / 2) % 2 !=  0) {
            c = a;
            a = b;
            b = c;
        }
        if (n == 1) {
            printf("%c\n", a);
            continue;
        }
        int i, j;
        printf(" ");
        for (i = 0; i < n - 2; i++) {
            printf("%c",a);
        }
        printf(" ");
        printf("\n");
        for (i = 1; i < n / 2; i++) {
            for (j = 1; j <= i; j++) {
                if (j % 2 == 0) {
                    printf("%c", b);
                }else{
                    printf("%c", a);}
            }
            for (j = 0; j < (n-2*i); j++) {
                if (i % 2 != 0) {
                    printf("%c", b);
                }else{
                    printf("%c", a);}
            }
            for (j = i; j >= 1 ; j--) {
                if (j % 2 == 0) {
                    printf("%c", b);
                }else{
                    printf("%c", a);}
            }
            printf("\n");
        }
        for (i = n / 2; i >= 1; i--) {
            for (j = 1; j <= i; j++) {
                if (j % 2 == 0) {
                    printf("%c", b);
                }else{
                    printf("%c", a);}
            }
            for (j = 0; j < (n-2*i); j++) {
                if (i % 2 != 0) {
                    printf("%c", b);
                }else{
                    printf("%c", a);}
            }
            for (j = i; j >= 1; j--) {
                if (j % 2 == 0) {
                    printf("%c", b);
                }else{
                    printf("%c", a);}
            }
            printf("\n");
        }
        printf(" ");
        for (i = 0; i < n - 2; i++) {
            printf("%c",a);
        }
        printf(" ");
        printf("\n");

    }
    return 0;
}

2075

#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a % b == 0) {
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}

2076 (gcc)

#include <stdio.h>
int main(){
    double h, m, s;
    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%lf%lf%lf", &h, &m, &s);
        double abs;
        if (h > 12) {
            h -= 12;
        }
        abs =fabs((h * 30 + m * 0.5 + 1.0 * 30 / 3600 * s) - (m * 6 + 1.0 * 6 / 60 * s));
        if (abs > 180) {
            printf("%d\n", (int )(360 - abs));
        }else {
            printf("%d\n", (int )abs);
        }
    }
    return 0;
}

2078 复习时间

#include <stdio.h>
#include <math.h>

void bubble(int *a, int n);

int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, max, lim;
        scanf("%d%d", &n, &m);
        int a[100], i, j;
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        bubble(a, n);
        max = pow(100 - a[0], 2);
        for (i = n - 1; i >= 0; i--) {
            for (j = 0; j < i; j++) {
                lim = pow(100 - a[i], 2) + pow(a[i] - a[j], 2);
                if (lim > max) {
                    max = lim;
                }
            }
        }
        printf("%d\n", max);
    }
    return 0;
    
}

void bubble(int *a, int n){
    int i, j;
    int temp;
    for (i = 0; i < n; i++) {
        for (j = n-1 ; j > i; j--) {
            if (a[j] < a[j-1]) {
                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }

}

2081（只用到一些基本的东西）

#include <stdio.h>
int main(){
    int n;
    char a[12];
    scanf("%d", &n);
    while (n--) {
        int i;
        for (i = 0; i < 12; i++) {
            scanf("%c", &a[i]);
        }
        printf("6");
        for (i = 7; i < 12; i++) {
            printf("%c", a[i]);
        }
        printf("\n");
    }
    return 0;
}

2083 (gcc)

#include<stdio.h>
int main() {
    int i,m,n,j;
    int a[505], b[505];
    scanf("%d", &m);
    while(m--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (i = 0; i < n; i++) {
            b[i] = 0;
            for (j = 0; j < n; j++) {
                if (a[i] > a[j]) {
                    b[i] += (a[i] - a[j]);
                }else{
                    b[i] += (a[j] - a[i]);
                }
            }
        }
        int min;
        min = b[0];
        for (i = 1;i < n; i++) {
            if(b[i] < min) {
                min = b[i];
            }
        }
        printf("%d\n", min);
    }
    return 0;   
}

2084 数塔

#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    while (n--) {
        int i, j, m, lin, a[100][100];
        scanf("%d", &m);
        for (i = 0; i < m; i++) {
            for (j = 0; j <= i; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        for (i = m - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (a[i][j] > a[i][j+1]) {
                    lin = a[i][j];
                }else{
                    lin = a[i][j+1];
                }
                a[i-1][j] += lin;
            }
        }
        printf("%d\n", a[0][0]);
    }
    return 0;
}

2085 核反应堆

#include <stdio.h>
int main(){
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == -1) {
            break;
        }
        long long int high = 1, low = 0, i, j, i1, j1;
        while (n > 0) {
            i = high * 3;
            j = high;
            i1 = low * 2;
            j1 = low;
            high = i + i1;
            low = j + j1;
            n--;
        }
        printf(“%lld, %lld\n", high, low);
    }
    return 0;
}

2086 A1 = ?

#include <stdio.h>
int main(){
    int n, i;
    while (scanf("%d", &n) != EOF) {
        double a0, an1, a1;
        double c[3000];
        scanf("%lf%lf", &a0, &an1);
        for (i = 0; i < n; i++) {
            scanf("%lf", &c[i]);
        }
        a1 = a0 * n + an1;
        for (i = 0; i < n; i++) {
            a1 -= 2 * (i + 1) * c[i];
        }
        printf("%.2lf\n", a1 / 2);
    }
    return 0;
}

2088 Box of Bricks

#include <stdio.h>
int main(){
    int n, l = 1;
    while (scanf("%d", &n) != EOF && n != 0) {
        if (l != 1) {
            printf("\n");
        }
        l++;
        int i, j = 0, aver,k = 0, a[55];
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (i = 0; i < n; i++) {
            k += a[i];
        }
        aver = k / n;
        for (i = 0; i < n; i++) {
            if (a[i] > aver) {
                j += (a[i] - aver);
            }
        }
        printf("%d\n", j);
    }
    return 0;
}

2091

#include <stdio.h>
int main() {
    char c;
    int n, i, j, k;
    k = 0;
    while((scanf("%c %d", &c, &n) != EOF) && (c != '@')){
        if(k > 0) {
            printf("\n");
        }
        getchar();
        k++;
        for(i = 1; i <= n; i++) {
            for(j = 1; j < n + i; j++) {
                if(i <= n - 1) {
                    if((i + j) == n + 1){
                        printf("%c", c);
                    }else if(j == (n + i - 1)) {
                        printf("%c", c);
                    }else{
                        printf(" ");
                    }
                }else{
                    printf("%c", c);
                }
            }
            printf("\n");
        }
    }
    return 0;
}

2094 shy数

#include <stdio.h>
int main() {
    int a;
    while (scanf("%d", &a) != EOF) {
        if (a == 0) {
            break;
        }
        int k, i, l, m;
        m = a;
        k = a;
        l = a;
        int tot = 0, tot12 = 0, tot16 = 0;
        for (i = 0; i < 3; i++) {
            tot += a % 10;
            a = a / 10;
            if (i == 2) {
                tot += a;
            }
        }
        for (i = 0; i < 3; i++) {
            tot12 += l % 12;
            l = l / 12;
            if (i == 2) {
                tot12 += l;
            }
        }
        for (i = 0; i < 3; i++) {
            tot16 += k % 16;
            k = k / 16;
            if (i == 2) {
                tot16 += k;
            }
        }if (tot == tot12 && tot12 == tot16) {
            printf("%d is a Sky Number.\n", m);
        }else{
            printf("%d is not a Sky Number.\n", m);
        }
    }
    return 0;
}



2096
#include <stdio.h>
int main()
{
    int n, a, b, i;
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        int c, d;
        scanf("%d%d", &a, &b);
        if (a >= 100 ) {
            c = a/100;
            a = a - c * 100;
        }
        if (b >= 100 ) {
            c = b/100;
            b = b - c * 100;
        }
        d = a + b;
        if (d >= 100) {
            d -= 100;
        }
        printf("%d\n",d);
    }
}

2098
#include <stdio.h>
#include <math.h>

int sushu(int n);

int main() {
    int n;
    while (scanf("%d", &n) != EOF && n != 0) {
        int i, tot = 0;
        for (i = 2; i < n / 2; i++) {
            if (sushu(i) != 0) {
                if (sushu(n - i) != 0) {
                    tot++;
                }
            }
        }
            printf("%d\n", tot);
    }
    return 0;
}

int sushu(int n){
    int k, i;
    if (n == 1) {
        return n;
    }
    k = sqrt(n);
    for (i = 2; i <= k; i++) {
        if (n % i == 0) {
            return 0;
            break;
        }
    }
    return n;
}

2099
#include<stdio.h>
int main()
{
    int a;int b;
    int i;
    while(scanf("%d%d",&a,&b) != EOF)
    {
        if(a==0 && b==0)
        {
            break;
        }
        int flag=0;
        for(i=0;i<100;i++)
        {
            if((a*100+i)%b==0)
            {
                if(flag==0)
                {
                    if(i<10)
                    {
                        printf("0%d",i);
                        flag=1;
                    }
                    else
                    {
                        printf("%d",i);
                        flag=1;
                    }
                }
                else 
                {
                    if(i<10)
                    {
                        printf(" 0%d",i);
                    }
                    else 
                    {
                        printf(" %d",i);
                    }
                }
            }
        }
        printf("\n");
    }
    return 0;
}

2052 picture

#include <stdio.h>
int main(){
    int x, y;
    while((scanf("%d%d", &x, &y) != EOF)){
    int i, j;
    for (i = 1; i <= y + 2; i++) {
        if (i == 1 || i == y + 2) {
            printf("+");
        }else{
            printf("|");
        }
        for (j = 1; j <= x + 1; j++) {
            if (i == 1 || i == y + 2) {
                if (j == x + 1) {
                    printf("+");
                }else{
                    printf("-");
                }
            }else if(j == x + 1){
                printf("|");
            }else{
                printf(" ");
            }
        }
        printf("\n");
        if (i == y + 2) {
            printf("\n");
        }
    }
    }
    return 0;
}