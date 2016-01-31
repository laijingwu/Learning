//1305
#include <stdio.h>
#include <math.h>

int main()
{
	int  n, i;
	double x, y, t = 1., s = 1.;
	while (scanf("%d %lf", &n, &x) != EOF){
		t = 1.;
		s = 1.;
		y = x / 1;
		t = t * x;
		for (i = 3; i <= 2 * n - 1; i = i + 2)
		{
			t = t * x * x;
			s = i * (i - 1) * s;
			y = y + pow(-1, (i - 1) / 2) * t / s;
		}
		printf("%.3f\n", y);
	}
	return 0;
}
