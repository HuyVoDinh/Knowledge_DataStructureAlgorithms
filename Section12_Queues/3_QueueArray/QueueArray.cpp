#include <stdio.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = new int();

}

void enqueue(Queue *q,int x)
{
    if(q->rear == q->size-1)
        printf("Queue is full");
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

void Display(Queue q)
{
    for(int i = q.front+1; i<= q.rear; i++)
        printf("%d ", q.Q[i]);
    printf("\n");
}

int dequeue(Queue *q)
{
    int x = -1;
    if(q->front == q->rear)
        printf("Queue is Empty\n");
    else
    {
        q->front++;
        x = q->Q[q->front];        
    }
    return x;
}

int main()
{
    Queue q;
    create(&q,5);

    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);

    Display(q);

    printf("%d ", dequeue(&q));
    return 0;
}