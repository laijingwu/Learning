//1309
#include <stdio.h>
#include <math.h>

float f(float a, float b, float c, float d, float x)
{
	float f;
	f = (float)(a * pow(x, 3) + b * pow(x, 2) + c * x + d);
	return f;
}

int main()
{
	float x0 = -10, x1 = 10, a, b, c, d, m;
	scanf("%f %f %f %f", &a, &b, &c, &d);

	m = (x0 + x1) / 2;
	while (fabs(f(a, b, c, d, m)) > 1e-5 && fabs(x0 - x1) > 1e-5)
	{
		if (f(a, b, c, d, m) * f(a, b, c, d, x1) < 0)
			x0 = m;
		if (f(a, b, c, d, x0) * f(a, b, c, d, m) < 0)
			x1 = m;
		m = (x0 + x1) / 2;
	}
	printf("%.3f\n",m);
}
