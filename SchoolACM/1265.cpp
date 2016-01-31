//1265
#include <stdio.h>
#include <math.h>

void root(float a, float b, float c)	// 求根函数
{
	float d, x1, x2, jp, ip;
	d = b * b - 4 * a * c;
	if (fabs(d) <= 1e-6)
	{
		printf("x1=x2=%.3f\n", -b / (2 * a));
	}
	else if (d > 1e-6)
	{
		x1 = (-b + sqrt(d)) / (2 * a);
		x2 = (-b - sqrt(d)) / (2 * a);
		printf("x1=%.3f x2=%.3f\n", x1, x2);
	}
	else
	{
		jp = -b / (2 * a);
		ip = sqrt(-d) / (2 * a);
		printf("x1=%.3f+%.3fi x2=%.3f-%.3fi\n", jp, ip, jp, ip);
	}
}

int main()
{
	float a, b, c;
	while(scanf("%f %f %f", &a, &b, &c) != EOF)
	{
		if (fabs(a) < 1e-6)
			printf("无解\n");
		else
			root(a, b, c);
	}
	return 0;
}
