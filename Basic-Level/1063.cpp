/* 1063 º∆À„∆◊∞Îæ∂ */
#include <stdio.h>
#include <math.h>

int main()
{
    //1. ‰»Î
    int N;
    scanf("%d", &N);

    int i;
    double total = 0;
    double temp;
    int a, b;
    for (i = 0; i < N; i++)
    {
        scanf("%d%d", &a, &b);
        temp = sqrt(a * a + b * b);
        if (temp > total)
        {
            total = temp;
        }
    }

    printf("%.02lf", total);

    return 0;
}
