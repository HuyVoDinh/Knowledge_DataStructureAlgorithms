#include "Queue.h"
#include <exception>
#ifndef Stack_h
#define Stack_h

struct Stack
{
    int size;
    int top;
    Node **S;
};

void StackCreate(Stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->S = new Node*[size];
}

void push(Stack *st, Node *x)
{
    if(st->top == st->size-1)
        printf("Stack overflow\n");
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

Node *pop(Stack *st)
{
    Node *x = NULL;
    if(st->top == -1)
        printf("Stack overflow\n");
    else
    {
        x = st->S[st->top--];
    }
    return x;
}
int isEmptyStack(Stack st)
{
    if (st.top == -1)
        return 1;
    return 0;
}

int isFullStack(Stack st)
{
    return st.top == st.size-1;
}
#endif