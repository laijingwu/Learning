//1315
//C语言版
#include <stdio.h>
#include <malloc.h>

int main()
{
	int n, m, i, j, tmp;
	while (1)
	{
		n = m = i = j = tmp = 0;
		// 输入第一组
		scanf("%d", &n);
		if (n < 2 || n > 20)
			return 0;
		int *pn = (int *)malloc(sizeof(int)* n);
		for (i = 0; i < n; i++)
			scanf("%d", &pn[i]);

		// 输入第二组
		scanf("%d", &m);
		if (m < 2 || m > 20)
			return 0;
		int *pm = (int *)malloc(sizeof(int)* m);
		for (i = 0; i < m; i++)
			scanf("%d", &pm[i]);

		// 合并数组
		int *ps = (int *)malloc(sizeof(int)* (n + m));
		for (i = 0; i < n; i++)
			ps[i] = pn[i];
		for (j = n; j < n + m; j++)
			ps[j] = pm[j - n];

		// 冒泡排序
		for (i = 0; i < n + m; i++)
		{
			for (j = 0; j < n + m - i; j++)
			{
				if (ps[j] > ps[j + 1] && j != n + m - 1)
				{
					tmp = ps[j];
					ps[j] = ps[j + 1];
					ps[j + 1] = tmp;
				}
			}
		}

		// 输出
		for (i = 0; i < n + m; i++)
		{
			if (i == n + m - 1)
				printf("%d\n", ps[i]);
			else
				printf("%d ", ps[i]);
		}
	}
	return 0;
}
