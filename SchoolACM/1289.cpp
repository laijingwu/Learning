//1289
#include <stdio.h>

int main()
{
	int y;
	while (scanf("%d", &y) != EOF)
	{
		if (y % 4 == 0)
		{
			if (y % 100 == 0)
			{
				if (y % 400 == 0)	// 被400整除，是闰年
				{
					printf("yes\n");
				} else {	// 被100整除，但不被400整除，不是闰年
					printf("no\n");
				}
			} else {	// 被4整除，但不被100整除，不是闰年
				printf("yes\n");
			}
		} else {	// 不被4整除，不是闰年
			printf("no\n");
		}
	}
	return 0;
}
