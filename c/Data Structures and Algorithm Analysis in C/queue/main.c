#include <stdio.h>
#include "queue.h"

int main() 
{
    Queue q;
    //int i;

    q = CreateQueue(5);
    printf("Is queue empty? %d\n", IsEmpty(q));

    Enqueue(10, q);
    Enqueue(6, q);
    Enqueue(4, q);
    Enqueue(8, q);
    Enqueue(9, q);

    printf("Is queue full? %d\n", IsFull(q));

    //Enqueue(7, q);

    Dequeue(q);
    Dequeue(q);
    Dequeue(q);

    printf("Queue front:%d\n", Front(q));

    DisposeQueue(q);
}
