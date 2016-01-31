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
