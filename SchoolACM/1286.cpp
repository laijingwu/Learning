//1286
#include <stdio.h>

int main()
{
    int m, n, a, b, c;
    scanf("%d", &m);
    a = m / 100;
    b = (m % 100) / 10;
    c = m % 10;
    n = c * 100 + b * 10 + a * 1;
    printf("%d\n", n);
	return 0;
}
