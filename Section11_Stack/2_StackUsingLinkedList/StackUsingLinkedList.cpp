#include <stdio.h>

struct Node
{
    int data;
    Node *next;
}*top = NULL;

void push(int x)
{
    Node *t;
    t = new Node();
    if(t == NULL)
        printf("Stack is full\n");
    else
    {
        t->data = x;
        t->next  = top;
        top = t;
    }
}

int pop()
{
    Node *t;
    int x = -1;
    if(top == NULL)
        printf("Stack is empty\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

void Display()
{
    Node *p;
    p = top;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    push(10);
    push(20);
    push(30);
    Display();
    printf("Pop: %d", pop());
    return 0;
}