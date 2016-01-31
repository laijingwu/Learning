//1270
#include <stdio.h>

void f(int x, int n)	// 转换进制
{
	int c = x / n, r = x % n;
	if (c == 0)
		printf("%d", r);
	else
	{
		f(c, n);
		printf("%d", r);
	}
	return;
}

int main()
{
	int x, n;
	while (scanf("%d %d", &x, &n) != EOF)
	{
		f(x, n);
		printf("\n");
	}
	return 0;
}
