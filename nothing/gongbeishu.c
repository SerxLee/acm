    #include <stdio.h>
int gongyueshu(int a, int b);
void gongbeishu(int a, int b);

int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    gongbeishu(a, b);
    return 0;
}
int gongyueshu(int a, int b){
    int temp;
    if(a < b){
        temp = a;
        a = b;
        b = temp;
    }
    while(b != 0){
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

void gongbeishu(int a, int b){
    int temp1;
    temp1 = a * b / gongyueshu(a, b);
    printf("%d\n", temp1);
}