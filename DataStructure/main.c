#include "include/stack.h"
#include "include/linkList.h"
#include "include/tree.h"
// #include "include/queue.h"
#include "include/algorithm.h"

int main()
{
    // 队列
    //  Q q;
    //  initQ(&q);
    //  printf("%d\n", q.length);
    //  QPop(&q);
    //  QPush(&q, 8);
    //  QPush(&q, 7);
    //  QPush(&q, 6);
    //  QVisit(q);
    //  QPop(&q);
    //  QVisit(q);
    //  if (getQHead(q) > 0)
    //  {
    //      printf("Head: %d\n", getQHead(q));
    //  }
    //  if (getQTail(q) > 0)
    //  {
    //      printf("Tail: %d\n", getQTail(q));
    //  }

    // 链队
    // QNode *node = newNode(3);
    // LQueue *q = newQueue();
    // q->front = q->rear = node;
    // enQueue(q, 5);
    // enQueue(q, 4);
    // printQueue(q);
    // deQue(q);
    // printQueue(q);
    // 循环队列
    // CQueue cq;
    // cq.front = cq.rear = 0;
    // cq.length = 0;
    // for (int i = 0;i < MaxSize;i++){
    //     cq.queue[i] = 0;
    // }
    // enCQueue(&cq, 1);
    // enCQueue(&cq, 2);
    // enCQueue(&cq, 3);
    // enCQueue(&cq, 4);
    // enCQueue(&cq, 5);
    // deCQueue(&cq);
    // printCQueue(cq);
    // enCQueue(&cq, 6);
    // for (int i = 0;i < MaxSize;i++){
    //     printf("%d->", cq.queue[i]);
    // }
    // printCQueue(cq);
    // deCQueue(&cq);
    // deCQueue(&cq);
    // deCQueue(&cq);
    // deCQueue(&cq);
    // printCQueue(cq);

    // 链表
    //  List l = initList();
    //  TailInsert(l,1);
    //  TailInsert(l,2);
    //  TailInsert(l,3);
    //  HeadInsert(l,0);
    //  TailInsert(l,4);
    //  traverseList(l);
    //  free(l);
    //  l = NULL;
    //  DoubleLink dl = initDList();
    //  insertDList(dl);
    //  traverseDList(dl);
    // 栈
    //  MyStack *s=(MyStack*)malloc(sizeof(MyStack));
    //  initStack(s);
    //  printf("%p\n",s);
    // 树
    //  Tree t = initTree(3);
    //  insertLeftNode(t,8);
    //  insertRightNode(t, 10);
    //  pre(t);
    //  mid(t);
    //  back(t);

    // TNode *root = initBTree();
    // root->left = newBNode(1);
    // root->right = newBNode(2);
    // root->left->right = newBNode(3);
    // root->left->right->left = newBNode(4);
    // root->right->left = newBNode(5);
    // root->right->left->right = newBNode(6);
    // printf("PreOrder:\n");
    // preBTree(root);
    // printf("MidOrder:\n");
    // midBTree(root);
    // printf("BackOrder:\n");
    // backBTree(root);
    // printf("LevelOrder:\n");
    // levelBTree(root);

    // 算法
    // 10年
    //  printf("\n");
    //  leftMoveAlg(3);
    //  printf("%d\n",test());
    // 11年
    // int s1[] = {11, 13, 15, 17, 19};
    // int s2[] = {2, 4, 6, 8, 20};
    // printf("%d", s1[0]);
    // 13
    // int s3[] = {0, 5, 5, 3, 5, 7, 5, 5};
    // int s4[] = {0, 5, 5, 3, 5, 1, 5, 7};
    // int temp = -1;
    // temp = test_13_findKey(s3,8);
    // printf("%d\n",temp);
    // temp = test_13_findKey(s4,8);
    // printf("%d\n",temp);
    // int s[] = {12, 1, 4, 5, 9, 8, 10, 3};
    // int len = sizeof(s) / sizeof(int);

    //归并排序测试
    // MergeSort(s, 0, len - 1);
    
    return 0;
}