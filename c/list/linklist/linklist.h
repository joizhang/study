#ifndef _List_H
#define _List_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

void DestoryList(List list);
List MakeEmpty(List list);
int IsEmpty(List list);
int IsLast(Position p, List list);
Position Find(int x, List list);
void Delete(int x, List list);
Position FindPrevious(int x, List list);
void Insert(int x, List list, Position p);
void DeleteList(List list);
Position Header(List list);
Position First(List list);
Position Advence(Position p);
int Retrieve(Position p);

void ListTraverse(List list);

void CreateList(List list, int *arr, int length);

#endif