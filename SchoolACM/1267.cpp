//1267
#include <stdio.h>
#define MAX 1024

int isChar(char x)
{
	if ((x > 64 && x < 91) || (x > 96 && x < 123))
		return 1;
	else
		return 0;
}

int count(char ch[])
{
	int i, nc = 0;
	for (i = 0; i < MAX; i++)
	{
		if (isChar(ch[i]) == 1)
			nc++;
	}
	return nc;
}

int main()
{
	char ch[MAX] = { 0 };
	while (gets(ch))
	{
		printf("%d\n", count(ch));
	}
	return 0;
}
