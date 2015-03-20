#include <stdio.h>
int n,m;
int main(){
    int i, j, a, ans1, ans2;
    while(scanf("%d%d", &n, &m) != EOF){
        ans1 = ans2 = 0;
        for(i = 0; i < n; i++){
            scanf("%d", &a);
            if(a > m)
                ans1 += a - m;
            else ans2 += m - a;
        }
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}