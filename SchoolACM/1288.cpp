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
