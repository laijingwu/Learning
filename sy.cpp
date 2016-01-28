/*
*	Latest: 2015-12-11 10:36
*	Author: Lai Jingwu(男版迪士尼)
*	Email: admin@laijingwu.com
*	Reference merely!
*	Cannot be referenced without permission.
*	Copyright (C) 2015 laijingwu.com All Rights Reserved
*/


//1264
#include <stdio.h>

int gcd(int n, int m)	// 计算n和m的最大公约数
{
	if (n % m == 0)
		return m;
	else
		return gcd(m, n% m);
}

int lcs(int n, int m)	// 计算n和m的最小公倍数
{
	int p, q, temp;
	p = (n > m) ? n : m;
	q = (n > m) ? m : n;
	temp = p;
	while(1)
	{
		if (p % q == 0)
			break;
		p += temp;
	}
	return p;
}

int main()
{
	int m, n;
	while(scanf("%d %d", &n, &m) != EOF)
		printf("%d %d\n", gcd(n, m), lcs(n, m));
	return 0;
}

//1265
#include <stdio.h>
#include <math.h>

void root(float a, float b, float c)	// 求根函数
{
	float d, x1, x2, jp, ip;
	d = b * b - 4 * a * c;
	if (fabs(d) <= 1e-6)
	{
		printf("x1=x2=%.3f\n", -b / (2 * a));
	}
	else if (d > 1e-6)
	{
		x1 = (-b + sqrt(d)) / (2 * a);
		x2 = (-b - sqrt(d)) / (2 * a);
		printf("x1=%.3f x2=%.3f\n", x1, x2);
	}
	else
	{
		jp = -b / (2 * a);
		ip = sqrt(-d) / (2 * a);
		printf("x1=%.3f+%.3fi x2=%.3f-%.3fi\n", jp, ip, jp, ip);
	}
}

int main()
{
	float a, b, c;
	while(scanf("%f %f %f", &a, &b, &c) != EOF)
	{
		if (fabs(a) < 1e-6)
			printf("无解\n");
		else
			root(a, b, c);
	}
	return 0;
}

//1266
#include <stdio.h>
#define MAX 200

void insert(int a[], int len, int x)
{
	int i, j;
	for (i = 0; i < len; i++)
	{
		if (x < a[i])
		{
			for (j = len - 1; j >= i; j--)
				a[j + 1] = a[j];
			break;
		}
	}
	a[i] = x;

	for (i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
	printf("%d\n", a[len]);
}

int main()
{
	int a[MAX], i, x, n;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		scanf("%d", &x);
		insert(a, n, x);
	}
	return 0;
}

//1267
#include <stdio.h>
#define MAX 1024

int isChar(char x)
{
	if ((x > 64 && x < 91) || (x > 96 && x < 123))
		return 1;
	else
		return 0;
}

int count(char ch[])
{
	int i, nc = 0;
	for (i = 0; i < MAX; i++)
	{
		if (isChar(ch[i]) == 1)
			nc++;
	}
	return nc;
}

int main()
{
	char ch[MAX] = { 0 };
	while (gets(ch))
	{
		printf("%d\n", count(ch));
	}
	return 0;
}

//1268
#include <stdio.h>
#include <malloc.h>
#include <memory.h>

void backInver(int n, int *a)
{
	int i;
	int *tmp = (int *)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
	{
		tmp[i] = a[n - 1 - i];
	}

	for (i = 0; i < n; i++)
	{
		if (i != n - 1)
			printf("%d ", tmp[i]);
		else
			printf("%d\n", tmp[i]);
	}
	return;
}

int main()
{
	int n, i;
	while (scanf("%d", &n) != EOF)
	{
		int *a = (int *)malloc(sizeof(int)* n);	// 动态分配内存
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		backInver(n, a);
		memset(a, 0, n * sizeof(int));	// 置空
	}
	return 0;
}

//1269
#include <stdio.h>

int Fibonacci(int n)
{
	if (n == 1 || n == 2)
		return 1;
	return (Fibonacci(n - 1) + Fibonacci(n - 2));
}

