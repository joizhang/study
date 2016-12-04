#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

struct Node
{
    int elem;
    Position next;
};

List MakeEmpty(List list)
{
    if(list != NULL)
        DeleteList(list);
    list = malloc(sizeof(struct Node));
    if (list == NULL)
        printf("out of memory!");
    list->next = NULL;
    return list;
}

int IsEmpty(List list) 
{
    return list->next == NULL;
}

// 3
int IsLast(Position p, List list) 
{
    return p->next == NULL;
}

// 4
Position Find(int x, List list)
{
    Position p;

    p = list->next;
    while(p != NULL && p->elem != x)
        p = p->next;

    return p;
}

Position FindPrevious(int x, List list){
    Position p;
    p = list;
    while(p->next != NULL && p->next->elem != x)
        p = p->next;
    return p;
}

void Insert(int x, List list, Position p)
{
    Position temp;
    temp = malloc(sizeof(struct Node));
    if(temp == NULL)
        printf("out of memory!\n");
    temp->next = p->next;
    temp->elem = x;
    p->next = temp;
}

void DeleteList(List list)
{
    Position p, temp;
    p = list->next;
    list->next = NULL;
    while(p != NULL){
        temp = p->next;
        free(p);
        p = temp;
    }
}

Position Header(List list){
    return list;
}
Position First(List list){
    return list->next;
}
Position Advence(Position p){
    return p->next;
}
int Retrieve(Position p){
    return p->elem;
}

void ListTraverse(const List list) 
{
    Position p = Header(list);
    if(IsEmpty(list))
        printf("Empty list\n");
    else {
        do{
            p = Advence(p);
            printf("%d ", Retrieve(p));
        } while(!IsLast(p, list));
        printf("\n");
    }
}

//逆位序输入n个元素的值
/*void CreateList(List list, int *arr, int length)
{
    printf("%d", arr[0]);
    Position p;
    int i;
    for (i = length-1; i >=0; i--) {
        p = malloc(sizeof(struct Node));
        p->elem = arr[i];
        p->next = list->next;
        list->next = p;
    }
}*/

 /*Position p1 = malloc (sizeof(struct Node));
Position p2 = malloc (sizeof(struct Node));
p2->elem = 2;
p2->next = NULL;
p1->elem = 1;
p1->next = p2;
printf("p2's elem equals %d\n", p1->next->elem);

Position p0;
p0 = p1;
printf("p1's elem equals %d\n", p0->elem);
p0->elem = 100;
printf("p1's elem equals %d\n", p1->elem);*/

/* //test InitList >>>>>> list is head node
List list;
InitList(list);
printf("hello\n");
printf("List list now is Empty? %d\n", IsEmpty(list));
printf("hello\n");

//input list with some node 
printf("hello");
int arr[10] = {2, 4, 2, 9, 8, 5, 7, 4, 1, 3};
printf("hello");
CreateList(list, arr, sizeof(arr)/sizeof(arr[0]));
//printf("List list now is Empty? %d\n", IsEmpty(list));

//test ListTraverse
ListTraverse(list);*/