//1264
#include <stdio.h>

int gcd(int n, int m)	// 计算n和m的最大公约数
{
	if (n % m == 0)
		return m;
	else
		return gcd(m, n% m);
}

int lcs(int n, int m)	// 计算n和m的最小公倍数
{
	int p, q, temp;
	p = (n > m) ? n : m;
	q = (n > m) ? m : n;
	temp = p;
	while(1)
	{
		if (p % q == 0)
			break;
		p += temp;
	}
	return p;
}

int main()
{
	int m, n;
	while(scanf("%d %d", &n, &m) != EOF)
		printf("%d %d\n", gcd(n, m), lcs(n, m));
	return 0;
}
