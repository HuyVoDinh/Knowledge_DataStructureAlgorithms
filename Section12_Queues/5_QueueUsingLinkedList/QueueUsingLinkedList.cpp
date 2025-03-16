#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    Node *next;
}*front = NULL, *rear = NULL;

void enqueue(int x)
{
    Node *t = new Node();
    if (t == NULL)
        printf("Queue is FULL\n");
    else 
    {
        t->data = x;
        t->next = NULL;
        if(front==NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    int x = -1;
    Node *t;
    if(front == NULL)
        printf("Queue is Empty");
    else
    {
        x = front->data;
        t = front;
        front = front->next;
        delete t;
    }
    return x;
}

void Display()
{
    Node *p = front;
    while(p)
    {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    Display();
    return 0;
}