//1299
#include <stdio.h>

int main()
{
	int sum, x;
	sum = 0;
	while (scanf("%d", &x) != EOF)
		sum += x;
	printf("%d\n", sum);
	return 0;
}
