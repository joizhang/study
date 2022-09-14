#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

int main()
{
    List list;
    Position p;
    int i;

    printf("MakeEmpty\n");
    list = MakeEmpty(NULL);
    p = Header(list);
    printf("Is list empty?%d\n", IsEmpty(list));
    //ListTraverse(list);

    for(i = 0; i < 10; i++) {
        Insert(i, list, p);
        //get next position
        p = Advence(p);
    }
    printf("ListTraverse:");
    ListTraverse(list);

    //test FindFind(int x, List list)
    Position p1;
    p1 = Find(3, list);
    printf("find %d\n", Retrieve(p1));


    DeleteList(list);
    return 0;
}