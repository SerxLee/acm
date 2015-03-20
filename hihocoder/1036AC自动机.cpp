#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1

template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline void CheckMin(T &a,T b){if(a>b) a=b;}
template<class T> inline void CheckMax(T &a,T b){if(a<b) a=b;}

const int N = 10000010;
const int INF=0x3f3f3f3f;
const int MOD=95041567,STA=8000010;
const double EPS=1e-8;
const double OO=1e15;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
const int M = 12;

//end

struct node
{
    struct node *fail; //失败指针
    struct node *next[26];//一个节点拥有的子节点
    int count; //是否为该单词最后一个点；1表示是最后一个点，0表示初始化，－1表示已经统计过
};
typedef struct node Node;
Node *q[N];//关键词每行50个词，共10000行
char    keyword[51];//关键词
char    str[N];//字符串
int        head, tail;//队列的头、尾指针

/*插入节点到字典树中*/
void insert(char *str,Node *root)
{
    Node *p = root;
    int i = 0, index;
    while(str[i])
    {
        index = str[i] - 'a';
        if (p->next[index] == NULL)
        {
            Node *newnode;
            int j;
            newnode = (Node *)malloc(sizeof(Node));
            for (j = 0; j < 26; j++)
                newnode->next[j] = 0;
            newnode->count = 0;
            p->next[index] = newnode;
        } /*如果不存在那个节点，首先得创建节点*/
        p = p->next[index];
        i++;
    }
    p->count = 1;//表示此节点为最后一个词
}
/*失败指针的建立*/
void build_fail(Node *root)
{
    int i;
    root->fail = NULL;/*让root的失败指针指向NULL，作为一种条件判断*/
    q[head++] = root;
    while (head != tail)/*当遍历完所有的节点后，head==tail*/
    {
        Node *temp = q[tail++];/*首先让指针指向root*/
        Node *p = NULL;
        for (i=0; i < 26; i++)
        {
            if (temp->next[i] != NULL)/*找到存在的节点，用的是遍历的方法*/
            {
                if (temp == root)
                {
                    temp->next[i]->fail = root;/*root所有下一级节点的失败指针全部指向root*/
                }
                else
                {
                    p = temp->fail;/*找到失配点父节点的失败指针,其父节点的字符与该失败指针指向字符相等*/
                    while (p != NULL)
                    {
                        if (p->next[i] != NULL)/*如果p->next[i]有节点，在p->next[i]就是temp->next[i]失败指针位置*/
                        {
                            temp->next[i]->fail = p->next[i];
                            break;
                        }
                        p = p->fail;/*如果上一个if不成立，则继续向上查找*/
                    }
                    if (p == NULL)
                    {
                        temp->next[i]->fail = root;/*如果没有找到，那么将失败指针指向root*/
                    }
                }
                q[head++] = temp->next[i];
            }
        }
    }
}
int query(Node *root, char *str){
    int cnt = 0, i = 0, index;
    Node *p = root;/*从root开始匹配*/
    while (str[i])
    {
        index = str[i] - 'a';
        while (p->next[index] == NULL && p != root)
            p = p->fail;
        p = p->next[index];
        if (p == NULL)
            p = root;/*没有找到匹配点，则从root出开始匹配*/
        Node *temp = p;
        while (temp != root && temp->count != -1)
        {
            cnt+=temp->count;
            temp->count = -1;
            temp = temp ->fail;
        }//统计匹配到的关键字
        i++;
    }
    free(root);
    return cnt;
}

int main(){
    int n, i;
    while (scanf("%d",&n) != EOF){
        head = tail = 0;
        Node *root = (Node *)malloc(sizeof(Node));
        for (i = 0; i < 26; i++)
            root->next[i] = 0;
        root->count = 0;
        while (n--)
        {
            scanf("%s",keyword);
            insert(keyword,root);//根据keyword建立字典树
        }
        build_fail(root);//建立失败指针
        scanf("%s", str);
        int res = query(root, str);
        if (res > 0){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}