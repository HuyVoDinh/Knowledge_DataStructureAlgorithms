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
    q->front = q->rear = 0;
    q->Q = new int();

}

void enqueue(Queue *q,int x)
{
    if((q->rear+1)%q->size == q->front)
        printf("Queue is full");
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear] = x;
    }
}

void Display(Queue q)
{
    int i = q.front+1;
    do{
        printf("%d ", q.Q[i]);
        i = (i+1)%q.size;
    }while(i!= (q.rear+1)%q.size);
    printf("\n");
}

int dequeue(Queue *q)
{
    int x = -1;
    if(q->front == q->rear)
        printf("Queue is Empty\n");
    else
    {
        q->front=(q->front+1)%q->size;
        x = q->Q[q->front];        
    }
    return x;
}

//Drawback of Queue Using Array
//Cannot reuse the spaces of deleted element. Cannot insert an element, through is a lot of space free. Every location can be used only once so cannot reuse them. 
// Front and rear are pointing at same place. So queue is empty, front is equal to rear, Queue is full because rear is equal to size -1. Queue is full, rear is at last location.
// Third point is a situation where queue is empty also.
//How to reuse?
// First solution: Resetting pointers. At anytime if a queue is becoming empty, at any place, bring front and rear pointer at the beginning. So that they can again start from the beginning. So in this way can reuse those places. 
// Circular Queue
/***
 * When queue is full, bring rear at zero and insert the element.  A new element is inserted at the backside of front pointer 
 * Dont use left space of front, wWherever front is pointing, that space must be left empty. 
 * What happens if use that space? -> rear and front are equal. We know the condition when they are at same space, queue is empty. -> It's empty condition. 
 * If the size of an array is seven, only size element have stored.
 * 
 * Rear = (Rear + 1) % size
 * 0        |   (0 + 1) % 7     |   1
 * 1        |   (1 + 1) % 7     |   2
 * 2        |   (2 + 1) % 7     |   3
 * 3        |   (3 + 1) % 7     |   4
 * 4        |   (4 + 1) % 7     |   5
 * 5        |   (5 + 1) % 7     |   6
 * 6        |   (6 + 1) % 7     |   0-> return
 * ***/

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