//1295
#include <stdio.h>

int main()
{
	int x;
	while(scanf("%d", &x) != EOF)
	{
		if (x > 100 || x < 0)
			continue;
		
		// if法
		/*if (x >= 90)
			printf("A\n");
		else if (x >= 80)
			printf("B\n");
		else if (x >= 70)
			printf("C\n");
		else if (x >= 60)
			printf("D\n");
		else
			printf("E\n");*/
		
		// 运算符法
		x = (x >= 90) ? 'A' : 
			(x >= 80) ? 'B' :
			(x >= 70) ? 'C' :
			(x >= 60) ? 'D' : 'E';
		printf("%c\n", x);
		
		// switch法
		/*switch(x / 10)
		{
			case 9:
				printf("A\n");
				break;
			case 8:
				printf("B\n");
				break;
			case 7:
				printf("C\n");
				break;
			case 6:
				printf("D\n");
				break;
			default:
				printf("E\n");
				break;
		}*/
	}
	return 0;
}
