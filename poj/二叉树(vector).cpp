#include <cstdio>
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> myv;
int arr[1001];

int CreateBiTree(SqBiTree T){
    int i=0;
    int l=0;
    char s[1000];
    gets(s);
    l = strlen(s);
    for (; i < l; i++){
        T[i]=s[i];
        if(i != 0 && T[(i + 1) / 2 - 1] == Nil && T[i] != Nil){
            return ERROR;
        }
    }
    for (; i < 1000; i++){
        T[i] = Nil; 
    }
    return OK;
}

int main(){
	cin >> arr;
}
