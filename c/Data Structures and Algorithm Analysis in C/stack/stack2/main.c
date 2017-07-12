#include <stdio.h>
#include "stack2.h"

int main()
{
    Stack s;
    int i;

    s = CreateStack(100);
    for(i = 0; i < 10; i++)
    {
        Push(i, s);
    }
    printf("Is empty? %d. ", IsEmpty(s));
    printf("s->capacity is %d. ", Capacity(s));
    printf("s->topOfStack is %d.\n", TopOfStack(s));

    printf("%d\n", TopAndPop(s));

    while (!IsEmpty(s))
        printf("%d ", TopAndPop(s));
    printf("\n");

    DisposeStack(s);
    return 0;
}