# include <stdio.h>
# include <math.h>
void main()
{
/*	float a, b, t;
	scanf("%f,%f",&a, &b);
	if(a > b)
	{
		t = a;
		a = b;
		b = t;
	}
	printf("%5.2f,%5.2f\n", a ,b);


	char ch;
	scanf("%c",&ch);
	ch = (ch>='A' && ch <= 'Z')? (ch + 32):ch;
	printf("%c\n",ch ); 


	switch(grade)
	{
		case 'A' : printf("85~100\n");
		case 'B' : printf("85~100\n");
		case 'C' : printf("85~100\n");
		case 'D' : printf("85~100\n");
		default  : printf("error\n"); 
	}

	int year, leap;
	scanf("%d",&year);
	if(year%4 == 0)
	{
		if(year%100 == 0)
		{
			if(year%400 == 0)
				leap = 1;
			else
				leap = 0;
		}
		else leap = 1;
	}
	else
		leap = 0;
	if(leap)
		printf("%d is ",year );
	else
		printf("%d is not ",year );
	printf("a leap year.\n");*/

	float a, b, c, disc, x1, x2, realpart, imagpart;
	scanf("%f, %f, %f", &a, &b, &c);
	printf("The equation ");
	if(fabs(a) <= 1e-6)
		printf("is not a quadratic\n");
	else
	{
		disc = b*b - 4*a*c;
		if(fabs(disc) <= 1e-6)
			printf("has two equal roots: %8.4f\n", -b/(2*a));
		else
			if(disc>1e-6)
			{
				x1 = (-b + sqrt(disc))/(2*a);
				x2 = (-b - sqrt(disc))/(2*a);
				printf("has distinct real roots: %8.4f and %8.4f\n", x1,x2);
			}
			else
			{
				realpart = -b/(2*a);
				imagpart = sqrt(-disc)/(2*a);
				printf("has complex roots: \n");
				printf("%8.4f + %f8.4i\n",realpart,imagpart);
				printf("%8.4f - %f8.4i\n",realpart,imagpart);
			}
	}
 }