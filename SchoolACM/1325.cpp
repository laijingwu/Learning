//1325
#include <stdio.h>

int f(char *s1, char *s2, char *s3)
{
	while (*s1 != 0)
	{
		*s3 = *s1;
		s1++;
		s3++;
	}
	while (*s2 != 0)
	{
		*s3 = *s2;
		s2++;
		s3++;
	}
	*s3 = 0;
	return 0;
}

int main()
{
	char s1[512], s2[512], s3[1024];
	gets(s1);
	gets(s2);
	f(s1, s2, s3);
	puts(s3);
	return 0;
}
