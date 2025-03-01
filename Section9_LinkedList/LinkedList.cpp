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

int count(Node *p)
{
    int l = 0;
    while (p)
    {
        l++;
        p = p->next;
    }
    return l;
}

int Rcount(Node *p)
{
    if(p!=NULL)
        return Rcount(p->next)+1;
    else
        return 0;
}

int sum(Node *p)
{
    int s = 0;
    while(p!=NULL)
    {
        s+= p->data;
        p = p->next;
    }
    return s;
}

int Rsum(Node *p)
{
    if (p == NULL)
        return 0;
    else 
        return Rsum(p->next)+p->data;
}

int main()
{
    int A[] = {3,5,7,10,15};

    create(A,5);
    Display(first);
    printf(" \nLength is: %d\n", Rcount(first));
    printf(" \nSum is: %d\n", sum(first));
    return 0;
}