//1316
#include <stdio.h>
#include <string.h>

int main()
{
	int i, a[26] = { 0 };
	char x[100];
	gets(x);
	strupr(x);
	i = 0;

	while (x[i] != '\0')
	{
		if (x[i] >= 'A' && x[i] <= 'Z')
			a[x[i] - 65]++;
		i++;
	}

	for (i = 0; i < 26; i++)
	if (a[i] != 0)
		printf("%d ", a[i]);

	return 0;
}
