#include <stdio.h>
#include <math.h>

int main()
{
double x = 0, y = 0, res;
int q = scanf("%lf%lf", &x, &y);
res = pow(x,y);
printf("%lf", res);
return q;
}
