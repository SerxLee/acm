#include <stdio.h>

typedef struct stack{
    int element[100];
    int p;
}stack;

void push(stack *s, int data)
{
    if ((*s).p < 100) {
        (*s).element[(*s).p] = data;
        (*s).p += 1;
    }else{
        printf("no");
    }
}
void pop(stack *s)
{
    if ((*s).p > 0) {
        (*s).p -= 1;
        printf("%d\n",(*s).element[(*s).p]);
    }else{
        printf("is empty");
    }
}
int main()
{
    stack s;
    s.p = 0;
    int i;
    for (i = 0; i < 100; i++) {
        push(&s, i);
    }
    for (i = 0; i < 100; i++) {
        pop(&s);
    }
    return 0;
}