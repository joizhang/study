# include <stdio.h>
//int max(int x, int y);
// int max(int x, int y)
// {
// 	int z;
// 	z = x>y?x : y;
// 	return (z);
// }

void main()
{
	int max(int x, int y);
	int a, b, c;
	scanf("%d,%d",&a,&b);
	c = max(a, b);
	printf("Max is %d\n", c);
}
int max(int x, int y)
{
	int z;
	z = x>y?x : y;
	return (z);
}

/*int max(int x,int y)
{
	int z;
	if(x>y) 
		z=x;
	else 
		z=y;
		return(z);
}
void main()     
{
	int a,b,c;
	scanf("%d %d",&a,&b);
	c=max(a,b);
	printf("max=%d\n",c);
}*/

