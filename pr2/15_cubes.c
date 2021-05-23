#include<stdio.h>

int main()
{
    int i, N = 0, a = 0;
    double sum = 1;
    (void)scanf("%d", &N);
    for(i=1; i<=N; i++)
    {
        (void)scanf("%d", &a);
        if (i%2 == 0)
        {
            sum += a * a * a;
        }
    }
    sum = sum - 1;
    printf("%lf", sum);
    return 0;
}
