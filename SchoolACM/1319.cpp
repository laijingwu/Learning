//1319
#include <stdio.h>
#define MAX 10

void MatrixMutiply(int m, int n, int p, long lMatrix1[MAX][MAX], long lMatrix2[MAX][MAX], long lMatrixResult[MAX][MAX])
{
	int i, j, k;
	long lSum;

	// 嵌套循环计算结果矩阵m*p的每个元素
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < p; j++)
		{
			// 按照矩阵乘法的规则计算结果矩阵的i*j元素
			lSum = 0;
			for (k = 0; k < n; k++)
				lSum += lMatrix1[i][k] * lMatrix2[k][j];
			lMatrixResult[i][j] = lSum;
		}
	}
}

int main()
{
	long lMatrix1[MAX][MAX], lMatrix2[MAX][MAX];
	long lMatrixResult[MAX][MAX], lTemp;
	int i, j, m, n, p;

	// 输入第一个矩阵的行列数
	scanf("%d %d", &m, &n);

	// 输入第一个矩阵的每一个元素
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%ld", &lTemp);
			lMatrix1[i][j] = lTemp;
		}
	}

	// 输入第二个矩阵的行列数
	scanf("%*d %d", &p);

	// 输入第二个矩阵的每一个元素
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < p; j++)
		{
			scanf("%ld", &lTemp);
			lMatrix2[i][j] = lTemp;
		}
	}

	// 调用函数进行乘法运算，结果放在lMatrixResult中
	MatrixMutiply(m, n, p, lMatrix1, lMatrix2, lMatrixResult);

	// 输出结果矩阵
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < p; j++)
		{
			printf("%ld ", lMatrixResult[i][j]);
		}
		printf("\n");
	}
	return 0;
}
