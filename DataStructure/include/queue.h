#include <stdio.h>
#include <stdlib.h>

#define MaxSize 5

typedef struct qNode
{
    int val;
    struct qNode *next;
} QNode;
// 链队列能否理解为尾插法的链表,加头指针和尾指针 OK

typedef struct Queue
{
    QNode *front;
    QNode *rear;
} LQueue;

QNode *newNode(int val)
{
    QNode *node = (QNode *)malloc(sizeof(QNode));
    node->val = val;
    node->next = NULL;
    return node;
}

LQueue *newQueue()
{
    LQueue *q = (LQueue *)malloc(sizeof(LQueue));
    q->front = q->rear = NULL;
    return q;
}

bool isEmpty(LQueue *q)
{
    if (q->front == q->rear)
        return 1;
    return 0;
}

void enQueue(LQueue *q, int val)
{
    QNode *temp = newNode(val);
    q->rear->next = temp;
    q->rear = temp;
}

void printQueue(LQueue *q)
{
    if (q->front)
    {
        QNode *node = q->front;
        // while (node)
        // {
        //     printf("%p->", node);
        //     node = node->next;
        // }
        // printf("\n");
        // node = q->front;
        while (node)
        {
            printf("%d->", node->val);
            node = node->next;
        }
        printf("\n");
    }
}

void deQue(LQueue *q)
{
    if (isEmpty(q))
        return;
    QNode *temp = q->front;
    q->front = temp->next;
    free(temp);
}

typedef struct CircleQueue
{
    int length;
    int front, rear;
    int queue[MaxSize];
} CQueue;

bool isCQFull(CQueue q)
{
    if (q.length == MaxSize)
        return 1;

    return 0;
    // if (q.rear == q.front && q.length != 0) return 1;
}

void enCQueue(CQueue *q, int val)
{
    // length Version
    if (isCQFull(*q))
    {
        printf("Full Queue,Please dequeue!!!\n");
        return;
    }

    int index = (q->front + q->length) % MaxSize;
    q->queue[index] = val;
    q->length++;
    q->rear++;

    // rear Version
    // if (isCQFull(*q))
    // {
    //     printf("Full Queue,Please dequeue!!!");
    //     return;
    // }

    // q->queue[q->rear] = val;
    // q->rear++;
    // q->length++;
}

void deCQueue(CQueue *q)
{
    if (q->length == 0)
    {
        printf("Empty,fault operation\n");
        return;
    }

    q->front++;
    q->length--;
}

void printCQueue(CQueue q)
{
    int i = q.front;
    while (i < q.rear)
    {
        if (i == (q.rear - 1))
        {
            printf("%d", q.queue[i]);
        }
        else
        {

            printf("%d->", q.queue[i]);
        }
        i++;
    }
    printf("\n");
}