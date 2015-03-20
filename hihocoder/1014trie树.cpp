http://hihocoder.com/problemset/problem/1014

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, m;
char a[15];
struct Node{
    int count = 0;
    Node * next[26] = {NULL};
};
Node * head = new Node;
void insert(){
    int i = 0;
    Node * tmp = head;
    while(a[i] != '\0'){
        Node *tt = new Node();
        if(tmp -> next[a[i] - 97] == NULL){
            tmp -> next[a[i]- 97] = tt;
            tt -> count = 1;
            tmp = tmp -> next[a[i]- 97];
        }else{
            tmp = tmp -> next[a[i]- 97];
            tmp -> count ++;
        }
        i++;
    }
}
int search(){
    int i = 0, cc = 0;
    Node * tmp = head;
    while(a[i] != '\0'){
        if(tmp -> next[a[i] - 97] != NULL){
            tmp = tmp -> next[a[i] - 97];
            cc = tmp -> count;
        }else{
            cc = 0;
            break;
        }
        i++;
    }
    return cc;
}
int main(){
    cin >> n;
    while(n--){
        memset(a, 0, sizeof(a));
        scanf("%s", a);
        insert();
    }
    cin >> m;
    while(m--){
        memset(a, 0, sizeof(a));
        scanf("%s", a);
        printf("%d\n", search());
    }
}