int main()
{
	int n, y;
	while (scanf("%d", &n) != EOF)
	{
		if (n < 0 || n > 20)
			continue;
		y = Fibonacci(n);
		printf("%d\n", y);
	}
	return 0;
}

//1270
#include <stdio.h>

void f(int x, int n)	// 转换进制
{
	int c = x / n, r = x % n;
	if (c == 0)
		printf("%d", r);
	else
	{
		f(c, n);
		printf("%d", r);
	}
	return;
}

int main()
{
	int x, n;
	while (scanf("%d %d", &x, &n) != EOF)
	{
		f(x, n);
		printf("\n");
	}
	return 0;
}


//1271
#include <stdio.h>

int w(int n)
{
	int x;
	if (n != 0)
	{
		scanf("%d", &x);
		w(x);
		printf("%d ", n);
	}
	return 0;
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		w(n);
		printf("\n");
	}
	return 0;
}

///以下未通过ACM验证，但通过VC6编译
//待测试数据：1 2 4 5 0 1 2 3 4 5 6 7 8 0
#include <stdio.h>

//Version 1
void f(int a[], int n)
{
   if (a[n] == 0)
     return;
  else
     f(a, n+1);
  printf("%d ", a[n]);
}

int main()
{
	int x[100], n = 0, i;
	while (1){
		n = 0;
		while (scanf("%d", &x[n]) != EOF)
		{
			if (x[n] == 0)
				break;
			n++;
		}
		f(x, 0);
		printf("\n");
	}
	return 0;
}

//Version 2
void Inverse(int *a, int left, int right)
{
	int tmp;
	if (left >= right)
		return;
	tmp = a[left];
	a[left] = a[right];
	a[right] = tmp;
	Inverse(a, left + 1, right - 1);
	return;
}

int main()
{
	int x[100], n = 0, i;
	while (1){
		n = 0;
		while (scanf("%d", &x[n]) != EOF)
		{
			if (x[n] == 0)
				break;
			n++;
		}
		Inverse(x, 0, n - 1);
		for (i = 0; i < n; i++)
		{
			if (i == n - 1)
				printf("%d", x[i]);
			else
				printf("%d ", x[i]);
		}
		printf("\n");
	}
	return 0;
}

//Version 3
void reverse()	// 递归函数
{
	int a;	// 保存数字变量
	scanf("%d", &a);
	if(a == 0)
		return;	//	如果遇到0结束
	else
		reverse();	// 进入递归
	if (a != 0)
		printf("%d ", a);	// 每个递归出来时输出接收一个数字
	return;
}

int main()
{
	while (1)
	{
		reverse();
		printf("\n");
	}
	return 0;
}
///以上未通过ACM验证

//1272
#include <stdio.h>

int fun(int n)	// 递归函数计算2+4+6+8+……+n
{
	if (n == 0)
		return 0;
	else
		return n + fun(n - 2);
}

int main()
{
	int n, sum;
	while (scanf("%d", &n) != EOF)
	{
		sum = fun(n);
		printf("%d\n", sum);
	}
	return 0;
}

//1273
#include <stdio.h>

