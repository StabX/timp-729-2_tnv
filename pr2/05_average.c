#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void)
{
    int i, N, ff, f;
    double aver = 0.0, summ = 0.0;
    f = scanf("%d", &N);
    int mas[N];
    memset(mas, 0, sizeof mas);
    for (i = 0; i < N; i++)
    {
        ff = scanf("%d", &mas[i]);
    }
    for (i = 0; i < N; i++)
    {
        summ += mas[i];
    }
    aver = summ / N;
    printf("%lg\n", aver);
    return 0;
}
