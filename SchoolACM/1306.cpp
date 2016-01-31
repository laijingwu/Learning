//1306
#include <stdio.h>
#include <math.h>

int isSu(int n);

int main()
{
	int a, b, i;
	while (scanf("%d %d", &a, &b) != EOF)
	{
		if (a < 2 || a > b || b >= 1000)
			break;
		for (i = a; i <= b; i++)
		{
			if (isSu(i))
			{
				printf("%d ", i);
			}
		}
		printf("\n");
	}
	return 0;
}

int isSu(int n)
{
	int k, i;
	k = (int)sqrt(n);
	for (i = 2; i <= k; i++)
	if (n % i == 0)
		break;
	if (i > k)
		return 1;
	else
		return 0;
}
