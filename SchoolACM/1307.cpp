//1307
#include <stdio.h>

int main()
{
	int n, i, j, k;
	scanf("%d", &n);
	if (n < 0 || n > 7)
		return 0;
	for (i = n; i <= n + 3; i++)
	{
		for (j = n; j <= n + 3; j++)
		{
			for (k = n; k <= n + 3; k++)
			{
				if (i != j && k != j && i != k)
				{
					printf("%d%d%d ", i, j, k);
				}
			}
		}
	}
	printf("\n");
	return 0;
}
