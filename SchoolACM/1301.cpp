//1301
#include <stdio.h>

int main()
{
	int p = 1, i;
	long s = 0;
	for (i = 1; i <= 10; i++)
	{
		p *= i;
		s += p;
		printf("%d\n", s);
	}
	return 0;
}
