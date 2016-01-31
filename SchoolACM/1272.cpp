//1272
#include <stdio.h>

int fun(int n)	// 递归函数计算2+4+6+8+……+n
{
	if (n == 0)
		return 0;
	else
		return n + fun(n - 2);
}

int main()
{
	int n, sum;
	while (scanf("%d", &n) != EOF)
	{
		sum = fun(n);
		printf("%d\n", sum);
	}
	return 0;
}
