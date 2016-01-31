//1323
#include <stdio.h>
#include <string.h>
#define LEN 100	// 单词最大长度
#define MAXNUM 100	// 单词个数

int main()
{
	char str[MAXNUM][LEN];
	int i = 0, j = 0, n = 0;

	// 输入
	while (scanf("%s", str[n]) != EOF)
		n++;

	// 对字符串排序
	for (i = 1; i < n; i++)
	{
		if (strcmp(str[i], str[i - 1]) < 0)
		{
			char temp[MAXNUM];
			strcpy(temp, str[i]);
			strcpy(str[i], str[i - 1]);
			for (j = i - 2; strcmp(str[j], temp) > 0 && j >= 0; --j)
				strcpy(str[j + 1], str[j]);
			strcpy(str[j + 1], temp);
		}
	}

	// 输出单词
	for (i = 0; i < n; i++)
	{
		printf("%s", str[i]);
		printf("\n");
	}
	return 0;
}
