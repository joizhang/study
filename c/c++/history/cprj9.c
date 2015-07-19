# include <stdio.h>
/*# define PI 3.1415926
void main()
{
	float l, s, r, v;
	printf("input radius: ");
	scanf("%f",&r);
	l = 2.0 * PI * r;
	s =PI  * r * r;
	v = 4.0/3 * PI * r * r * r;
	printf("l = %10.4f\ns = %10.4f\nv = %10.4f\n", l, s, v);
}*/
#define LETTER 1
void main()
{
	char str[20] = "C Language",c;
	int i;
	i = 0;
	while((c = str[i]) !='\0')
	{
		i++;
		#if (LETTER)
		if(c >= 'a' && c <= 'z')
			c = c-32;
		#else
		if(c >= 'A' && c <= 'Z')
			c = c+32;
		#endif
		printf("%c", c);
	}
	printf("\n");
}