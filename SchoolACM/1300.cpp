//1300
#include <stdio.h>

int main()
{
	int sum = 0, n, i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		sum += i;
	printf("%d\n", sum);
	return 0;
}
