//1268
#include <stdio.h>
#include <malloc.h>
#include <memory.h>

void backInver(int n, int *a)
{
	int i;
	int *tmp = (int *)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
	{
		tmp[i] = a[n - 1 - i];
	}

	for (i = 0; i < n; i++)
	{
		if (i != n - 1)
			printf("%d ", tmp[i]);
		else
			printf("%d\n", tmp[i]);
	}
	return;
}

int main()
{
	int n, i;
	while (scanf("%d", &n) != EOF)
	{
		int *a = (int *)malloc(sizeof(int)* n);	// 动态分配内存
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		backInver(n, a);
		memset(a, 0, n * sizeof(int));	// 置空
	}
	return 0;
}