void move(int n, char a, char b, char c)
{
	if (n == 1)
		printf("%c->%c\n", a, c);	// 当n为1个时直接从a移动到c
	else
	{
		move(n - 1, a, c, b);	// 第n-1个从a通过c移动到b
		printf("%c->%c\n", a, c);
		move(n - 1, b, a, c);	// n-1个移动过来后b变起始盘，b通过a移动到c
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	move(n, 'A', 'B', 'C');
	return 0;
}

// 1274
#include <stdio.h>

int main()
{
	struct comp
	{
		float r, i;
	};
	struct comp x, y, a, b, c;
	while (scanf("%f%f%f%f", &x.r, &x.i, &y.r, &y.i) != EOF)
	{
		a.r = x.r + y.r;
		a.i = x.i + y.i;
		c.r = x.r * y.r - x.i * y.i;
		c.i = x.r * y.i + x.i * y.r;

		printf("%.4g+(%.4gi)\n", a.r, a.i);
		printf("%.4g+(%.4gi)\n", c.r, c.i);
	}
	return 0;
}

//1275
#include <stdio.h>
#include <time.h>

struct Date{
	int Year;
	int Month;
	int Day;
};

int main()
{
	struct Date Birth, Now;
	int nYear, nMonth, nDay, unixbirth, unixnow, age;
	while (scanf("%d %d %d %d %d %d", &Birth.Year, &Birth.Month, &Birth.Day, &Now.Year, &Now.Month, &Now.Day) != EOF)
	{
		struct tm tm_birth = { 0 }, tm_now = { 0 };
		nYear = Now.Year - Birth.Year;
		nMonth = Now.Month - Birth.Month;
		nDay = Now.Day - Birth.Day;
		if (nYear < 0)
			return 0;
		tm_birth.tm_year = Birth.Year - 1900;
		tm_birth.tm_mon = Birth.Month - 1;
		tm_birth.tm_mday = Birth.Day - 1;
		tm_now.tm_year = Now.Year - 1900;
		tm_now.tm_mon = Now.Month - 1;
		tm_now.tm_mday = Now.Day - 1;
		unixbirth = mktime(&tm_birth);
		unixnow = mktime(&tm_now);
		age = (unixnow - unixbirth)/(365*24*60*60);
		printf("%d\n", age);
	}
	return 0;
}

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

//1277
#include <stdio.h>

int sum(int y, int m, int d)
{
	int x[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int i, s = 0;
	for (i = 1; i < y; i++)
		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
			s += 366;
		else
			s += 365;
		
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
		x[2] = 29;
	
	for (i = 1; i < m; i++)
		s += x[i];
	s += d;
	return s;
}

int main()
{
	int y1, m1, d1, y2, m2, d2;
	int s1, s2;
	while (scanf("%d %d %d%d %d %d", &y1, &m1, &d1, &y2, &m2, &d2) != EOF)
	{
		s1 = sum(y1, m1, d1);
		s2 = sum(y2, m2, d2);
		if (s1 > s2)
			printf("%d/%d/%d-%d/%d/%d=%ld\n", y1, m1, d1, y2, m2, d2, s1 - s2);
		else
			printf("%d/%d/%d-%d/%d/%d=%ld\n", y2, m2, d2, y1, m1, d1, s2 - s1);
	}
	return 0;
}

//1278
#include <stdio.h>

void main()
{
	printf("*****************************\n");
	printf("This is my first C program!\n");
	printf("*****************************\n");
	return;
}

//1279
#include <stdio.h>

int main()
{
	printf("  *\n");
	printf(" ***\n");
	printf("*****\n");
	return 0;
}

//1280
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
	printf("%#o %#x\n", n, n);
    return 0;
}

//1281
#include <stdio.h>
int main ()
{
    float x;
    scanf("%f", &x);
    printf("%20.3f\n", x);
    return 0;
}

//1282
#include <stdio.h>

int main()
{
    char str;
    scanf("%c",&str);
    int n = (int)str;
    printf("%d",n);
    n -= 32;
    char strup = (char)n;
    printf(" %c\n",strup);
    return 0;
}

//1283
#include <stdio.h>

int main()
{
   char x[100];
   scanf("%s",&x); 
   printf("%.10s", x);
   return 0;
}

//1284
#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, d, e, f, g;
    scanf("%f %f %f %f", &a, &b, &c, &d);
    e = a - c;
    f =b - d;
    g = sqrt(e * e + f * f);
    printf("%.3f\n", g);
    return 0;
}

//1285
#include <stdio.h>

int main()
{
    int a, b, temp;
    scanf("%d %d", &a, &b);
    temp = b;
    b = a;
    a = temp;
    printf("%d %d\n", a, b);
    return 0;
}

//1286
#include <stdio.h>

