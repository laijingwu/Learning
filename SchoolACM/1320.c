//1320
//C语言版
#include <stdio.h>

void f(char a[])
{
	int n = 0, i;
	for (i = 0; a[i] != '\0'; i++)
	{
		if (a[i] == ' ' && ((a[i + 1] >= 'a' && a[i + 1] <= 'z') || (a[i + 1] >= 'A' && a[i + 1] <= 'Z')))
			n++;
	}
	if (a[0] == ' ')
		printf("%d\n", n);
	else
		printf("%d\n", n + 1);
}

int main()
{
	char a[1024];
	gets(a);
	f(a);
	return 0;
}
