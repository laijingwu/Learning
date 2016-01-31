//1292
#include <stdio.h>

int main()
{
	double x, y;
	int a;
	while (scanf("%d", &a) != EOF)
	{
		x = a * 95;
		if (x >= 300)
			y = x * 0.85;
		else
			y = x;
		printf("%.3lf\n", y);
	}
	return 0;
}
