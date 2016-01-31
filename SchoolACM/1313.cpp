//1313
#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, i, m, k, s[1000];
	while (scanf("%d %d", &a, &b) != EOF)
	{
		for (i = 0; i <= b - a; i++)
		{
			s[i] = i + a;
			k = (int)sqrt(s[i]);
			for (m = 2; m <= k; m++)
			if (s[i] % m == 0)
				break;

			if (m > k)
				printf("%d ", s[i]);
		}
		printf("\n");
	}
	return 0;
}
