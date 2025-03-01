#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;   // this become a global pointer

void create(int a[], int n)
{
    struct Node *t, *last;
    first = new Node();
    first->data=a[0];
    first->next = NULL;
    last = first;
    for(int i = 1; i < n;i++)
    {
        t = new Node();
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last =t;
    }
}

void Display(struct Node *p)
{
    while(p!=nullptr)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void RDisplay(struct Node *p)
{
    if(p != NULL)
    {
        printf("%d ", p->data);
        RDisplay(p->next);
    }
}



int main()
{
    int A[] = {3,5,7,10,15};

    create(A,5);
    Display(first);

    return 0;
}