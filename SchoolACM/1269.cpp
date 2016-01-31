//1269
#include <stdio.h>

int Fibonacci(int n)
{
	if (n == 1 || n == 2)
		return 1;
	return (Fibonacci(n - 1) + Fibonacci(n - 2));
}

int main()
{
	int n, y;
	while (scanf("%d", &n) != EOF)
	{
		if (n < 0 || n > 20)
			continue;
		y = Fibonacci(n);
		printf("%d\n", y);
	}
	return 0;
}
