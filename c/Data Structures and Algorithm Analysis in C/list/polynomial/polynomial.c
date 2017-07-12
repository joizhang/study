#include <stdio.h>
#include <stdlib.h>

#define MaxDegree 100

static int Max(int a, int b)
{
    return a > b ? a : b;
}

typedef struct
{
    int CoeffArray[MaxDegree + 1];
    int HighPower;
} *Polynomial;

void ZeroPolynomial(Polynomial poly)
{
    int i; 
    for(i = 0; i < MaxDegree; i++)
        poly->CoeffArray[i] = 0;
    poly->HighPower = 0;
}

void AddPolynomial(const Polynomial poly1, 
    const Polynomial poly2, Polynomial polySum)
{
    int i;
    ZeroPolynomial(polySum);
    polySum->HighPower = Max(poly1->HighPower, poly2->HighPower);
    //i-- way is more efficient than i++
    for (i = polySum->HighPower; i >= 0 ; i--)
        polySum->CoeffArray[i] = poly1->CoeffArray[i] + poly2->CoeffArray[i];
}

void MultPolynomial(const Polynomial poly1, 
    const Polynomial poly2, Polynomial polyProd)
{
    int i, j;
    ZeroPolynomial(polyProd);
    polyProd->HighPower = poly1->HighPower + poly2->HighPower;
    if (polyProd->HighPower > MaxDegree) {
        printf("Error");
        return ;
    } else {
        for (i = 0; i <= poly1->HighPower; i++)
            for (j = 0; j <= poly2->HighPower; j++)
                polyProd->CoeffArray[i + j] += poly1->CoeffArray[i] * poly2->CoeffArray[j];
    }
}

void PrintPoly(const Polynomial poly)
{
    int i;
    
    for (i = poly->HighPower; i >0 ; i--)
        if (poly->CoeffArray[i] != 0)
            printf("%dx^%d + ", poly->CoeffArray[i], i);
    printf("%d\n", poly->CoeffArray[0]);
}

int main() 
{
    Polynomial poly1, poly2;
    poly1 = malloc(sizeof(*poly1));
    poly2 = malloc(sizeof(*poly2));

    poly1->HighPower = 1; 
    poly1->CoeffArray[ 0 ] = 1; 
    poly1->CoeffArray[ 1 ] = 1;
    PrintPoly(poly1);
    AddPolynomial(poly1, poly1, poly2);
    PrintPoly(poly2);
    MultPolynomial(poly1, poly1, poly2);
    PrintPoly(poly2);
    MultPolynomial(poly2, poly2, poly1);
    PrintPoly(poly1);

    return 0;
}