//1315
//C++语言版
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, m, i, j;
	while (true)
	{
		n = m = i = j = 0;
		// 输入第一组
		cin >> n;
		if (n < 2 || n > 20)
			return 0;
		int *pn = (int *)malloc(sizeof(int)* n);
		for (i = 0; i < n; i++)
			cin >> pn[i];

		// 输入第二组
		cin >> m;
		if (m < 2 || m > 20)
			return 0;
		int *pm = (int *)malloc(sizeof(int)* m);
		for (i = 0; i < m; i++)
			cin >> pm[i];

		// 合并数组
		int *ps = (int *)malloc(sizeof(int)* (n + m));
		for (i = 0; i < n; i++)
			ps[i] = pn[i];
		for (j = n; j < n + m; j++)
			ps[j] = pm[j - n];

		// 排序
		sort(ps, ps + n + m);

		// 输出
		for (i = 0; i < n + m; i++)
		{
			if (i == n + m - 1)
				cout << ps[i] << endl;
			else
				cout << ps[i] << " ";
		}
	}
	return 0;
}
