/**
 * Node is having a pointer to next node, as well as a previous node. So it means from one node and can go forward as well as come backward.
 * So can access this list of elements bi-directionally. Can traverse them in either direction. 
 * 
 * ***/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first =NULL;

void create(int A[], int n)
{
    Node *t, *last;
    first = new Node();
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;

    for(int i = 1; i < n; i++)
    {
        t = new Node();
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void Display (Node *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    
}

int Length(Node *p)
{
    int length = 0;
    while(p)
    {
        length++;
        p= p->next;
    }
    return length;
}

void Insert(Node *p, int index, int x)
{
    Node *t;
    if(index < 0 || index > Length(p))
        return;
    
    if(index == 0)
    {
        t = new Node();
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for(int i = 0; i < index-1; i++)
        {
            p = p->next;
        }
        t = new Node();
        t->data = x;
        t->prev = p;
        t->next = p->next;
        if(p->next)
            p->next->prev = t;
        p->next = t;
    }
}

int Delete(Node *p, int index)
{
    Node *q;
    int x = -1;
    if(index < 1 || index > Length(p))
        return -1;
    if(index == 1)
    {
        first = first->next;
        if(first) first->prev = NULL;
        x = p->data;
        delete p;
    }
    else
    {
        for(int i = 0; i < index-1;i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        if(p->next)
            p->next->prev = p->prev;
        x = p->data;
        delete p;
    }
    return x;
}

int main()
{
    int A[] = {10,20,30,40,50};
    create(A,5);
    printf("\nLength is :%d\n", Length(first));

    Display(first);
    printf("\nInsert \n");
    Insert(first,5,25);
    Display(first);

    printf("\nDelete \n");
    Delete(first,6);
    Display(first);


    return 0;
}