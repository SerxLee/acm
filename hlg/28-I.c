#include <stdio.h>
#include <string.h>
const int Max_N=100008 ;
int stone[Max_N] ;
int T[Max_N] ,N ,M ,k ;
int Sum_st[Max_N] ;
int find_id(int id){
    int Left ,Right ,Mid ,ans;
    if(Sum_st[1]-Sum_st[id+1]<=k)
        return 0 ;
    Left = 1 ;
    Right = id ;
    while(Left <= Right){
        Mid = (Left + Right) >> 1 ;
        if(Sum_st[Mid] - Sum_st[id + 1] > k){
            ans = Mid ;
            Left = Mid+1 ;
        }
        else
            Right = Mid-1 ;
    }
    return ans-1 ;
}
int gao(){
    int stone_j = 0 ,ans = 0 ,i;
    T[0]=0 ;
    for(i = 1; i <= M; i++){
        stone_j += (T[i]-T[i-1]-1) ;
        ans += (T[i] - T[i-1]-1) ;
        if(stone_j >= N)
            return ans - (stone_j - N) ;
        stone_j = find_id(stone_j) ;
        ans++;
    }
    if(stone_j < N)
        return ans+N-stone_j ;
    return 0;
}
int main(){
    int i;
    while(scanf("%d%d%d", &N, &M, &k) != EOF){
        for(i = 1; i <= N;  i++)
            scanf("%d", &stone[i]) ;
        Sum_st[N + 1] = 0 ;
        for(i = N; i >= 1; i--)
            Sum_st[i] = Sum_st[i + 1] + stone[i];
        for(i = 1; i <= M; i++)
            scanf("%d",&T[i]) ;
        printf("%d\n",gao()) ;
    }
    return 0 ;
}