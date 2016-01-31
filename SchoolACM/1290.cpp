//1290
#include <stdio.h>

void main()
{
	int m, n, a, b, t;
	while (scanf("%d %d", &m, &n) != EOF)
	{
		if (n > m)
		{
			t = n;
			n = m;
			m = t;
		}
		if (m % 2 == 0 && m >= 2 * n && m <= 4 * n)
		{
			b = (m - 2 * n) / 2;
			a = n - b;
			printf("%d %d\n", a, b);
		}
		if (n < 1 || m % 2 != 0 || m < 2 * n || m > 4 * n)
			printf("no answer\n");
	}
}
