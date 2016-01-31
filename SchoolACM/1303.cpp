//1303
#include <stdio.h>

int main()
{
	int n, r, j, i;
	scanf("%d", &n);
	for (i = 1; i < n; i++)
	{
		r = 0;
		for (j = 1; j < i; j++)
		{
			if (i % j == 0)
			{
				r += j;
			}
		}
		if (r == i)
			printf("%d\n", r);
	}
	return 0;
}
