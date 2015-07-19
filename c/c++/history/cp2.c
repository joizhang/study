# include <stdio.h>
void main()
{
	long int Fib(int N);
	int n;
	long int sum;
	printf("input one number: \n");
	scanf("%d",&n);
	sum = Fib(n);
	printf("%ld\n", sum);
}
long int Fib(int N)
{
	if(N <= 1)
		return 1;
	else
		return Fib( N - 1 ) * Fib( N - 2 );
}
