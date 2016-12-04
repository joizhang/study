#include "queue.h"
#include <stdlib.h>
#include "fatal.h"

#define MinQueueSize (5)

struct QueueRecord 
{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
};

int IsEmpty(Queue q) 
{
    return q->Size == 0;
}

int IsFull(Queue q)
{
    return q->Size == q->Capacity;
}

Queue CreateQueue(int MaxElements) 
{
    Queue q;

    if (MaxElements < MinQueueSize) 
        Error("Queue size is too small");

    q = malloc(sizeof(struct QueueRecord));
    if (q == NULL)
        FatalError("Out of space!");

    q->Array = (int *)malloc(sizeof(ElementType) * MaxElements);
    if (q->Array == NULL)
        FatalError("Out of space!");

    q->Capacity = MaxElements;
    MakeEmpty(q);
    return q;
}

void DisposeQueue(Queue q)
{
    if (q != NULL)
    {
        free(q->Array);
        free(q);
    }
}

void MakeEmpty(Queue q)
{
    q->Size = 0;
    q->Front = 1;
    q->Rear = 0;
}

static int Succ(int value, Queue q)
{
    if (++value == q->Capacity)
        value = 0;
    return value;
}

void Enqueue(ElementType x, Queue q)
{
    if (IsFull(q))
        Error("Full Queue!");
    else
    {
        q->Size++;
        q->Rear = Succ(q->Rear, q);
        q->Array[q->Rear] = x;
    }
}

ElementType Front(Queue q)
{
    if (!IsEmpty(q))
        return q->Array[q->Front];
    Error("Empty Queue");
    return 0;
}

void Dequeue(Queue q)
{
    if (IsEmpty(q)) 
        Error("Empty Queue!");
    else 
    {
        q->Size--;
        q->Front = Succ(q->Front, q);
    }
}

ElementType FrontAndDequeue(Queue q) 
{
    ElementType x = 0;

    if (IsEmpty(q)) 
        Error("Empty Queue!");
    else
    {
        x = Front(q);
        Dequeue(q);
    }

    return x;
}