int main()
{
    int m, n, a, b, c;
    scanf("%d", &m);
    a = m / 100;
    b = (m % 100) / 10;
    c = m % 10;
    n = c * 100 + b * 10 + a * 1;
    printf("%d\n", n);
	return 0;
}

//1287
#include <stdio.h>

int main()
{
    float r, v;
    scanf("%f", &r);
    v = r * r * r * 3.14159 * 4 / 3;
    printf("%.3f\n", v);
    return 0;
}

//1288
#include <stdio.h>

int main()
{
    char ch;
    scanf("%c", &ch);
    if (ch <= 90 && ch >= 65)
        printf("%c\n", ch + 32);
    else
        printf("%c\n", ch - 32);
    return 0;
}

//1289
#include <stdio.h>

int main()
{
	int y;
	while (scanf("%d", &y) != EOF)
	{
		if (y % 4 == 0)
		{
			if (y % 100 == 0)
			{
				if (y % 400 == 0)	// 被400整除，是闰年
				{
					printf("yes\n");
				} else {	// 被100整除，但不被400整除，不是闰年
					printf("no\n");
				}
			} else {	// 被4整除，但不被100整除，不是闰年
				printf("yes\n");
			}
		} else {	// 不被4整除，不是闰年
			printf("no\n");
		}
	}
	return 0;
}

//1290
#include <stdio.h>

void main()
{
	int m, n, a, b, t;
	while (scanf("%d %d", &m, &n) != EOF)
	{
		if (n > m)
		{
			t = n;
			n = m;
			m = t;
		}
		if (m % 2 == 0 && m >= 2 * n && m <= 4 * n)
		{
			b = (m - 2 * n) / 2;
			a = n - b;
			printf("%d %d\n", a, b);
		}
		if (n < 1 || m % 2 != 0 || m < 2 * n || m > 4 * n)
			printf("no answer\n");
	}
}

//1291
#include <stdio.h>

int main()
{
	int a, b, c, t;
	while (scanf("%d %d %d", &a, &b, &c) != EOF)
	{
		if (a > b)
		{
			t = a;
			a = b;
			b = t;
		}
		if (b > c)
		{
			t = b;
			b = c;
			c = t;
		}
		if (a > b)
		{
			t = a;
			a = b;
			b = t;
		}
		printf("%d %d %d\n", a, b, c);
	}
	return 0;
}

//1292
#include <stdio.h>

int main()
{
	double x, y;
	int a;
	while (scanf("%d", &a) != EOF)
	{
		x = a * 95;
		if (x >= 300)
			y = x * 0.85;
		else
			y = x;
		printf("%.3lf\n", y);
	}
	return 0;
}

//1293
#include <stdio.h>

void main()
{
	int a, b, c;
	while (scanf("%d %d %d", &a, &b, &c) != EOF)
	{
		if ((a > 0 && b > 0 && c > 0) && (a + b > c && a + c > b && b + c > a))
		{
			if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
				printf("yes\n");
			else
				printf("no\n");
		}
		else
			printf("not a triangle\n");
	}
}

//1294
#include <stdio.h>

int main()
{
	int x, y;
	while (scanf("%d", &x) != EOF)
	{
		if (x < 1)
			y = x;
		else if (x >= 1 && x < 10)
			y = 2 * x - 1;
		else
			y = 3 * x - 11;
		printf("%d\n", y);
	}
	return 0;
}

//1295
#include <stdio.h>

int main()
{
	int x;
	while(scanf("%d", &x) != EOF)
	{
		if (x > 100 || x < 0)
			continue;
		
		// if法
		/*if (x >= 90)
			printf("A\n");
		else if (x >= 80)
			printf("B\n");
		else if (x >= 70)
			printf("C\n");
		else if (x >= 60)
			printf("D\n");
		else
			printf("E\n");*/
		
		// 运算符法
		x = (x >= 90) ? 'A' : 
			(x >= 80) ? 'B' :
			(x >= 70) ? 'C' :
			(x >= 60) ? 'D' : 'E';
		printf("%c\n", x);
		
		// switch法
		/*switch(x / 10)
		{
			case 9:
				printf("A\n");
				break;
			case 8:
				printf("B\n");
				break;
			case 7:
				printf("C\n");
				break;
			case 6:
				printf("D\n");
				break;
			default:
				printf("E\n");
				break;
		}*/
	}
	return 0;
}

