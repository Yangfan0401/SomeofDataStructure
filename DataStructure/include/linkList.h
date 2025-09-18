#include <stdlib.h>
#include <stdio.h>

// typedef struct linkList
// {
//     struct linkList *next;
//     int data;
// } ListNode, *List;

// typedef struct List
// {
//     ListNode *head;
//     ListNode *tail;
// } list;

typedef struct ListNode
{
    int data;
    struct ListNode *next;
} ListNode;

// 单链表
typedef struct
{
    ListNode *head;
    ListNode *tail;
} LinkedList;

LinkedList *createList()
{
    LinkedList *l = (LinkedList *)malloc(sizeof(LinkedList));
    l->head = l->tail = NULL;

    return l;
}

ListNode *createNode(int value)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = value;
    node->next = NULL;

    return node;
}

void tailAppend(LinkedList *l, int value)
{
    ListNode *node = createNode(value);

    l->tail->next = node;
    l->tail = node;
}

void crossList(LinkedList *l)
{

    ListNode *temp = l->head;
    if (!temp->next)
        return;
    temp = temp->next;
    while (temp)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//
void unionList(LinkedList *l_1, LinkedList *l_2)
{
    int length1 = 0, length2 = 0;
    ListNode *temp = l_1->head;
    temp = temp->next;
    while (temp)
    {
        temp = temp->next;
        length1++;
    }

    temp = l_2->head;
    temp = temp->next;
    while (temp)
    {
        temp = temp->next;
        length2++;
    }

    int offset = abs(length1 - length2);
    if (length1 > length2)
    { // l_1长
        temp = l_2->head;
        temp = temp->next;
        for (int i = 0; i < offset; i++)
        {
            temp = temp->next;
        } // 对齐

        ListNode *node = l_1->head;
        node = node->next;
        while (node || temp)
        {
            while (node->data != temp->data)
            {
                node = node->next;
            } // 指针对齐
            while (node->data == temp->data)
            {
                node = node->next;
                temp = temp->next;
            }
        }
    }
    else
    { // l_2长
        temp = l_1->head;
        temp = temp->next;
        for (int i = 0; i < offset; i++)
        {
            temp = temp->next;
        } // 对齐

        ListNode *node = l_2->head;
        node = node->next;
        while (node || temp)
        {
            while (node->data != temp->data)
            {
                node = node->next;
            } // 指针对齐
            while (node->data == temp->data)
            {
                node = node->next;
                temp = temp->next;;
            }
        }
    }

}