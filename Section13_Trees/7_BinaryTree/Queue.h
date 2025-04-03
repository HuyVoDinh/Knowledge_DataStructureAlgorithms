#ifndef Queue_h
#define Queue_h

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    Node *lchild;
    int data;
    Node *rchild;
};

struct Queue
{
    int size;
    int front;
    int rear;
    Node **Q;       // first point is for array, second point for type node. It's going to store pointer of type nodes. Then this queue structure.  When we are creating an array, it is not integer type pointer, it's a node type pointer to a pointer. That is double pointer.
};

void create(Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = new Node*[size];
}

void enqueue(Queue *q, Node *x)
{
    if((q->rear+1)%q->size == q->front)
        printf("Queue is Full");
    else
    {
        q->rear = (q->rear+1)%q->size;
        q->Q[q->rear] = x;
    }
}

Node* dequeue(Queue *q)
{
    Node *x = NULL;
    if(q->front==q->rear)
        printf("Queue is Empty\n");
    else
    {
        q->front=(q->front+1)%q->size;
        x= q->Q[q->front];
    }

    return x;
}

int isEmpty(Queue q)
{
    return q.front == q.rear;
}

#endif