//1296
#include <stdio.h>

int main()
{
	int x, a, b, c, d, e, y;
	while (scanf("%d", &x) != EOF)
	{
		a = 1;
		y = x;
		while (y / 10 != 0){
			y /= 10;
			a++;
		}
		printf("%d\n", a);

		for (e = a; e > 0; e--)
		{
			y = x;
			for (d = 0; d < e - 1; d++)
				y /= 10;
			if (e == 1)
				printf("%d\n", y % 10);
			else
				printf("%d ", y % 10);
		}

		for (c = 1; c <= a; c++)
		{
			y = x;
			for (b = 0; b < c - 1; b++)
				y /= 10;
			if (c == a)
				printf("%d\n", y % 10);
			else
				printf("%d", y % 10);

		}

	}
	return 0;
}

//1297
#include <stdio.h>

int main()
{
	int x;
	double y;
	while (scanf("%d", &x) != EOF)
	{
		switch (x / 100000)
		{
		case 0:
			y = x * 0.1;
			break;
		case 1:
			if (x == 100000)
				y = x * 0.1;
			y = (x - 100000) * 0.075 + 100000 * 0.1;
			break;
		case 2:
		case 3:
			if (x == 200000)
				y = (x - 100000) * 0.075 + 100000 * 0.1;
			y = (x - 200000) * 0.05 + 100000 * (0.075 + 0.1);
			break;
		case 4:
		case 5:
			if (x == 400000)
				y = (x - 200000) * 0.05 + 100000 * (0.075 + 0.1);
			y = (x - 400000) * 0.03 + 200000 * 0.05 + 100000 * (0.075 + 0.1);
			break;
		case 6:
		case 7:
		case 8:
		case 9:
			if (x == 600000)
				y = (x - 400000) * 0.03 + 200000 * 0.05 + 100000 * (0.075 + 0.1);
			y = (x - 600000) * 0.015 + 200000 * 0.03 + 200000 * 0.05 + 100000 * (0.075 + 0.1);
			break;
		default:
			if (x == 1000000)
				y = (x - 600000) * 0.015 + 200000 * 0.03 + 200000 * 0.05 + 100000 * (0.075 + 0.1);
			else if (x > 1000000)
				y = (x - 1000000) * 0.01 + 400000 * 0.015 + 200000 * 0.03 + 200000 * 0.05 + 100000 * (0.075 + 0.1);
			break;
		}
		printf("%.0f\n", y);
	}
	return 0;
}


//1298
#include <stdio.h>

int main()
{
	int a, n, s, i, t;
	scanf("%d %d", &a, &n);
	s = 0;
	i = 1;
	t = a;
	while (i <= n)
	{
		s += t;
		t = t * 10 + a;
		i++;
	}
	printf("%d\n", s);
	return 0;
}

//1299
#include <stdio.h>

int main()
{
	int sum, x;
	sum = 0;
	while (scanf("%d", &x) != EOF)
		sum += x;
	printf("%d\n", sum);
	return 0;
}

//1300
#include <stdio.h>

int main()
{
	int sum = 0, n, i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		sum += i;
	printf("%d\n", sum);
	return 0;
}

//1301
#include <stdio.h>

int main()
{
	int p = 1, i;
	long s = 0;
	for (i = 1; i <= 10; i++)
	{
		p *= i;
		s += p;
		printf("%d\n", s);
	}
	return 0;
}

//1302
#include <stdio.h>

int main()
{
	int n = 0, i, j, k;
	scanf("%d", &n);
	if (n < 0 || n > 10)
		return;
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j < n - i; j++)
			printf(" ");
		for (k = 1; k <= i; k++)
			printf("%d", i);
		printf("\n");
	}
	return 0;
}

