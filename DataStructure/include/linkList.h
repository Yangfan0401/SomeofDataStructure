#include <stdlib.h>
#include <stdio.h>

typedef struct linkList
{
    struct linkList *next;
    int data;
} ListNode, *List;

List initList()
{
    List l = (ListNode *)malloc(sizeof(ListNode));
    // 带头结点--不存数据
    l->data = -1;
    l->next = NULL;
    // 不带头结点
    //  l = NULL;

    return l;
}

void TailInsert(List l, int value)
{
    ListNode *p = l;
    while (p->next != NULL)
    {
        p = p->next;
    }

    ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
    temp->data = value;
    temp->next = NULL;
    p->next = temp;
}

void HeadInsert(List l, int value)
{
    ListNode *p = l;

    ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
    temp->data = value;
    temp->next = p->next; // 当仅存在头结点时,temp->next == temp->next = NULL
    p->next = temp;
}

void traverseList(List l)
{
    ListNode *p = l; // l->next直接跳过头结点
    while (p != NULL)
    {
        printf("Point: %p --> Data: %d\n", p, p->data);
        p = p->next;
    }
}

typedef struct doubleLinkList
{
    struct doubleLinkList *prior, *next;
    int data;
} DListNode, *DoubleLink;

DoubleLink initDList()
{
    DoubleLink p = (DListNode *)malloc(sizeof(DListNode));
    p->next = NULL;
    p->data = -1;
    return p;
}

void HeadInsertDList(DoubleLink l,int value){
    DListNode *p = l;
    printf("P: %p\n",p);

    DListNode* temp = (DListNode*)malloc(sizeof(DListNode));
    temp->data = value;
    temp->next = p->next;
    p->next = temp;

    free(p);
    // printf("%p");
}

void TailInsertDList(DoubleLink l,int value){

}

void traverseDList(DoubleLink l) {
    DListNode *p = l;
    while (p->next)
    {
        printf("P: %p-->data: %d",p,p->data);
        p = p->next;
    }

    free(p);
}