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
