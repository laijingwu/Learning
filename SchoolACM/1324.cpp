//1324
#include <stdio.h>

int f(char *s1, int start, int len, char *s2)
{
	int i;
	s1 += start - 1;
	for (i = 0; i < len; i++)
	{
		*s2 = *s1;
		s1++;
		s2++;
	}
	*s2 = 0;
	return 0;
}

int main()
{
	char s1[1024], s2[1024];
	int start, len;
	gets(s1);
	scanf("%d %d", &start, &len);
	f(s1, start, len, s2);
	puts(s2);
	return 0;
}
