#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;

struct Node
{
    int coefficient;
    int exponent;
    PtrToNode next;
};

typedef PtrToNode Polynomial;

void DeleteList(Polynomial polylinklist)
{
    PtrToNode p, temp;
    p = polylinklist->next;
    polylinklist->next = NULL;
    while (p != NULL) {
        temp = p->next;
        free(p);
        p = temp;
    }
}

Polynomial MakeEmpty(Polynomial polylinklist)
{
    if (polylinklist != NULL)
        DeleteList(polylinklist);

    polylinklist = malloc(sizeof(struct Node));
    if(polylinklist == NULL)
        printf("OUTOFMEMORY");

    polylinklist->coefficient = 0;
    polylinklist->exponent = 0;
    polylinklist->next = NULL;
    return polylinklist;
}

void Insert(int coefficient, int exponent, Polynomial polylinklist, PtrToNode p) {
    PtrToNode temp;
    temp = malloc(sizeof(struct Node));
    if (temp == NULL)
        printf("OUTOFMEMORY");

    temp->next = p->next;
    temp->coefficient = coefficient;
    temp->exponent = exponent;
    p->next = temp;
}

void AddPolynomial(const Polynomial polylinklist1, 
    const Polynomial polylinklist2, Polynomial polylinklistSum)
{
    PtrToNode temp1, temp2, temp;
    temp1 = polylinklist1->next == NULL ? polylinklist1 : polylinklist1->next;
    temp2 = polylinklist2->next == NULL ? polylinklist2 : polylinklist2->next;
    MakeEmpty(polylinklistSum);
    temp = polylinklistSum;
    while (temp1 != NULL || temp2 != NULL) {
        if ((temp1->exponent) > (temp2->exponent)) {
            Insert(temp1->coefficient, temp1->exponent, polylinklistSum, temp);
            temp = temp->next;
            temp1 = temp1->next;
        } else if ((temp1->exponent) == (temp2->exponent)) {
            Insert(temp1->coefficient + temp2->coefficient, 
                    temp1->exponent, polylinklistSum, temp);
            temp = temp->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else {
            Insert(temp2->coefficient, temp2->exponent, polylinklistSum, temp);
            temp = temp->next;
            temp2 = temp2->next;
        }
    }
}

void MultPolynomial(const Polynomial polylinklist1, 
    const Polynomial polylinklist2, Polynomial polylinklistProd)
{
    PtrToNode temp1, temp2, temp;
    Polynomial templist;
    temp1 = polylinklist1->next;
    temp2 = polylinklist2->next;

}

void PrintPoly(const Polynomial polylinklist)
{
    PtrToNode temp;
    temp = polylinklist->next;
    while(temp->next != NULL) {
        if (temp->coefficient != 0)
            printf("%dx^%d + ", temp->coefficient, temp->exponent);
        temp = temp->next;
    }
    if (temp->coefficient != 0)
        printf("%dx^%d\n", temp->coefficient, temp->exponent);
}

int main()
{
    int i;

    Polynomial polylinklist1, polylinklist2;
    PtrToNode p, temp;
    
    polylinklist1 = MakeEmpty(NULL);
    polylinklist2 = MakeEmpty(NULL);

    p = polylinklist1;
    for (i = 2; i > 0; i--) {
        Insert(i, i, polylinklist1, p);
        p = p->next;
    }
    PrintPoly(polylinklist1);

    temp = polylinklist1->next == NULL ? polylinklist1 : polylinklist1->next;
    printf("%d\n", temp->exponent);

    AddPolynomial(MakeEmpty(NULL), polylinklist1, polylinklist2);
    PrintPoly(polylinklist2);

    AddPolynomial(polylinklist2, polylinklist2, polylinklist1);
    PrintPoly(polylinklist1);


}