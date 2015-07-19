# include <stdio.h>
# include <math.h>
void main()
{
	// char a, b, c;
	// a = 'B'; b = 'O'; c = 'Y';
	// putchar(a); putchar(b); putchar(c); putchar('\n');

	// char c;
	// c = getchar();
	// putchar(c);
	// putchar('\n');

	// printf("%3s, %7.2s, %.4s, %-5.3s","CHINA","CHINA","CHINA","CHINA\n");

	// char c1, c2;
	// c1 = getchar();
	// printf("%c,%d\n", c1, c1);
	// c2 = c1 + 32;
	// printf("%c,%d\n",c2, c2 );

	//ax2+bx+c=0
	float a, b, c, disc, x1, x2, p, q;
	scanf("a = %f, b = %f, c = %f", &a, &b, &c);
	disc = b*b - 4*a*c;
	p = -b/(2*a);
	q = sqrt(disc)/(2*a);
	x1 = q + p; x2 = p - q;
	printf("x1 = %5.2f\nx2 = %f\n",x1, x2 );
 }