//1317
//C语言版
#include <stdio.h>
#include <memory.h>

int main()
{
	int n, i, per, score[101];
	memset(score, 0, sizeof(int)* 101);
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		per = 0;
		scanf("%d", &per);
		if (per < 0 || per > 100)
			return 0;
		score[per]++;
	}

	int part59 = 0, part69 = 0, part79 = 0, part89 = 0, part100 = 0;
	for (i = 0; i < 60; i++)
		part59 += score[i];
	for (i = 60; i < 70; i++)
		part69 += score[i];
	for (i = 70; i < 80; i++)
		part79 += score[i];
	for (i = 80; i < 90; i++)
		part89 += score[i];
	for (i = 90; i <= 100; i++)
		part100 += score[i];

	printf("%d %d %d %d %d \n", part59, part69, part79, part89, part100);

	return 0;
}
