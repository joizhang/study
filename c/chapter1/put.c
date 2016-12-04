#include <stdio.h>
#define MAXLENGTH 100

int main()
{
	char c1 = 'q';
	char chars[MAXLENGTH];
	char longest[10] = {'h', 'e', 'l', 'l', 'o'};
	char *str = "helloworld";
	int digit[] = {1, 2, 3, 4};
	int i = 0;
	char c;
	while ((c = getchar()) != 27) {
		chars[i] = c;
	}
	// printf("%s\n", "hahhhahahah");
	printf("%s\n", chars);
	printf("%s\n", longest);
	printf("%s\n", str);
	printf("%d\n", *digit);
	return 0;
}