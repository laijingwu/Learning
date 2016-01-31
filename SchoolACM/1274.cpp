// 1274
#include <stdio.h>

int main()
{
	struct comp
	{
		float r, i;
	};
	struct comp x, y, a, b, c;
	while (scanf("%f%f%f%f", &x.r, &x.i, &y.r, &y.i) != EOF)
	{
		a.r = x.r + y.r;
		a.i = x.i + y.i;
		c.r = x.r * y.r - x.i * y.i;
		c.i = x.r * y.i + x.i * y.r;

		printf("%.4g+(%.4gi)\n", a.r, a.i);
		printf("%.4g+(%.4gi)\n", c.r, c.i);
	}
	return 0;
}
