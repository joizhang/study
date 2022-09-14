#ifndef _Sqllist_H

#define TRUE 1
#define FALSE 0
#define OVERFLOW -1
#define INFEASIBLE -1
 
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int BOOL;
typedef int ElemType;

typedef struct
{
    ElemType *elem; 
    int length;
    int listsize;
} List;

BOOL InitList(List *list);
void DestoryList(List *list);
void ClearList(List *list);
BOOL ListEmpty(List *list);
int ListLength(List *list);
BOOL GetElem(List *list, int i, ElemType *e);
int LocateElem(List *list, ElemType *e);
BOOL PriorElem(List *list, ElemType *currentElem, ElemType *preElem);
BOOL NextElem(List *list, ElemType *currentElem, ElemType *nextElem);
BOOL ListInsert(List *list, int i, ElemType *e);
ElemType ListDelete(List *list, int i, ElemType *e);
void ListTraverse(List *list);

//TODO I am really lazy ^_^
//将L2中存在但L1中不存在的元素插入到L1中
void unionList_Sq(List *list1, List *list2);
//已知线性表L1和L2中数据元素按值非递减排列
//归并L1和L2得到新的线性表L3,L3的数据元素也按值非递减排列
void MergeList_Sq(List *list1, List *list2, List *list3);

#endif