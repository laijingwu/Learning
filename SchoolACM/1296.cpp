//1296
#include <stdio.h>

int main()
{
	int x, a, b, c, d, e, y;
	while (scanf("%d", &x) != EOF)
	{
		a = 1;
		y = x;
		while (y / 10 != 0){
			y /= 10;
			a++;
		}
		printf("%d\n", a);

		for (e = a; e > 0; e--)
		{
			y = x;
			for (d = 0; d < e - 1; d++)
				y /= 10;
			if (e == 1)
				printf("%d\n", y % 10);
			else
				printf("%d ", y % 10);
		}

		for (c = 1; c <= a; c++)
		{
			y = x;
			for (b = 0; b < c - 1; b++)
				y /= 10;
			if (c == a)
				printf("%d\n", y % 10);
			else
				printf("%d", y % 10);

		}

	}
	return 0;
}
