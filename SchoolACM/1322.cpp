//1322
#include <stdio.h>

//下面是函数 f()的定义
int f(int a[], int n, int *min, int *max)
{
	int i;
	*min = *max = a[0];
	for (i = 0; i < n; i++)
	{
		if (a[i] < *min)
			*min = a[i];
		if (a[i] > *max)
			*max = a[i];
	}
	return 0;
}

int main()
{
	int i, n, max, min, a[100];
	while (scanf("%d", &n) != EOF)
	{
		if (n < 2 || n > 100)
			return 0;

		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		f(a, n, &min, &max);
		printf("%d %d\n", min, max);
	}
	return 0;
}
