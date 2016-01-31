//1276
#include <stdio.h>

struct stu
{
	int uid;
	int score1;
	int score2;
	int score3;
	int total;
};

int main()
{
	int n, i, j;
	struct stu info[100], temp;
	scanf("%d", &n);
	if (n > 20)
		return 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &info[i].uid, &info[i].score1, &info[i].score2, &info[i].score3);
		info[i].total = info[i].score1 + info[i].score2 + info[i].score3;
	}
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (info[i].total > info[j].total)
			{
				temp = info[i];
				info[i] = info[j];
				info[j] = temp;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%d %d", info[i].uid, info[i].total);
		if (i != n - 1)
			printf("\n");
	}
	return 0;
}
