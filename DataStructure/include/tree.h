#include <stdio.h>
#include <stdlib.h>
// #include "queue.h"

typedef struct BTree
{
    struct BTree *left;
    struct BTree *right;
    int val;
} TNode;

typedef struct Qn
{
    TNode *bnode;
    struct Qn *next;
} QNode;

typedef struct Q
{
    QNode *front, *rear;
} Q;

TNode *initBTree()
{
    TNode *root = (TNode *)malloc(sizeof(TNode));
    root->val = -1;
    root->left = NULL;
    root->right = NULL;
    return root;
}

TNode *newBNode(int val)
{
    TNode *node = (TNode *)malloc(sizeof(TNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void preBTree(TNode *root)
{

    if (!root)
        return;

    printf("%d\n", root->val);
    preBTree(root->left);
    preBTree(root->right);
}

void backBTree(TNode *root)
{
    if (!root)
    {
        return;
    }

    preBTree(root->left);
    preBTree(root->right);
    printf("%d\n", root->val);
}

void midBTree(TNode *root)
{
    if (!root)
    {
        return;
    }

    preBTree(root->left);
    printf("%d\n", root->val);
    preBTree(root->right);
}

void enqueue(Q *q, TNode *bnode)
{
    QNode *newNode = (QNode *)malloc(sizeof(QNode));
    newNode->bnode = bnode;
    newNode->next = NULL;
    if (!q->rear)
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

TNode *dequeue(Q *q)
{
    if (!q->front)
        return NULL;
    QNode *temp = q->front;
    TNode *node = temp->bnode;
    q->front = q->front->next;
    if (!q->front)
        q->rear = NULL;
    free(temp);
    return node;
}

void levelBTree(TNode *root)
{
    if (!root)
        return;

    Q *q = (Q *)malloc(sizeof(Q));
    q->front = q->rear = NULL;
    enqueue(q, root);

    while (q->front)
    {
        TNode *temp = (TNode *)malloc(sizeof(TNode));
        temp = dequeue(q);
        printf("%d, ", temp->val);
        if (temp->left)
        {
            enqueue(q, temp->left);
        }
        if (temp->right)
        {
            enqueue(q, temp->right);
        }
    }
    free(q);
    printf("\n");
}

typedef struct UnionSets
{
    int Sets[MaxSize];
    int size;
} uSets;

uSets *initialSets()
{
    uSets *sets = (uSets *)malloc(sizeof(uSets));
    sets->size = MaxSize;
    for (int i = 0; i < sets->size; i++)
    {
        sets->Sets[i] = -1;
    }

    return sets;
}

void Union(uSets *set, int Root1, int Root2, int flag)
{
    if (Root1 == Root2 || (!(set->Sets[Root2] < 0) || !(set->Sets[Root2] < 0)))
        return;

    if (flag)
    {
        /*优化
            细则: [Root]下存储的数的绝对值是所挂结点个数(初始化为-1)
            把小树挂到大树下 减小合并时高度的增加
            */
        if (Root1 > Root2)
        { // Root2下节点数小于Root1

            set->Sets[Root2] += set->Sets[Root1];
            set->Sets[Root1] = Root2; // Roo1挂到Root2 则此时Root1不再做根结点
        }
        else
        { // Root2下节点数小于Root1
            set->Sets[Root1] += set->Sets[Root2];
            set->Sets[Root2] = Root1; // Root2挂到Root1 则此时Root2不再做根结点
        }
    }
    else
    {
        // 未优化前
        set->Sets[Root1] = Root2; // 把Roo1挂到Root2下
    }
}

int  recurseFind(uSets *set, int x){
    
    if(set->Set[x] < 0) {
    		return x;
	}	
    
    return set->Set[x] = recuseFind(set, set->Set[x]);
}
int Find(uSets *set, int x, bool flag)
{
    if ((set->Sets[x] < 0))
        return x;

    int root = x;
    if (flag)
    {

        /* 优化后
    思路: 基于路径压缩
    */

        while (set->Sets[root] >= 0)
        {
            root = set->Sets[root];
        }
        // 压缩路径
        while (x != root)
        {
            int t = x;
            x = set->Sets[x];    // 回上层
            set->Sets[t] = root; // 修改根
        }
    }
    else
    {

        // 未优化
        int temp = x;
        while (set->Sets[temp] >= 0)
        {
            temp = set->Sets[temp];
        }
        return temp;
    }
    return root;
}