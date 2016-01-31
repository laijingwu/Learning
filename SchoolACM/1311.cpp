//1311
#include <stdio.h>

int main()
{
	char a[100];
	int i = 0, count1 = 0, count2 = 0, count3 = 0, count4 = 0;
	gets(a);
	for (; a[i] != '\0'; i++)
	{
		if (a[i] >= 'a' && a[i] <= 'z' || a[i] >= 'A' && a[i] <= 'Z')
			count1++;
		else  if (a[i] == ' ')
			count2++;
		else  if (a[i] >= '0' && a[i] <= '9')
			count3++;
		else
			count4++;
	}
	printf("%d %d %d %d", count1, count2, count3, count4);
	return 0;
}
