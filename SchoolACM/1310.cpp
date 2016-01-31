//1310
// 第一种方法：递归函数
#include <stdio.h>

int f(int x)
{
	if (x == 1 || x == 2)
		return 1;
	else
		return (f(x - 1) + f(x - 2));
}

int main()
{
	int n;
	scanf("%d", &n);
	if (n < 1 || n > 46)
		return 0;
	printf("%d\n", f(n));
	return 0;
}

// 第二种方法：数组
#include <stdio.h>

int main()
{
	int a[47] = { 0, 1, 1, 0 }, i, n;
	scanf("%d", &n);
	for (i = 3; i <= n; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
	}
	printf("%d", a[n]);
	return 0;
}

// 第三种方法：多变量交替
#include <stdio.h>

int main()
{
	int a = 1, b = 1, c, i, n;
	scanf("%d", &n);
	for (i = 3; i <= n; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	printf("%d", c);
	return 0;
}
