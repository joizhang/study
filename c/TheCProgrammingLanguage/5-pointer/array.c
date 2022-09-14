#include <stdio.h>

int main()
{
	int a = 3;
	int b = 2;
	int array[3];
	array[0] = 1;
	array[1] = 10;
	array[2] = 100;
	int *p = array;
	int *pa = &a;
	printf("%d\n", *pa);
	pa = &b;
	printf("%d\n", *pa);
	int i;
	for (i = 0; i < 3; ++i)
	{
		/* code */
		printf("%d\n", *p);
		p++;
	}
	printf("-----------------------------------------------------------------\n");
	return 0;
}