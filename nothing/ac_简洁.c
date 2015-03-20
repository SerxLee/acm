#include    <stdio.h>
#include    <sys/malloc.h>
#include    <stdlib.h>
#include    <string.h>

struct node
{
    struct node *fail;
    struct node *next[26];
    int count;
};
typedef struct node Node;
Node *q[5001];
char    keyword[55];
char    str[1000005];
int        head, tail;

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
        }
        p = p->next[index];
        i++;
    }
    p->count = 1;
}

void build_fail(Node *root)
{
    int i;
    root->fail = NULL;
    q[head++] = root;
    while (head != tail)
    {
        Node *temp = q[tail++];
        Node *p = NULL;
        for (i=0; i < 26; i++)
        {
            if (temp->next[i] != NULL)
            {
                if (temp == root)
                {
                    temp->next[i]->fail = root;
                }
                else
                {
                    p = temp->fail;
                    while (p != NULL)
                    {
                        if (p->next[i] != NULL)
                        {
                            temp->next[i]->fail = p->next[i];
                            break;
                        }
                        p = p->fail;
                    }
                    if (p == NULL)
                    {
                        temp->next[i]->fail = root;
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
    Node *p = root;
    while (str[i])
    {
        index = str[i] - 'a';
        while (p->next[index] == NULL && p != root)
            p = p->fail;
        p = p->next[index];
        if (p == NULL)
            p = root;
        Node *temp = p;
        while (temp != root && temp->count != -1)
        {
            cnt+=temp->count;
            temp->count = -1;
            temp = temp ->fail;
        }
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
            insert(keyword,root);
        }
        build_fail(root);
        scanf("%s", str);
        printf("%d\n", query(root,str));
    }
    return 0;
}