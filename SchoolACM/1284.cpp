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
