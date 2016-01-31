//1298
#include <stdio.h>

int main()
{
	int a, n, s, i, t;
	scanf("%d %d", &a, &n);
	s = 0;
	i = 1;
	t = a;
	while (i <= n)
	{
		s += t;
		t = t * 10 + a;
		i++;
	}
	printf("%d\n", s);
	return 0;
}
