#include <stdio.h>

void main() 
{
	int a = 1;
	printf("%d\n", a);
	int *pointer = &a;
	*pointer = 10;
	printf("%d\n", a);
}