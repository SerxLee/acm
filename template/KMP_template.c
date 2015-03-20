#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void GetNext_R(char *t,int *next){
    unsigned int j=0;
    int k = -1;
    next[0] = -1;
    
    while(j < strlen(t)-1){
        
        if(k==-1||t[j]==t[k]){
            j++;
            k++;
            next[j] = k;
        }
        else
            k = next[k];
    }
    
}

int KMP(char *s, char *t){
    unsigned int i;
    int j = 0;
    int *next = (int*)calloc(strlen(t),sizeof(int)); 
       
    GetNext_R(t,next);

    for(i = 0; i < strlen(t); i++)
        printf("%d ",next[i]);
    
    i = 0;
    while (i < strlen(s)){
        if(j == -1||s[i]==t[j]){
            i++;
            j++;
        }
        else
            j = next[j];
        
        if(j == strlen(t))
            return (i - strlen(t));
    }
    
    free(next);
    
    return -1;
}

int main()
{
    char *S = "acabaabaabcacaabc";
    char *T = "abaabcac";
    
    printf("\n匹配结果： %d\n",KMP(S,T));
    
    return 0;
}