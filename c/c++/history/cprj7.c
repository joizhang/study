# include <stdio.h>
#include <string.h>
void main()
{
	/*int a[3][4]
	int i, a[10];
	for(i = 0; i<=9; i++)
		a[i] = i;
	for(i = 9; i>=0; i--)
		printf("%d ",a[i] );
	printf("\n");*/


	/*char c[] = {"China"};
	printf("%s\n", c);*/


	/*char str1[5], str2[5], str3[5];
	scanf("%s,%s,%s",str1,str2,str3);
	printf("%s,%s,%s\n",str1,str2,str3 );*/


	/*char string[81];
	int i, num = 0, word = 0;
	char c;
	scanf("%s\n",string);
	//gets(string);
	for(i = 0; (c = string[i]) != '\0'; i++)
	{
		if(c == ' ') 
			word = 0;
		else if(word == 0)
		{
			word = 1;
			num ++;
		}
	}
	//printf("%s\n",string );
	printf("There are %d words in the line.\n",num);*/

	char string[20];
	char str[3][20];
	int i;
	for(i = 0; i<3; i++)
		scanf("%s",str[i]) ;
	if(strcmp(str[0],str[1]) > 0)
		strcpy(string, str[0]);
	else
		strcpy(string, str[1]);
	if(strcmp(str[2],string) > 0)
		strcpy(string, str[2]);
	printf("\nthe largest string is: \n%s\n",string);
}