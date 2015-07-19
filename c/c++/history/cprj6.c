# include <stdio.h>
void main()
{
/*	
	int i, sum = 0;
	i = 1;
	/*loop: if(i <= 100)
	{
		sum = sum + i;
		i++;
		goto loop;
	}*/

	/*while(i <=100)
	{
		sum = sum + i;
		i++;
	}*/

	/*do
	{
		sum = sum + i;
		i++; 
	}while(i <= 100);

	for(i = 1; i<=100; i++)
		sum = sum+i;
	printf("%d\n",sum);*/
	float pi = 3.14159;
	int r;
	for(r = 1; r <= 10; r++)
	{
		float area = pi*r*r;
		if(area>100) break;
		printf("r=%d,area=%f\n",r,area );
	}
}