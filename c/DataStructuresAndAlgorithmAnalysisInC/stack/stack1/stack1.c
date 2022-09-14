#include "stack1.h"
#include <stdlib.h>
#include "fatal.h"

struct Node
{
    ElementType elem;
    PtrToNode next;
};

int IsEmpty(Stack s)
{
    return s->next == NULL;
}

Stack CreateStack(void)
{
    Stack s;
    s = malloc(sizeof(struct Node));
    if (s == NULL)
        FatalError("Out of space!");
    s->next = NULL;
    MakeEmpty(s);
    return s;
}

void MakeEmpty(Stack s)
{
    if (s == NULL)
        Error("Must use CreateStack first!");
    else 
        while(!IsEmpty(s))
            Pop(s);
}

void Push(ElementType x, Stack s)
{
    PtrToNode temp;

    temp = malloc(sizeof(struct Node));
    if (temp == NULL)
        FatalError("Out of space!");
    else 
    {
        temp->next = s->next;
        temp->elem = x;
        s->next = temp;
    }
}

ElementType Top(Stack s)
{
    if (!IsEmpty(s))
        return s->next->elem;
    Error("Empty stack!");
    return 0;
}

void Pop(Stack s)
{
    PtrToNode firstCell;

    if (IsEmpty(s))
        Error("Empty stack");
    else 
    {
        firstCell = s->next;
        s->next = s->next->next;
        free(firstCell);
    }
}