//1314
#include <stdio.h>
#include <malloc.h>
#include <memory.h>

int main()
{
	int n, i, j, sum;
	while (scanf("%d", &n) != EOF)
	{
		sum = 0;
		if (n < 3)
			return 0;

		// 动态分配建立二维数组
		int **arr = (int **)malloc(sizeof(int *)* n);
		for (i = 0; i < n; i++)
			arr[i] = (int *)malloc(sizeof(int)* n);

		// 输入
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				scanf("%d", &arr[i][j]);

		// 计算和
		for (i = 0; i < n; i++)
		{
			if (n % 2 != 0 && i == (n - 1) / 2)	// 奇数
				continue;
			else
			{
				sum += arr[i][i];
				sum += arr[i][n - 1 - i];
			}
		}
		if (n % 2 != 0)	// 奇数
			sum += arr[(n + 1) / 2][(n + 1) / 2];
		printf("%d\n", sum);
	}
	return 0;
}
