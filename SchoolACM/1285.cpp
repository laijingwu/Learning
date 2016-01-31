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
