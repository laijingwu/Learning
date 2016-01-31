//1304
#include <stdio.h>

int main()
{
	int n, s, t;
	while (scanf("%d", &s) != EOF)
	{
		n = 0;
		t = 0;
		while (1)
		{
			t += n;
			if ((s > t && s <= t + n + 1) || s <= 0)	// 防止为负数或0时超出范围
				break;
			n++;
		}
		printf("%d\n", n);
	}
	return 0;
}
