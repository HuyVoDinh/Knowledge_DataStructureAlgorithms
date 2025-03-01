#include <stdio.h>
#define INT32_MIN (-2147483647 - 1)

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

int Max(Node *p)
{
    int max = INT32_MIN;

    while(p)
    {
        if(p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

int RMax(Node *p)
{
    int x = 0;
    if (p == 0)
        return INT32_MIN;
    x = RMax(p->next);
    if (x > p->data)
        return x;
    else 
        return p->data;
}

Node *LSearch (Node *p, int key)
{
    while(p!=NULL)
    {
        if (key == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}

Node *RSearch(Node *p, int key)
{
    if (p == NULL)
        return NULL;
    if(key == p->data)
        return p;
    return RSearch(p->next, key);
}

// Move node to first if found
Node *LSearch2(Node *p, int key)
{
    struct Node*q;
    while(p != NULL)
    {
        q = p;
        if(key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        
        p = p->next;
    }
    
    return RSearch(p->next, key);
}

void Insert(Node *p, int index, int x)
{
    struct Node *t;
    if(index < 0 || index > count(p))
    {
        return;
    }
    t = new Node();
    t->data = x;
    if(index == 0)
    {
        t->next = first;
        first = t;
    }
    else 
    {
        for(int  i = 0; i < index; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }

}

int main()
{
    int A[] = {3,5,7,10,15};
    Node *temp;

    create(A,5);
    Display(first);
    printf(" \nLength is: %d\n", Rcount(first));
    printf(" \nSum is: %d\n", sum(first));
    printf("\nMax is %d\n", RMax(first));

    temp = RSearch(first, 10);
    if(temp)
        printf("Key is found %d\n", temp->data);
    else
        printf("Key not found\n");

    Insert(first, 3 , 10);
    Display(first);
    return 0;
}