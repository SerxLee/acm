#include<iostream>
using namespace std;
const int Max = 1005;
 
int n, m;
bool ar[Max][Max];
 
int lowbit(int x){
    return x & (-x);
}
 
void updata(int i, int j){
    int tmpj;
    while(i > 0){
        tmpj = j;
        while(tmpj > 0){
            ar[i][tmpj] ^= 1;
            tmpj -= lowbit(tmpj);
        }
        i -= lowbit(i);
    }
}
int query(int i, int j){
    int tmpj, ans = 0;
    while(i <= n){
        tmpj = j;
        while(tmpj <= n){
            ans ^= ar[i][tmpj];
            tmpj += lowbit(tmpj);
        }
        i += lowbit(i);
    }
    return ans;
}
int main(){
    int t, x, xx, y, yy;
    scanf("%d", &t);
    while(t --){
        memset(ar, 0, sizeof(ar));
        scanf("%d%d", &n, &m);
        while(m--){
            char ord;
            cin >> ord;
            if(ord == 'C'){
                scanf("%d%d%d%d", &x, &y, &xx, &yy);
                updata(xx, yy);
                updata(x-1, yy);
                updata(xx, y-1);
                updata(x-1, y-1);
            }else{
                scanf("%d%d", &x, &y);
                printf("%d\n", query(x, y));
            }
        }
        printf("\n");
    }
    return 0;
}