//1303
#include <stdio.h>

int main()
{
	int n, r, j, i;
	scanf("%d", &n);
	for (i = 1; i < n; i++)
	{
		r = 0;
		for (j = 1; j < i; j++)
		{
			if (i % j == 0)
			{
				r += j;
			}
		}
		if (r == i)
			printf("%d\n", r);
	}
	return 0;
}

//1304
#include <stdio.h>

int main()
{
	int n, s, t;
	while (scanf("%d", &s) != EOF)
	{
		n = 0;
		t = 0;
		while (1)
		{
			t += n;
			if ((s > t && s <= t + n + 1) || s <= 0)	// 防止为负数或0时超出范围
				break;
			n++;
		}
		printf("%d\n", n);
	}
	return 0;
}

//1305
#include <stdio.h>
#include <math.h>

int main()
{
	int  n, i;
	double x, y, t = 1., s = 1.;
	while (scanf("%d %lf", &n, &x) != EOF){
		t = 1.;
		s = 1.;
		y = x / 1;
		t = t * x;
		for (i = 3; i <= 2 * n - 1; i = i + 2)
		{
			t = t * x * x;
			s = i * (i - 1) * s;
			y = y + pow(-1, (i - 1) / 2) * t / s;
		}
		printf("%.3f\n", y);
	}
	return 0;
}

//1306
#include <stdio.h>
#include <math.h>

int isSu(int n);

int main()
{
	int a, b, i;
	while (scanf("%d %d", &a, &b) != EOF)
	{
		if (a < 2 || a > b || b >= 1000)
			break;
		for (i = a; i <= b; i++)
		{
			if (isSu(i))
			{
				printf("%d ", i);
			}
		}
		printf("\n");
	}
	return 0;
}

int isSu(int n)
{
	int k, i;
	k = (int)sqrt(n);
	for (i = 2; i <= k; i++)
	if (n % i == 0)
		break;
	if (i > k)
		return 1;
	else
		return 0;
}

//1307
#include <stdio.h>

int main()
{
	int n, i, j, k;
	scanf("%d", &n);
	if (n < 0 || n > 7)
		return 0;
	for (i = n; i <= n + 3; i++)
	{
		for (j = n; j <= n + 3; j++)
		{
			for (k = n; k <= n + 3; k++)
			{
				if (i != j && k != j && i != k)
				{
					printf("%d%d%d ", i, j, k);
				}
			}
		}
	}
	printf("\n");
	return 0;
}

//1308
#include <stdio.h>
#include <math.h>

float f(float a, float b, float c, float d, float x)
{
	float f;
	f = ((a * x + b) * x + c) * x + d;
	return f;
}

float f1(float a, float b, float c, float d, float x)
{
	float f1;
	f1 = (3 * a * x + 2 * b) * x + c;
	return f1;
}

float root(float a, float b, float c, float d, float x0)
{
	float x1;
	do
	{
		x1 = x0;
		x0 = x1 - f(a, b, c, d, x0) / f1(a, b, c, d, x0);
	} while (fabs(x1 - x0) >= 1e-6);
	return x0;
}

int main()
{
	float a, b, c, d, x = 2.5, nx;
	scanf("%f %f %f %f", &a, &b, &c, &d);
	nx = root(a, b, c, d, x);
	printf("%.3f\n", nx);
	return 0;
}

//1309
#include <stdio.h>
#include <math.h>

float f(float a, float b, float c, float d, float x)
{
	float f;
	f = (float)(a * pow(x, 3) + b * pow(x, 2) + c * x + d);
	return f;
}

int main()
{
	float x0 = -10, x1 = 10, a, b, c, d, m;
	scanf("%f %f %f %f", &a, &b, &c, &d);

	m = (x0 + x1) / 2;
	while (fabs(f(a, b, c, d, m)) > 1e-5 && fabs(x0 - x1) > 1e-5)
	{
		if (f(a, b, c, d, m) * f(a, b, c, d, x1) < 0)
			x0 = m;
		if (f(a, b, c, d, x0) * f(a, b, c, d, m) < 0)
			x1 = m;
		m = (x0 + x1) / 2;
	}
	printf("%.3f\n",m);
}

