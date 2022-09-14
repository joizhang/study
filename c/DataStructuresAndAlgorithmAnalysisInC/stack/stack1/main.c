#include <stdio.h>
#include "stack1.h"

int main()
{
    Stack s;
    int i;

    s = CreateStack();
    for (i = 0; i < 10; i++)
        Push(i, s);

    while(!IsEmpty(s))
    {
        printf("%d ", Top(s));
        Pop(s);
    }
    printf("\n");
}