#include <stdio.h>

enum DAY{MON = 1, TUE, WED, THU, FRI, SAT, SUN};

int main(int argc, char const *argv[])
{
	/* 使用枚举类型声明变量，再对枚举型变量赋值 */
	enum DAY yesterday, today, tomorrow;
	yesterday = MON;
	today     = TUE;
	tomorrow  = WED;
	printf("%d %d %d \n", yesterday, today, tomorrow);

	return 0;
}