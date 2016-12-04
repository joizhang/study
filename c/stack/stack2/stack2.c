#include <stdlib.h>
#include "fatal.h"
#include "stack2.h"

#define EmptyTOS (-1)
#define MinStackSize (5)

struct StackRecord
{
    int capacity;
    int topOfStack;
    ElementType *array;
};

int IsEmpty(Stack s)
{
    return s->topOfStack == EmptyTOS;
}

int IsFull(Stack s)
{
    return s->topOfStack + 1 == s->capacity;
}

void MakeEmpty(Stack s)
{
    s->topOfStack = EmptyTOS;
}

Stack CreateStack(int MaxElements)
{
    Stack s;

    if (MaxElements < MinStackSize)
        Error("Stack size is too small!");
    
    s = malloc(sizeof(struct StackRecord));
    if(s == NULL)
        FatalError("Out of space!");

    s->array = malloc(sizeof(ElementType) * MaxElements);
    if (s->array == NULL)
        FatalError("Out of space!");
    s->capacity = MaxElements;
    MakeEmpty(s);

    return s;
}

void Push(ElementType x, Stack s)
{
    if (IsFull(s))
        Error("Stack full");
    else
        s->array[++s->topOfStack] = x;
}

ElementType Top(Stack s)
{
    if(!IsEmpty)
        return s->array[s->topOfStack];
    Error("Stack empty");
    return 0;
}

void Pop(Stack s)
{
    if (IsEmpty(s))
        Error("Stack empty");
    else
        s->topOfStack--;
}

ElementType TopAndPop(Stack s)
{
    if(!IsEmpty(s))
        return s->array[s->topOfStack--];
    Error("Stack empty");
    return 0;    
}

void DisposeStack(Stack s)
{
    if (s != NULL)
    {
        free(s->array);
        free(s);
    }
}

int Capacity(Stack s)
{
    return s->capacity;
}
int TopOfStack(Stack s)
{
    return s->topOfStack;
}
