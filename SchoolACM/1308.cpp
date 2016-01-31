//1308
#include <stdio.h>
#include <math.h>

float f(float a, float b, float c, float d, float x)
{
	float f;
	f = ((a * x + b) * x + c) * x + d;
	return f;
}

float f1(float a, float b, float c, float d, float x)
{
	float f1;
	f1 = (3 * a * x + 2 * b) * x + c;
	return f1;
}

float root(float a, float b, float c, float d, float x0)
{
	float x1;
	do
	{
		x1 = x0;
		x0 = x1 - f(a, b, c, d, x0) / f1(a, b, c, d, x0);
	} while (fabs(x1 - x0) >= 1e-6);
	return x0;
}

int main()
{
	float a, b, c, d, x = 2.5, nx;
	scanf("%f %f %f %f", &a, &b, &c, &d);
	nx = root(a, b, c, d, x);
	printf("%.3f\n", nx);
	return 0;
}
