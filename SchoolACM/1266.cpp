//1266
#include <stdio.h>
#define MAX 200

void insert(int a[], int len, int x)
{
	int i, j;
	for (i = 0; i < len; i++)
	{
		if (x < a[i])
		{
			for (j = len - 1; j >= i; j--)
				a[j + 1] = a[j];
			break;
		}
	}
	a[i] = x;

	for (i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
	printf("%d\n", a[len]);
}

int main()
{
	int a[MAX], i, x, n;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		scanf("%d", &x);
		insert(a, n, x);
	}
	return 0;
}
