//1318
//C++语言版
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	typedef vector<int> IntArray;
	while (cin >> n)
	{
		if (n <= 1 || n >= 30)
			continue;
		
		IntArray Ori, Des;
		// 输入
		for (int i = 0; i < n; i++)
		{
			int tmp;
			cin >> tmp;
			Ori.push_back(tmp);
		}

		for (IntArray::iterator iter = Ori.begin(); iter != Ori.end(); iter++)
		{
			IntArray::iterator result = find(Des.begin(), Des.end(), (*iter));
			if (result == Des.end())	// 没找到
				Des.push_back((*iter));
			else	// 找到
				continue;
		}
		
		// 输出
		for (IntArray::iterator iter2 = Des.begin(); iter2 != Des.end(); iter2++)
		{
			cout << *iter2 << " ";
		}
		cout << endl;
	}
	return 0;
}
