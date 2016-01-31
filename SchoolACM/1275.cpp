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
