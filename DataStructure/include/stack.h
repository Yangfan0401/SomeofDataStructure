#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 5

typedef struct {
    int* stack;
    size_t length;
}MyStack;

void initStack(MyStack *s){
    s->stack = (int*)malloc(sizeof(int)*MaxSize);
    s->length = 0;
}

void extend(MyStack *s,int size) {

}

void push(MyStack* s,int value) {
    if (s->length > MaxSize - 1) return; //extend()扩容

    *s->stack = value;
    s->stack++;
    s->length++;
}

int pop(MyStack* s,int e) {
    if (s->length < 1) return -1;

    e = *s->stack; //Stack Top Element
    s->stack--;
    s->length--;

    return e;
}

bool empty(MyStack* s) {
    if (s->stack && s->length == 0) return true;

    return false;
}