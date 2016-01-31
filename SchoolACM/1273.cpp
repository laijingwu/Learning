//1273
#include <stdio.h>

void move(int n, char a, char b, char c)
{
	if (n == 1)
		printf("%c->%c\n", a, c);	// 当n为1个时直接从a移动到c
	else
	{
		move(n - 1, a, c, b);	// 第n-1个从a通过c移动到b
		printf("%c->%c\n", a, c);
		move(n - 1, b, a, c);	// n-1个移动过来后b变起始盘，b通过a移动到c
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	move(n, 'A', 'B', 'C');
	return 0;
}
