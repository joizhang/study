#include <stdio.h>
#include <stdlib.h>

#include "sqlist.h"

int main()
{
    List list;
    InitList(&list);
    printf("创建线性表后线性表的当前长度:%d\n", list.length);  
    printf("ListTraverse:");
    
    //initialize
    int j;
    for(j = 0; j < 10; j++) {
        list.elem[j] = j;
        list.length++;  
    }
    printf("after sqlist inited: %d=====%d\n", list.listsize, list.length);

    //test DestoryList
    /*DestoryList(&list);
    printf("After Destory List %d=====%d\n", list.listsize, list.length);*/

    //test ListEmpty(List *list);
    printf("Is List Empty? %s\n", ListEmpty(&list) ? "true" : "false");

    //test GetElem(List *list, int i, ElemType *e)
    ElemType e1;
    if(GetElem(&list, 3, &e1) ) {
        printf("Get index 3 element from list: %d\n", e1);
    }
    
    /*for(j = 0; j < list.length; j++) {
        if(list.elem[j] == 3)
            printf("i found %d in list index %d\n", 3, j);
    }*/

    //test LocateElem
    ElemType e2 = 3;
    int position = LocateElem(&list, &e2);
    printf("%d\n", position);
    if (position >= 0)
        printf("I find e2 in list, it's index is %d\n", position);
    else 
        printf("Not Found!\n");
    
    //test ListInsert(List *list, int i, ElemType *e);
    ElemType e3 = 100;
    if(ListInsert(&list, 2, &e3)) {
        ListTraverse(&list);
    }

    //test BOOL ListDelete
    ElemType e4;
    if(ListDelete(&list, 2, &e4)) {
        printf("Delete index %d ElemType %d success\n", 1, e4);
    }
    ListTraverse(&list);

    return 0;
}

BOOL InitList(List *list)
{
    list->listsize = LIST_INIT_SIZE;
    list->elem = (int *)malloc(list->listsize * sizeof(int));
    list->length = 0;
    return TRUE;
}

void DestoryList(List *list)
{
    free(list->elem);
    list->elem = NULL;
    list->length = 0;
    list->listsize = 0;
}

BOOL ListEmpty(List *list)
{
    return list->elem == NULL;
}

BOOL GetElem(List *list, int i, ElemType *e) 
{
    //printf("%d", list->elem[2]);
    if(list->length >= (i + 1)) {
        *e = list->elem[i];
        return TRUE;
    } 
    return FALSE;
}

//if not found return -1
int LocateElem(List *list, ElemType *e) {
    int i;
    for (i = 0; i < list->length; i++) {
        if (list->elem[i] == *e)
            return i;
    }
    return -1;
}

BOOL ListInsert(List *list, int i, ElemType *e) 
{
    if (i > (list->length + 1)) {
        return FALSE;
    }

    int j;
    list->length++;
    for (j = (list->length - 1); j > (i-1); j--) {
        list->elem[j] = list->elem[j-1];
    }

    list->elem[i-1] = *e;
    return TRUE; 
}

//删除L的第i个元素，并用e返回其值，L的长度减1
BOOL ListDelete(List *list, int i, ElemType *e)
{
    if (i > (list->length)) {
        return FALSE;
    }

    *e = list->elem[i-1];
    int j;
    for(j = (i - 1); j < list->length; j++) {
        list->elem[j] = list->elem[j + 1];
    }
    list->length--;
    return TRUE;
}

void ListTraverse(List *list) 
{
    int i;
    for (i = 0; i < list->length; i++) {
        printf("%d ", list->elem[i]);
    }
    printf("\n");
}