//1310
// 第一种方法：递归函数
#include <stdio.h>

int f(int x)
{
	if (x == 1 || x == 2)
		return 1;
	else
		return (f(x - 1) + f(x - 2));
}

int main()
{
	int n;
	scanf("%d", &n);
	if (n < 1 || n > 46)
		return 0;
	printf("%d\n", f(n));
	return 0;
}

// 第二种方法：数组
#include <stdio.h>

int main()
{
	int a[47] = { 0, 1, 1, 0 }, i, n;
	scanf("%d", &n);
	for (i = 3; i <= n; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
	}
	printf("%d", a[n]);
	return 0;
}

// 第三种方法：多变量交替
#include <stdio.h>

int main()
{
	int a = 1, b = 1, c, i, n;
	scanf("%d", &n);
	for (i = 3; i <= n; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	printf("%d", c);
	return 0;
}

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

//1312
#include <stdio.h>

int  main()
{
	int n, i, j, temp;
	int a[100];
	scanf("%d", &n);
	for (i = 0; i != n; ++i)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i != n; ++i)
	{
		for (j = i + 1; j != n; ++j)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	printf("%d", a[0]);
	for (i = 1; i != n; ++i)

	{

		printf(" %d", a[i]);
	}
}

//1313
#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, i, m, k, s[1000];
	while (scanf("%d %d", &a, &b) != EOF)
	{
		for (i = 0; i <= b - a; i++)
		{
			s[i] = i + a;
			k = (int)sqrt(s[i]);
			for (m = 2; m <= k; m++)
			if (s[i] % m == 0)
				break;

			if (m > k)
				printf("%d ", s[i]);
		}
		printf("\n");
	}
	return 0;
}

//1314
#include <stdio.h>
#include <malloc.h>
#include <memory.h>

int main()
{
	int n, i, j, sum;
	while (scanf("%d", &n) != EOF)
	{
		sum = 0;
		if (n < 3)
			return 0;

		// 动态分配建立二维数组
		int **arr = (int **)malloc(sizeof(int *)* n);
		for (i = 0; i < n; i++)
			arr[i] = (int *)malloc(sizeof(int)* n);

		// 输入
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				scanf("%d", &arr[i][j]);

		// 计算和
		for (i = 0; i < n; i++)
		{
			if (n % 2 != 0 && i == (n - 1) / 2)	// 奇数
				continue;
			else
			{
				sum += arr[i][i];
				sum += arr[i][n - 1 - i];
			}
		}
		if (n % 2 != 0)	// 奇数
			sum += arr[(n + 1) / 2][(n + 1) / 2];
		printf("%d\n", sum);
	}
	return 0;
}


//1315
//C语言版
#include <stdio.h>
#include <malloc.h>

int main()
{
	int n, m, i, j, tmp;
	while (1)
	{
		n = m = i = j = tmp = 0;
		// 输入第一组
		scanf("%d", &n);
		if (n < 2 || n > 20)
			return 0;
		int *pn = (int *)malloc(sizeof(int)* n);
		for (i = 0; i < n; i++)
			scanf("%d", &pn[i]);

		// 输入第二组
		scanf("%d", &m);
		if (m < 2 || m > 20)
			return 0;
		int *pm = (int *)malloc(sizeof(int)* m);
		for (i = 0; i < m; i++)
			scanf("%d", &pm[i]);

		// 合并数组
		int *ps = (int *)malloc(sizeof(int)* (n + m));
		for (i = 0; i < n; i++)
			ps[i] = pn[i];
		for (j = n; j < n + m; j++)
			ps[j] = pm[j - n];

		// 冒泡排序
		for (i = 0; i < n + m; i++)
		{
			for (j = 0; j < n + m - i; j++)
			{
				if (ps[j] > ps[j + 1] && j != n + m - 1)
				{
					tmp = ps[j];
					ps[j] = ps[j + 1];
					ps[j + 1] = tmp;
				}
			}
		}

		// 输出
		for (i = 0; i < n + m; i++)
		{
			if (i == n + m - 1)
				printf("%d\n", ps[i]);
			else
				printf("%d ", ps[i]);
		}
	}
	return 0;
}
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
//C++语言版
#include <iostream>
using namespace std;

