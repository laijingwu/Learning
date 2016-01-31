//1321
#include <stdio.h>

//swap()函数
int swap(int *n, int *m)
{
	int tmp = *n;
	*n = *m;
	*m = tmp;
	return 0;
}

int main()
{
	int m, n;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		swap(&n, &m);
		printf("%d %d\n", n, m);
	}
	return 0;
}
