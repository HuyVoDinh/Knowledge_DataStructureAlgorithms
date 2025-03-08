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

int main()
{
    int A[] = {10,20,30,40,50};
    create(A,5);
    printf("\nLength is :%d\n", Length(first));

    Display(first);
    return 0;
}