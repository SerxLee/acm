/*
 * ac.c--多模式匹配算法
 *
 *  Created on: Jul 14, 2011
 *      Author: root
 */
#include    <stdio.h>
#include    <malloc.h>
#include    <stdlib.h>
#include    <string.h>

struct node
{
    struct node *fail; //失败指针
    struct node *next[26];//一个节点拥有的子节点
    int count; //是否为该单词最后一个点；1表示是最后一个点，0表示初始化，－1表示已经统计过
};
typedef struct node Node;
Node *q[5001];//关键词每行50个词，共10000行
char    keyword[51];//关键词
char    str[1000001];//字符串
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
int query(Node *root, char *str)
{
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
    return cnt;
}

int main()
{
    int n, t, i;
    scanf("%d",&t);
    while (t--)
    {
        head = tail = 0;
        Node *root = (Node *)malloc(sizeof(Node));        
        for (i = 0; i < 26; i++)
            root->next[i] = 0;
        root->count = 0;
        scanf("%d",&n);
        while (n--)
        {            
            scanf("%s",keyword);
            insert(keyword,root);//根据keyword建立字典树
        }
        build_fail(root);//建立失败指针
        scanf("%s", str);
        printf("%d\n", query(root,str));//根据输入字串查找关键字出现次数
    }
    return 0;
}