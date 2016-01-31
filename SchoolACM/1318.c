//1318
//C语言版
#include <stdio.h>
#include <malloc.h>
#include <memory.h>

int main()
{
	int n, i, j, k = 0, flag = 1;
	while (scanf("%d", &n) != EOF)
	{
		i = j = k = 0;
		flag = 1;
		if (n <= 1 || n >= 30)
			continue;

		int *a = (int *)malloc(sizeof(int) * n);	// 动态分配内存
		int *b = (int *)malloc(sizeof(int) * n);	// 动态分配内存
		memset(a, 0, n * sizeof(int));	// 置空
		memset(b, 0, n * sizeof(int));	// 置空
		
		// 输入
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);

		for (i = 0; i < n; i++)
		{
			flag = 1;
			for (j = 0; j < k; j++)
			{
				if(a[i] == b[j])
					flag = 0;
			}
			if(flag)
			{
				b[k] = a[i];
				k++;
			}
			
		}

		// 输出
		for (i = 0; i < k; i++)
		{
			printf("%d ", b[i]);
		}
		printf("\n");
	}
	return 0;
}