int main()
{
	int n, i, per, score[101];
	memset(score, 0, sizeof(int)* 101);
	cin >> n;
	for (i = 0; i < n; i++)
	{
		per = 0;
		cin >> per;
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

	cout << part59 << " " << part69 << " " << part79 << " " << part89 << " " << part100 << " " << endl;

	return 0;
}

//1318
//C语言版
#include <stdio.h>
#include <malloc.h>
#include <memory.h>

int main()
{
	int n, i, j, k = 0, flag = 1;
	while (scanf("%d", &n) != EOF)
	{
		i = j = k = 0;
		flag = 1;
		if (n <= 1 || n >= 30)
			continue;

		int *a = (int *)malloc(sizeof(int) * n);	// 动态分配内存
		int *b = (int *)malloc(sizeof(int) * n);	// 动态分配内存
		memset(a, 0, n * sizeof(int));	// 置空
		memset(b, 0, n * sizeof(int));	// 置空
		
		// 输入
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);

		for (i = 0; i < n; i++)
		{
			flag = 1;
			for (j = 0; j < k; j++)
			{
				if(a[i] == b[j])
					flag = 0;
			}
			if(flag)
			{
				b[k] = a[i];
				k++;
			}
			
		}

		// 输出
		for (i = 0; i < k; i++)
		{
			printf("%d ", b[i]);
		}
		printf("\n");
	}
	return 0;
}
//C++版
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

//1320
//C语言版
#include <stdio.h>

void f(char a[])
{
	int n = 0, i;
	for (i = 0; a[i] != '\0'; i++)
	{
		if (a[i] == ' ' && ((a[i + 1] >= 'a' && a[i + 1] <= 'z') || (a[i + 1] >= 'A' && a[i + 1] <= 'Z')))
			n++;
	}
	if (a[0] == ' ')
		printf("%d\n", n);
	else
		printf("%d\n", n + 1);
}

int main()
{
	char a[1024];
	gets(a);
	f(a);
	return 0;
}
//C++语言版
#include <iostream>
using namespace std;

void f(char a[])
{
	int n = 0, i;
	for (i = 0; a[i] != '\0'; i++)
	{
		if (a[i] == ' ' && ((a[i + 1] >= 'a' && a[i + 1] <= 'z') || (a[i + 1] >= 'A' && a[i + 1] <= 'Z')))
			n++;
	}
	if (a[0] == ' ')
		cout << n << endl;
	else
		cout << n + 1 << endl;
}

int main()
{
	char a[1024];
	gets(a);
	f(a);
	return 0;
}

//1321
#include <stdio.h>

//swap()函数
int swap(int *n, int *m)
{
	int tmp = *n;
	*n = *m;
	*m = tmp;
	return 0;
}

int main()
{
	int m, n;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		swap(&n, &m);
		printf("%d %d\n", n, m);
	}
	return 0;
}

//1322
#include <stdio.h>

//下面是函数 f()的定义
int f(int a[], int n, int *min, int *max)
{
	int i;
	*min = *max = a[0];
	for (i = 0; i < n; i++)
	{
		if (a[i] < *min)
			*min = a[i];
		if (a[i] > *max)
			*max = a[i];
	}
	return 0;
}

int main()
{
	int i, n, max, min, a[100];
	while (scanf("%d", &n) != EOF)
	{
		if (n < 2 || n > 100)
			return 0;

		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		f(a, n, &min, &max);
		printf("%d %d\n", min, max);
	}
	return 0;
}

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

//1326
