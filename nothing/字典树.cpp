#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 26
typedef struct Trie {   
    Trie *next[MAX];   
    int v;   
};
Trie root;

void create(char *str){
    int len = strlen(str);
    Trie *p = &root,*q;
    for (int i = 0; i < len; i++){
        int id = str[i]-'a';
        if (p->next[id] == NULL){
            q = (Trie *)malloc(sizeof(Trie));
            q->v = -1;
            for (int j = 0; j < MAX; j++){
                q->next[j]=NULL;
            
            p->next[id]=q;
            p=p->next[id];
        }
        else{
            p=p->next[id];
        }
    }
    p->v=1;
}

int findTrie(char *str){
    int len = strlen(str);
    Trie *p = &root;
    for(int i=0; i<len; ++i){
        int id = str[i]-'a';
        p = p->next[id];
        if(p == NULL)
            return -1;
    }
    return p->v;
}

char ch[50000][100];

int main(){
    int count=0;
    for (int i=0;i<MAX;i++){
        root.next[i]=NULL;
    }
    while(scanf("%s",ch[count])!=EOF){
        create(ch[count]);
        count++;
    }
    char c1[100]={'\0'},c2[100]={'\0'};
    for (int i=0;i<count;i++){
        int len=strlen(ch[i]);
        for (int j = 1;j < len; j++){
            strcpy(c1, ch[i]);
            c1[j] = '\0';
            strcpy(c2,ch[i]+j);
            if (findTrie(c1) == 1 && findTrie(c2) == 1){
               printf("%s\n",ch[i]);
               break;
            }
        }
    }
    return 0;
}