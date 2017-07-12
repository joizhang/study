typedef int ElementType;

#ifndef _Stack_h
#define _Stack_h

struct StackRecord;
typedef struct StackRecord *Stack;

int IsEmpty(Stack s);
int IsFull(Stack s);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack s);
void MakeEmpty(Stack s);
void Push(ElementType x, Stack s);
ElementType Top(Stack s);
void Pop(Stack s);
ElementType TopAndPop(Stack s);
int Capacity(Stack s);
int TopOfStack(Stack s);

#endif