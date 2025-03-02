#include <stdio.h>
#define INT32_MIN (-2147483647 - 1)

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, * third = NULL;   // this become a global pointer

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
        for(int  i = 0; i < index-1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void SortedInsert(Node *p, int x)
{
    Node *t, *q = NULL;
    t = new Node();
    t->data = x;
    t->next = NULL;

    if(first == NULL)
        first = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if(p == first)
        {
            t->next = first;
            first = t;
        }
        else 
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int Delete(Node *p, int index)
{
    Node *q = NULL;
    int x = -1;

    if(index < 1 || index > count(p))
        return -1;
    if(index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        delete q;
        return x;
    }
    else
    {
        for(int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        return x;
    }
}

int isSorted(Node *p)
{
    int x = -65536;
    while(p!=nullptr)
    {
        if(p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

void Reverse1(Node *p)
{
    int *A, i =0;
    Node *q = p;
    int size = count(p);
    A = new int(size);
    while (q!=NULL)
    {
        A[i] = q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q!=NULL)
    {
        q->data=A[i];
        q=q->next;
        i--;
    }
}

void Reverse2(Node *p)
{
    Node *q = NULL, *r = NULL;
    while (p!=nullptr)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void Reverse3(Node *q, Node *p)
{
    if(p)
    {
        Reverse3(p,p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

void RemoveDuplicate(Node *p)
{
    Node *q = p->next;
    while(q != NULL)
    {
        if(p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = nullptr;
            q = p->next;
        }
    }
}

// Example merge, concat
void create2(int a[], int n)
{
    struct Node *t, *last;
    second = new Node();
    second->data=a[0];
    second->next = NULL;
    last = second;
    for(int i = 1; i < n;i++)
    {
        t = new Node();
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last =t;
    }
}

void Concat(Node *p, Node *q)
{
    third = p;
    while(p->next!=NULL)
    {
        p = p->next;
    }
    p->next = q;
}
//Only apply to sorted linked list
void Merge(Node *p, Node *q)
{
    Node *last;
    if(p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }

    while(p && q)
    {
        if(p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if(p)last->next = p;
    if(q) last->next = q;
}

//Loop linked list: Last node of a linked list is pointing on some node in the linked list. It's not hte first node, it's some other node. 
// If a last node is pointing on some node of a linked list, then it is forming a loop. 
int isLoop(Node *f)
{
    Node *p, *q;
    p = q = f;

    do
    {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    } while (q && p && q!=p);
    if (p == q)
        return 1;
    else 
        return 0;
    
}

int main()
{
    int A[] = {6,7,8,10,15};
    int B[] = {1,2,3,4,20};
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

    Insert(first, 4, 13);
    Display(first);
    printf("\n\n");
    SortedInsert(first,10);
    Display(first);
    printf("\nDeleted element %d\n",Delete(first,4));
    printf("\nIs sorted: %d\n",isSorted(first));
    printf("\nRemove duplicated\n");
    RemoveDuplicate(first);
    Display(first);
    printf("\nReverse\n");
    Reverse3(NULL,first);
    Display(first);
    Reverse3(NULL,first);

    //Concat & merge
    create2(B,5);
    // printf("\nConcat\n");
    // printf("\nFirst: ");
    // Display(first);
    // printf("\nSecond: ");
    // Display(second);
    // Concat(first,second);
    // printf("\nThird: ");
    // Display(third);

    
    printf("Merge\n");
    printf("\nFirst: ");
    Display(first);
    printf("\nSecond: ");
    Display(second);
    Merge(first,second);
    printf("\nThird: ");
    Display(third);

    Node *t1, *t2;
    t1 = first->next->next;//pointing on 2th node
    t2 = first->next->next->next->next; // pointing on 4th node
    t2-> next = t1;
    printf("\nis Loop: %d", isLoop(first));
    return 0;
}