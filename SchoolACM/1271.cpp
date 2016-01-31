//1271
//ACM测试数据：1 2 4 5 0 1 2 3 4 5 6 7 8 0
#include <stdio.h>

int w(int n)
{
	int x;
	if (n != 0)
	{
		scanf("%d", &x);
		w(x);
		printf("%d ", n);
	}
	return 0;
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		w(n);
		printf("\n");
	}
	return 0;
}
